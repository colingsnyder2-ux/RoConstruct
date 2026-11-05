// from server: 100% by auto
// roc 2007-03 005937d0  unit: seg_00590000  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005937d0
//
// 005937d0  53                   push ebx
// 005937d1  55                   push ebp
// 005937d2  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 005937d6  56                   push esi
// 005937d7  57                   push edi
// 005937d8  eb06                 jmp 0x5937e0
// 005937da  8d9b00000000         lea ebx, [ebx]
// 005937e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 005937e4  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 005937e8  0f848e000000         je 0x59387c
// 005937ee  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005937f2  8bf0                 mov esi, eax
// 005937f4  8bd8                 mov ebx, eax
// 005937f6  c1ee04               shr esi, 4
// 005937f9  83e30f               and ebx, 0xf
// 005937fc  85ff                 test edi, edi
// 005937fe  750a                 jne 0x59380a
// 00593800  ff1544e97700         call dword ptr [0x77e944]
// 00593806  8b442420             mov eax, dword ptr [esp + 0x20]
// 0059380a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0059380d  034f0c               add ecx, dword ptr [edi + 0xc]
// 00593810  3bc1                 cmp eax, ecx
// 00593812  7206                 jb 0x59381a
// 00593814  ff1544e97700         call dword ptr [0x77e944]
// 0059381a  8b4708               mov eax, dword ptr [edi + 8]
// 0059381d  3bc6                 cmp eax, esi
// 0059381f  7702                 ja 0x593823
// 00593821  2bf0                 sub esi, eax
// 00593823  8b5704               mov edx, dword ptr [edi + 4]
// 00593826  8b3cb2               mov edi, dword ptr [edx + esi*4]
// 00593829  8b442434             mov eax, dword ptr [esp + 0x34]
// 0059382d  03fb                 add edi, ebx
// 0059382f  8bf5                 mov esi, ebp
// 00593831  8bdd                 mov ebx, ebp
// 00593833  c1ee04               shr esi, 4
// 00593836  83e30f               and ebx, 0xf
// 00593839  85c0                 test eax, eax
// 0059383b  750a                 jne 0x593847
// 0059383d  ff1544e97700         call dword ptr [0x77e944]
// 00593843  8b442434             mov eax, dword ptr [esp + 0x34]
// 00593847  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0059384a  03480c               add ecx, dword ptr [eax + 0xc]
// 0059384d  3be9                 cmp ebp, ecx
// 0059384f  720a                 jb 0x59385b
// 00593851  ff1544e97700         call dword ptr [0x77e944]
// 00593857  8b442434             mov eax, dword ptr [esp + 0x34]
// 0059385b  8b4808               mov ecx, dword ptr [eax + 8]
// 0059385e  3bce                 cmp ecx, esi
// 00593860  7702                 ja 0x593864
// 00593862  2bf1                 sub esi, ecx
// 00593864  8b5004               mov edx, dword ptr [eax + 4]
// 00593867  8b04b2               mov eax, dword ptr [edx + esi*4]
// 0059386a  8a0f                 mov cl, byte ptr [edi]
// 0059386c  83c501               add ebp, 1
// 0059386f  8344242001           add dword ptr [esp + 0x20], 1
// 00593874  880c03               mov byte ptr [ebx + eax], cl
// 00593877  e964ffffff           jmp 0x5937e0
// 0059387c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00593880  8b542434             mov edx, dword ptr [esp + 0x34]
// 00593884  5f                   pop edi
// 00593885  5e                   pop esi
// 00593886  896808               mov dword ptr [eax + 8], ebp
// 00593889  5d                   pop ebp
// 0059388a  c70000000000         mov dword ptr [eax], 0
// 00593890  895004               mov dword ptr [eax + 4], edx
// 00593893  5b                   pop ebx
// 00593894  c3                   ret 
// standard library deque<char> (function ??$_Copy_opt@V?$_Deque_const_iterator@DV?$allocator@D@std@@$0A@@std@@V?$_Deque_iterator@DV?$allocator@D@std@@$0A@@2@Uforward_iterator_tag@2@@std@@YA?AV?$_Deque_iterator@DV?$allocator@D@std@@$0A@@0@V?$_Deque_const_iterator@DV?$allocator@D@std@@$0A@@0@0V10@Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
