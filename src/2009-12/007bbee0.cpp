// from server: 100% by auto
// roc 2009-12 007bbee0  unit: RBX::SpatialFilter  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bbee0
//
// 007bbee0  83ec08               sub esp, 8
// 007bbee3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007bbee7  53                   push ebx
// 007bbee8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007bbeec  56                   push esi
// 007bbeed  8b742418             mov esi, dword ptr [esp + 0x18]
// 007bbef1  57                   push edi
// 007bbef2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007bbef6  32c0                 xor al, al
// 007bbef8  88442410             mov byte ptr [esp + 0x10], al
// 007bbefc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bbf00  8844240c             mov byte ptr [esp + 0xc], al
// 007bbf04  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bbf08  50                   push eax
// 007bbf09  51                   push ecx
// 007bbf0a  52                   push edx
// 007bbf0b  57                   push edi
// 007bbf0c  56                   push esi
// 007bbf0d  53                   push ebx
// 007bbf0e  e82d12faff           call 0x75d140
// 007bbf13  83c418               add esp, 0x18
// 007bbf16  2bf3                 sub esi, ebx
// 007bbf18  c1fe03               sar esi, 3
// 007bbf1b  8d04f7               lea eax, [edi + esi*8]
// 007bbf1e  5f                   pop edi
// 007bbf1f  5e                   pop esi
// 007bbf20  5b                   pop ebx
// 007bbf21  83c408               add esp, 8
// 007bbf24  c3                   ret 
// library templates-boost-1_34_1/vector_sp.cpp (function ??$_Copy_opt@PAV?$shared_ptr@UT@@@boost@@PAV12@@std@@YAPAV?$shared_ptr@UT@@@boost@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
