
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Requires at least one argument\n");
        return EINVAL;
    }

    int fd[2], fd_in = 0; // Start with standard input for the first process

    for (int i = 1; i < argc; i++) {
        if (pipe(fd) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            if (fd_in != 0) { // Not the first command
                if (dup2(fd_in, 0) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            if (i < argc - 1) { // Not the last command
                if (dup2(fd[1], 1) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            close(fd[0]); // Close read end in child

            execlp(argv[i], argv[i], (char *)NULL);
            perror("execlp");
            exit(errno);
        } else { // Parent process
            close(fd[1]); // Close write end in parent after forking
            if (fd_in != 0) { // Close the old read end if not the first command
                close(fd_in);
            }
            fd_in = fd[0]; // Save read end for the next child
            int status;
		waitpid(pid, &status, 0);
	     if(WIFEXITED(status) && WEXITSTATUS(status)!=0){
		return WEXITSTATUS(status);
	}
	}
    }

    // Close the last unused read end
    if (fd_in != 0) {
        close(fd_in);
    }

    // Wait for all children to complete
    while (wait(NULL) > 0);

    return 0;
}
