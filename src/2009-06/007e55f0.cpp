// from server: 100% by auto
// roc 2009-06 007e55f0  unit: CXTPShadowsManager::CShadowWnd  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e55f0
//
// 007e55f0  83ec30               sub esp, 0x30
// 007e55f3  53                   push ebx
// 007e55f4  8bd9                 mov ebx, ecx
// 007e55f6  53                   push ebx
// 007e55f7  8d4c2408             lea ecx, [esp + 8]
// 007e55fb  e870aef8ff           call 0x770470
// 007e5600  8d442438             lea eax, [esp + 0x38]
// 007e5604  50                   push eax
// 007e5605  8d4c2408             lea ecx, [esp + 8]
// 007e5609  51                   push ecx
// 007e560a  8d54241c             lea edx, [esp + 0x1c]
// 007e560e  52                   push edx
// 007e560f  ff15f0ee8900         call dword ptr [0x89eef0]
// 007e5615  85c0                 test eax, eax
// 007e5617  7476                 je 0x7e568f
// 007e5619  56                   push esi
// 007e561a  57                   push edi
// 007e561b  53                   push ebx
// 007e561c  8d4c2430             lea ecx, [esp + 0x30]
// 007e5620  e8abaef8ff           call 0x7704d0
// 007e5625  8b3d80e08900         mov edi, dword ptr [0x89e080]
// 007e562b  8d44242c             lea eax, [esp + 0x2c]
// 007e562f  50                   push eax
// 007e5630  ffd7                 call edi
// 007e5632  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e5636  8bf0                 mov esi, eax
// 007e5638  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e563c  f7d9                 neg ecx
// 007e563e  51                   push ecx
// 007e563f  f7d8                 neg eax
// 007e5641  50                   push eax
// 007e5642  8d4c2424             lea ecx, [esp + 0x24]
// 007e5646  51                   push ecx
// 007e5647  ff15f8ed8900         call dword ptr [0x89edf8]
// 007e564d  8d54241c             lea edx, [esp + 0x1c]
// 007e5651  52                   push edx
// 007e5652  ffd7                 call edi
// 007e5654  6a04                 push 4
// 007e5656  8bf8                 mov edi, eax
// 007e5658  57                   push edi
// 007e5659  56                   push esi
// 007e565a  56                   push esi
// 007e565b  ff150ce18900         call dword ptr [0x89e10c]
// 007e5661  57                   push edi
// 007e5662  8b3d60e18900         mov edi, dword ptr [0x89e160]
// 007e5668  ffd7                 call edi
// 007e566a  8b4320               mov eax, dword ptr [ebx + 0x20]
// 007e566d  6a00                 push 0
// 007e566f  56                   push esi
// 007e5670  50                   push eax
// 007e5671  ff1584ec8900         call dword ptr [0x89ec84]
// 007e5677  85c0                 test eax, eax
// 007e5679  7503                 jne 0x7e567e
// 007e567b  56                   push esi
// 007e567c  ffd7                 call edi
// 007e567e  5f                   pop edi
// 007e567f  b801000000           mov eax, 1
// 007e5684  5e                   pop esi
// 007e5685  894360               mov dword ptr [ebx + 0x60], eax
// 007e5688  5b                   pop ebx
// 007e5689  83c430               add esp, 0x30
// 007e568c  c21000               ret 0x10
// 007e568f  b801000000           mov eax, 1
// 007e5694  5b                   pop ebx
// 007e5695  83c430               add esp, 0x30
// 007e5698  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?ExcludeRect@CShadowWnd@CXTPShadowManager@@QAEHVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
