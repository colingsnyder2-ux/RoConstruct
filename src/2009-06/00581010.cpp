// from server: 100% by auto
// roc 2009-06 00581010  unit: seg_00580000  size: 459 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581010
//
// 00581010  83ec08               sub esp, 8
// 00581013  55                   push ebp
// 00581014  57                   push edi
// 00581015  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00581019  85ff                 test edi, edi
// 0058101b  0f84b2010000         je 0x5811d3
// 00581021  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00581025  85ed                 test ebp, ebp
// 00581027  0f84a6010000         je 0x5811d3
// 0058102d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00581031  85c9                 test ecx, ecx
// 00581033  0f849a010000         je 0x5811d3
// 00581039  8b4530               mov eax, dword ptr [ebp + 0x30]
// 0058103c  53                   push ebx
// 0058103d  56                   push esi
// 0058103e  8b7534               mov esi, dword ptr [ebp + 0x34]
// 00581041  03c1                 add eax, ecx
// 00581043  3bc6                 cmp eax, esi
// 00581045  7e7a                 jle 0x5810c1
// 00581047  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 0058104a  85db                 test ebx, ebx
// 0058104c  7448                 je 0x581096
// 0058104e  83c008               add eax, 8
// 00581051  894534               mov dword ptr [ebp + 0x34], eax
// 00581054  c1e004               shl eax, 4
// 00581057  50                   push eax
// 00581058  57                   push edi
// 00581059  e882dc0000           call 0x58ece0
// 0058105e  83c408               add esp, 8
// 00581061  894538               mov dword ptr [ebp + 0x38], eax
// 00581064  85c0                 test eax, eax
// 00581066  7517                 jne 0x58107f
// 00581068  53                   push ebx
// 00581069  57                   push edi
// 0058106a  e841dc0000           call 0x58ecb0
// 0058106f  83c408               add esp, 8
// 00581072  5e                   pop esi
// 00581073  5b                   pop ebx
// 00581074  5f                   pop edi
// 00581075  b801000000           mov eax, 1
// 0058107a  5d                   pop ebp
// 0058107b  83c408               add esp, 8
// 0058107e  c3                   ret 
// 0058107f  c1e604               shl esi, 4
// 00581082  56                   push esi
// 00581083  53                   push ebx
// 00581084  50                   push eax
// 00581085  e82c8e1900           call 0x719eb6
// 0058108a  53                   push ebx
// 0058108b  57                   push edi
// 0058108c  e81fdc0000           call 0x58ecb0
// 00581091  83c414               add esp, 0x14
// 00581094  eb2b                 jmp 0x5810c1
// 00581096  83c108               add ecx, 8
// 00581099  894d34               mov dword ptr [ebp + 0x34], ecx
// 0058109c  c1e104               shl ecx, 4
// 0058109f  51                   push ecx
// 005810a0  57                   push edi
// 005810a1  c7453000000000       mov dword ptr [ebp + 0x30], 0
// 005810a8  e833dc0000           call 0x58ece0
// 005810ad  83c408               add esp, 8
// 005810b0  894538               mov dword ptr [ebp + 0x38], eax
// 005810b3  85c0                 test eax, eax
// 005810b5  74bb                 je 0x581072
// 005810b7  818db800000000400000 or dword ptr [ebp + 0xb8], 0x4000
// 005810c1  837c242800           cmp dword ptr [esp + 0x28], 0
// 005810c6  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005810ce  0f8ef5000000         jle 0x5811c9
// 005810d4  8b542424             mov edx, dword ptr [esp + 0x24]
// 005810d8  83c208               add edx, 8
// 005810db  89542410             mov dword ptr [esp + 0x10], edx
// 005810df  90                   nop 
// 005810e0  8b7530               mov esi, dword ptr [ebp + 0x30]
// 005810e3  8b42fc               mov eax, dword ptr [edx - 4]
// 005810e6  c1e604               shl esi, 4
// 005810e9  037538               add esi, dword ptr [ebp + 0x38]
// 005810ec  85c0                 test eax, eax
// 005810ee  0f84bb000000         je 0x5811af
// 005810f4  8d5801               lea ebx, [eax + 1]
// 005810f7  8a08                 mov cl, byte ptr [eax]
// 005810f9  40                   inc eax
// 005810fa  84c9                 test cl, cl
// 005810fc  75f9                 jne 0x5810f7
// 005810fe  8b4af8               mov ecx, dword ptr [edx - 8]
// 00581101  2bc3                 sub eax, ebx
// 00581103  8bd8                 mov ebx, eax
// 00581105  85c9                 test ecx, ecx
// 00581107  0f8f90000000         jg 0x58119d
// 0058110d  8b3a                 mov edi, dword ptr [edx]
// 0058110f  85ff                 test edi, edi
// 00581111  741a                 je 0x58112d
// 00581113  803f00               cmp byte ptr [edi], 0
// 00581116  7415                 je 0x58112d
// 00581118  8d5701               lea edx, [edi + 1]
// 0058111b  eb03                 jmp 0x581120
// 0058111d  8d4900               lea ecx, [ecx]
// 00581120  8a07                 mov al, byte ptr [edi]
// 00581122  47                   inc edi
// 00581123  84c0                 test al, al
// 00581125  75f9                 jne 0x581120
// 00581127  2bfa                 sub edi, edx
// 00581129  890e                 mov dword ptr [esi], ecx
// 0058112b  eb08                 jmp 0x581135
// 0058112d  33ff                 xor edi, edi
// 0058112f  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 00581135  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00581139  8d541f04             lea edx, [edi + ebx + 4]
// 0058113d  52                   push edx
// 0058113e  50                   push eax
// 0058113f  e89cdb0000           call 0x58ece0
// 00581144  83c408               add esp, 8
// 00581147  894604               mov dword ptr [esi + 4], eax
// 0058114a  85c0                 test eax, eax
// 0058114c  0f8420ffffff         je 0x581072
// 00581152  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00581156  8b51fc               mov edx, dword ptr [ecx - 4]
// 00581159  53                   push ebx
// 0058115a  52                   push edx
// 0058115b  50                   push eax
// 0058115c  e8558d1900           call 0x719eb6
// 00581161  8b4604               mov eax, dword ptr [esi + 4]
// 00581164  c6040300             mov byte ptr [ebx + eax], 0
// 00581168  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058116b  83c40c               add esp, 0xc
// 0058116e  8d5c0b01             lea ebx, [ebx + ecx + 1]
// 00581172  895e08               mov dword ptr [esi + 8], ebx
// 00581175  85ff                 test edi, edi
// 00581177  7411                 je 0x58118a
// 00581179  8b542410             mov edx, dword ptr [esp + 0x10]
// 0058117d  8b02                 mov eax, dword ptr [edx]
// 0058117f  57                   push edi
// 00581180  50                   push eax
// 00581181  53                   push ebx
// 00581182  e82f8d1900           call 0x719eb6
// 00581187  83c40c               add esp, 0xc
// 0058118a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0058118d  c6040f00             mov byte ptr [edi + ecx], 0
// 00581191  897e0c               mov dword ptr [esi + 0xc], edi
// 00581194  ff4530               inc dword ptr [ebp + 0x30]
// 00581197  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0058119b  eb0e                 jmp 0x5811ab
// 0058119d  684cc88c00           push 0x8cc84c
// 005811a2  57                   push edi
// 005811a3  e868d00000           call 0x58e210
// 005811a8  83c408               add esp, 8
// 005811ab  8b542410             mov edx, dword ptr [esp + 0x10]
// 005811af  8b442414             mov eax, dword ptr [esp + 0x14]
// 005811b3  40                   inc eax
// 005811b4  83c210               add edx, 0x10
// 005811b7  3b442428             cmp eax, dword ptr [esp + 0x28]
// 005811bb  89442414             mov dword ptr [esp + 0x14], eax
// 005811bf  89542410             mov dword ptr [esp + 0x10], edx
// 005811c3  0f8c17ffffff         jl 0x5810e0
// 005811c9  5e                   pop esi
// 005811ca  5b                   pop ebx
// 005811cb  5f                   pop edi
// 005811cc  33c0                 xor eax, eax
// 005811ce  5d                   pop ebp
// 005811cf  83c408               add esp, 8
// 005811d2  c3                   ret 
// 005811d3  5f                   pop edi
// 005811d4  33c0                 xor eax, eax
// 005811d6  5d                   pop ebp
// 005811d7  83c408               add esp, 8
// 005811da  c3                   ret 
// library libpng-1.2.18/pngset.c (function _png_set_text_2)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngset.c
