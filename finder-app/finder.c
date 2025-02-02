#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

    char *filesdir = argv[1];
    char *searchstr = argv[2];
    struct stat statbuf;

    printf("filesdir: %s\n", filesdir);
    printf("Searchdir: %s\n", searchstr);

    if (argc != 3)
    {
        printf("Usage: %s <filename> <searchstr>\n", argv[0]);
        return 1;
    }

    // check if filesdir is a directory
    if (stat(filesdir, &statbuf) != 0)
    {
        printf("Error: Cannot access %s\n", filesdir);
        return 1;
    }

    if (S_ISDIR(statbuf.st_mode))
    {
        printf("%s is a directory ✅\n", filesdir);
    }
    else
    {
        printf("%s is NOT a directory ❌\n", filesdir);
    }

    int file_count = 0;
    DIR *dirp;
    struct dirent *entry;
    dirp = opendir(filesdir); 
    while ((entry = readdir(dirp)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { /* If the entry is a regular file */
            file_count++;
        }
    }
    printf("Total files in directory: %d\n", file_count);
    closedir(dirp);

    return 0;
}
