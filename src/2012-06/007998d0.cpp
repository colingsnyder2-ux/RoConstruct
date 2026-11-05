// from server: 45% by Intel
extern "C" void __stdcall sub_797950(int, int, int, int);
extern "C" void* __stdcall sub_98211a(int);
extern "C" int __stdcall sub_783bf0();
extern "C" void __stdcall sub_796130(int);
extern "C" void __stdcall sub_794e50(int, int);

struct VHumanoidBoundFuncDesc {
    int f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
};

int VHumanoidBoundFuncDesc::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    sub_797950(a9, a8, a2, a1);
    *(int*)((char*)this + 0x30) = a5;
    *(int*)((char*)this + 0x34) = a6;
    *(int*)((char*)this + 0x38) = a7;
    void* v = sub_98211a(4);
    *(int*)this = 0xBB3E00;
    int* p = 0;
    if (v) {
        *(int*)v = a4;
        p = (int*)v;
    }
    *(int*)((char*)this + 0x3C) = (int)p;
    int v2 = sub_783bf0();
    int v3;
    sub_796130((int)&v3);
    *(int*)((char*)&v3) = v2;
    sub_794e50((int)this, v3);
    return (int)this;
}
