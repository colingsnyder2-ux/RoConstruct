// from server: 100% by auto
// roc 2007-08 0044a130  unit: CRobloxModule  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a130
//
// 0044a130  55                   push ebp
// 0044a131  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044a135  85ed                 test ebp, ebp
// 0044a137  7509                 jne 0x44a142
// 0044a139  b857000780           mov eax, 0x80070057
// 0044a13e  5d                   pop ebp
// 0044a13f  c20c00               ret 0xc
// 0044a142  53                   push ebx
// 0044a143  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044a146  56                   push esi
// 0044a147  57                   push edi
// 0044a148  33ff                 xor edi, edi
// 0044a14a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044a14d  734e                 jae 0x44a19d
// 0044a14f  90                   nop 
// 0044a150  8b33                 mov esi, dword ptr [ebx]
// 0044a152  85f6                 test esi, esi
// 0044a154  743b                 je 0x44a191
// 0044a156  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044a15a  85c0                 test eax, eax
// 0044a15c  7410                 je 0x44a16e
// 0044a15e  8b0e                 mov ecx, dword ptr [esi]
// 0044a160  51                   push ecx
// 0044a161  50                   push eax
// 0044a162  e86907feff           call 0x42a8d0
// 0044a167  83c408               add esp, 8
// 0044a16a  85c0                 test eax, eax
// 0044a16c  7423                 je 0x44a191
// 0044a16e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0044a171  6a00                 push 0
// 0044a173  ffd2                 call edx
// 0044a175  50                   push eax
// 0044a176  8b06                 mov eax, dword ptr [esi]
// 0044a178  50                   push eax
// 0044a179  e802f3ffff           call 0x449480
// 0044a17e  8bf8                 mov edi, eax
// 0044a180  85ff                 test edi, edi
// 0044a182  7c2d                 jl 0x44a1b1
// 0044a184  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044a187  6a00                 push 0
// 0044a189  ffd1                 call ecx
// 0044a18b  8bf8                 mov edi, eax
// 0044a18d  85ff                 test edi, edi
// 0044a18f  7c20                 jl 0x44a1b1
// 0044a191  83c304               add ebx, 4
// 0044a194  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044a197  72b7                 jb 0x44a150
// 0044a199  85ff                 test edi, edi
// 0044a19b  7c14                 jl 0x44a1b1
// 0044a19d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044a1a2  740d                 je 0x44a1b1
// 0044a1a4  8b5504               mov edx, dword ptr [ebp + 4]
// 0044a1a7  6a00                 push 0
// 0044a1a9  52                   push edx
// 0044a1aa  e8b1f0ffff           call 0x449260
// 0044a1af  8bf8                 mov edi, eax
// 0044a1b1  8bc7                 mov eax, edi
// 0044a1b3  5f                   pop edi
// 0044a1b4  5e                   pop esi
// 0044a1b5  5b                   pop ebx
// 0044a1b6  5d                   pop ebp
// 0044a1b7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
