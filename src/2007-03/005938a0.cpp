// from server: 100% by auto
// roc 2007-03 005938a0  unit: seg_00590000  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005938a0
//
// 005938a0  53                   push ebx
// 005938a1  55                   push ebp
// 005938a2  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 005938a6  56                   push esi
// 005938a7  57                   push edi
// 005938a8  eb06                 jmp 0x5938b0
// 005938aa  8d9b00000000         lea ebx, [ebx]
// 005938b0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005938b4  39442420             cmp dword ptr [esp + 0x20], eax
// 005938b8  0f8490000000         je 0x59394e
// 005938be  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005938c2  83e801               sub eax, 1
// 005938c5  8bf0                 mov esi, eax
// 005938c7  8bd8                 mov ebx, eax
// 005938c9  c1ee04               shr esi, 4
// 005938cc  83e30f               and ebx, 0xf
// 005938cf  85ff                 test edi, edi
// 005938d1  8944242c             mov dword ptr [esp + 0x2c], eax
// 005938d5  750a                 jne 0x5938e1
// 005938d7  ff1544e97700         call dword ptr [0x77e944]
// 005938dd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005938e1  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005938e4  034f0c               add ecx, dword ptr [edi + 0xc]
// 005938e7  3bc1                 cmp eax, ecx
// 005938e9  7206                 jb 0x5938f1
// 005938eb  ff1544e97700         call dword ptr [0x77e944]
// 005938f1  8b4708               mov eax, dword ptr [edi + 8]
// 005938f4  3bc6                 cmp eax, esi
// 005938f6  7702                 ja 0x5938fa
// 005938f8  2bf0                 sub esi, eax
// 005938fa  8b5704               mov edx, dword ptr [edi + 4]
// 005938fd  8b3cb2               mov edi, dword ptr [edx + esi*4]
// 00593900  8b442434             mov eax, dword ptr [esp + 0x34]
// 00593904  83ed01               sub ebp, 1
// 00593907  03fb                 add edi, ebx
// 00593909  8bf5                 mov esi, ebp
// 0059390b  8bdd                 mov ebx, ebp
// 0059390d  c1ee04               shr esi, 4
// 00593910  83e30f               and ebx, 0xf
// 00593913  85c0                 test eax, eax
// 00593915  750a                 jne 0x593921
// 00593917  ff1544e97700         call dword ptr [0x77e944]
// 0059391d  8b442434             mov eax, dword ptr [esp + 0x34]
// 00593921  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00593924  03480c               add ecx, dword ptr [eax + 0xc]
// 00593927  3be9                 cmp ebp, ecx
// 00593929  720a                 jb 0x593935
// 0059392b  ff1544e97700         call dword ptr [0x77e944]
// 00593931  8b442434             mov eax, dword ptr [esp + 0x34]
// 00593935  8b4808               mov ecx, dword ptr [eax + 8]
// 00593938  3bce                 cmp ecx, esi
// 0059393a  7702                 ja 0x59393e
// 0059393c  2bf1                 sub esi, ecx
// 0059393e  8b5004               mov edx, dword ptr [eax + 4]
// 00593941  8b04b2               mov eax, dword ptr [edx + esi*4]
// 00593944  8a0f                 mov cl, byte ptr [edi]
// 00593946  880c03               mov byte ptr [ebx + eax], cl
// 00593949  e962ffffff           jmp 0x5938b0
// 0059394e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00593952  8b542434             mov edx, dword ptr [esp + 0x34]
// 00593956  5f                   pop edi
// 00593957  5e                   pop esi
// 00593958  896808               mov dword ptr [eax + 8], ebp
// 0059395b  5d                   pop ebp
// 0059395c  c70000000000         mov dword ptr [eax], 0
// 00593962  895004               mov dword ptr [eax + 4], edx
// 00593965  5b                   pop ebx
// 00593966  c3                   ret 
// standard library deque<char> (function ??$_Copy_backward_opt@V?$_Deque_iterator@DV?$allocator@D@std@@$0A@@std@@V12@Uforward_iterator_tag@2@@std@@YA?AV?$_Deque_iterator@DV?$allocator@D@std@@$0A@@0@V10@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
