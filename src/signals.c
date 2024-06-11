/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:51 by oseivane          #+#    #+#             */
/*   Updated: 2024/06/11 02:07:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define norminetterror "FIXME ^C, GLOBAL ASSIGNATION??"

int	g_sigint;

void	sint_handler(int signal)
{
	(void) signal;
	write(1, "\n", 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	if (g_sigint != SINT_HEREDOC)
		rl_redisplay();
	g_sigint = SINT_ON;
}

void	reset_signal(t_var *var)
{
	(void) var;
	g_sigint = SINT_OFF;
}

void	set_signal_ignore(int signal)
{
	struct sigaction	sigs;

	sigs.sa_flags = 0;
	sigs.sa_handler = SIG_IGN;
	sigemptyset(&sigs.sa_mask);
	sigaction(signal, &sigs, NULL);
}

void	set_signal_handler(int signal, void (*handler))
{
	struct sigaction	sigs;

	sigs.sa_flags = 0;
	sigs.sa_handler = handler;
	sigemptyset(&sigs.sa_mask);
	sigaction(signal, &sigs, NULL);
}

void	init_signals(void)
{
	g_sigint = SINT_OFF;
	set_signal_ignore(SIGQUIT);
	set_signal_handler(SIGINT, sint_handler);
}
