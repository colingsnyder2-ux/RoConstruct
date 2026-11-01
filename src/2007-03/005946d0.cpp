// from server: 100% by auto
// roc 2007-03 005946d0  unit: seg_00590000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005946d0
//
// 005946d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 005946d4  53                   push ebx
// 005946d5  55                   push ebp
// 005946d6  56                   push esi
// 005946d7  8b742428             mov esi, dword ptr [esp + 0x28]
// 005946db  57                   push edi
// 005946dc  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005946e0  2bf0                 sub esi, eax
// 005946e2  85ff                 test edi, edi
// 005946e4  7506                 jne 0x5946ec
// 005946e6  ff1544e97700         call dword ptr [0x77e944]
// 005946ec  8b470c               mov eax, dword ptr [edi + 0xc]
// 005946ef  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 005946f3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005946f6  8d2c33               lea ebp, [ebx + esi]
// 005946f9  03c8                 add ecx, eax
// 005946fb  3be9                 cmp ebp, ecx
// 005946fd  7704                 ja 0x594703
// 005946ff  3be8                 cmp ebp, eax
// 00594701  7306                 jae 0x594709
// 00594703  ff1544e97700         call dword ptr [0x77e944]
// 00594709  8b742414             mov esi, dword ptr [esp + 0x14]
// 0059470d  c644241400           mov byte ptr [esp + 0x14], 0
// 00594712  8b542414             mov edx, dword ptr [esp + 0x14]
// 00594716  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059471a  52                   push edx
// 0059471b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0059471f  c644243400           mov byte ptr [esp + 0x34], 0
// 00594724  8b442434             mov eax, dword ptr [esp + 0x34]
// 00594728  50                   push eax
// 00594729  51                   push ecx
// 0059472a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0059472e  83ec0c               sub esp, 0xc
// 00594731  8bc4                 mov eax, esp
// 00594733  c70000000000         mov dword ptr [eax], 0
// 00594739  897804               mov dword ptr [eax + 4], edi
// 0059473c  895808               mov dword ptr [eax + 8], ebx
// 0059473f  83ec0c               sub esp, 0xc
// 00594742  8bc4                 mov eax, esp
// 00594744  895004               mov dword ptr [eax + 4], edx
// 00594747  8b542440             mov edx, dword ptr [esp + 0x40]
// 0059474b  894808               mov dword ptr [eax + 8], ecx
// 0059474e  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00594752  c70000000000         mov dword ptr [eax], 0
// 00594758  83ec0c               sub esp, 0xc
// 0059475b  8bc4                 mov eax, esp
// 0059475d  895004               mov dword ptr [eax + 4], edx
// 00594760  8d542454             lea edx, [esp + 0x54]
// 00594764  52                   push edx
// 00594765  c70600000000         mov dword ptr [esi], 0
// 0059476b  897e04               mov dword ptr [esi + 4], edi
// 0059476e  896e08               mov dword ptr [esi + 8], ebp
// 00594771  c70000000000         mov dword ptr [eax], 0
// 00594777  894808               mov dword ptr [eax + 8], ecx
// 0059477a  e851f0ffff           call 0x5937d0
// 0059477f  83c434               add esp, 0x34
// 00594782  5f                   pop edi
// 00594783  8bc6                 mov eax, esi
// 00594785  5e                   pop esi
// 00594786  5d                   pop ebp
// 00594787  5b                   pop ebx
// 00594788  c3                   ret 
// standard library deque<ptr> (function ??$_Copy_opt@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$0A@@std@@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@2@@std@@YA?AV?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@0@V?$_Deque_iterator@PAUT@@V?$allocator@PAUT@@@std@@$0A@@0@0V10@Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
