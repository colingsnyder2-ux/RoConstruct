// from server: 100% by Xemicl
// roc 2012-06 004dfeb0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004dfeb0
//
// 004dfeb0  833901               cmp dword ptr [ecx], 1
// 004dfeb3  7506                 jne 0x4dfebb
// 004dfeb5  c70100000000         mov dword ptr [ecx], 0
// 004dfebb  83c104               add ecx, 4
// 004dfebe  e91d24ffff           jmp 0x4d22e0
// copied from an identical function in another client (function ?method@S@ns_ROCX000006@@QAEXXZ)

namespace ns_ROCX000006 {
struct S {
    int field0;
    void method();
};

void S::method() {
    if (field0 == 1) {
        field0 = 0;
    }
    int* p = &field0 + 1;
    extern void __fastcall helper(int*);
    helper(p);
}
}
