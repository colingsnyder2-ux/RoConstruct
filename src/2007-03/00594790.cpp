// from server: 100% by auto
// roc 2007-03 00594790  unit: seg_00590000  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00594790
//
// 00594790  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00594794  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00594798  53                   push ebx
// 00594799  55                   push ebp
// 0059479a  56                   push esi
// 0059479b  8b3544e97700         mov esi, dword ptr [0x77e944]
// 005947a1  2bc1                 sub eax, ecx
// 005947a3  57                   push edi
// 005947a4  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005947a8  f7d8                 neg eax
// 005947aa  85ff                 test edi, edi
// 005947ac  8be8                 mov ebp, eax
// 005947ae  7502                 jne 0x5947b2
// 005947b0  ffd6                 call esi
// 005947b2  8b470c               mov eax, dword ptr [edi + 0xc]
// 005947b5  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 005947b9  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005947bc  03eb                 add ebp, ebx
// 005947be  03c8                 add ecx, eax
// 005947c0  3be9                 cmp ebp, ecx
// 005947c2  7704                 ja 0x5947c8
// 005947c4  3be8                 cmp ebp, eax
// 005947c6  7302                 jae 0x5947ca
// 005947c8  ffd6                 call esi
// 005947ca  8b742414             mov esi, dword ptr [esp + 0x14]
// 005947ce  c644241400           mov byte ptr [esp + 0x14], 0
// 005947d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 005947d7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005947db  52                   push edx
// 005947dc  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005947e0  c644243400           mov byte ptr [esp + 0x34], 0
// 005947e5  8b442434             mov eax, dword ptr [esp + 0x34]
// 005947e9  50                   push eax
// 005947ea  51                   push ecx
// 005947eb  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 005947ef  83ec0c               sub esp, 0xc
// 005947f2  8bc4                 mov eax, esp
// 005947f4  c70000000000         mov dword ptr [eax], 0
// 005947fa  897804               mov dword ptr [eax + 4], edi
// 005947fd  895808               mov dword ptr [eax + 8], ebx
// 00594800  83ec0c               sub esp, 0xc
// 00594803  8bc4                 mov eax, esp
// 00594805  895004               mov dword ptr [eax + 4], edx
// 00594808  8b542440             mov edx, dword ptr [esp + 0x40]
// 0059480c  894808               mov dword ptr [eax + 8], ecx
// 0059480f  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00594813  c70000000000         mov dword ptr [eax], 0
// 00594819  83ec0c               sub esp, 0xc
// 0059481c  8bc4                 mov eax, esp
// 0059481e  895004               mov dword ptr [eax + 4], edx
// 00594821  8d542454             lea edx, [esp + 0x54]
// 00594825  52                   push edx
// 00594826  c70600000000         mov dword ptr [esi], 0
// 0059482c  897e04               mov dword ptr [esi + 4], edi
// 0059482f  896e08               mov dword ptr [esi + 8], ebp
// 00594832  c70000000000         mov dword ptr [eax], 0
// 00594838  894808               mov dword ptr [eax + 8], ecx
// 0059483b  e860f0ffff           call 0x5938a0
// 00594840  83c434               add esp, 0x34
// 00594843  5f                   pop edi
// 00594844  8bc6                 mov eax, esi
// 00594846  5e                   pop esi
// 00594847  5d                   pop ebp
// 00594848  5b                   pop ebx
// 00594849  c3                   ret 
// standard library deque<ptr> (function ??$_Copy_backward_opt@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$0A@@std@@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@2@@std@@YA?AV?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@0@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$0A@@0@0V10@Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
