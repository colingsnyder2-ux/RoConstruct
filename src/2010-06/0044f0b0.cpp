// from server: 100% by auto
// roc 2010-06 0044f0b0  unit: CRbxPlayDocTemplate  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f0b0
//
// 0044f0b0  55                   push ebp
// 0044f0b1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044f0b5  85ed                 test ebp, ebp
// 0044f0b7  7509                 jne 0x44f0c2
// 0044f0b9  b857000780           mov eax, 0x80070057
// 0044f0be  5d                   pop ebp
// 0044f0bf  c20c00               ret 0xc
// 0044f0c2  53                   push ebx
// 0044f0c3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044f0c6  56                   push esi
// 0044f0c7  57                   push edi
// 0044f0c8  33ff                 xor edi, edi
// 0044f0ca  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044f0cd  734e                 jae 0x44f11d
// 0044f0cf  90                   nop 
// 0044f0d0  8b33                 mov esi, dword ptr [ebx]
// 0044f0d2  85f6                 test esi, esi
// 0044f0d4  743b                 je 0x44f111
// 0044f0d6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f0da  85c0                 test eax, eax
// 0044f0dc  7410                 je 0x44f0ee
// 0044f0de  8b0e                 mov ecx, dword ptr [esi]
// 0044f0e0  51                   push ecx
// 0044f0e1  50                   push eax
// 0044f0e2  e879a2fcff           call 0x419360
// 0044f0e7  83c408               add esp, 8
// 0044f0ea  85c0                 test eax, eax
// 0044f0ec  7423                 je 0x44f111
// 0044f0ee  8b5604               mov edx, dword ptr [esi + 4]
// 0044f0f1  6a01                 push 1
// 0044f0f3  ffd2                 call edx
// 0044f0f5  8bf8                 mov edi, eax
// 0044f0f7  85ff                 test edi, edi
// 0044f0f9  7c36                 jl 0x44f131
// 0044f0fb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f0fe  6a01                 push 1
// 0044f100  ffd0                 call eax
// 0044f102  8b0e                 mov ecx, dword ptr [esi]
// 0044f104  50                   push eax
// 0044f105  51                   push ecx
// 0044f106  e8a5faffff           call 0x44ebb0
// 0044f10b  8bf8                 mov edi, eax
// 0044f10d  85ff                 test edi, edi
// 0044f10f  7c20                 jl 0x44f131
// 0044f111  83c304               add ebx, 4
// 0044f114  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044f117  72b7                 jb 0x44f0d0
// 0044f119  85ff                 test edi, edi
// 0044f11b  7c14                 jl 0x44f131
// 0044f11d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044f122  740d                 je 0x44f131
// 0044f124  8b5504               mov edx, dword ptr [ebp + 4]
// 0044f127  6a00                 push 0
// 0044f129  52                   push edx
// 0044f12a  e861feffff           call 0x44ef90
// 0044f12f  8bf8                 mov edi, eax
// 0044f131  8bc7                 mov eax, edi
// 0044f133  5f                   pop edi
// 0044f134  5e                   pop esi
// 0044f135  5b                   pop ebx
// 0044f136  5d                   pop ebp
// 0044f137  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
