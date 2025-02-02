#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <file_path> <content>\n", argv[0]);
        return 1;
    }

    char *filePath = argv[1];
    char *content = argv[2];

    // open syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // create file at filePath if it doesn't exist
    FILE *file = fopen(filePath, "w");
    if (file == NULL)
    {
        syslog(LOG_ERR, "Error: Cannot create file at %s", filePath);
        closelog();
        return 1;
    }

    // write content to file
    syslog(LOG_INFO, "Writing content %s to file at %s", content, filePath);
    if (fprintf(file, "%s", content) < 0)
    {
        syslog(LOG_ERR, "Error: Failed to write content to file at %s", filePath);
        fclose(file);
        closelog();
        return 1;
    }
    fclose(file);

    syslog(LOG_INFO, "Successfully wrote to file at %s", filePath);

    // close syslog
    closelog();
    return 0;
}
