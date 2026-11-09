// from server: 100% by auto
// roc 2009-06 0065be80  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065be80
//
// 0065be80  53                   push ebx
// 0065be81  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0065be85  55                   push ebp
// 0065be86  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065be8a  3beb                 cmp ebp, ebx
// 0065be8c  7451                 je 0x65bedf
// 0065be8e  56                   push esi
// 0065be8f  8b742418             mov esi, dword ptr [esp + 0x18]
// 0065be93  57                   push edi
// 0065be94  8b43f8               mov eax, dword ptr [ebx - 8]
// 0065be97  83eb08               sub ebx, 8
// 0065be9a  83ee08               sub esi, 8
// 0065be9d  8906                 mov dword ptr [esi], eax
// 0065be9f  8b7b04               mov edi, dword ptr [ebx + 4]
// 0065bea2  3b7e04               cmp edi, dword ptr [esi + 4]
// 0065bea5  742d                 je 0x65bed4
// 0065bea7  85ff                 test edi, edi
// 0065bea9  740c                 je 0x65beb7
// 0065beab  8d4f08               lea ecx, [edi + 8]
// 0065beae  ba01000000           mov edx, 1
// 0065beb3  f00fc111             lock xadd dword ptr [ecx], edx
// 0065beb7  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065beba  85c9                 test ecx, ecx
// 0065bebc  7413                 je 0x65bed1
// 0065bebe  8d4108               lea eax, [ecx + 8]
// 0065bec1  83caff               or edx, 0xffffffff
// 0065bec4  f00fc110             lock xadd dword ptr [eax], edx
// 0065bec8  7507                 jne 0x65bed1
// 0065beca  8b01                 mov eax, dword ptr [ecx]
// 0065becc  8b5008               mov edx, dword ptr [eax + 8]
// 0065becf  ffd2                 call edx
// 0065bed1  897e04               mov dword ptr [esi + 4], edi
// 0065bed4  3bdd                 cmp ebx, ebp
// 0065bed6  75bc                 jne 0x65be94
// 0065bed8  5f                   pop edi
// 0065bed9  8bc6                 mov eax, esi
// 0065bedb  5e                   pop esi
// 0065bedc  5d                   pop ebp
// 0065bedd  5b                   pop ebx
// 0065bede  c3                   ret 
// 0065bedf  8b442414             mov eax, dword ptr [esp + 0x14]
// 0065bee3  5d                   pop ebp
// 0065bee4  5b                   pop ebx
// 0065bee5  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_backward_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
