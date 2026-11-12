// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0049ad70  unit: RBX::Network::VClient::?$SignalDesc  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049ad70
//
// 0049ad70  6aff                 push -1
// 0049ad72  68088d7400           push 0x748d08
// 0049ad77  64a100000000         mov eax, dword ptr fs:[0]
// 0049ad7d  50                   push eax
// 0049ad7e  51                   push ecx
// 0049ad7f  56                   push esi
// 0049ad80  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049ad85  33c4                 xor eax, esp
// 0049ad87  50                   push eax
// 0049ad88  8d44240c             lea eax, [esp + 0xc]
// 0049ad8c  64a300000000         mov dword ptr fs:[0], eax
// 0049ad92  8bf1                 mov esi, ecx
// 0049ad94  89742408             mov dword ptr [esp + 8], esi
// 0049ad98  e833e7ffff           call 0x4994d0
// 0049ad9d  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0049ada5  c706e4c27900         mov dword ptr [esi], 0x79c2e4
// 0049adab  c74604dcc27900       mov dword ptr [esi + 4], 0x79c2dc
// 0049adb2  c74610d4c27900       mov dword ptr [esi + 0x10], 0x79c2d4
// 0049adb9  c74614c4c27900       mov dword ptr [esi + 0x14], 0x79c2c4
// 0049adc0  c7462cb4c27900       mov dword ptr [esi + 0x2c], 0x79c2b4
// 0049adc7  c74644a4c27900       mov dword ptr [esi + 0x44], 0x79c2a4
// 0049adce  c7465c94c27900       mov dword ptr [esi + 0x5c], 0x79c294
// 0049add5  c7467484c27900       mov dword ptr [esi + 0x74], 0x79c284
// 0049addc  c7868c00000074c27900 mov dword ptr [esi + 0x8c], 0x79c274
// 0049ade6  c786e800000044c27900 mov dword ptr [esi + 0xe8], 0x79c244
// 0049adf0  c786ec00000038c27900 mov dword ptr [esi + 0xec], 0x79c238
// 0049adfa  e8b1e3ffff           call 0x4991b0
// 0049adff  89460c               mov dword ptr [esi + 0xc], eax
// 0049ae02  8bc6                 mov eax, esi
// 0049ae04  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049ae08  64890d00000000       mov dword ptr fs:[0], ecx
// 0049ae0f  59                   pop ecx
// 0049ae10  5e                   pop esi

// Base subobject offsets read from the vfptr stores above (0,4,0x10,0x14,0x2c,
// 0x44,0x5c,0x74,0x8c,0xe8,0xec); FactoryProduct ctor is 0x4994d0.
struct P00 { virtual void f00(); };
struct P04 { virtual void f04(); int m08; int m0c; };
struct P10 { virtual void f10(); };
struct P14 { virtual void f14(); int pad[5]; };
struct P2c { virtual void f2c(); int pad[5]; };
struct P44 { virtual void f44(); int pad[5]; };
struct P5c { virtual void f5c(); int pad[5]; };
struct P74 { virtual void f74(); int pad[5]; };
struct P8c { virtual void f8c(); int pad[22]; };
struct Pe8 { virtual void fe8(); };
struct Pec { virtual void fec(); };

struct FactoryProduct : P00, P04, P10, P14, P2c, P44, P5c, P74, P8c, Pe8, Pec {
    FactoryProduct();
    virtual ~FactoryProduct();
};

int sub_4991B0();

struct SignalDesc : FactoryProduct {
    SignalDesc();
};

SignalDesc::SignalDesc()
{
    m0c = sub_4991B0();
}
