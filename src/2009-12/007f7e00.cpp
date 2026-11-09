// roc 2009-12 007f7e00  unit: IIHH::?$CMap  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f7e00
//
// 007f7e00  53                   push ebx
// 007f7e01  56                   push esi
// 007f7e02  8bd9                 mov ebx, ecx
// 007f7e04  33f6                 xor esi, esi
// 007f7e06  e8755e0500           call 0x84dc80
// 007f7e0b  85c0                 test eax, eax
// 007f7e0d  7e26                 jle 0x7f7e35
// 007f7e0f  57                   push edi
// 007f7e10  56                   push esi
// 007f7e11  8bcb                 mov ecx, ebx
// 007f7e13  e818b10a00           call 0x8a2f30
// 007f7e18  8bf8                 mov edi, eax
// 007f7e1a  8bcf                 mov ecx, edi
// 007f7e1c  e8bffeffff           call 0x7f7ce0
// 007f7e21  8bcf                 mov ecx, edi
// 007f7e23  e8b4bfffff           call 0x7f3ddc
// 007f7e28  8bcb                 mov ecx, ebx
// 007f7e2a  46                   inc esi
// 007f7e2b  e8505e0500           call 0x84dc80
// 007f7e30  3bf0                 cmp esi, eax
// 007f7e32  7cdc                 jl 0x7f7e10
// 007f7e34  5f                   pop edi
// 007f7e35  6aff                 push -1
// 007f7e37  6a00                 push 0
// 007f7e39  8d4b20               lea ecx, [ebx + 0x20]
// 007f7e3c  e85fd50500           call 0x8553a0
// 007f7e41  5e                   pop esi
// 007f7e42  5b                   pop ebx
// 007f7e43  c3                   ret 
// copied from an identical function in another client (function ?RemoveAll@Outer@ns_ROCX000000@ns_ROCX000007@@QAEXXZ)

namespace ns_ROCX000000 {
namespace ns_ROCX00000a {
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
}
