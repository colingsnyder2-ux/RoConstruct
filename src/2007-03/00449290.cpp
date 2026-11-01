// from server: 100% by auto
// roc 2007-03 00449290  unit: seg_00440000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00449290
//
// 00449290  55                   push ebp
// 00449291  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00449295  85ed                 test ebp, ebp
// 00449297  7509                 jne 0x4492a2
// 00449299  b857000780           mov eax, 0x80070057
// 0044929e  5d                   pop ebp
// 0044929f  c20c00               ret 0xc
// 004492a2  53                   push ebx
// 004492a3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004492a6  56                   push esi
// 004492a7  57                   push edi
// 004492a8  33ff                 xor edi, edi
// 004492aa  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 004492ad  734e                 jae 0x4492fd
// 004492af  90                   nop 
// 004492b0  8b33                 mov esi, dword ptr [ebx]
// 004492b2  85f6                 test esi, esi
// 004492b4  743b                 je 0x4492f1
// 004492b6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004492ba  85c0                 test eax, eax
// 004492bc  7410                 je 0x4492ce
// 004492be  8b0e                 mov ecx, dword ptr [esi]
// 004492c0  51                   push ecx
// 004492c1  50                   push eax
// 004492c2  e88928feff           call 0x42bb50
// 004492c7  83c408               add esp, 8
// 004492ca  85c0                 test eax, eax
// 004492cc  7423                 je 0x4492f1
// 004492ce  8b5604               mov edx, dword ptr [esi + 4]
// 004492d1  6a01                 push 1
// 004492d3  ffd2                 call edx
// 004492d5  8bf8                 mov edi, eax
// 004492d7  85ff                 test edi, edi
// 004492d9  7c36                 jl 0x449311
// 004492db  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004492de  6a01                 push 1
// 004492e0  ffd0                 call eax
// 004492e2  8b0e                 mov ecx, dword ptr [esi]
// 004492e4  50                   push eax
// 004492e5  51                   push ecx
// 004492e6  e8e5f6ffff           call 0x4489d0
// 004492eb  8bf8                 mov edi, eax
// 004492ed  85ff                 test edi, edi
// 004492ef  7c20                 jl 0x449311
// 004492f1  83c304               add ebx, 4
// 004492f4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 004492f7  72b7                 jb 0x4492b0
// 004492f9  85ff                 test edi, edi
// 004492fb  7c14                 jl 0x449311
// 004492fd  837c241800           cmp dword ptr [esp + 0x18], 0
// 00449302  740d                 je 0x449311
// 00449304  8b5504               mov edx, dword ptr [ebp + 4]
// 00449307  6a00                 push 0
// 00449309  52                   push edx
// 0044930a  e841f5ffff           call 0x448850
// 0044930f  8bf8                 mov edi, eax
// 00449311  8bc7                 mov eax, edi
// 00449313  5f                   pop edi
// 00449314  5e                   pop esi
// 00449315  5b                   pop ebx
// 00449316  5d                   pop ebp
// 00449317  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
