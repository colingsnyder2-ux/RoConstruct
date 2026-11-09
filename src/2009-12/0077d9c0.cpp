// from server: 32% by atomic.potato
struct Inner {
    char pad0[8];
    int f8;
    int fc;
    int f10;
    int f14;
    char pad18[4];
    Inner* f18;
};

struct Outer {
    short f0;
    char pad2[6];
    int f8;
    int fc;
    int f10;
    unsigned short f14[8];
    unsigned char f24;
    char pad25[3];
    int f28;
    int f2c;
    int f30;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" int __cdecl sub_6ecd40(int, int);
extern "C" void __cdecl sub_719ea0(int, int);
extern "C" int __cdecl sub_77b630(int, int, int, int);
extern "C" int __cdecl sub_77d710(int, int);

struct BlockBlockContact {
    char pad0[0x1c];
    char f1c[0x14];
    int f30;
    int f28;
    int recurse(int, int);
};

int BlockBlockContact::recurse(int a, int b) {
    Outer* o = (Outer*)a;
    int esi = o->f8;
    int edi = o->fc;
    int edx = o->f10;
    esi += esi;
    edi += edi;
    edx += edx;
    int ebx = 0;
    while (ebx < 8) {
        unsigned char al = (unsigned char)(1 << ebx);
        if (o->f24 & al) {
            unsigned short cx = o->f14[ebx];
            int eax = ebx & 1;
            eax += esi;
            int esi2 = ebx >> 1;
            esi2 &= 1;
            esi2 += edi;
            int edi2 = ebx >> 2;
            edi2 &= 1;
            edi2 += edx;
            int saved28 = eax;
            int saved2c = esi2;
            int saved30 = edi2;
            int saved14 = cx;
            int base = (int)this + (o->f0 * 3) * 8 + 0x1c;
            int cnt = (*(int*)(base + 0x10) - *(int*)(base + 0xc)) >> 3;
            if (cx >= cnt) {
                _invalid_parameter_noinfo();
            }
            Inner* p = *(Inner**)(*(int*)(base + 0xc) + cx * 8);
            while (p) {
                int v14 = p->f14;
                if (v14 != b && p->f8 == saved28 && p->fc == esi2 && p->f10 == edi2) {
                    if (sub_6ecd40(v14, b) == 0) {
                        int r = sub_77d710(v14, b);
                        sub_719ea0(this->f28, r);
                    }
                }
                p = p->f18;
            }
            if (o->f0 > 1) {
                unsigned short cx2 = o->f14[ebx];
                int r2 = sub_77b630((int)this, o->f0 - 1, cx2, (int)&saved28);
                this->recurse(r2, b);
            }
        }
        ebx++;
    }
    return 0;
}
