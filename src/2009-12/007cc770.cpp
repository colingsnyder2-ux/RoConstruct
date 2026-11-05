// from server: 100% by nuck16
// roc 2009-12 007cc770  unit: RBX::GroupDropTool  size: 99 bytes
//
// 007cc770  64a100000000         mov eax, dword ptr fs:[0]
// 007cc776  6aff                 push -1
// 007cc778  685e6e9500           push 0x956e5e
// 007cc77d  50                   push eax
// 007cc77e  b801000000           mov eax, 1
// 007cc783  64892500000000       mov dword ptr fs:[0], esp
// 007cc78a  8405a08db900         test byte ptr [0xb98da0], al
// 007cc790  752e                 jne 0x7cc7c0
// 007cc792  0905a08db900         or dword ptr [0xb98da0], eax
// 007cc798  686c3bb600           push 0xb63b6c
// 007cc79d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007cc7a5  e8365be6ff           call 0x6322e0
// 007cc7aa  83c404               add esp, 4
// 007cc7ad  a39c8db900           mov dword ptr [0xb98d9c], eax
// 007cc7b2  8b0c24               mov ecx, dword ptr [esp]
// 007cc7b5  64890d00000000       mov dword ptr fs:[0], ecx
// 007cc7bc  83c40c               add esp, 0xc
// 007cc7bf  c3                   ret 
// 007cc7c0  8b0c24               mov ecx, dword ptr [esp]
// 007cc7c3  a19c8db900           mov eax, dword ptr [0xb98d9c]
// 007cc7c8  64890d00000000       mov dword ptr fs:[0], ecx
// 007cc7cf  83c40c               add esp, 0xc
// 007cc7d2  c3                   ret 

extern char string_00b63b6c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63b6c);
    return *name;
}
