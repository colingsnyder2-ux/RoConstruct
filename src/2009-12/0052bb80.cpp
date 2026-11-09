// from server: 100% by nuck16
// roc 2009-12 0052bb80  unit: RBX::Network::Server  size: 99 bytes
//
// 0052bb80  64a100000000         mov eax, dword ptr fs:[0]
// 0052bb86  6aff                 push -1
// 0052bb88  680e909300           push 0x93900e
// 0052bb8d  50                   push eax
// 0052bb8e  b801000000           mov eax, 1
// 0052bb93  64892500000000       mov dword ptr fs:[0], esp
// 0052bb9a  84056401b800         test byte ptr [0xb80164], al
// 0052bba0  752e                 jne 0x52bbd0
// 0052bba2  09056401b800         or dword ptr [0xb80164], eax
// 0052bba8  6880b5b400           push 0xb4b580
// 0052bbad  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0052bbb5  e826671000           call 0x6322e0
// 0052bbba  83c404               add esp, 4
// 0052bbbd  a36001b800           mov dword ptr [0xb80160], eax
// 0052bbc2  8b0c24               mov ecx, dword ptr [esp]
// 0052bbc5  64890d00000000       mov dword ptr fs:[0], ecx
// 0052bbcc  83c40c               add esp, 0xc
// 0052bbcf  c3                   ret 
// 0052bbd0  8b0c24               mov ecx, dword ptr [esp]
// 0052bbd3  a16001b800           mov eax, dword ptr [0xb80160]
// 0052bbd8  64890d00000000       mov dword ptr fs:[0], ecx
// 0052bbdf  83c40c               add esp, 0xc
// 0052bbe2  c3                   ret 

extern char string_00b4b580[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4b580);
    return *name;
}
