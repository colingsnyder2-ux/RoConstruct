// from server: 100% by auto
// roc 2007-08 0042ab20  unit: VCLuaFunction::?$CComObject  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ab20
//
// 0042ab20  6aff                 push -1
// 0042ab22  68a9b77600           push 0x76b7a9
// 0042ab27  64a100000000         mov eax, dword ptr fs:[0]
// 0042ab2d  50                   push eax
// 0042ab2e  83ec44               sub esp, 0x44
// 0042ab31  56                   push esi
// 0042ab32  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042ab37  33c4                 xor eax, esp
// 0042ab39  50                   push eax
// 0042ab3a  8d44244c             lea eax, [esp + 0x4c]
// 0042ab3e  64a300000000         mov dword ptr fs:[0], eax
// 0042ab44  8b4108               mov eax, dword ptr [ecx + 8]
// 0042ab47  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0042ab4b  beffffff1f           mov esi, 0x1fffffff
// 0042ab50  2bf0                 sub esi, eax
// 0042ab52  3bf2                 cmp esi, edx
// 0042ab54  733c                 jae 0x42ab92
// 0042ab56  688c597800           push 0x78598c
// 0042ab5b  8d4c240c             lea ecx, [esp + 0xc]
// 0042ab5f  ff1598e67700         call dword ptr [0x77e698]
// 0042ab65  8d442408             lea eax, [esp + 8]
// 0042ab69  50                   push eax
// 0042ab6a  8d4c2428             lea ecx, [esp + 0x28]
// 0042ab6e  c744245800000000     mov dword ptr [esp + 0x58], 0
// 0042ab76  e84579fdff           call 0x4024c0
// 0042ab7b  6878f78300           push 0x83f778
// 0042ab80  8d4c2428             lea ecx, [esp + 0x28]
// 0042ab84  51                   push ecx
// 0042ab85  c744242c6c4e7800     mov dword ptr [esp + 0x2c], 0x784e6c
// 0042ab8d  e80c602000           call 0x630b9e
// 0042ab92  03c2                 add eax, edx
// 0042ab94  894108               mov dword ptr [ecx + 8], eax
// 0042ab97  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0042ab9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0042aba2  59                   pop ecx
// 0042aba3  5e                   pop esi
// 0042aba4  83c450               add esp, 0x50
// 0042aba7  c20400               ret 4
// standard library list<double> (function ?_Incsize@?$list@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
