#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Handler only three parameters because we are using sa_sigaction
static void hdl(int sig, siginfo_t *siginfo, void *context)
{
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)si_uid);
}

int main(int argc, char *argv[])
{
    struct sigaction act;

    memset(&act, '\0', sizeof(act));
    
    /* 
        Use the sa_sigaction field because the handles have two additional parameters
        hdl contains a siginfo_t and a void pointer
    */
    act.sa_sigaction = &hdl;

    /* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler */
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGTERM, &act, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }

    while(1)
    {
        sleep(3);
    }

    return 0;
}