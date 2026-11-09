// from server: 100% by auto
// roc 2011-06 005616d0  unit: seg_00560000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005616d0
//
// 005616d0  56                   push esi
// 005616d1  8b742408             mov esi, dword ptr [esp + 8]
// 005616d5  85f6                 test esi, esi
// 005616d7  7504                 jne 0x5616dd
// 005616d9  33c0                 xor eax, eax
// 005616db  5e                   pop esi
// 005616dc  c3                   ret 
// 005616dd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005616e1  57                   push edi
// 005616e2  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 005616e5  8bc7                 mov eax, edi
// 005616e7  51                   push ecx
// 005616e8  0d00001000           or eax, 0x100000
// 005616ed  56                   push esi
// 005616ee  89466c               mov dword ptr [esi + 0x6c], eax
// 005616f1  e84affffff           call 0x561640
// 005616f6  83c408               add esp, 8
// 005616f9  897e6c               mov dword ptr [esi + 0x6c], edi
// 005616fc  5f                   pop edi
// 005616fd  5e                   pop esi
// 005616fe  c3                   ret 
// library libpng-1.2.16/pngmem.c (function _png_malloc_warn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngmem.c
