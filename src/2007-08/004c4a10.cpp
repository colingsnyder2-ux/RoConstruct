// from server: 100% by colin
extern "C" {
    int (__stdcall *getsockname)(unsigned int s, void* name, int* namelen);
    unsigned short (__stdcall *ntohs)(unsigned short netshort);
}

struct RakPeer {
    unsigned short GetLocalPort(unsigned int s);
};

unsigned short RakPeer::GetLocalPort(unsigned int s)
{
    char buf[16];
    int len = 16;
    if (getsockname(s, buf, &len) != 0)
        return 0;
    return ntohs(*(unsigned short*)(buf + 2));
}
