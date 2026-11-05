// from server: 100% by nuck16
// roc 2009-12 004f5800  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5800  64a100000000         mov eax, dword ptr fs:[0]
// 004f5806  6aff                 push -1
// 004f5808  686e569300           push 0x93566e
// 004f580d  50                   push eax
// 004f580e  b801000000           mov eax, 1
// 004f5813  64892500000000       mov dword ptr fs:[0], esp
// 004f581a  8405c8ddb700         test byte ptr [0xb7ddc8], al
// 004f5820  752e                 jne 0x4f5850
// 004f5822  0905c8ddb700         or dword ptr [0xb7ddc8], eax
// 004f5828  681c76b400           push 0xb4761c
// 004f582d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5835  e8a6ca1300           call 0x6322e0
// 004f583a  83c404               add esp, 4
// 004f583d  a3c4ddb700           mov dword ptr [0xb7ddc4], eax
// 004f5842  8b0c24               mov ecx, dword ptr [esp]
// 004f5845  64890d00000000       mov dword ptr fs:[0], ecx
// 004f584c  83c40c               add esp, 0xc
// 004f584f  c3                   ret 
// 004f5850  8b0c24               mov ecx, dword ptr [esp]
// 004f5853  a1c4ddb700           mov eax, dword ptr [0xb7ddc4]
// 004f5858  64890d00000000       mov dword ptr fs:[0], ecx
// 004f585f  83c40c               add esp, 0xc
// 004f5862  c3                   ret 

extern char string_00b4761c[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4761c);
    return *name;
}
