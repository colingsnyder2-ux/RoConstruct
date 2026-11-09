// from server: 37% by atomic.potato
struct S {
    char pad0[0x14];
    void* field14;
    char pad18[0x20];
    int field38;
    int field3c;
    int field40;
    char pad44[0x100];
    int init(int, int, int, int, int, int);
};

extern "C" int __cdecl sub_651670(int, int);
extern "C" int __cdecl sub_702890(int);
extern "C" int __cdecl sub_6aa720(int);
extern "C" int __cdecl sub_642f50();
extern "C" int __cdecl sub_643260();
extern "C" int __cdecl sub_6322e0(int, int, int);
extern "C" int __cdecl sub_6aa7a0(int, int);

extern int dword_B8FD4C;
extern int dword_B90118;

int S::init(int a, int b, int c, int d, int e, int f)
{
    int r = sub_651670(a, b);
    sub_702890(r);
    field38 = c;
    field3c = d;
    field40 = e;
    *(int*)((char*)this + 0) = 0x9d2688;
    sub_6aa720((int)((char*)this + 0x44));
    dword_B8FD4C++;
    field14 = (void*)sub_642f50();
    dword_B90118++;
    int t = sub_643260();
    int u = sub_6322e0(f, t, (int)((char*)this + 0x44));
    sub_6aa7a0((int)((char*)this + 0x14), u);
    return (int)this;
}
