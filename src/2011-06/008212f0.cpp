// from server: 100% by auto
// roc 2011-06 008212f0  unit: CXTPImageManagerResource::CBitmapDC  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008212f0
//
// 008212f0  83ec0c               sub esp, 0xc
// 008212f3  53                   push ebx
// 008212f4  55                   push ebp
// 008212f5  56                   push esi
// 008212f6  8d442420             lea eax, [esp + 0x20]
// 008212fa  50                   push eax
// 008212fb  8d542414             lea edx, [esp + 0x14]
// 008212ff  52                   push edx
// 00821300  8d44241c             lea eax, [esp + 0x1c]
// 00821304  50                   push eax
// 00821305  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00821309  8d542418             lea edx, [esp + 0x18]
// 0082130d  52                   push edx
// 0082130e  33f6                 xor esi, esi
// 00821310  50                   push eax
// 00821311  89742420             mov dword ptr [esp + 0x20], esi
// 00821315  89742424             mov dword ptr [esp + 0x24], esi
// 00821319  e892fcffff           call 0x820fb0
// 0082131e  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00821322  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00821326  85c0                 test eax, eax
// 00821328  7432                 je 0x82135c
// 0082132a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0082132e  57                   push edi
// 0082132f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00821333  57                   push edi
// 00821334  8bce                 mov ecx, esi
// 00821336  e8bd98feff           call 0x80abf8
// 0082133b  57                   push edi
// 0082133c  55                   push ebp
// 0082133d  8bce                 mov ecx, esi
// 0082133f  e89c98feff           call 0x80abe0
// 00821344  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00821348  57                   push edi
// 00821349  8bce                 mov ecx, esi
// 0082134b  e8a898feff           call 0x80abf8
// 00821350  57                   push edi
// 00821351  53                   push ebx
// 00821352  8bce                 mov ecx, esi
// 00821354  e88798feff           call 0x80abe0
// 00821359  5f                   pop edi
// 0082135a  eb0a                 jmp 0x821366
// 0082135c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00821360  56                   push esi
// 00821361  e89298feff           call 0x80abf8
// 00821366  8b35740aa400         mov esi, dword ptr [0xa40a74]
// 0082136c  85db                 test ebx, ebx
// 0082136e  7406                 je 0x821376
// 00821370  53                   push ebx
// 00821371  ffd6                 call esi
// 00821373  83c404               add esp, 4
// 00821376  85ed                 test ebp, ebp
// 00821378  7406                 je 0x821380
// 0082137a  55                   push ebp
// 0082137b  ffd6                 call esi
// 0082137d  83c404               add esp, 4
// 00821380  5e                   pop esi
// 00821381  5d                   pop ebp
// 00821382  5b                   pop ebx
// 00821383  83c40c               add esp, 0xc
// 00821386  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?WriteDIBBitmap@CXTPImageManagerIcon@@AAEXAAVCArchive@@PAUHBITMAP__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPImageManager.cpp
