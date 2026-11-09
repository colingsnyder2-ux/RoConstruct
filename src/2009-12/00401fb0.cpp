// from server: 100% by nuck16
// roc 2009-12 00401fb0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 99 bytes
//
// 00401fb0  64a100000000         mov eax, dword ptr fs:[0]
// 00401fb6  6aff                 push -1
// 00401fb8  68ee6f9200           push 0x926fee
// 00401fbd  50                   push eax
// 00401fbe  b801000000           mov eax, 1
// 00401fc3  64892500000000       mov dword ptr fs:[0], esp
// 00401fca  84051895b700         test byte ptr [0xb79518], al
// 00401fd0  752e                 jne 0x402000
// 00401fd2  09051895b700         or dword ptr [0xb79518], eax
// 00401fd8  68d0c09c00           push 0x9cc0d0
// 00401fdd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00401fe5  e8f6022300           call 0x6322e0
// 00401fea  83c404               add esp, 4
// 00401fed  a31495b700           mov dword ptr [0xb79514], eax
// 00401ff2  8b0c24               mov ecx, dword ptr [esp]
// 00401ff5  64890d00000000       mov dword ptr fs:[0], ecx
// 00401ffc  83c40c               add esp, 0xc
// 00401fff  c3                   ret 
// 00402000  8b0c24               mov ecx, dword ptr [esp]
// 00402003  a11495b700           mov eax, dword ptr [0xb79514]
// 00402008  64890d00000000       mov dword ptr fs:[0], ecx
// 0040200f  83c40c               add esp, 0xc
// 00402012  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Selection");
    return *name;
}
