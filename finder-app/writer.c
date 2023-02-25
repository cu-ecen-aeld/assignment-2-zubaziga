#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SYSLOG_ERR_EXIT(...)  syslog(LOG_ERR, ##__VA_ARGS__); exit(1);

int main(int argc, char *argv[]) {
   FILE *fp;
   openlog(NULL,0,LOG_USER);
   if (argc != 3) 
   {
   	SYSLOG_ERR_EXIT("Invalid number of arguments: %d", argc-1);
   }
	
   fp = fopen(argv[1],"w");
   if (errno != 0) 
   {
	SYSLOG_ERR_EXIT("Error opening %s file, errno: %d - %s",
			        argv[1], errno, strerror(errno));
   }

   if (fp == NULL)
   {
	//should never hit this (errno == 0), just for OCD sake
	SYSLOG_ERR_EXIT("Failed to open %s file, errno: %d, but pointer is NULL",
			        argv[1], errno);
   }

   fprintf(fp, "%s", argv[2]);
   if (errno != 0)
   {
	int errval = errno;//fclose will change errno
	fclose(fp);
	SYSLOG_ERR_EXIT("Failed to write \"%s\" string to file %s, errno: %d - %s",
		       		argv[2], argv[1], errval, strerror(errval));	
   }

 
   fclose(fp);
   if (errno != 0)
   {
	SYSLOG_ERR_EXIT("Failed to close file %s, errno: %d - %s", 
			        argv[1], errno, strerror(errno));
   }

   //All ok, reporting.
   syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
   return 0;
}
