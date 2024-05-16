/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:34:19 by oseivane          #+#    #+#             */
/*   Updated: 2024/05/13 11:20:29 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_env(t_var *var, char *str)
{
	t_env	*tmp;

	tmp = var->env;
	while (tmp)
	{
		printf("%s %s:%s\n", str, tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void	get_add_var_env(t_var *var, char **params, int index)
{
	char	*name;
	char	*value;
	t_env	*env_name;

	name = ft_substr(params[1], 0, index);
	value = ft_substr(params[1], index + 1, ft_strlen(params[1]) - index + 1);
	env_name = find_in_env(var->env, name);
	if (ft_isalpha(name[0]))
	{
		if (!env_name)
			add_in_env(var, ft_strdup(name), ft_strdup(value));
		else
		{
			free(env_name->value);
			env_name->value = ft_strdup(value);
		}
		if (ft_strcmp(params[0], "env") == 0)
			print_env(var, "");
	}
	else
		printf("minishell: %s: '%s': not a valis identifier\n",
			params[0], params[1]);
}

void	ft_export(t_var *var, char **params)
{
	if (params[1] && ft_strchr_index(params[1], '=') != -1)
		get_add_var_env(var, params, ft_strchr_index(params[1], '='));
	else
		print_env(var, "declare -x");
}

void	ft_env(t_var *var, char **params)
{
	int	index;

	if (ft_strcmp(params[0], "env") == 0)
	{
		if (!params[1] || params[1][0] == '\0')
			print_env(var, "");
		else if (params[1] && ft_strchr_index(params[1], '=') != -1)
			get_add_var_env(var, params, ft_strchr_index(params[1], '='));
	}
}

void	ft_help(t_var *var, char **params)
{
	printf("\033[0;35m\tHOW TO USE MINISHELL:\n\033[0m");
	printf("Bash is a command-line interpreter and scripting language.\n\n");
	printf("Commands:\t\tActions:\n______________________________\n");
	printf("(flag -n) Display text or output to the terminal\n");
	printf("\033[0;33mpwd:\033[0m Print working directory\n");
	printf("\033[0;33mexport:\033[0m Used to set an environment variable\n");
	printf("Used to unset or delete a variable or function\n");
	printf("Used to display or modify the environment variables\n\n");
}
