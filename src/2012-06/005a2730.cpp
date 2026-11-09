// from server: 72% by atomic.potato
struct Hostent
{
    char *h_name;
    char **h_aliases;
    short h_addrtype;
    short h_length;
    char **h_addr_list;
};

extern "C" Hostent *__stdcall gethostbyname(const char *);
extern "C" char *__stdcall inet_ntoa(unsigned long);

char *f_005a2730(const char *name)
{
    Hostent *h = gethostbyname(name);
    if (h != 0 && h->h_addr_list != 0 && *h->h_addr_list != 0)
        return inet_ntoa((unsigned long)*h->h_addr_list);
    return 0;
}
