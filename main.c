#include "csapp.h"

int main(int argc, char **argv) {

    uint32_t addr = htonl(0x8002c2f2);
    struct in_addr inAddr = {addr};

    char buf[MAXBUF];
    inet_ntop(AF_INET, &inAddr, buf, MAXBUF);
    printf("ntop: %s", buf);

    return 0;
}