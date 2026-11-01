// from server: 53% by colin
typedef unsigned short WORD;
typedef unsigned int DWORD;

extern "C" {
    DWORD __stdcall WSAGetLastError();
    WORD __stdcall htons(WORD hostshort);
    int __stdcall sendto(unsigned int s, const char* buf, int len, int flags, const void* to, int tolen);
}

extern "C" void __cdecl __security_check_cookie(DWORD cookie);

struct RakPeer {
    int sendTo(const void* data, int length, DWORD binaryAddress, WORD port, DWORD flags);
};

int RakPeer::sendTo(const void* data, int length, DWORD binaryAddress, WORD port, DWORD flags)
{
    if (binaryAddress == 0xFFFFFFFF)
        return -1;

    WORD netPort = htons(port);

    struct {
        WORD family;
        WORD netPort;
        DWORD address;
        char pad[8];
    } addr;

    addr.family = 2;
    addr.netPort = netPort;
    addr.address = binaryAddress;

    int result;
    do {
        result = sendto((unsigned int)length, (const char*)data, length, 0, &addr, 16);
    } while (result == 0);

    if (result == -1) {
        WSAGetLastError();
        return -1;
    }

    return 0;
}
