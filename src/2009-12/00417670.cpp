// from server: 100% by nuck16
// roc 2009-12 00417670  unit: VCContent::?$CComObject  size: 99 bytes
//
// 00417670  64a100000000         mov eax, dword ptr fs:[0]
// 00417676  6aff                 push -1
// 00417678  68de819200           push 0x9281de
// 0041767d  50                   push eax
// 0041767e  b801000000           mov eax, 1
// 00417683  64892500000000       mov dword ptr fs:[0], esp
// 0041768a  8405a8a1b700         test byte ptr [0xb7a1a8], al
// 00417690  752e                 jne 0x4176c0
// 00417692  0905a8a1b700         or dword ptr [0xb7a1a8], eax
// 00417698  6818119d00           push 0x9d1118
// 0041769d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004176a5  e836ac2100           call 0x6322e0
// 004176aa  83c404               add esp, 4
// 004176ad  a3a4a1b700           mov dword ptr [0xb7a1a4], eax
// 004176b2  8b0c24               mov ecx, dword ptr [esp]
// 004176b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004176bc  83c40c               add esp, 0xc
// 004176bf  c3                   ret 
// 004176c0  8b0c24               mov ecx, dword ptr [esp]
// 004176c3  a1a4a1b700           mov eax, dword ptr [0xb7a1a4]
// 004176c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004176cf  83c40c               add esp, 0xc
// 004176d2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Hopper");
    return *name;
}
