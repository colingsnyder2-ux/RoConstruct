// from server: 100% by auto
// roc 2007-03 0050ab90  unit: seg_00500000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050ab90
//
// 0050ab90  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0050ab94  85c9                 test ecx, ecx
// 0050ab96  7506                 jne 0x50ab9e
// 0050ab98  394c2408             cmp dword ptr [esp + 8], ecx
// 0050ab9c  7409                 je 0x50aba7
// 0050ab9e  83b92002000000       cmp dword ptr [ecx + 0x220], 0
// 0050aba5  7f03                 jg 0x50abaa
// 0050aba7  33c0                 xor eax, eax
// 0050aba9  c3                   ret 
// 0050abaa  8b8120020000         mov eax, dword ptr [ecx + 0x220]
// 0050abb0  8b8924020000         mov ecx, dword ptr [ecx + 0x224]
// 0050abb6  53                   push ebx
// 0050abb7  55                   push ebp
// 0050abb8  56                   push esi
// 0050abb9  8bd8                 mov ebx, eax
// 0050abbb  85db                 test ebx, ebx
// 0050abbd  8d1480               lea edx, [eax + eax*4]
// 0050abc0  57                   push edi
// 0050abc1  8d7c0afb             lea edi, [edx + ecx - 5]
// 0050abc5  0f849e000000         je 0x50ac69
// 0050abcb  eb03                 jmp 0x50abd0
// 0050abcd  8d4900               lea ecx, [ecx]
// 0050abd0  8b542418             mov edx, dword ptr [esp + 0x18]
// 0050abd4  b804000000           mov eax, 4
// 0050abd9  8bcf                 mov ecx, edi
// 0050abdb  eb03                 jmp 0x50abe0
// 0050abdd  8d4900               lea ecx, [ecx]
// 0050abe0  8b32                 mov esi, dword ptr [edx]
// 0050abe2  3b31                 cmp esi, dword ptr [ecx]
// 0050abe4  7512                 jne 0x50abf8
// 0050abe6  83e804               sub eax, 4
// 0050abe9  83c104               add ecx, 4
// 0050abec  83c204               add edx, 4
// 0050abef  83f804               cmp eax, 4
// 0050abf2  73ec                 jae 0x50abe0
// 0050abf4  85c0                 test eax, eax
// 0050abf6  745d                 je 0x50ac55
// 0050abf8  0fb632               movzx esi, byte ptr [edx]
// 0050abfb  0fb629               movzx ebp, byte ptr [ecx]
// 0050abfe  2bf5                 sub esi, ebp
// 0050ac00  7545                 jne 0x50ac47
// 0050ac02  83e801               sub eax, 1
// 0050ac05  83c101               add ecx, 1
// 0050ac08  83c201               add edx, 1
// 0050ac0b  85c0                 test eax, eax
// 0050ac0d  7446                 je 0x50ac55
// 0050ac0f  0fb632               movzx esi, byte ptr [edx]
// 0050ac12  0fb629               movzx ebp, byte ptr [ecx]
// 0050ac15  2bf5                 sub esi, ebp
// 0050ac17  752e                 jne 0x50ac47
// 0050ac19  83e801               sub eax, 1
// 0050ac1c  83c101               add ecx, 1
// 0050ac1f  83c201               add edx, 1
// 0050ac22  85c0                 test eax, eax
// 0050ac24  742f                 je 0x50ac55
// 0050ac26  0fb632               movzx esi, byte ptr [edx]
// 0050ac29  0fb629               movzx ebp, byte ptr [ecx]
// 0050ac2c  2bf5                 sub esi, ebp
// 0050ac2e  7517                 jne 0x50ac47
// 0050ac30  83e801               sub eax, 1
// 0050ac33  83c101               add ecx, 1
// 0050ac36  83c201               add edx, 1
// 0050ac39  85c0                 test eax, eax
// 0050ac3b  7418                 je 0x50ac55
// 0050ac3d  0fb632               movzx esi, byte ptr [edx]
// 0050ac40  0fb611               movzx edx, byte ptr [ecx]
// 0050ac43  2bf2                 sub esi, edx
// 0050ac45  740e                 je 0x50ac55
// 0050ac47  85f6                 test esi, esi
// 0050ac49  b801000000           mov eax, 1
// 0050ac4e  7f07                 jg 0x50ac57
// 0050ac50  83c8ff               or eax, 0xffffffff
// 0050ac53  eb02                 jmp 0x50ac57
// 0050ac55  33c0                 xor eax, eax
// 0050ac57  85c0                 test eax, eax
// 0050ac59  7415                 je 0x50ac70
// 0050ac5b  83eb01               sub ebx, 1
// 0050ac5e  83ef05               sub edi, 5
// 0050ac61  85db                 test ebx, ebx
// 0050ac63  0f8567ffffff         jne 0x50abd0
// 0050ac69  5f                   pop edi
// 0050ac6a  5e                   pop esi
// 0050ac6b  5d                   pop ebp
// 0050ac6c  33c0                 xor eax, eax
// 0050ac6e  5b                   pop ebx
// 0050ac6f  c3                   ret 
// 0050ac70  0fb64704             movzx eax, byte ptr [edi + 4]
// 0050ac74  5f                   pop edi
// 0050ac75  5e                   pop esi
// 0050ac76  5d                   pop ebp
// 0050ac77  5b                   pop ebx
// 0050ac78  c3                   ret 
// library libpng-1.2.7/png.c (function _png_handle_as_unknown)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
