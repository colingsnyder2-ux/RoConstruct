// from server: 45% by atomic.potato
extern "C" char* __stdcall inet_ntoa(unsigned int in);

struct IdSerializer {
    unsigned int field0;
    unsigned short field4;
    void copyTo(char* dest, char flag);
};

void IdSerializer::copyTo(char* dest, char flag) {
    if (field0 == *(unsigned int*)0xb1f644 && field4 == *(unsigned short*)0xb1f648) {
        char* src = (char*)0x9be3bc;
        for (int i = 0; i < 26; i++) dest[i] = src[i];
        return;
    }
    char* s = inet_ntoa(field0);
    char* d = dest;
    do { *d++ = *s; } while (*s++);
    if (flag != 0) {
        char* p = dest - 1;
        while (*++p) {}
        *(unsigned short*)p = *(unsigned short*)0x9b4034;
        char* q = dest;
        char* r = dest + 1;
        while (*q++) {}
        int len = (int)(q - r) + (int)dest;
        extern int __cdecl sub_564cd0(int, char*, int);
        sub_564cd0(field4, dest, 10);
    }
}
