// from server: 13% by atomic.potato
extern "C" {
    int __cdecl sub_64F840(int, int);
    int __cdecl sub_6432D0();
    int __cdecl sub_6322E0(int, int, int);
    void __cdecl sub_6AA720();
    void __cdecl sub_6AA690();
    void __cdecl sub_6AA7A0();
    void __cdecl sub_702890();
    extern int dword_B8FD60;
    extern int dword_B8FDA0;
}

struct S {
    char pad0[0x14];
    int field14;
    char pad18[0x20];
    int field38;
    int field3C;
    int field40;
    int method(int, int, int, int, int);
};

int S::method(int a1, int a2, int a3, int a4, int a5)
{
    int v = sub_64F840(a1, a2);
    sub_702890();
    field38 = a3;
    field3C = a4;
    sub_6AA720();
    dword_B8FD60++;
    sub_6AA690();
    field14 = 0;
    dword_B8FDA0++;
    int r = sub_6432D0();
    int r2 = sub_6322E0(a5, r, (int)&field40);
    sub_6AA7A0();
    return (int)this;
}
