// from server: 100% by nuck16
// roc 2009-12 004c00e0  unit: RBX::RbxParticleEmitter  size: 99 bytes
//
// 004c00e0  64a100000000         mov eax, dword ptr fs:[0]
// 004c00e6  6aff                 push -1
// 004c00e8  687e249300           push 0x93247e
// 004c00ed  50                   push eax
// 004c00ee  b801000000           mov eax, 1
// 004c00f3  64892500000000       mov dword ptr fs:[0], esp
// 004c00fa  840564cfb700         test byte ptr [0xb7cf64], al
// 004c0100  752e                 jne 0x4c0130
// 004c0102  090564cfb700         or dword ptr [0xb7cf64], eax
// 004c0108  687846b400           push 0xb44678
// 004c010d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004c0115  e8c6211700           call 0x6322e0
// 004c011a  83c404               add esp, 4
// 004c011d  a360cfb700           mov dword ptr [0xb7cf60], eax
// 004c0122  8b0c24               mov ecx, dword ptr [esp]
// 004c0125  64890d00000000       mov dword ptr fs:[0], ecx
// 004c012c  83c40c               add esp, 0xc
// 004c012f  c3                   ret 
// 004c0130  8b0c24               mov ecx, dword ptr [esp]
// 004c0133  a160cfb700           mov eax, dword ptr [0xb7cf60]
// 004c0138  64890d00000000       mov dword ptr fs:[0], ecx
// 004c013f  83c40c               add esp, 0xc
// 004c0142  c3                   ret 

extern char string_00b44678[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b44678);
    return *name;
}
