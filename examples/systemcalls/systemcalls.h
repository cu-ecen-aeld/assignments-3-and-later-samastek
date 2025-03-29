#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>    // For EXIT_FAILURE
#include <unistd.h>    // For fork(), execv(), _exit()
#include <sys/types.h> // For pid_t
#include <sys/wait.h>  // For waitpid()
#include <stdarg.h>    // For variable arguments (va_list)
#include <stdbool.h>   // For bool type
#include <fcntl.h>

bool do_system(const char *command);

bool do_exec(int count, ...);

bool do_exec_redirect(const char *outputfile, int count, ...);
