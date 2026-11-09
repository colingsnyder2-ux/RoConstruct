// from server: 100% by auto
// roc 2007-08 0044a0a0  unit: CRobloxModule  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a0a0
//
// 0044a0a0  55                   push ebp
// 0044a0a1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044a0a5  85ed                 test ebp, ebp
// 0044a0a7  7509                 jne 0x44a0b2
// 0044a0a9  b857000780           mov eax, 0x80070057
// 0044a0ae  5d                   pop ebp
// 0044a0af  c20c00               ret 0xc
// 0044a0b2  53                   push ebx
// 0044a0b3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044a0b6  56                   push esi
// 0044a0b7  57                   push edi
// 0044a0b8  33ff                 xor edi, edi
// 0044a0ba  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044a0bd  734e                 jae 0x44a10d
// 0044a0bf  90                   nop 
// 0044a0c0  8b33                 mov esi, dword ptr [ebx]
// 0044a0c2  85f6                 test esi, esi
// 0044a0c4  743b                 je 0x44a101
// 0044a0c6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044a0ca  85c0                 test eax, eax
// 0044a0cc  7410                 je 0x44a0de
// 0044a0ce  8b0e                 mov ecx, dword ptr [esi]
// 0044a0d0  51                   push ecx
// 0044a0d1  50                   push eax
// 0044a0d2  e8f907feff           call 0x42a8d0
// 0044a0d7  83c408               add esp, 8
// 0044a0da  85c0                 test eax, eax
// 0044a0dc  7423                 je 0x44a101
// 0044a0de  8b5604               mov edx, dword ptr [esi + 4]
// 0044a0e1  6a01                 push 1
// 0044a0e3  ffd2                 call edx
// 0044a0e5  8bf8                 mov edi, eax
// 0044a0e7  85ff                 test edi, edi
// 0044a0e9  7c36                 jl 0x44a121
// 0044a0eb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044a0ee  6a01                 push 1
// 0044a0f0  ffd0                 call eax
// 0044a0f2  8b0e                 mov ecx, dword ptr [esi]
// 0044a0f4  50                   push eax
// 0044a0f5  51                   push ecx
// 0044a0f6  e885f3ffff           call 0x449480
// 0044a0fb  8bf8                 mov edi, eax
// 0044a0fd  85ff                 test edi, edi
// 0044a0ff  7c20                 jl 0x44a121
// 0044a101  83c304               add ebx, 4
// 0044a104  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044a107  72b7                 jb 0x44a0c0
// 0044a109  85ff                 test edi, edi
// 0044a10b  7c14                 jl 0x44a121
// 0044a10d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044a112  740d                 je 0x44a121
// 0044a114  8b5504               mov edx, dword ptr [ebp + 4]
// 0044a117  6a00                 push 0
// 0044a119  52                   push edx
// 0044a11a  e8e1f1ffff           call 0x449300
// 0044a11f  8bf8                 mov edi, eax
// 0044a121  8bc7                 mov eax, edi
// 0044a123  5f                   pop edi
// 0044a124  5e                   pop esi
// 0044a125  5b                   pop ebx
// 0044a126  5d                   pop ebp
// 0044a127  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
