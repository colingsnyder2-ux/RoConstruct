// from server: 30% by atomic.potato
struct Inner {
    char pad0[0x38];
    int field38;
};

struct Mid {
    char pad0[8];
    Inner* p8;
    char padC[4];
    int fieldC;
};

struct Outer {
    char pad0[0x1c];
    int field1c;
};

struct S {
    char pad0[8];
    Mid* p8;
    Outer* pC;
    char pad10[0xc];
    int field1c;
    void func();
};

extern "C" void __stdcall sub_6652c0(int*, int*, int*);
extern "C" void __stdcall sub_720d50(int*, int*);
extern "C" void __stdcall sub_41afe0(int*);

void S::func()
{
    int tmp;
    Inner* inner = p8 ? (Inner*)((char*)p8 + 0x1c) : 0;
    int* edx = (int*)0x662040;
    int* ecx;
    if (inner) {
        ecx = (int*)((char*)pC + 0x38);
        ecx = (int*)((char*)ecx + (int)((char*)inner - 0x1c));
    } else {
        ecx = 0;
    }
    sub_6652c0(&tmp, edx, (int*)this);
    sub_720d50(&field1c, &tmp);
    tmp = -1;
    sub_41afe0(&tmp);
}
