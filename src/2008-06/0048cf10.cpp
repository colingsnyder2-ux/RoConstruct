// from server: 100% by auto
// roc 2008-06 0048cf10  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048cf10
//
// 0048cf10  6aff                 push -1
// 0048cf12  68e8727d00           push 0x7d72e8
// 0048cf17  64a100000000         mov eax, dword ptr fs:[0]
// 0048cf1d  50                   push eax
// 0048cf1e  64892500000000       mov dword ptr fs:[0], esp
// 0048cf25  51                   push ecx
// 0048cf26  56                   push esi
// 0048cf27  8bf1                 mov esi, ecx
// 0048cf29  6a04                 push 4
// 0048cf2b  89742408             mov dword ptr [esp + 8], esi
// 0048cf2f  e8ec392100           call 0x6a0920
// 0048cf34  83c404               add esp, 4
// 0048cf37  85c0                 test eax, eax
// 0048cf39  7404                 je 0x48cf3f
// 0048cf3b  8930                 mov dword ptr [eax], esi
// 0048cf3d  eb02                 jmp 0x48cf41
// 0048cf3f  33c0                 xor eax, eax
// 0048cf41  8906                 mov dword ptr [esi], eax
// 0048cf43  8bce                 mov ecx, esi
// 0048cf45  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048cf4d  e8cee3ffff           call 0x48b320
// 0048cf52  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048cf56  894618               mov dword ptr [esi + 0x18], eax
// 0048cf59  c6400e01             mov byte ptr [eax + 0xe], 1
// 0048cf5d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048cf60  894004               mov dword ptr [eax + 4], eax
// 0048cf63  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048cf66  8900                 mov dword ptr [eax], eax
// 0048cf68  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048cf6b  894008               mov dword ptr [eax + 8], eax
// 0048cf6e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048cf75  8bc6                 mov eax, esi
// 0048cf77  5e                   pop esi
// 0048cf78  64890d00000000       mov dword ptr fs:[0], ecx
// 0048cf7f  83c410               add esp, 0x10
// 0048cf82  c20800               ret 8
// standard library set<char> (function ??0?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE@ABU?$less@D@1@ABV?$allocator@D@1@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
