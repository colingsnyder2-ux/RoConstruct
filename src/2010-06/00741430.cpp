// from server: 100% by auto
// roc 2010-06 00741430  unit: RBX::VHttp::?$sp_counted_impl_p  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741430
//
// 00741430  83ec08               sub esp, 8
// 00741433  53                   push ebx
// 00741434  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0074143a  56                   push esi
// 0074143b  8bf1                 mov esi, ecx
// 0074143d  8b4614               mov eax, dword ptr [esi + 0x14]
// 00741440  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00741444  57                   push edi
// 00741445  8b38                 mov edi, dword ptr [eax]
// 00741447  8b06                 mov eax, dword ptr [esi]
// 00741449  85c9                 test ecx, ecx
// 0074144b  7404                 je 0x741451
// 0074144d  3bc8                 cmp ecx, eax
// 0074144f  7406                 je 0x741457
// 00741451  ffd3                 call ebx
// 00741453  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00741457  8b442420             mov eax, dword ptr [esp + 0x20]
// 0074145b  3bc7                 cmp eax, edi
// 0074145d  7541                 jne 0x7414a0
// 0074145f  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00741462  8b16                 mov edx, dword ptr [esi]
// 00741464  55                   push ebp
// 00741465  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00741469  85ed                 test ebp, ebp
// 0074146b  7404                 je 0x741471
// 0074146d  3bea                 cmp ebp, edx
// 0074146f  740a                 je 0x74147b
// 00741471  ffd3                 call ebx
// 00741473  8b442424             mov eax, dword ptr [esp + 0x24]
// 00741477  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0074147b  5d                   pop ebp
// 0074147c  397c2428             cmp dword ptr [esp + 0x28], edi
// 00741480  751e                 jne 0x7414a0
// 00741482  8bce                 mov ecx, esi
// 00741484  e8b7fbffff           call 0x741040
// 00741489  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0074148c  8b16                 mov edx, dword ptr [esi]
// 0074148e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00741492  5f                   pop edi
// 00741493  5e                   pop esi
// 00741494  894804               mov dword ptr [eax + 4], ecx
// 00741497  8910                 mov dword ptr [eax], edx
// 00741499  5b                   pop ebx
// 0074149a  83c408               add esp, 8
// 0074149d  c21400               ret 0x14
// 007414a0  85c9                 test ecx, ecx
// 007414a2  7406                 je 0x7414aa
// 007414a4  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 007414a8  740a                 je 0x7414b4
// 007414aa  ffd3                 call ebx
// 007414ac  8b442420             mov eax, dword ptr [esp + 0x20]
// 007414b0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007414b4  8b542428             mov edx, dword ptr [esp + 0x28]
// 007414b8  3bc2                 cmp eax, edx
// 007414ba  741d                 je 0x7414d9
// 007414bc  50                   push eax
// 007414bd  51                   push ecx
// 007414be  8d442414             lea eax, [esp + 0x14]
// 007414c2  50                   push eax
// 007414c3  8bce                 mov ecx, esi
// 007414c5  e8c6a9f1ff           call 0x65be90
// 007414ca  8b08                 mov ecx, dword ptr [eax]
// 007414cc  894c241c             mov dword ptr [esp + 0x1c], ecx
// 007414d0  8b4004               mov eax, dword ptr [eax + 4]
// 007414d3  89442420             mov dword ptr [esp + 0x20], eax
// 007414d7  ebc7                 jmp 0x7414a0
// 007414d9  8b0e                 mov ecx, dword ptr [esi]
// 007414db  8b442418             mov eax, dword ptr [esp + 0x18]
// 007414df  5f                   pop edi
// 007414e0  5e                   pop esi
// 007414e1  895004               mov dword ptr [eax + 4], edx
// 007414e4  8908                 mov dword ptr [eax], ecx
// 007414e6  5b                   pop ebx
// 007414e7  83c408               add esp, 8
// 007414ea  c21400               ret 0x14
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
