// from server: 100% by nuck16
// roc 2009-12 0075c4e0  unit: RBX::SelectionPartLasso  size: 99 bytes
//
// 0075c4e0  64a100000000         mov eax, dword ptr fs:[0]
// 0075c4e6  6aff                 push -1
// 0075c4e8  687e179500           push 0x95177e
// 0075c4ed  50                   push eax
// 0075c4ee  b801000000           mov eax, 1
// 0075c4f3  64892500000000       mov dword ptr fs:[0], esp
// 0075c4fa  84050478b900         test byte ptr [0xb97804], al
// 0075c500  752e                 jne 0x75c530
// 0075c502  09050478b900         or dword ptr [0xb97804], eax
// 0075c508  6804cfb500           push 0xb5cf04
// 0075c50d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0075c515  e8c65dedff           call 0x6322e0
// 0075c51a  83c404               add esp, 4
// 0075c51d  a30078b900           mov dword ptr [0xb97800], eax
// 0075c522  8b0c24               mov ecx, dword ptr [esp]
// 0075c525  64890d00000000       mov dword ptr fs:[0], ecx
// 0075c52c  83c40c               add esp, 0xc
// 0075c52f  c3                   ret 
// 0075c530  8b0c24               mov ecx, dword ptr [esp]
// 0075c533  a10078b900           mov eax, dword ptr [0xb97800]
// 0075c538  64890d00000000       mov dword ptr fs:[0], ecx
// 0075c53f  83c40c               add esp, 0xc
// 0075c542  c3                   ret 

extern char string_00b5cf04[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5cf04);
    return *name;
}
