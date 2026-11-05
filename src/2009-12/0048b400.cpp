// from server: 100% by nuck16
// roc 2009-12 0048b400  unit: Ogre::VisualEngine  size: 99 bytes
//
// 0048b400  64a100000000         mov eax, dword ptr fs:[0]
// 0048b406  6aff                 push -1
// 0048b408  683efc9200           push 0x92fc3e
// 0048b40d  50                   push eax
// 0048b40e  b801000000           mov eax, 1
// 0048b413  64892500000000       mov dword ptr fs:[0], esp
// 0048b41a  8405d4ccb700         test byte ptr [0xb7ccd4], al
// 0048b420  752e                 jne 0x48b450
// 0048b422  0905d4ccb700         or dword ptr [0xb7ccd4], eax
// 0048b428  687828b400           push 0xb42878
// 0048b42d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0048b435  e8a66e1a00           call 0x6322e0
// 0048b43a  83c404               add esp, 4
// 0048b43d  a3d0ccb700           mov dword ptr [0xb7ccd0], eax
// 0048b442  8b0c24               mov ecx, dword ptr [esp]
// 0048b445  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b44c  83c40c               add esp, 0xc
// 0048b44f  c3                   ret 
// 0048b450  8b0c24               mov ecx, dword ptr [esp]
// 0048b453  a1d0ccb700           mov eax, dword ptr [0xb7ccd0]
// 0048b458  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b45f  83c40c               add esp, 0xc
// 0048b462  c3                   ret 

extern char string_00b42878[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b42878);
    return *name;
}
