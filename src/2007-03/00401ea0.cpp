// from server: 100% by auto
// roc 2007-03 00401ea0  unit: seg_00400000  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401ea0
//
// 00401ea0  f6059c538b0001       test byte ptr [0x8b539c], 1
// 00401ea7  7553                 jne 0x401efc
// 00401ea9  830d9c538b0001       or dword ptr [0x8b539c], 1
// 00401eb0  c7057c538b00383a7800 mov dword ptr [0x8b537c], 0x783a38
// 00401eba  66c70580538b000800   mov word ptr [0x8b5380], 8
// 00401ec3  c70584538b00343a7800 mov dword ptr [0x8b5384], 0x783a34
// 00401ecd  66c70588538b000840   mov word ptr [0x8b5388], 0x4008
// 00401ed6  c7058c538b00303a7800 mov dword ptr [0x8b538c], 0x783a30
// 00401ee0  66c70590538b001300   mov word ptr [0x8b5390], 0x13
// 00401ee9  c70594538b002c3a7800 mov dword ptr [0x8b5394], 0x783a2c
// 00401ef3  66c70598538b001100   mov word ptr [0x8b5398], 0x11
// 00401efc  53                   push ebx
// 00401efd  8b1db0d27700         mov ebx, dword ptr [0x77d2b0]
// 00401f03  56                   push esi
// 00401f04  57                   push edi
// 00401f05  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401f09  33f6                 xor esi, esi
// 00401f0b  eb03                 jmp 0x401f10
// 00401f0d  8d4900               lea ecx, [ecx]
// 00401f10  8b04f57c538b00       mov eax, dword ptr [esi*8 + 0x8b537c]
// 00401f17  50                   push eax
// 00401f18  57                   push edi
// 00401f19  ffd3                 call ebx
// 00401f1b  85c0                 test eax, eax
// 00401f1d  740e                 je 0x401f2d
// 00401f1f  83c601               add esi, 1
// 00401f22  83fe04               cmp esi, 4
// 00401f25  7ce9                 jl 0x401f10
// 00401f27  5f                   pop edi
// 00401f28  5e                   pop esi
// 00401f29  33c0                 xor eax, eax
// 00401f2b  5b                   pop ebx
// 00401f2c  c3                   ret 
// 00401f2d  668b0cf580538b00     mov cx, word ptr [esi*8 + 0x8b5380]
// 00401f35  8b542414             mov edx, dword ptr [esp + 0x14]
// 00401f39  5f                   pop edi
// 00401f3a  5e                   pop esi
// 00401f3b  66890a               mov word ptr [edx], cx
// 00401f3e  b801000000           mov eax, 1
// 00401f43  5b                   pop ebx
// 00401f44  c3                   ret 
// library atl-8.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
