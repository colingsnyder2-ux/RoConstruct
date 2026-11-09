// from server: 47% by colin
// roc 2007-08 00577460  unit: RBX::Part::W4PartType::?$EnumDesc  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00577460
//
// 00577460  c70000000000         mov dword ptr [eax], 0
// 00577466  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0057746e  89642430             mov dword ptr [esp + 0x30], esp
// 00577472  8911                 mov dword ptr [ecx], edx
// 00577474  8b542420             mov edx, dword ptr [esp + 0x20]
// 00577478  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0057747c  52                   push edx
// 0057747d  50                   push eax
// 0057747e  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00577483  e878fcffff           call 0x577100
// 00577488  50                   push eax
// 00577489  8bce                 mov ecx, esi
// 0057748b  c644242000           mov byte ptr [esp + 0x20], 0
// 00577490  e82bdbffff           call 0x574fc0
// 00577495  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00577499  51                   push ecx
// 0057749a  e8c3870b00           call 0x62fc62
// 0057749f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005774a3  83c404               add esp, 4
// 005774a6  c7067cac7a00         mov dword ptr [esi], 0x7aac7c
// 005774ac  8bc6                 mov eax, esi
// 005774ae  64890d00000000       mov dword ptr fs:[0], ecx
// 005774b5  5e                   pop esi
// 005774b6  83c40c               add esp, 0xc
// 005774b9  c22400               ret 0x24

struct EnumDesc {
    void construct(int a, int b, int c, int d, int e, int f, int g, int h, int i);
};

extern "C" void __cdecl sub_577100();
extern "C" void __cdecl sub_574FC0();
extern "C" void __cdecl sub_62FC62();

void EnumDesc::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    *(int*)0 = 0;
    *(int*)((char*)0 + 0x14) = 0;
    *(void**)((char*)0 + 0x30) = 0;
    *(int*)0 = 0;
    sub_577100();
    sub_574FC0();
    sub_62FC62();
    *(int*)this = 0x7aac7c;
}
