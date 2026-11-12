// from server: 100% by auto
// roc 2008-06 004bcc90  unit: ProfiledRakPeer  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bcc90
//
// 004bcc90  55                   push ebp
// 004bcc91  8bec                 mov ebp, esp
// 004bcc93  83ec34               sub esp, 0x34
// 004bcc96  8b4508               mov eax, dword ptr [ebp + 8]
// 004bcc99  53                   push ebx
// 004bcc9a  56                   push esi
// 004bcc9b  57                   push edi
// 004bcc9c  8bf0                 mov esi, eax
// 004bcc9e  b908000000           mov ecx, 8
// 004bcca3  8d7dcc               lea edi, [ebp - 0x34]
// 004bcca6  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bcca8  33c9                 xor ecx, ecx
// 004bccaa  8908                 mov dword ptr [eax], ecx
// 004bccac  894804               mov dword ptr [eax + 4], ecx
// 004bccaf  894808               mov dword ptr [eax + 8], ecx
// 004bccb2  89480c               mov dword ptr [eax + 0xc], ecx
// 004bccb5  894810               mov dword ptr [eax + 0x10], ecx
// 004bccb8  894814               mov dword ptr [eax + 0x14], ecx
// 004bccbb  894818               mov dword ptr [eax + 0x18], ecx
// 004bccbe  89481c               mov dword ptr [eax + 0x1c], ecx
// 004bccc1  33c0                 xor eax, eax
// 004bccc3  8945fc               mov dword ptr [ebp - 4], eax
// 004bccc6  894df4               mov dword ptr [ebp - 0xc], ecx
// 004bccc9  8da42400000000       lea esp, [esp]
// 004bccd0  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004bccd3  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004bccd6  c745f820000000       mov dword ptr [ebp - 8], 0x20
// 004bccdd  85db                 test ebx, ebx
// 004bccdf  0f848a000000         je 0x4bcd6f
// 004bcce5  f6c301               test bl, 1
// 004bcce8  746d                 je 0x4bcd57
// 004bccea  85c0                 test eax, eax
// 004bccec  7414                 je 0x4bcd02
// 004bccee  50                   push eax
// 004bccef  8d45cc               lea eax, [ebp - 0x34]
// 004bccf2  50                   push eax
// 004bccf3  e8e8faffff           call 0x4bc7e0
// 004bccf8  83c408               add esp, 8
// 004bccfb  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004bcd02  8d4dcc               lea ecx, [ebp - 0x34]
// 004bcd05  894dec               mov dword ptr [ebp - 0x14], ecx
// 004bcd08  c745f001000000       mov dword ptr [ebp - 0x10], 1
// 004bcd0f  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 004bcd12  8b7d08               mov edi, dword ptr [ebp + 8]
// 004bcd15  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004bcd18  8b06                 mov eax, dword ptr [esi]
// 004bcd1a  33d2                 xor edx, edx
// 004bcd1c  0107                 add dword ptr [edi], eax
// 004bcd1e  8b4604               mov eax, dword ptr [esi + 4]
// 004bcd21  114704               adc dword ptr [edi + 4], eax
// 004bcd24  8b4608               mov eax, dword ptr [esi + 8]
// 004bcd27  114708               adc dword ptr [edi + 8], eax
// 004bcd2a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bcd2d  11470c               adc dword ptr [edi + 0xc], eax
// 004bcd30  e322                 jecxz 0x4bcd54
// 004bcd32  42                   inc edx
// 004bcd33  42                   inc edx
// 004bcd34  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bcd37  1104d7               adc dword ptr [edi + edx*8], eax
// 004bcd3a  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bcd3e  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bcd42  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bcd46  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bcd4a  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bcd4e  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bcd52  e2de                 loop 0x4bcd32
// 004bcd54  8b45fc               mov eax, dword ptr [ebp - 4]
// 004bcd57  8145f8ffff0000       add dword ptr [ebp - 8], 0xffff
// 004bcd5e  d1eb                 shr ebx, 1
// 004bcd60  40                   inc eax
// 004bcd61  8945fc               mov dword ptr [ebp - 4], eax
// 004bcd64  85db                 test ebx, ebx
// 004bcd66  0f8579ffffff         jne 0x4bcce5
// 004bcd6c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004bcd6f  0fb755f8             movzx edx, word ptr [ebp - 8]
// 004bcd73  41                   inc ecx
// 004bcd74  03c2                 add eax, edx
// 004bcd76  8945fc               mov dword ptr [ebp - 4], eax
// 004bcd79  894df4               mov dword ptr [ebp - 0xc], ecx
// 004bcd7c  83f904               cmp ecx, 4
// 004bcd7f  0f824bffffff         jb 0x4bccd0
// 004bcd85  5f                   pop edi
// 004bcd86  5e                   pop esi
// 004bcd87  5b                   pop ebx
// 004bcd88  8be5                 mov esp, ebp
// 004bcd8a  5d                   pop ebp
// 004bcd8b  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY03I$$BY07I@big@@YAXAAY07IAAY03I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
