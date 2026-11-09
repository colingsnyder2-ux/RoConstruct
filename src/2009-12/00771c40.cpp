// from server: 100% by nuck16
// roc 2009-12 00771c40  unit: RBX::VGuiButton::?$EventReplicator  size: 99 bytes
//
// 00771c40  64a100000000         mov eax, dword ptr fs:[0]
// 00771c46  6aff                 push -1
// 00771c48  682e2c9500           push 0x952c2e
// 00771c4d  50                   push eax
// 00771c4e  b801000000           mov eax, 1
// 00771c53  64892500000000       mov dword ptr fs:[0], esp
// 00771c5a  84054882b900         test byte ptr [0xb98248], al
// 00771c60  752e                 jne 0x771c90
// 00771c62  09054882b900         or dword ptr [0xb98248], eax
// 00771c68  68bcfdb500           push 0xb5fdbc
// 00771c6d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00771c75  e86606ecff           call 0x6322e0
// 00771c7a  83c404               add esp, 4
// 00771c7d  a34482b900           mov dword ptr [0xb98244], eax
// 00771c82  8b0c24               mov ecx, dword ptr [esp]
// 00771c85  64890d00000000       mov dword ptr fs:[0], ecx
// 00771c8c  83c40c               add esp, 0xc
// 00771c8f  c3                   ret 
// 00771c90  8b0c24               mov ecx, dword ptr [esp]
// 00771c93  a14482b900           mov eax, dword ptr [0xb98244]
// 00771c98  64890d00000000       mov dword ptr fs:[0], ecx
// 00771c9f  83c40c               add esp, 0xc
// 00771ca2  c3                   ret 

extern char string_00b5fdbc[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5fdbc);
    return *name;
}
