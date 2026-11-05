// from server: 24% by Intel
struct BoundFuncDesc {
    int func();
};

extern "C" int __cdecl sub_564FF0(int, int, int);
extern "C" int __cdecl sub_533590(int, int, int, int);
extern "C" void __stdcall func_00B22644(int);
extern "C" void __stdcall func_00B2263C(int);

int BoundFuncDesc::func() {
    int v_ebp;
    int v_ebx = 0;
    int v_edi = sub_564FF0(0, (int)this + 0x3C, *(int*)(*(int*)((char*)this + 0x40)));
    sub_533590(0, (int)this + 0x38, *(int*)(*(int*)((char*)this + 0x40)), (int)&v_ebp);
    v_edi = *(int*)((char*)this + 0x30);
    int v_esi = *(int*)((char*)this + 0x34);
    int v_esp_10;
    func_00B22644(v_ebp);
    ((void(__cdecl*)(int))v_edi)(v_ebx + v_esi);
    func_00B2263C(v_esp_10);
    return 0;
}
