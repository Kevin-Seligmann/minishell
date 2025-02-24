# Minishell

A small - mini - shell based on Bash, written on C.

## General Requirements

- Must follow the Norminette style guide.
- Allowed functions: readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
- Should not have memory leaks or terminate unexpectedly.
- Must submit a Makefile with specified rules.

## Requirements

- The shell must display a promtp waiting for input
- There should be a history of commands
- The right executable should be launch based on the PATH enviromental variable
- Only one global variable is allowed, only to indicate a received signal
- Handle single ' and double quotes " like in Bash
- Implement the following redirections: >, <, >>, <<
- Implement pipes |
- Handle adding, removing, showing, expanding envorimental variables ($)
- Handle exits codes like Bash ($?)
- Handle ctrl-c and ctrl-\ signals like in Bash.
- Handle ctrl-d (EOF)
- Add &&, || and parenthesis. Not like in Bash, just for execution order (Must not create subshells).
- Add wilcard * expansions for the working directory.

## Builtins

There behave like Bash, including edge cases.

- Implement echo with the -n flag.
- Implement cd
- Implement pwd (No flags)
- Implement export (No flags)
- Implement unset (No flags)
- Implement env (No flags)
- Implement exit (No flags)
