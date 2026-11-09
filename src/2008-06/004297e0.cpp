// from server: 100% by auto
// roc 2008-06 004297e0  unit: ThreadLogManager  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004297e0
//
// 004297e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004297e4  8b5004               mov edx, dword ptr [eax + 4]
// 004297e7  53                   push ebx
// 004297e8  56                   push esi
// 004297e9  57                   push edi
// 004297ea  8bd9                 mov ebx, ecx
// 004297ec  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004297f0  8d7804               lea edi, [eax + 4]
// 004297f3  51                   push ecx
// 004297f4  52                   push edx
// 004297f5  50                   push eax
// 004297f6  8bcb                 mov ecx, ebx
// 004297f8  e8d3f6ffff           call 0x428ed0
// 004297fd  6a01                 push 1
// 004297ff  8bcb                 mov ecx, ebx
// 00429801  8bf0                 mov esi, eax
// 00429803  e8e8f0ffff           call 0x4288f0
// 00429808  8937                 mov dword ptr [edi], esi
// 0042980a  8b4604               mov eax, dword ptr [esi + 4]
// 0042980d  8b3d90288000         mov edi, dword ptr [0x802890]
// 00429813  8930                 mov dword ptr [eax], esi
// 00429815  8b442414             mov eax, dword ptr [esp + 0x14]
// 00429819  85c0                 test eax, eax
// 0042981b  7506                 jne 0x429823
// 0042981d  ffd7                 call edi
// 0042981f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00429823  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00429827  8b4904               mov ecx, dword ptr [ecx + 4]
// 0042982a  894c2418             mov dword ptr [esp + 0x18], ecx
// 0042982e  85c0                 test eax, eax
// 00429830  7404                 je 0x429836
// 00429832  8b00                 mov eax, dword ptr [eax]
// 00429834  eb02                 jmp 0x429838
// 00429836  33c0                 xor eax, eax
// 00429838  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0042983b  7506                 jne 0x429843
// 0042983d  ffd7                 call edi
// 0042983f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00429843  8b742410             mov esi, dword ptr [esp + 0x10]
// 00429847  c70600000000         mov dword ptr [esi], 0
// 0042984d  894e04               mov dword ptr [esi + 4], ecx
// 00429850  85db                 test ebx, ebx
// 00429852  7502                 jne 0x429856
// 00429854  ffd7                 call edi
// 00429856  8b13                 mov edx, dword ptr [ebx]
// 00429858  5f                   pop edi
// 00429859  8916                 mov dword ptr [esi], edx
// 0042985b  8bc6                 mov eax, esi
// 0042985d  5e                   pop esi
// 0042985e  5b                   pop ebx
// 0042985f  c21000               ret 0x10
// standard library list<ptr> (function ?insert@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
