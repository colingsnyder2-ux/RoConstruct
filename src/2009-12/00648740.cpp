// from server: 100% by nuck16
// roc 2009-12 00648740  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 99 bytes
//
// 00648740  64a100000000         mov eax, dword ptr fs:[0]
// 00648746  6aff                 push -1
// 00648748  685e189400           push 0x94185e
// 0064874d  50                   push eax
// 0064874e  b801000000           mov eax, 1
// 00648753  64892500000000       mov dword ptr fs:[0], esp
// 0064875a  8405885eb800         test byte ptr [0xb85e88], al
// 00648760  752e                 jne 0x648790
// 00648762  0905885eb800         or dword ptr [0xb85e88], eax
// 00648768  68301fb500           push 0xb51f30
// 0064876d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00648775  e8669bfeff           call 0x6322e0
// 0064877a  83c404               add esp, 4
// 0064877d  a3845eb800           mov dword ptr [0xb85e84], eax
// 00648782  8b0c24               mov ecx, dword ptr [esp]
// 00648785  64890d00000000       mov dword ptr fs:[0], ecx
// 0064878c  83c40c               add esp, 0xc
// 0064878f  c3                   ret 
// 00648790  8b0c24               mov ecx, dword ptr [esp]
// 00648793  a1845eb800           mov eax, dword ptr [0xb85e84]
// 00648798  64890d00000000       mov dword ptr fs:[0], ecx
// 0064879f  83c40c               add esp, 0xc
// 006487a2  c3                   ret 

extern char string_00b51f30[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b51f30);
    return *name;
}
