// from server: 100% by colin
// roc 2008-06 004d7590  unit: Ogre::VDataStream::?$SharedPtr  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d7590
//
// 004d7590  68702a5000           push 0x502a70
// 004d7595  6a01                 push 1
// 004d7597  6a04                 push 4
// 004d7599  51                   push ecx
// 004d759a  e8bca01c00           call 0x6a165b
// 004d759f  c3                   ret 

extern "C" void __stdcall G1_func_006a165b(void*, int, int, void*);
extern "C" void func_00502a70();

struct S {
    void f();
};

void S::f()
{
    G1_func_006a165b(this, 4, 1, (void*)func_00502a70);
}
