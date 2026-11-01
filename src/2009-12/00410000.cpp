// from server: 100% by auto
// roc 2009-12 00410000  unit: boost::Vbad_weak_ptr::?$error_info_injector  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410000
//
// 00410000  83ec08               sub esp, 8
// 00410003  8b542414             mov edx, dword ptr [esp + 0x14]
// 00410007  53                   push ebx
// 00410008  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0041000c  56                   push esi
// 0041000d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00410011  57                   push edi
// 00410012  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00410016  32c0                 xor al, al
// 00410018  88442410             mov byte ptr [esp + 0x10], al
// 0041001c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00410020  8844240c             mov byte ptr [esp + 0xc], al
// 00410024  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00410028  50                   push eax
// 00410029  51                   push ecx
// 0041002a  52                   push edx
// 0041002b  57                   push edi
// 0041002c  56                   push esi
// 0041002d  53                   push ebx
// 0041002e  e8ed1a2900           call 0x6a1b20
// 00410033  83c418               add esp, 0x18
// 00410036  2bf3                 sub esi, ebx
// 00410038  c1fe03               sar esi, 3
// 0041003b  8d04f7               lea eax, [edi + esi*8]
// 0041003e  5f                   pop edi
// 0041003f  5e                   pop esi
// 00410040  5b                   pop ebx
// 00410041  83c408               add esp, 8
// 00410044  c3                   ret 
// library templates-boost-1_34_1/vector_sp.cpp (function ??$_Copy_opt@PAV?$shared_ptr@UT@@@boost@@PAV12@@std@@YAPAV?$shared_ptr@UT@@@boost@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
