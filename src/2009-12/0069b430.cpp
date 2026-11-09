// from server: 32% by atomic.potato
extern "C" {
    int __stdcall sub_651670(int, int);
    int __stdcall sub_6322e0(int, int, int);
    int __stdcall sub_642f50();
    int __stdcall sub_6aa690();
    int __stdcall sub_6aa720();
    int __stdcall sub_6aa7a0(int);
    int __stdcall sub_702890(int);
}

struct VWorkspace {
    char pad0[0x14];
    int field14;
    char pad18[0x20];
    int field38;
    int field3c;
    int field40;
    char field44[4];
    int ctor(int, int, int, int, int, int);
};

int VWorkspace::ctor(int a1, int a2, int a3, int a4, int a5, int a6) {
    int tmp;
    tmp = sub_651670(a1, a2);
    sub_702890(tmp);
    field38 = a3;
    field3c = a4;
    field40 = a5;
    *(int*)field44 = 0;
    *(int*)this = 0x9d2694;
    sub_6aa720();
    ++*(int*)0xb8fd60;
    field14 = sub_6aa690();
    ++*(int*)0xb8fd4c;
    tmp = sub_642f50();
    tmp = sub_6322e0(a6, tmp, (int)field44);
    sub_6aa7a0(tmp);
    return (int)this;
}
