// from server: 58% by atomic.potato
struct S {
    char pad0[4];
    char* field4;
    char* field8;
    char padC[4];
    unsigned int field10;
    char pad14[0x14];
    char* field28;
    char* field2c;
    char* field30;
    char pad34[4];
    unsigned int field38;
    void f();
};

extern "C" void __cdecl sub_80a058(void*);

void S::f() {
    unsigned int i = 0;
    unsigned int stride = 8;
    if (field38 > 0) {
        do {
            field30 = (char*)field30 + stride;
            char* eax = field30;
            i++;
            if (eax == field2c) {
                field30 = field28;
            }
        } while (i < field38);
    }
    if (field28 != 0) {
        sub_80a058(field28);
    }
    i = 0;
    if (field10 > 0) {
        do {
            field8 = (char*)field8 + stride;
            char* eax = field8;
            i++;
            if (eax == field4) {
                field8 = *(char**)this;
            }
        } while (i < field10);
    }
    char* esi = *(char**)this;
    if (esi != 0) {
        sub_80a058(esi);
    }
}
