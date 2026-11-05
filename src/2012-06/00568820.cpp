// from server: 48% by Intel
struct NetAddress {
    unsigned short port;
    unsigned short getPort();
};

extern "C" unsigned long __stdcall inet_addr(const char* cp);

struct VRegistry {
    int field_18;
    int func(NetAddress* addr);
};

unsigned short NetAddress::getPort() {
    return port;
}

int VRegistry::func(NetAddress* addr) {
    unsigned long ip = inet_addr((const char*)addr);
    unsigned short port = addr->getPort();
    unsigned int esi = ip - 0x61C88647;
    unsigned int eax = port;
    unsigned int ecx = esi;
    unsigned int edx = esi;
    ecx <<= 6;
    edx >>= 2;
    ecx += edx;
    eax = ecx + eax - 0x61C88647;
    eax ^= esi;
    edx = 0;
    unsigned int divisor = field_18;
    unsigned int quotient = eax / divisor;
    unsigned int remainder = eax % divisor;
    return remainder;
}
