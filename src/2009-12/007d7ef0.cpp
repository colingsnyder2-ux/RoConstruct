// from server: 100% by nuck16
// roc 2009-12 007d7ef0  unit: RBX::HUMAN::StrafingNoPhysics  size: 99 bytes
//
// 007d7ef0  64a100000000         mov eax, dword ptr fs:[0]
// 007d7ef6  6aff                 push -1
// 007d7ef8  681e719500           push 0x95711e
// 007d7efd  50                   push eax
// 007d7efe  b801000000           mov eax, 1
// 007d7f03  64892500000000       mov dword ptr fs:[0], esp
// 007d7f0a  8405008fb900         test byte ptr [0xb98f00], al
// 007d7f10  752e                 jne 0x7d7f40
// 007d7f12  0905008fb900         or dword ptr [0xb98f00], eax
// 007d7f18  6860f79e00           push 0x9ef760
// 007d7f1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d7f25  e8b6a3e5ff           call 0x6322e0
// 007d7f2a  83c404               add esp, 4
// 007d7f2d  a3fc8eb900           mov dword ptr [0xb98efc], eax
// 007d7f32  8b0c24               mov ecx, dword ptr [esp]
// 007d7f35  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7f3c  83c40c               add esp, 0xc
// 007d7f3f  c3                   ret 
// 007d7f40  8b0c24               mov ecx, dword ptr [esp]
// 007d7f43  a1fc8eb900           mov eax, dword ptr [0xb98efc]
// 007d7f48  64890d00000000       mov dword ptr fs:[0], ecx
// 007d7f4f  83c40c               add esp, 0xc
// 007d7f52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RunningNoPhysics");
    return *name;
}
