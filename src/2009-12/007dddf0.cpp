// from server: 100% by nuck16
// roc 2009-12 007dddf0  unit: RBX::HUMAN::GettingUp  size: 99 bytes
//
// 007dddf0  64a100000000         mov eax, dword ptr fs:[0]
// 007dddf6  6aff                 push -1
// 007dddf8  68ee739500           push 0x9573ee
// 007dddfd  50                   push eax
// 007dddfe  b801000000           mov eax, 1
// 007dde03  64892500000000       mov dword ptr fs:[0], esp
// 007dde0a  84054090b900         test byte ptr [0xb99040], al
// 007dde10  752e                 jne 0x7dde40
// 007dde12  09054090b900         or dword ptr [0xb99040], eax
// 007dde18  68b8fb9e00           push 0x9efbb8
// 007dde1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007dde25  e8b644e5ff           call 0x6322e0
// 007dde2a  83c404               add esp, 4
// 007dde2d  a33c90b900           mov dword ptr [0xb9903c], eax
// 007dde32  8b0c24               mov ecx, dword ptr [esp]
// 007dde35  64890d00000000       mov dword ptr fs:[0], ecx
// 007dde3c  83c40c               add esp, 0xc
// 007dde3f  c3                   ret 
// 007dde40  8b0c24               mov ecx, dword ptr [esp]
// 007dde43  a13c90b900           mov eax, dword ptr [0xb9903c]
// 007dde48  64890d00000000       mov dword ptr fs:[0], ecx
// 007dde4f  83c40c               add esp, 0xc
// 007dde52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("MovingNoPhysicsBase");
    return *name;
}
