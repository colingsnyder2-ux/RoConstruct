// from server: 100% by nuck16
// roc 2009-12 004038f0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004038f0
//
// 004038f0  64a100000000         mov eax, dword ptr fs:[0]
// 004038f6  6aff                 push -1
// 004038f8  684e709200           push 0x92704e
// 004038fd  50                   push eax
// 004038fe  b801000000           mov eax, 1
// 00403903  64892500000000       mov dword ptr fs:[0], esp
// 0040390a  84057095b700         test byte ptr [0xb79570], al
// 00403910  752e                 jne 0x403940
// 00403912  09057095b700         or dword ptr [0xb79570], eax
// 00403918  6890a09a00           push 0x9aa090
// 0040391d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00403925  e8b6e92200           call 0x6322e0
// 0040392a  83c404               add esp, 4
// 0040392d  a36c95b700           mov dword ptr [0xb7956c], eax
// 00403932  8b0c24               mov ecx, dword ptr [esp]
// 00403935  64890d00000000       mov dword ptr fs:[0], ecx
// 0040393c  83c40c               add esp, 0xc
// 0040393f  c3                   ret 
// 00403940  8b0c24               mov ecx, dword ptr [esp]
// 00403943  a16c95b700           mov eax, dword ptr [0xb7956c]
// 00403948  64890d00000000       mov dword ptr fs:[0], ecx
// 0040394f  83c40c               add esp, 0xc
// 00403952  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RenderSettings");
    return *name;
}
