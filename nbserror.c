#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "nbserror.h"
/***
  nbserrno set by components of NBS
 example slave did found job 
  nbserrno = SLAVE_JOBID_NOTFOUND 
  errno declared in errno.h
 ****/ 
int nbserrno = SLAVE_JOBID_NOTFOUND;

char   *nbserrmsg[] = {
    /*00*/   "No error",
    /*01*/   "HOST Not matching",
    /*02*/   "Job NOT Found",
    /*03*/   "Host communication error",
    /*04*/   "Unable to set PATH",
    /*05*/   "Job Id not found", /* no message needed */
    /*06*/   "Job finshed",
    /*07*/   "Net work error",
      NULL
};


char* nbsmsg(void)
{
    static char buf[512];

    if (nbserrno >= NBS_MAX_ERR) 
   {
        sprintf(buf, "Unknown batch error number %d", nbserrno);
        return buf;
    }
    if(errno >0)
            sprintf(buf, "%s: %s", nbserrmsg[nbserrno], strerror(errno));
    else
            sprintf(buf, "%s: unknown error %d", nbserrmsg[nbserrno], errno);
    

    return buf;
}

void nbsEmessage(const char *usrMsg)
{
    if (usrMsg) {
        fputs(usrMsg, stderr);
        fputs(": ", stderr);
    }
    fputs(nbsmsg(), stderr);
    putc('\n', stderr);

}

int main()
{
  nbsEmessage("NBSJobId");
  printf("NBS error test\n");
 return 0;
}