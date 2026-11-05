// from server: 65% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void __stdcall func2(int, unsigned char, unsigned int, unsigned int);

struct NodeVisiter {
    char pad0[0xc];
    unsigned int field_c;
    unsigned int field_10;
    char pad14[4];
    unsigned char field_18;
    void func();
};

void NodeVisiter::func() {
    unsigned int ebp = field_10;
    if (field_c > ebp)
        _invalid_parameter_noinfo();
    unsigned int ebx = field_c;
    unsigned int edi = *(unsigned int*)this;
    if (ebx > field_10)
        _invalid_parameter_noinfo();
    unsigned char cl = field_18;
    unsigned int eax = *(unsigned int*)this;
    unsigned char tmp = cl;
    if (edi != 0 && edi == eax) {
    } else {
        _invalid_parameter_noinfo();
    }
    unsigned int edx = ebp - ebx;
    edx &= 0xfffffff0;
    if ((int)edx > 0x10) {
        unsigned int t = tmp;
        func2(0, t, ebp, ebx);
    }
    unsigned int eax2 = field_10;
    unsigned int ecx2 = eax2 - field_c;
    if ((ecx2 & 0xfffffff0) != 0) {
        eax2 -= 0x10;
        field_10 = eax2;
    }
}
