// from server: 100% by auto
// roc 2010-06 00874360  unit: CXTPShadowsManager::CShadowWnd  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00874360
//
// 00874360  83ec30               sub esp, 0x30
// 00874363  53                   push ebx
// 00874364  8bd9                 mov ebx, ecx
// 00874366  53                   push ebx
// 00874367  8d4c2408             lea ecx, [esp + 8]
// 0087436b  e840aff8ff           call 0x7ff2b0
// 00874370  8d442438             lea eax, [esp + 0x38]
// 00874374  50                   push eax
// 00874375  8d4c2408             lea ecx, [esp + 8]
// 00874379  51                   push ecx
// 0087437a  8d54241c             lea edx, [esp + 0x1c]
// 0087437e  52                   push edx
// 0087437f  ff15a4ba9e00         call dword ptr [0x9ebaa4]
// 00874385  85c0                 test eax, eax
// 00874387  7476                 je 0x8743ff
// 00874389  56                   push esi
// 0087438a  57                   push edi
// 0087438b  53                   push ebx
// 0087438c  8d4c2430             lea ecx, [esp + 0x30]
// 00874390  e87baff8ff           call 0x7ff310
// 00874395  8b3d0ca19e00         mov edi, dword ptr [0x9ea10c]
// 0087439b  8d44242c             lea eax, [esp + 0x2c]
// 0087439f  50                   push eax
// 008743a0  ffd7                 call edi
// 008743a2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008743a6  8bf0                 mov esi, eax
// 008743a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008743ac  f7d9                 neg ecx
// 008743ae  51                   push ecx
// 008743af  f7d8                 neg eax
// 008743b1  50                   push eax
// 008743b2  8d4c2424             lea ecx, [esp + 0x24]
// 008743b6  51                   push ecx
// 008743b7  ff1540bc9e00         call dword ptr [0x9ebc40]
// 008743bd  8d54241c             lea edx, [esp + 0x1c]
// 008743c1  52                   push edx
// 008743c2  ffd7                 call edi
// 008743c4  6a04                 push 4
// 008743c6  8bf8                 mov edi, eax
// 008743c8  57                   push edi
// 008743c9  56                   push esi
// 008743ca  56                   push esi
// 008743cb  ff15f4a09e00         call dword ptr [0x9ea0f4]
// 008743d1  57                   push edi
// 008743d2  8b3dd4a09e00         mov edi, dword ptr [0x9ea0d4]
// 008743d8  ffd7                 call edi
// 008743da  8b4320               mov eax, dword ptr [ebx + 0x20]
// 008743dd  6a00                 push 0
// 008743df  56                   push esi
// 008743e0  50                   push eax
// 008743e1  ff150cba9e00         call dword ptr [0x9eba0c]
// 008743e7  85c0                 test eax, eax
// 008743e9  7503                 jne 0x8743ee
// 008743eb  56                   push esi
// 008743ec  ffd7                 call edi
// 008743ee  5f                   pop edi
// 008743ef  b801000000           mov eax, 1
// 008743f4  5e                   pop esi
// 008743f5  894360               mov dword ptr [ebx + 0x60], eax
// 008743f8  5b                   pop ebx
// 008743f9  83c430               add esp, 0x30
// 008743fc  c21000               ret 0x10
// 008743ff  b801000000           mov eax, 1
// 00874404  5b                   pop ebx
// 00874405  83c430               add esp, 0x30
// 00874408  c21000               ret 0x10
// library xtp-13.2.1/Source\Common\XTPHookManager.cpp (function ?ExcludeRect@CShadowWnd@CXTPShadowManager@@QAEHVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPHookManager.cpp
