// from server: 100% by nuck16
// roc 2009-12 00741bf0  unit: RBX::DebrisService  size: 99 bytes
//
// 00741bf0  64a100000000         mov eax, dword ptr fs:[0]
// 00741bf6  6aff                 push -1
// 00741bf8  68ce029500           push 0x9502ce
// 00741bfd  50                   push eax
// 00741bfe  b801000000           mov eax, 1
// 00741c03  64892500000000       mov dword ptr fs:[0], esp
// 00741c0a  8405d06cb900         test byte ptr [0xb96cd0], al
// 00741c10  752e                 jne 0x741c40
// 00741c12  0905d06cb900         or dword ptr [0xb96cd0], eax
// 00741c18  68e0299e00           push 0x9e29e0
// 00741c1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00741c25  e8b606efff           call 0x6322e0
// 00741c2a  83c404               add esp, 4
// 00741c2d  a3cc6cb900           mov dword ptr [0xb96ccc], eax
// 00741c32  8b0c24               mov ecx, dword ptr [esp]
// 00741c35  64890d00000000       mov dword ptr fs:[0], ecx
// 00741c3c  83c40c               add esp, 0xc
// 00741c3f  c3                   ret 
// 00741c40  8b0c24               mov ecx, dword ptr [esp]
// 00741c43  a1cc6cb900           mov eax, dword ptr [0xb96ccc]
// 00741c48  64890d00000000       mov dword ptr fs:[0], ecx
// 00741c4f  83c40c               add esp, 0xc
// 00741c52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Feature");
    return *name;
}
