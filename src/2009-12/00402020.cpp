// from server: 100% by nuck16
// roc 2009-12 00402020  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 99 bytes
//
// 00402020  64a100000000         mov eax, dword ptr fs:[0]
// 00402026  6aff                 push -1
// 00402028  680e709200           push 0x92700e
// 0040202d  50                   push eax
// 0040202e  b801000000           mov eax, 1
// 00402033  64892500000000       mov dword ptr fs:[0], esp
// 0040203a  84052095b700         test byte ptr [0xb79520], al
// 00402040  752e                 jne 0x402070
// 00402042  09052095b700         or dword ptr [0xb79520], eax
// 00402048  6800c29c00           push 0x9cc200
// 0040204d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00402055  e886022300           call 0x6322e0
// 0040205a  83c404               add esp, 4
// 0040205d  a31c95b700           mov dword ptr [0xb7951c], eax
// 00402062  8b0c24               mov ecx, dword ptr [esp]
// 00402065  64890d00000000       mov dword ptr fs:[0], ecx
// 0040206c  83c40c               add esp, 0xc
// 0040206f  c3                   ret 
// 00402070  8b0c24               mov ecx, dword ptr [esp]
// 00402073  a11c95b700           mov eax, dword ptr [0xb7951c]
// 00402078  64890d00000000       mov dword ptr fs:[0], ecx
// 0040207f  83c40c               add esp, 0xc
// 00402082  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RunService");
    return *name;
}
