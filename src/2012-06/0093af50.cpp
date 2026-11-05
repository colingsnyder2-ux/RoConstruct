// roc 2012-06 0093af50  unit: seg_00930000  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0093af50
//
// 0093af50  83ec18               sub esp, 0x18
// 0093af53  53                   push ebx
// 0093af54  56                   push esi
// 0093af55  8bf0                 mov esi, eax
// 0093af57  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 0093af5a  56                   push esi
// 0093af5b  e860d4ffff           call 0x9383c0
// 0093af60  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0093af63  8d81fcfeffff         lea eax, [ecx - 0x104]
// 0093af69  83c404               add esp, 4
// 0093af6c  83f81b               cmp eax, 0x1b
// 0093af6f  770e                 ja 0x93af7f
// 0093af71  0fb68054b09300       movzx eax, byte ptr [eax + 0x93b054]
// 0093af78  ff24854cb09300       jmp dword ptr [eax*4 + 0x93b04c]
// 0093af7f  83f93b               cmp ecx, 0x3b
// 0093af82  0f84ad000000         je 0x93b035
// 0093af88  57                   push edi
// 0093af89  8d7c240c             lea edi, [esp + 0xc]
// 0093af8d  e88ee4ffff           call 0x939420
// 0093af92  8bf0                 mov esi, eax
// 0093af94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0093af98  5f                   pop edi
// 0093af99  83f80d               cmp eax, 0xd
// 0093af9c  744c                 je 0x93afea
// 0093af9e  83f80e               cmp eax, 0xe
// 0093afa1  7447                 je 0x93afea
// 0093afa3  83fe01               cmp esi, 1
// 0093afa6  751f                 jne 0x93afc7
// 0093afa8  8d4c2408             lea ecx, [esp + 8]
// 0093afac  51                   push ecx
// 0093afad  53                   push ebx
// 0093afae  e83dce0200           call 0x967df0
// 0093afb3  83c408               add esp, 8
// 0093afb6  56                   push esi
// 0093afb7  50                   push eax
// 0093afb8  53                   push ebx
// 0093afb9  e862c90200           call 0x967920
// 0093afbe  83c40c               add esp, 0xc
// 0093afc1  5e                   pop esi
// 0093afc2  5b                   pop ebx
// 0093afc3  83c418               add esp, 0x18
// 0093afc6  c3                   ret 
// 0093afc7  8d542408             lea edx, [esp + 8]
// 0093afcb  52                   push edx
// 0093afcc  53                   push ebx
// 0093afcd  e89ecd0200           call 0x967d70
// 0093afd2  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 0093afd6  83c408               add esp, 8
// 0093afd9  56                   push esi
// 0093afda  50                   push eax
// 0093afdb  53                   push ebx
// 0093afdc  e83fc90200           call 0x967920
// 0093afe1  83c40c               add esp, 0xc
// 0093afe4  5e                   pop esi
// 0093afe5  5b                   pop ebx
// 0093afe6  83c418               add esp, 0x18
// 0093afe9  c3                   ret 
// 0093afea  6aff                 push -1
// 0093afec  8d44240c             lea eax, [esp + 0xc]
// 0093aff0  50                   push eax
// 0093aff1  53                   push ebx
// 0093aff2  e859c40200           call 0x967450
// 0093aff7  83c40c               add esp, 0xc
// 0093affa  837c24080d           cmp dword ptr [esp + 8], 0xd
// 0093afff  751c                 jne 0x93b01d
// 0093b001  83fe01               cmp esi, 1
// 0093b004  7517                 jne 0x93b01d
// 0093b006  8b0b                 mov ecx, dword ptr [ebx]
// 0093b008  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0093b00b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0093b00f  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0093b012  8d0482               lea eax, [edx + eax*4]
// 0093b015  83e1dd               and ecx, 0xffffffdd
// 0093b018  83c91d               or ecx, 0x1d
// 0093b01b  8908                 mov dword ptr [eax], ecx
// 0093b01d  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 0093b021  83ceff               or esi, 0xffffffff
// 0093b024  56                   push esi
// 0093b025  50                   push eax
// 0093b026  53                   push ebx
// 0093b027  e8f4c80200           call 0x967920
// 0093b02c  83c40c               add esp, 0xc
// 0093b02f  5e                   pop esi
// 0093b030  5b                   pop ebx
// 0093b031  83c418               add esp, 0x18
// 0093b034  c3                   ret 
// 0093b035  33f6                 xor esi, esi
// 0093b037  33c0                 xor eax, eax
// 0093b039  56                   push esi
// 0093b03a  50                   push eax
// 0093b03b  53                   push ebx
// 0093b03c  e8dfc80200           call 0x967920
// 0093b041  83c40c               add esp, 0xc
// 0093b044  5e                   pop esi
// 0093b045  5b                   pop ebx
// 0093b046  83c418               add esp, 0x18
// 0093b049  c3                   ret 
// 0093b04a  8bff                 mov edi, edi
// 0093b04c  35b093007f           xor eax, 0x7f0093b0
// 0093b051  af                   scasd eax, dword ptr es:[edi]
// 0093b052  93                   xchg ebx, eax
// 0093b053  0000                 add byte ptr [eax], al
// 0093b055  0000                 add byte ptr [eax], al
// 0093b057  0101                 add dword ptr [ecx], eax
// 0093b059  0101                 add dword ptr [ecx], eax
// 0093b05b  0101                 add dword ptr [ecx], eax
// 0093b05d  0101                 add dword ptr [ecx], eax
// 0093b05f  0101                 add dword ptr [ecx], eax
// 0093b061  0101                 add dword ptr [ecx], eax
// 0093b063  0100                 add dword ptr [eax], eax
// 0093b065  0101                 add dword ptr [ecx], eax
// 0093b067  0101                 add dword ptr [ecx], eax
// 0093b069  0101                 add dword ptr [ecx], eax
// 0093b06b  0101                 add dword ptr [ecx], eax
// 0093b06d  0101                 add dword ptr [ecx], eax
// library lua-5.1/lparser.c (function _retstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
