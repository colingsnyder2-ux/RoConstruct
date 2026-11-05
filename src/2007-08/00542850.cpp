// from server: 100% by colin
// roc 2007-08 00542850  unit: RBX::VInstance::?$SignalDesc  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00542850
//
// 00542850  a1a0df8900           mov eax, dword ptr [0x89dfa0]
// 00542855  c3                   ret 

extern int G_0089dfa0;

struct S {
    int f();
};

int S::f() {
    return G_0089dfa0;
}
