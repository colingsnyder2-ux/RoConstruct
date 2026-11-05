// from server: 43% by atomic.potato
extern "C" unsigned int __cdecl strcspn(const char*, const char*);
extern "C" char* __cdecl strncat(char*, const char*, unsigned int);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

extern char DAT_009eab44;
extern char DAT_009eab46;
extern int DAT_009eab48;
extern int DAT_009eab4c;
extern short DAT_009eab50;
extern int DAT_009eab54;
extern char DAT_009afc14;

void __cdecl sub_0079a5a0(char* dst, const char* src, unsigned int n)
{
    char al = *src;
    if (al == '=') {
        unsigned int len = n;
        ++src;
        strncpy(dst, src, len);
        dst[len - 1] = 0;
        return;
    }
    if (al == '@') {
        unsigned int limit = n - 8;
        ++src;
        const char* p = src;
        const char* q = p + 1;
        while (*p) ++p;
        unsigned int slen = (unsigned int)(p - q);
        *dst = 0;
        if (slen > limit) {
            unsigned int over = slen - limit;
            src += over;
            char* d = dst - 1;
            while (d[1]) ++d;
            *(int*)d = DAT_009eab54;
        }
        const char* s = src;
        while (*s) ++s;
        unsigned int clen = (unsigned int)(s - src);
        char* d = dst - 1;
        while (d[1]) ++d;
        strncpy(d, src, clen);
        return;
    }
    unsigned int r = strcspn(src, &DAT_009afc14);
    unsigned int lim = n - 0x11;
    if (r > lim) r = lim;
    *(int*)dst = DAT_009eab48;
    *(int*)(dst + 4) = DAT_009eab4c;
    *(short*)(dst + 8) = DAT_009eab50;
    if (src[r] != 0) {
        strncat(dst, src, r);
        char* d = dst - 1;
        while (d[1]) ++d;
        *(int*)d = DAT_009eab54;
    } else {
        const char* s = src;
        while (*s) ++s;
        unsigned int clen = (unsigned int)(s - src);
        char* d = dst - 1;
        while (d[1]) ++d;
        strncpy(d, src, clen);
    }
    char* d = dst - 1;
    while (d[1]) ++d;
    *(short*)d = *(short*)&DAT_009eab44;
    d[2] = DAT_009eab46;
}
