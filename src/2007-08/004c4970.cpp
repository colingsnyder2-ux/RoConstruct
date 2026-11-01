// from server: 75% by colin
struct RakPeer {
    void DomainNameToIP(const char* domain, char* out);
};

extern "C" {
    int __stdcall gethostname(char* name, int namelen);
    struct hostent {
        char* h_name;
        char** h_aliases;
        short h_addrtype;
        short h_length;
        char** h_addr_list;
    };
    struct hostent* __stdcall gethostbyname(const char* name);
    char* __stdcall inet_ntoa(unsigned int in);
}

void RakPeer::DomainNameToIP(const char* domain, char* out)
{
    char name[80];
    if (gethostname(name, 80) == -1)
        return;
    hostent* he = gethostbyname(name);
    if (he == 0)
        return;
    if (he->h_addr_list == 0)
        return;
    if (he->h_addr_list[0] == 0)
        return;
    int i = 0;
    while (i < 0x28) {
        unsigned int addr = *(unsigned int*)he->h_addr_list[i];
        char* s = inet_ntoa(addr);
        char* d = out;
        char c;
        do {
            c = *s;
            *d = c;
            s++;
            d++;
        } while (c != 0);
        i += 4;
        out += 0x10;
        if (he->h_addr_list[i] == 0)
            break;
    }
}
