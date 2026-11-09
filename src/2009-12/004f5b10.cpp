// from server: 100% by nuck16
// roc 2009-12 004f5b10  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f5b10  64a100000000         mov eax, dword ptr fs:[0]
// 004f5b16  6aff                 push -1
// 004f5b18  684e579300           push 0x93574e
// 004f5b1d  50                   push eax
// 004f5b1e  b801000000           mov eax, 1
// 004f5b23  64892500000000       mov dword ptr fs:[0], esp
// 004f5b2a  840500deb700         test byte ptr [0xb7de00], al
// 004f5b30  752e                 jne 0x4f5b60
// 004f5b32  090500deb700         or dword ptr [0xb7de00], eax
// 004f5b38  68f4d59d00           push 0x9dd5f4
// 004f5b3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5b45  e896c71300           call 0x6322e0
// 004f5b4a  83c404               add esp, 4
// 004f5b4d  a3fcddb700           mov dword ptr [0xb7ddfc], eax
// 004f5b52  8b0c24               mov ecx, dword ptr [esp]
// 004f5b55  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5b5c  83c40c               add esp, 0xc
// 004f5b5f  c3                   ret 
// 004f5b60  8b0c24               mov ecx, dword ptr [esp]
// 004f5b63  a1fcddb700           mov eax, dword ptr [0xb7ddfc]
// 004f5b68  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5b6f  83c40c               add esp, 0xc
// 004f5b72  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("BodyColors");
    return *name;
}
