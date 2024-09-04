# Minishell

A small - mini - shell based on Bash, written on C.

## Requirements

Styleguide [Norminette](https://github.com/42School/norminette)

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

### Builtins

There behave like Bash, including edge cases.

- Implement echo with the -n flag.
- Implement cd
- Implement pwd (No flags)
- Implement export (No flags)
- Implement unset (No flags)
- Implement env (No flags)
- Implement exit (No flags)

- There should be no leaks, or unexpected exits. 
- Allowed functions: readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs

### Bonus requirements

- Add &&, || and parenthesis. Not like in Bash, just for execution order (Must not create subshells).
- Add wilcard * expansions for the working directory.

## 42

[42](https://www.42network.org/about-us/) Is a programming school that teaches in an innovative way, focused on an strict model of peer to peer evaluation and self learning via the writting of, mostly, coding projects.

## Score/Testing

 - Evaluation (125/125)
