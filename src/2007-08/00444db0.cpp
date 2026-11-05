// from server: 100% by colin
// roc 2007-08 00444db0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444db0
//
// 00444db0  a154858800           mov eax, dword ptr [0x888554]
// 00444db5  c3                   ret 

struct S {
    int f();
};

extern int G1_00888554;

int S::f() {
    return G1_00888554;
}
