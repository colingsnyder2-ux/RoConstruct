// from server: 100% by nuck16
// roc 2009-12 004c2210  unit: Ogre::RbxCluster  size: 99 bytes
//
// 004c2210  64a100000000         mov eax, dword ptr fs:[0]
// 004c2216  6aff                 push -1
// 004c2218  68fe259300           push 0x9325fe
// 004c221d  50                   push eax
// 004c221e  b801000000           mov eax, 1
// 004c2223  64892500000000       mov dword ptr fs:[0], esp
// 004c222a  840590cfb700         test byte ptr [0xb7cf90], al
// 004c2230  752e                 jne 0x4c2260
// 004c2232  090590cfb700         or dword ptr [0xb7cf90], eax
// 004c2238  681449b400           push 0xb44914
// 004c223d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004c2245  e896001700           call 0x6322e0
// 004c224a  83c404               add esp, 4
// 004c224d  a38ccfb700           mov dword ptr [0xb7cf8c], eax
// 004c2252  8b0c24               mov ecx, dword ptr [esp]
// 004c2255  64890d00000000       mov dword ptr fs:[0], ecx
// 004c225c  83c40c               add esp, 0xc
// 004c225f  c3                   ret 
// 004c2260  8b0c24               mov ecx, dword ptr [esp]
// 004c2263  a18ccfb700           mov eax, dword ptr [0xb7cf8c]
// 004c2268  64890d00000000       mov dword ptr fs:[0], ecx
// 004c226f  83c40c               add esp, 0xc
// 004c2272  c3                   ret 

extern char string_00b44914[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b44914);
    return *name;
}
