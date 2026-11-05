// from server: 100% by nuck16
// roc 2009-12 0071d9e0  unit: RBX::VDataModelMesh::?$NonFactoryProduct  size: 99 bytes
//
// 0071d9e0  64a100000000         mov eax, dword ptr fs:[0]
// 0071d9e6  6aff                 push -1
// 0071d9e8  68cee99400           push 0x94e9ce
// 0071d9ed  50                   push eax
// 0071d9ee  b801000000           mov eax, 1
// 0071d9f3  64892500000000       mov dword ptr fs:[0], esp
// 0071d9fa  8405805ab900         test byte ptr [0xb95a80], al
// 0071da00  752e                 jne 0x71da30
// 0071da02  0905805ab900         or dword ptr [0xb95a80], eax
// 0071da08  68e0fa9d00           push 0x9dfae0
// 0071da0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0071da15  e8c648f1ff           call 0x6322e0
// 0071da1a  83c404               add esp, 4
// 0071da1d  a37c5ab900           mov dword ptr [0xb95a7c], eax
// 0071da22  8b0c24               mov ecx, dword ptr [esp]
// 0071da25  64890d00000000       mov dword ptr fs:[0], ecx
// 0071da2c  83c40c               add esp, 0xc
// 0071da2f  c3                   ret 
// 0071da30  8b0c24               mov ecx, dword ptr [esp]
// 0071da33  a17c5ab900           mov eax, dword ptr [0xb95a7c]
// 0071da38  64890d00000000       mov dword ptr fs:[0], ecx
// 0071da3f  83c40c               add esp, 0xc
// 0071da42  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("DataModelMesh");
    return *name;
}
