// from server: 100% by colin
struct S {
    char pad0[0x18];
    int f18;
    int f1c;
    char pad20[0x70];
    int f90;
    int f94;
    char pad98[0x8];
    int fa0;
    char pada4[0x8];
    int fac;
    char padb0[0x10];
    int fc0;
    void tail();
    void init();
};

void S::init()
{
    int* p = *(int**)((char*)this + 0x94);
    *(int*)((char*)this + 0x00) = 0xaafe2c;
    *(int*)((char*)this + 0x04) = 0xaafe24;
    *(int*)((char*)this + 0x18) = 0xaafe18;
    *(int*)((char*)this + 0x1c) = 0xaafe0c;
    *(int*)((char*)this + 0x90) = 0xaafe04;
    *(int*)((char*)this + 0xa0) = 0xaafdf0;
    *(int*)((char*)this + 0xac) = 0xaafdc8;
    *(int*)((char*)this + 0xc0) = 0xaafda0;
    int edx = p[1];
    *(int*)((char*)this + edx + 0x94) = 0xaafd98;
    int* q = *(int**)((char*)this + 0x94);
    int eax = q[1];
    int edx2 = eax - 0x200;
    *(int*)((char*)this + eax + 0x90) = edx2;
    tail();
}
