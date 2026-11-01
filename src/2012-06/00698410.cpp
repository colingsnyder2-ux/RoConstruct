// from server: 28% by Intel
struct EnumDesc {
    void* vftable;
    char pad[0xAC];

    int Init(int a2, int a3, int a4);
};

extern "C" int __stdcall sub_6974A0(int, int);
extern "C" int __stdcall sub_75FAE0(int, int, int);
extern "C" void __stdcall sub_46C000(int, int);
extern "C" void __stdcall sub_75F9C0(int, int);
extern "C" void __stdcall sub_596B70(int, int);

int EnumDesc::Init(int a2, int a3, int a4) {
    int v5 = 0;
    int v6 = sub_6974A0(a2, a4);
    int v7 = sub_75FAE0(*(int*)this + 0xC0, 0xB838F0, 1);
    sub_75FAE0(*(int*)this + 0xC4, 0xB93710, v7);
    sub_75FAE0(*(int*)this + 0xC8, 0xB93708, v7);
    sub_75FAE0(*(int*)this + 0xCC, 0xB936FC, v7);
    sub_75FAE0(*(int*)this + 0xD0, 0xB936F4, v7);
    sub_46C000(*(int*)this + 0xBC, 0xB936E4);
    sub_75F9C0(*(int*)this + 0xAC, 0xB936DC);
    sub_75F9C0(*(int*)this + 0xB0, 0xB936D8);
    sub_596B70(*(int*)this + 0xB4, 0xB936CC);
    sub_596B70(*(int*)this + 0xB8, 0xB936C0);
    return a4;
}
