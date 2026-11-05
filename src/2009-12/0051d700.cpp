// from server: 39% by atomic.potato
struct C1 { char pad[0x40]; };
struct C2 { char pad[0x40]; };

extern "C" int __cdecl f_51a420(int, int);
extern "C" int __cdecl f_702890();
extern "C" int __cdecl f_523d20();
extern "C" void* __cdecl f_7f3860(int);
extern "C" int __cdecl f_6aa690();
extern "C" int __cdecl f_6322e0(int, int, int);
extern "C" int __cdecl f_6aa7a0();

extern int d_b7fcb0;
extern int d_b8fd60;

struct S {
    char pad0[0x14];
    int field14;
    char pad18[0x20];
    int field38;
    int field3c;
    int field40;
    int field44;
    int f(int, int, int, int, int, int);
};

int S::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int r;
    r = f_51a420(a1, a2);
    f_702890();
    *(int*)this = 0x9bb5e4;
    field38 = a3;
    field3c = a4;
    d_b7fcb0++;
    field40 = f_523d20();
    void* p = f_7f3860(8);
    if (p) {
        *(int*)p = 0x9bb37c;
        *(int*)((char*)p + 4) = a5;
    } else {
        p = 0;
    }
    field44 = (int)p;
    d_b8fd60++;
    field14 = f_6aa690();
    d_b7fcb0++;
    int t = f_523d20();
    int u = f_6322e0(a6, t, (int)&field40);
    f_6aa7a0();
    return (int)this;
}
