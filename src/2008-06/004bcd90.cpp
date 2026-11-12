// from server: 100% by auto
// roc 2008-06 004bcd90  unit: ProfiledRakPeer  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bcd90
//
// 004bcd90  55                   push ebp
// 004bcd91  8bec                 mov ebp, esp
// 004bcd93  83ec54               sub esp, 0x54
// 004bcd96  8b4508               mov eax, dword ptr [ebp + 8]
// 004bcd99  53                   push ebx
// 004bcd9a  56                   push esi
// 004bcd9b  57                   push edi
// 004bcd9c  6a40                 push 0x40
// 004bcd9e  8bf0                 mov esi, eax
// 004bcda0  6a00                 push 0
// 004bcda2  b910000000           mov ecx, 0x10
// 004bcda7  8d7dac               lea edi, [ebp - 0x54]
// 004bcdaa  50                   push eax
// 004bcdab  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bcdad  e852491e00           call 0x6a1704
// 004bcdb2  33c0                 xor eax, eax
// 004bcdb4  83c40c               add esp, 0xc
// 004bcdb7  33c9                 xor ecx, ecx
// 004bcdb9  8945fc               mov dword ptr [ebp - 4], eax
// 004bcdbc  894df4               mov dword ptr [ebp - 0xc], ecx
// 004bcdbf  90                   nop 
// 004bcdc0  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004bcdc3  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004bcdc6  c745f820000000       mov dword ptr [ebp - 8], 0x20
// 004bcdcd  85db                 test ebx, ebx
// 004bcdcf  0f848a000000         je 0x4bce5f
// 004bcdd5  f6c301               test bl, 1
// 004bcdd8  746d                 je 0x4bce47
// 004bcdda  85c0                 test eax, eax
// 004bcddc  7414                 je 0x4bcdf2
// 004bcdde  50                   push eax
// 004bcddf  8d45ac               lea eax, [ebp - 0x54]
// 004bcde2  50                   push eax
// 004bcde3  e8b8fbffff           call 0x4bc9a0
// 004bcde8  83c408               add esp, 8
// 004bcdeb  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004bcdf2  8d4dac               lea ecx, [ebp - 0x54]
// 004bcdf5  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bcdf8  c745f003000000       mov dword ptr [ebp - 0x10], 3
// 004bcdff  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 004bce02  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bce05  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004bce08  8b06                 mov eax, dword ptr [esi]
// 004bce0a  33d2                 xor edx, edx
// 004bce0c  0107                 add dword ptr [edi], eax
// 004bce0e  8b4604               mov eax, dword ptr [esi + 4]
// 004bce11  114704               adc dword ptr [edi + 4], eax
// 004bce14  8b4608               mov eax, dword ptr [esi + 8]
// 004bce17  114708               adc dword ptr [edi + 8], eax
// 004bce1a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bce1d  11470c               adc dword ptr [edi + 0xc], eax
// 004bce20  e322                 jecxz 0x4bce44
// 004bce22  42                   inc edx
// 004bce23  42                   inc edx
// 004bce24  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bce27  1104d7               adc dword ptr [edi + edx*8], eax
// 004bce2a  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bce2e  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bce32  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bce36  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bce3a  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bce3e  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bce42  e2de                 loop 0x4bce22
// 004bce44  8b45fc               mov eax, dword ptr [ebp - 4]
// 004bce47  8145f8ffff0000       add dword ptr [ebp - 8], 0xffff
// 004bce4e  d1eb                 shr ebx, 1
// 004bce50  40                   inc eax
// 004bce51  8945fc               mov dword ptr [ebp - 4], eax
// 004bce54  85db                 test ebx, ebx
// 004bce56  0f8579ffffff         jne 0x4bcdd5
// 004bce5c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004bce5f  0fb755f8             movzx edx, word ptr [ebp - 8]
// 004bce63  41                   inc ecx
// 004bce64  03c2                 add eax, edx
// 004bce66  8945fc               mov dword ptr [ebp - 4], eax
// 004bce69  894df4               mov dword ptr [ebp - 0xc], ecx
// 004bce6c  83f908               cmp ecx, 8
// 004bce6f  0f824bffffff         jb 0x4bcdc0
// 004bce75  5f                   pop edi
// 004bce76  5e                   pop esi
// 004bce77  5b                   pop ebx
// 004bce78  8be5                 mov esp, ebp
// 004bce7a  5d                   pop ebp
// 004bce7b  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY07I$$BY0BA@I@big@@YAXAAY0BA@IAAY07I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
