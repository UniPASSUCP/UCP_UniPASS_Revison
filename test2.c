/*******************************************************************************
 *  Filename: logreader.c                                                      *
 *  Author: Nicholas Wright 12880155                                           *
 *  Purpose: Read and search a log file                                        *
 *  Date Written: 30/08/21                                                     *
 *  Edited By:       Date Editted:                                             *
 *  ***************************************************************************/
#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE !FALSE

/*fscanf extracts variables from a known pattern
 * fgets gets a string to the end of the line*/

int main(int argc, char * argv[])
{
    char* logFileName;
    FILE* logFile;
    int nRead = 0;
    int done = FALSE;

    char month[512];
    char process[512];
    char message[512];
    char *locFail;
    int day =0, hour =0, min =0, sec =0;

    if( argc == 2 )
    {
        logFileName = argv[1];
        logFile = fopen( logFileName, "r" );

        if( logFile == NULL )
        {
            perror("Error opening file");
        }
        else
        {
            while( !done )
            {
                nRead = fscanf(logFile, "%s %d %d:%d:%d %s ",
                               month, &day, &hour, &min, &sec, process );
                fgets( message, 512, logFile );

                if( nRead != 6 )
                {
                    done = TRUE;
                }
                else
                {
                    locFail = strstr( message, "fail" );

                    if( locFail != NULL )
                    {
                        printf("seconds at fail is %d\n", sec );
                    }
                }
            }

            fclose(logFile);
        }
    }
    return 0;
}
