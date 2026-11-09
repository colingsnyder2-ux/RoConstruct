// from server: 100% by nuck16
// roc 2009-12 007157c0  unit: RBX::JointInstance  size: 99 bytes
//
// 007157c0  64a100000000         mov eax, dword ptr fs:[0]
// 007157c6  6aff                 push -1
// 007157c8  683ede9400           push 0x94de3e
// 007157cd  50                   push eax
// 007157ce  b801000000           mov eax, 1
// 007157d3  64892500000000       mov dword ptr fs:[0], esp
// 007157da  84053456b900         test byte ptr [0xb95634], al
// 007157e0  752e                 jne 0x715810
// 007157e2  09053456b900         or dword ptr [0xb95634], eax
// 007157e8  68e8e79d00           push 0x9de7e8
// 007157ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007157f5  e8e6caf1ff           call 0x6322e0
// 007157fa  83c404               add esp, 4
// 007157fd  a33056b900           mov dword ptr [0xb95630], eax
// 00715802  8b0c24               mov ecx, dword ptr [esp]
// 00715805  64890d00000000       mov dword ptr fs:[0], ecx
// 0071580c  83c40c               add esp, 0xc
// 0071580f  c3                   ret 
// 00715810  8b0c24               mov ecx, dword ptr [esp]
// 00715813  a13056b900           mov eax, dword ptr [0xb95630]
// 00715818  64890d00000000       mov dword ptr fs:[0], ecx
// 0071581f  83c40c               add esp, 0xc
// 00715822  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("JointInstance");
    return *name;
}
