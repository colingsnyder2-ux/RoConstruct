// from server: 100% by nuck16
// roc 2009-12 007cca90  unit: RBX::GroupDropTool  size: 99 bytes
//
// 007cca90  64a100000000         mov eax, dword ptr fs:[0]
// 007cca96  6aff                 push -1
// 007cca98  68be6e9500           push 0x956ebe
// 007cca9d  50                   push eax
// 007cca9e  b801000000           mov eax, 1
// 007ccaa3  64892500000000       mov dword ptr fs:[0], esp
// 007ccaaa  8405b88db900         test byte ptr [0xb98db8], al
// 007ccab0  752e                 jne 0x7ccae0
// 007ccab2  0905b88db900         or dword ptr [0xb98db8], eax
// 007ccab8  68543cb600           push 0xb63c54
// 007ccabd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007ccac5  e81658e6ff           call 0x6322e0
// 007ccaca  83c404               add esp, 4
// 007ccacd  a3b48db900           mov dword ptr [0xb98db4], eax
// 007ccad2  8b0c24               mov ecx, dword ptr [esp]
// 007ccad5  64890d00000000       mov dword ptr fs:[0], ecx
// 007ccadc  83c40c               add esp, 0xc
// 007ccadf  c3                   ret 
// 007ccae0  8b0c24               mov ecx, dword ptr [esp]
// 007ccae3  a1b48db900           mov eax, dword ptr [0xb98db4]
// 007ccae8  64890d00000000       mov dword ptr fs:[0], ecx
// 007ccaef  83c40c               add esp, 0xc
// 007ccaf2  c3                   ret 

extern char string_00b63c54[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63c54);
    return *name;
}
