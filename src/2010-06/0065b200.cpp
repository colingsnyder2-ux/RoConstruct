// from server: 23% by atomic.potato
extern "C" int __cdecl sub_795820(const char*, const char*, const char*, const char*, char*);

struct S {
    char pad[0x18];
    unsigned int len;
    char buf[4];
};

int __fastcall f(S* a, int, S* b, bool flag, char* out);
int __fastcall f(S* a, int, S* b, bool flag, char* out) {
    const char* p1;
    const char* p2;
    const char* fmt;
    if (flag)
        fmt = (const char*)0xa208c4;
    else
        fmt = (const char*)0xa132a4;
    if (a->len < 0x10)
        p1 = a->buf;
    else
        p1 = *(const char**)((char*)a + 4);
    if (b->len < 0x10)
        p2 = b->buf;
    else
        p2 = *(const char**)((char*)b + 4);
    sub_795820((const char*)0xa3a280, p2, p1, fmt, out);
    return (int)out;
}
