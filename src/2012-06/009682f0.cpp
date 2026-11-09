// roc 2012-06 009682f0  unit: RBX::CellContact  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009682f0
//
// 009682f0  56                   push esi
// 009682f1  57                   push edi
// 009682f2  e8d9f6ffff           call 0x9679d0
// 009682f7  8b06                 mov eax, dword ptr [esi]
// 009682f9  48                   dec eax
// 009682fa  83c408               add esp, 8
// 009682fd  83f80b               cmp eax, 0xb
// 00968300  776a                 ja 0x96836c
// 00968302  0fb680a4839600       movzx eax, byte ptr [eax + 0x9683a4]
// 00968309  ff248590839600       jmp dword ptr [eax*4 + 0x968390]
// 00968310  c70602000000         mov dword ptr [esi], 2
// 00968316  eb54                 jmp 0x96836c
// 00968318  c70603000000         mov dword ptr [esi], 3
// 0096831e  eb4c                 jmp 0x96836c
// 00968320  8bc6                 mov eax, esi
// 00968322  8bcf                 mov ecx, edi
// 00968324  e817f2ffff           call 0x967540
// 00968329  eb41                 jmp 0x96836c
// 0096832b  56                   push esi
// 0096832c  8bc7                 mov eax, edi
// 0096832e  e8bdf8ffff           call 0x967bf0
// 00968333  83c404               add esp, 4
// 00968336  833e0c               cmp dword ptr [esi], 0xc
// 00968339  7515                 jne 0x968350
// 0096833b  8b4608               mov eax, dword ptr [esi + 8]
// 0096833e  a900010000           test eax, 0x100
// 00968343  750b                 jne 0x968350
// 00968345  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 00968349  3bc1                 cmp eax, ecx
// 0096834b  7c03                 jl 0x968350
// 0096834d  ff4f24               dec dword ptr [edi + 0x24]
// 00968350  8b5608               mov edx, dword ptr [esi + 8]
// 00968353  6a00                 push 0
// 00968355  52                   push edx
// 00968356  6a00                 push 0
// 00968358  6a13                 push 0x13
// 0096835a  57                   push edi
// 0096835b  e8f0f3ffff           call 0x967750
// 00968360  83c414               add esp, 0x14
// 00968363  894608               mov dword ptr [esi + 8], eax
// 00968366  c7060b000000         mov dword ptr [esi], 0xb
// 0096836c  8b4614               mov eax, dword ptr [esi + 0x14]
// 0096836f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00968372  894610               mov dword ptr [esi + 0x10], eax
// 00968375  57                   push edi
// 00968376  8bc1                 mov eax, ecx
// 00968378  894e14               mov dword ptr [esi + 0x14], ecx
// 0096837b  e820edffff           call 0x9670a0
// 00968380  8b4610               mov eax, dword ptr [esi + 0x10]
// 00968383  57                   push edi
// 00968384  e817edffff           call 0x9670a0
// 00968389  83c408               add esp, 8
// 0096838c  c3                   ret 
// 0096838d  8d4900               lea ecx, [ecx]
// 00968390  108396001883         adc byte ptr [ebx - 0x7ce7ff6a], al
// 00968396  96                   xchg esi, eax
// 00968397  0020                 add byte ptr [eax], ah
// 00968399  8396002b839600       adc dword ptr [esi - 0x697cd500], 0
// 009683a0  6c                   insb byte ptr es:[edi], dx
// 009683a1  83960000010001       adc dword ptr [esi + 0x10000], 1
// 009683a8  010404               add dword ptr [esp + eax], eax
// 009683ab  0404                 add al, 4
// 009683ad  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
