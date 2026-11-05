// from server: 100% by nuck16
// roc 2009-12 007d8030  unit: RBX::HUMAN::StrafingNoPhysics  size: 99 bytes
//
// 007d8030  64a100000000         mov eax, dword ptr fs:[0]
// 007d8036  6aff                 push -1
// 007d8038  685e719500           push 0x95715e
// 007d803d  50                   push eax
// 007d803e  b801000000           mov eax, 1
// 007d8043  64892500000000       mov dword ptr fs:[0], esp
// 007d804a  8405188fb900         test byte ptr [0xb98f18], al
// 007d8050  752e                 jne 0x7d8080
// 007d8052  0905188fb900         or dword ptr [0xb98f18], eax
// 007d8058  68b8f79e00           push 0x9ef7b8
// 007d805d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d8065  e876a2e5ff           call 0x6322e0
// 007d806a  83c404               add esp, 4
// 007d806d  a3148fb900           mov dword ptr [0xb98f14], eax
// 007d8072  8b0c24               mov ecx, dword ptr [esp]
// 007d8075  64890d00000000       mov dword ptr fs:[0], ecx
// 007d807c  83c40c               add esp, 0xc
// 007d807f  c3                   ret 
// 007d8080  8b0c24               mov ecx, dword ptr [esp]
// 007d8083  a1148fb900           mov eax, dword ptr [0xb98f14]
// 007d8088  64890d00000000       mov dword ptr fs:[0], ecx
// 007d808f  83c40c               add esp, 0xc
// 007d8092  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Flying");
    return *name;
}
