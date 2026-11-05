// from server: 100% by nuck16
// roc 2009-12 00484c60  unit: Ogre::RbxSceneManagerFactory  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00484c60
//
// 00484c60  c7413cfeffffff       mov dword ptr [ecx + 0x3c], 0xfffffffe
// 00484c67  e9d4d10600           jmp 0x4f1e40

extern "C" void func_4f1e40();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x3c) = 0xfffffffe;
    func_4f1e40();
}
