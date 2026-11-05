// from server: 38% by atomic.potato
struct S {
    char pad0[0x24];
    unsigned char* field_0x24;
    char pad1[0xc];
    int* field_0x34;
    char pad2[0x8];
    char field_0x40[0x4c];
    unsigned int field_0x8c;
    char pad3[0xc];
    unsigned int field_0x9c;
    int put(unsigned char c);
    int sub_617180();
};

extern "C" int __stdcall sub_615c40(char* a, unsigned char* b, unsigned int c);


int S::put(unsigned char c) {
    if (((field_0x9c >> 1) & 1) && *field_0x24 == 0) {
        (*(void (__thiscall**)(S*))(*(int*)this + 0x58))(this);
    }
    if (c == 0xff) {
        return 0;
    }
    if ((field_0x9c >> 1) & 1) {
        unsigned char* p = field_0x24;
        int* q = field_0x34;
        int end = *q + *p;
        if (*p == end) {
            sub_617180();
            p = field_0x24;
            q = field_0x34;
            end = *q + *p;
            if (*p == end) {
                return -1;
            }
        }
        *p = c;
        --*q;
        ++*field_0x24;
        return c;
    } else {
        unsigned char tmp = c;
        if (sub_615c40(field_0x40, &tmp, field_0x8c) != 1) {
            return -1;
        }
        return c;
    }
}
