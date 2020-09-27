### 第三部分 程序间的交流和通信

---
#### 第10章 系统级I/O
##### 10.3 打开和关闭文件 
```c
#include <stdio.h>
#include <sys/fcntl.h>
#include "csapp.h"

int main() {
    int u = umask(DEF_UMASK);
    int fd = Open("foo.txt", O_CREAT | O_TRUNC | O_RDWR, DEF_MODE);
    printf("fd = %d\n", fd);
    Close(fd);
    return 0;
}
```
###### 习题10.1
```c
#include <stdio.h>
#include <sys/fcntl.h>
#include "csapp.h"

int main() {
    int fd1 = Open("foo.txt", O_RDONLY, 0);
    printf("fd1 = %d\n", fd1);
    Close(fd1);

    int fd2 = Open("baz.txt", O_RDONLY, 0);
    printf("fd2 = %d\n", fd2);
    return 0;
}
```

##### 10.4 读和写文件
> 补充测试 Read/Write
```c
#include "csapp.h"

int main() {
    // count 大小不能大于 buf数组大小, 防止溢出
    int count = 3;
    char buf[count];
    memset(buf, 0, count);

    ssize_t sr, rw;
    // 输入的字符 遇到 '\n'(回车输入的就是这个) 后开始read, 字符数量小于count,
    // read一次, 大于count, 则需要多次read, 直到read完
    while ((sr = Read(STDIN_FILENO, &buf, count))) {
        printf("input char: %s, size: %zd\n", buf, sr);
        // 输出的时候, 按实际输入字符数量进行输出
        rw = Write(STDOUT_FILENO, &buf, sr);
        printf("\n");
        printf("output char size: %zd\n", rw);
    }
    exit(0);
}
```

##### 10.8 共享文件 
###### 习题10.2
```c
#include <stdio.h>
#include <sys/fcntl.h>
#include "csapp.h"

int main() {
    char c;
    int fd1 = Open("foobar.txt", O_RDONLY, 0);
    int fd2 = Open("./foobar.txt", O_RDONLY, 0);

    Read(fd1, &c, 1);
    Read(fd2, &c, 1);

    printf("c = %c\n", c);
    return 0;
}
```
###### 习题10.3
```c
#include <stdio.h>
#include <sys/fcntl.h>
#include "csapp.h"

int main() {
    char c;
    int fd = Open("foo.txt", O_RDONLY, 0);
    printf("pid = %d\n", getpid());

    pid_t i = Fork();
    printf("pid = %d, process start...\n", getpid());

    // 子进程
    if (i == 0) {
        Read(fd, &c, 1);
        printf("pid = %d, c = %c\n", getpid(), c);
        exit(0);
    }
    printf("pid = %d, fork pid = %d\n", getpid(), i);

    Wait(NULL);
    Read(fd, &c, 1);
    printf("pid = %d, c = %c\n", getpid(), c);
    exit(0);
}
```
###### 习题10.4
```c
#include "csapp.h"

int main(void) {
    char c;
    int fd = Open("foo.txt", O_RDONLY, 0);
    Dup2(fd, STDIN_FILENO);

    while (Read(STDIN_FILENO, &c, 1) != 0)
        Write(STDOUT_FILENO, &c, 1);
    exit(0);
}
```
###### 习题10.5
```c
#include "csapp.h"

int main() {
    char c;
    int fd1 = Open("foobar.txt", O_RDONLY, 0);
    int fd2 = Open("foobar.txt", O_RDONLY, 0);

    Read(fd2, &c, 1);
    Dup2(fd2, fd1);
    Read(fd1, &c, 1);

    printf("c = %c\n", c);
    return 0;
}
```