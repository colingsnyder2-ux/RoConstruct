// from server: 100% by nuck16
// roc 2009-12 00577820  unit: RBX::ViewRbxGfx  size: 99 bytes
//
// 00577820  64a100000000         mov eax, dword ptr fs:[0]
// 00577826  6aff                 push -1
// 00577828  680ebf9300           push 0x93bf0e
// 0057782d  50                   push eax
// 0057782e  b801000000           mov eax, 1
// 00577833  64892500000000       mov dword ptr fs:[0], esp
// 0057783a  84055827b800         test byte ptr [0xb82758], al
// 00577840  752e                 jne 0x577870
// 00577842  09055827b800         or dword ptr [0xb82758], eax
// 00577848  6878d8b400           push 0xb4d878
// 0057784d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00577855  e886aa0b00           call 0x6322e0
// 0057785a  83c404               add esp, 4
// 0057785d  a35427b800           mov dword ptr [0xb82754], eax
// 00577862  8b0c24               mov ecx, dword ptr [esp]
// 00577865  64890d00000000       mov dword ptr fs:[0], ecx
// 0057786c  83c40c               add esp, 0xc
// 0057786f  c3                   ret 
// 00577870  8b0c24               mov ecx, dword ptr [esp]
// 00577873  a15427b800           mov eax, dword ptr [0xb82754]
// 00577878  64890d00000000       mov dword ptr fs:[0], ecx
// 0057787f  83c40c               add esp, 0xc
// 00577882  c3                   ret 

extern char string_00b4d878[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4d878);
    return *name;
}
