#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
/* limits.h defines "PATH_MAX". */
#include <limits.h>

/* List the files in "directory_name". */

void list_directory (const char * directory_name)
{
    DIR * d; 
    /*DIR ....a type representing a directory stream.....
      which is an ordered sequence of all the directory entries in a particular directory....
      it's been derived from dirent.h header :) */

    d = opendir (directory_name);

    /* check whether the directory is open or not */
    if (! d) 
    {
        printf ("Cannot open the specified directory\n"); 
        printf ("try again with a valid directory name :) "); 
    }
    while (1) 
    {
        struct dirent * entry;
        const char * d_name;

        /*readdir gets subsequent entries from "d"....
        this function derived from dirent.h and sys/types.h */
        
        entry = readdir (d);
        if (! entry) 
        {
            break;  // if entry....finished. then break the loop  
        }
        
        d_name = entry->d_name;
        
        /* Print the name of the file and directory.
         * d_name indicates file/folder name...
         * directory_name indicates the path of the file/folder */
	
		
		if (!((strcmp (d_name, "..") == 0) ||
                (strcmp (d_name, ".") == 0))) 
		{
		printf ("%s\t\t\t", directory_name );
		printf ("%s\n", d_name);
		}
        if (entry->d_type & DT_DIR)  /* d_type is a byte at the end of the structure that  indicates  the  file
										type.  It contains some values(defined in <dirent.h>) like.... DT_DIR  means    This is a directory.*/
 
        {

            /* Check that the directory is not "d" or d's parent. */
            
            if (strcmp (d_name, "..") != 0 &&
                strcmp (d_name, ".") != 0) 
                {
                int path_length;
                char path[PATH_MAX];
 
                path_length = snprintf (path, PATH_MAX,
                                        "%s/%s", directory_name, d_name);
                //printf ("%s\n", path);
                if (path_length >= PATH_MAX) 
                {
                    printf ("Path length is beyond range\n");
         
                }
                /* Recursively call "list_directory" with the new path. */
                 
                list_directory (path);
				}
		}
    }
    /* After finishing traversing... close the directory. */
    closedir (d);
}


int main ()
{
    printf ("File/Folder:\t\t");
	printf ("Path:\n" );
	printf("\n\n");
    list_directory ("/");
    return 0;
}


/* directoryListing er habijabi 
 
#include <dirent.h>

 DESCRIPTION

The internal format of directories is unspecified.
The <dirent.h> header defines the following data type through typedef:

DIR
A type representing a directory stream.
It also defines the structure dirent which includes the following members:


ino_t  d_ino       file serial number
char   d_name[]    name of entry

The type ino_t is defined as described in <sys/types.h>.

The character array d_name is of unspecified size, but the number of bytes preceding the terminating null byte will not exceed {NAME_MAX}.

The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


int            closedir(DIR *);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *, struct dirent *, struct dirent **);
void           rewinddir(DIR *);
void           seekdir(DIR *, long int);
long int       telldir(DIR *);
*/

/*The linux_dirent structure is declared as follows:

           struct linux_dirent {
               unsigned long  d_ino;     /* Inode number */
               /*unsigned long  d_off;     /* Offset to next linux_dirent */
               //unsigned short d_reclen;  /* Length of this linux_dirent */
               //char           d_name[];  /* Filename (null-terminated) */
                                 /* length is actually (d_reclen - 2 -
                                    offsetof(struct linux_dirent, d_name)) */
               /*
               char           pad;       // Zero padding byte
               char           d_type;    // File type (only since Linux
                                         // 2.6.4); offset is (d_reclen - 1)
               */

          // }*/
