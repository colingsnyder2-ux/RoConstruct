// from server: 100% by auto
// roc 2009-12 008c00a0  unit: CXTPShadowsManager::CShadowWnd  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c00a0
//
// 008c00a0  83ec30               sub esp, 0x30
// 008c00a3  53                   push ebx
// 008c00a4  8bd9                 mov ebx, ecx
// 008c00a6  53                   push ebx
// 008c00a7  8d4c2408             lea ecx, [esp + 8]
// 008c00ab  e8c0b1f8ff           call 0x84b270
// 008c00b0  8d442438             lea eax, [esp + 0x38]
// 008c00b4  50                   push eax
// 008c00b5  8d4c2408             lea ecx, [esp + 8]
// 008c00b9  51                   push ecx
// 008c00ba  8d54241c             lea edx, [esp + 0x1c]
// 008c00be  52                   push edx
// 008c00bf  ff15dcca9800         call dword ptr [0x98cadc]
// 008c00c5  85c0                 test eax, eax
// 008c00c7  7476                 je 0x8c013f
// 008c00c9  56                   push esi
// 008c00ca  57                   push edi
// 008c00cb  53                   push ebx
// 008c00cc  8d4c2430             lea ecx, [esp + 0x30]
// 008c00d0  e8fbb1f8ff           call 0x84b2d0
// 008c00d5  8b3dc4b09800         mov edi, dword ptr [0x98b0c4]
// 008c00db  8d44242c             lea eax, [esp + 0x2c]
// 008c00df  50                   push eax
// 008c00e0  ffd7                 call edi
// 008c00e2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008c00e6  8bf0                 mov esi, eax
// 008c00e8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c00ec  f7d9                 neg ecx
// 008c00ee  51                   push ecx
// 008c00ef  f7d8                 neg eax
// 008c00f1  50                   push eax
// 008c00f2  8d4c2424             lea ecx, [esp + 0x24]
// 008c00f6  51                   push ecx
// 008c00f7  ff156ccc9800         call dword ptr [0x98cc6c]
// 008c00fd  8d54241c             lea edx, [esp + 0x1c]
// 008c0101  52                   push edx
// 008c0102  ffd7                 call edi
// 008c0104  6a04                 push 4
// 008c0106  8bf8                 mov edi, eax
// 008c0108  57                   push edi
// 008c0109  56                   push esi
// 008c010a  56                   push esi
// 008c010b  ff15acb09800         call dword ptr [0x98b0ac]
// 008c0111  57                   push edi
// 008c0112  8b3d3cb19800         mov edi, dword ptr [0x98b13c]
// 008c0118  ffd7                 call edi
// 008c011a  8b4320               mov eax, dword ptr [ebx + 0x20]
// 008c011d  6a00                 push 0
// 008c011f  56                   push esi
// 008c0120  50                   push eax
// 008c0121  ff1554cb9800         call dword ptr [0x98cb54]
// 008c0127  85c0                 test eax, eax
// 008c0129  7503                 jne 0x8c012e
// 008c012b  56                   push esi
// 008c012c  ffd7                 call edi
// 008c012e  5f                   pop edi
// 008c012f  b801000000           mov eax, 1
// 008c0134  5e                   pop esi
// 008c0135  894360               mov dword ptr [ebx + 0x60], eax
// 008c0138  5b                   pop ebx
// 008c0139  83c430               add esp, 0x30
// 008c013c  c21000               ret 0x10
// 008c013f  b801000000           mov eax, 1
// 008c0144  5b                   pop ebx
// 008c0145  83c430               add esp, 0x30
// 008c0148  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?ExcludeRect@CShadowWnd@CXTPShadowManager@@QAEHVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
