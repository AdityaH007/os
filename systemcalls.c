Write a program to open, read and
                             write files using system calls.
#include <stdio.h>
#include <fcntl.h>
                         main()
{
    char buff[100], fn[10];
    int fd, n;
    printf("Enter file name\n");
    scanf("%s", fn);
    fd = open(fn, O_RDONLY);
    n = read(fd, buff, 100);
    n = write(1, buff, n);
    close(fd);
}
2. Using system calls write line of texts in
    a file
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
    main()
{
    char *buff, fn[10];
    int fd, n, i;
    printf("\nEnter file name ");
    scanf("%s", fn);
    printf("\nEnter text ");
    scanf("%s", buff);
    // fgets(buff,100,stdin);
    fd = open(fn, O_CREAT | O_WRONLY);
    n = write(fd, buff, strlen(buff));
    close(fd);
}
3. Write a program to open, read and
                                write files and perform file copy
                                    operation.
#include <stdio.h>
#include <fcntl.h>
                            main()
{
    char buff[1000], fn1[10], fn2[10];
    int fd1, fd2, n;
    printf("Enter source filename\n");
    scanf("%s", fn1);
    printf("Enter destination file name\n");
    scanf("%s", fn2);
    fd1 = open(fn1, O_RDONLY);
    n = read(fd1, buff, 1000);
    fd2 = open(fn2, O_CREAT | O_WRONLY);
    n = write(fd2, buff, n);
    close(fd1);
    close(fd2);
}
4. Write a program to remove a directory.
#include <stdio.h>
#include <fcntl.h>
    main()
{
    char fn[10];
    printf("Enter source filename\n");
    scanf("%s", fn);
    if (remove(fn) == 0)
        printf("File removed\n");
    else
        printf("File cannot be removed\n");
