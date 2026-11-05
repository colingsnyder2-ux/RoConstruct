// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004898d0  unit: G3D::GWindow  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004898d0
//
// 004898d0  56                   push esi
// 004898d1  8b742408             mov esi, dword ptr [esp + 8]
// 004898d5  85f6                 test esi, esi
// 004898d7  742c                 je 0x489905
// 004898d9  8da42400000000       lea esp, [esp]
// 004898e0  6a00                 push 0
// 004898e2  685ce19200           push 0x92e15c
// 004898e7  687c909200           push 0x92907c
// 004898ec  6a00                 push 0
// 004898ee  56                   push esi
// 004898ef  e8d27e2100           call 0x6a17c6
// 004898f4  83c414               add esp, 0x14
// 004898f7  85c0                 test eax, eax
// 004898f9  750c                 jne 0x489907
// 004898fb  8bb604010000         mov esi, dword ptr [esi + 0x104]
// 00489901  85f6                 test esi, esi
// 00489903  75db                 jne 0x4898e0
// 00489905  33c0                 xor eax, eax
// 00489907  5e                   pop esi
// 00489908  c3                   ret 

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char padding[0x44];
        Instance* parent;
    };

    class ServiceProvider : public Instance {};
}

RBX::ServiceProvider* findServiceProvider(RBX::Instance* instance)
{
    while (instance) {
        RBX::ServiceProvider* provider =
            dynamic_cast<RBX::ServiceProvider*>(instance);
        if (provider)
            return provider;
        instance = instance->parent;
    }
    return 0;
}
