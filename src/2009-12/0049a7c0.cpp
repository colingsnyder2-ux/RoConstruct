// from server: 100% by nuck16
// roc 2009-12 0049a7c0  unit: Ogre::RbxMeshPartAdapter::??fillVertices::?L::FileLoader  size: 99 bytes
//
// 0049a7c0  64a100000000         mov eax, dword ptr fs:[0]
// 0049a7c6  6aff                 push -1
// 0049a7c8  68de039300           push 0x9303de
// 0049a7cd  50                   push eax
// 0049a7ce  b801000000           mov eax, 1
// 0049a7d3  64892500000000       mov dword ptr fs:[0], esp
// 0049a7da  8405e0cdb700         test byte ptr [0xb7cde0], al
// 0049a7e0  752e                 jne 0x49a810
// 0049a7e2  0905e0cdb700         or dword ptr [0xb7cde0], eax
// 0049a7e8  68982bb400           push 0xb42b98
// 0049a7ed  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0049a7f5  e8e67a1900           call 0x6322e0
// 0049a7fa  83c404               add esp, 4
// 0049a7fd  a3dccdb700           mov dword ptr [0xb7cddc], eax
// 0049a802  8b0c24               mov ecx, dword ptr [esp]
// 0049a805  64890d00000000       mov dword ptr fs:[0], ecx
// 0049a80c  83c40c               add esp, 0xc
// 0049a80f  c3                   ret 
// 0049a810  8b0c24               mov ecx, dword ptr [esp]
// 0049a813  a1dccdb700           mov eax, dword ptr [0xb7cddc]
// 0049a818  64890d00000000       mov dword ptr fs:[0], ecx
// 0049a81f  83c40c               add esp, 0xc
// 0049a822  c3                   ret 

extern char string_00b42b98[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b42b98);
    return *name;
}
