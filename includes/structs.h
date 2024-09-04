/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:38:34 by oseivane          #+#    #+#             */
/*   Updated: 2024/09/04 05:15:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "definitions.h"

typedef struct s_var		t_var;

struct						s_command;

typedef struct s_command	t_command;

/*
	Double linked list representing an enviroment - and some shell variables.
	
	`name` - Name of the variable.
	`value` - Value of the variable.
	`prev` `next` - Neighbour nodes
*/
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

/*
	Minishell builtins.
	
	`action` - Builtin name.
	`function` - Builtin function pointer.
*/
typedef struct s_actions
{
	char	*action;
	int		(*function)(t_var *var, char **params);
}	t_actions;

/*
	Global-like data structure.
	
	`command_tree` - Command tree result of parsing.
	`env` - Enviromental variables and some internals.
	`act` - Builtins
	`exit` - Exit code
	`kill` - Boolean-like for fatal error
	`fds_list` - STD file descriptors stored.
*/
typedef struct s_var
{
	t_command			*command_tree;
	struct s_env		*env;
	struct s_actions	*act;
	int					exit;
	int					kill;
	int					fds_list[3];
}	t_var;

typedef struct s_redirect	t_redirect;

typedef struct s_word_list	t_word_list;

/*
	A linked list of words.
*/
struct s_word_list
{
	t_word_list		*next;
	char			*word;
};

/*
	A linked list of redirects.

	`type` - Which kind of redirect this is (<, >, >>, <<).
	`word` - Redirect argument (Usually a file, but could be a here-doc delimiter).
	`expanded` - `word` is subject to expansions, but on all cases an expansion to more than one argument results in an error.
	`fd` - After opening the file, this is its file descriptor.
*/
struct s_redirect
{
	t_redirect			*next;
	enum e_redir_type	type;
	char				*word;
	t_word_list			*expanded;
	int					fd;
};

/*
	A connected command. E.g: Pipe, &&, ||.
*/
typedef struct s_connection
{
	t_command			*first;
	t_command			*second;
	enum e_connector	connector;
}	t_connection;

/*
	A simple command.

	`redirects` - A list of redirects to perform before command execution.
	`words` - Command arguments on a linked list.
	`args` - Command arguments on a char ** (To use execve).
*/
typedef struct s_simple_command
{
	t_redirect	*redirects;
	t_word_list	*words;
	char		**args;
}	t_simple_command;

/*
	A command of either type.
*/
union u_command_value
{
	t_connection		*connection;
	t_simple_command	*simple;
};

/*
	A command.
*/
struct s_command
{
	enum e_command_type		type;
	union u_command_value	value;
	int						flags;
};

#endif
