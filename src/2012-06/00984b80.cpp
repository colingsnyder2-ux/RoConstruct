// roc 2012-06 00984b80  unit: CRobloxControlColorSelector  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984b80
//
// 00984b80  8b542408             mov edx, dword ptr [esp + 8]
// 00984b84  8b01                 mov eax, dword ptr [ecx]
// 00984b86  8b80e8000000         mov eax, dword ptr [eax + 0xe8]
// 00984b8c  52                   push edx
// 00984b8d  8b542408             mov edx, dword ptr [esp + 8]
// 00984b91  52                   push edx
// 00984b92  6a00                 push 0
// 00984b94  ffd0                 call eax
// 00984b96  b801000000           mov eax, 1
// 00984b9b  c20800               ret 8
// copied from an identical function in another client (function ?method@CRobloxControlColorSelector@ns_ROCX000032@@QAEHHH@Z)

namespace ns_ROCX000032 {
struct CRobloxControlColorSelector {
    virtual void vfunc_000();
    virtual void vfunc_004();
    virtual void vfunc_008();
    virtual void vfunc_00c();
    virtual void vfunc_010();
    virtual void vfunc_014();
    virtual void vfunc_018();
    virtual void vfunc_01c();
    virtual void vfunc_020();
    virtual void vfunc_024();
    virtual void vfunc_028();
    virtual void vfunc_02c();
    virtual void vfunc_030();
    virtual void vfunc_034();
    virtual void vfunc_038();
    virtual void vfunc_03c();
    virtual void vfunc_040();
    virtual void vfunc_044();
    virtual void vfunc_048();
    virtual void vfunc_04c();
    virtual void vfunc_050();
    virtual void vfunc_054();
    virtual void vfunc_058();
    virtual void vfunc_05c();
    virtual void vfunc_060();
    virtual void vfunc_064();
    virtual void vfunc_068();
    virtual void vfunc_06c();
    virtual void vfunc_070();
    virtual void vfunc_074();
    virtual void vfunc_078();
    virtual void vfunc_07c();
    virtual void vfunc_080();
    virtual void vfunc_084();
    virtual void vfunc_088();
    virtual void vfunc_08c();
    virtual void vfunc_090();
    virtual void vfunc_094();
    virtual void vfunc_098();
    virtual void vfunc_09c();
    virtual void vfunc_0a0();
    virtual void vfunc_0a4();
    virtual void vfunc_0a8();
    virtual void vfunc_0ac();
    virtual void vfunc_0b0();
    virtual void vfunc_0b4();
    virtual void vfunc_0b8();
    virtual void vfunc_0bc();
    virtual void vfunc_0c0();
    virtual void vfunc_0c4();
    virtual void vfunc_0c8();
    virtual void vfunc_0cc();
    virtual void vfunc_0d0();
    virtual void vfunc_0d4();
    virtual void vfunc_0d8();
    virtual void vfunc_0dc();
    virtual void vfunc_0e0();
    virtual void vfunc_0e4();
    virtual void vfunc_0e8(int, int, int);
    int method(int a, int b);
};

int CRobloxControlColorSelector::method(int a, int b)
{
    vfunc_0e8(0, a, b);
    return 1;
}
}
