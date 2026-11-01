// from server: 100% by auto
// roc 2010-06 007bf210  unit: CXTPImageManagerResource::CBitmapDC  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf210
//
// 007bf210  83ec0c               sub esp, 0xc
// 007bf213  53                   push ebx
// 007bf214  55                   push ebp
// 007bf215  56                   push esi
// 007bf216  8d442420             lea eax, [esp + 0x20]
// 007bf21a  50                   push eax
// 007bf21b  8d542414             lea edx, [esp + 0x14]
// 007bf21f  52                   push edx
// 007bf220  8d44241c             lea eax, [esp + 0x1c]
// 007bf224  50                   push eax
// 007bf225  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007bf229  8d542418             lea edx, [esp + 0x18]
// 007bf22d  52                   push edx
// 007bf22e  33f6                 xor esi, esi
// 007bf230  50                   push eax
// 007bf231  89742420             mov dword ptr [esp + 0x20], esi
// 007bf235  89742424             mov dword ptr [esp + 0x24], esi
// 007bf239  e892fcffff           call 0x7beed0
// 007bf23e  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007bf242  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007bf246  85c0                 test eax, eax
// 007bf248  7432                 je 0x7bf27c
// 007bf24a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007bf24e  57                   push edi
// 007bf24f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007bf253  57                   push edi
// 007bf254  8bce                 mov ecx, esi
// 007bf256  e8d992feff           call 0x7a8534
// 007bf25b  57                   push edi
// 007bf25c  55                   push ebp
// 007bf25d  8bce                 mov ecx, esi
// 007bf25f  e8b892feff           call 0x7a851c
// 007bf264  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007bf268  57                   push edi
// 007bf269  8bce                 mov ecx, esi
// 007bf26b  e8c492feff           call 0x7a8534
// 007bf270  57                   push edi
// 007bf271  53                   push ebx
// 007bf272  8bce                 mov ecx, esi
// 007bf274  e8a392feff           call 0x7a851c
// 007bf279  5f                   pop edi
// 007bf27a  eb0a                 jmp 0x7bf286
// 007bf27c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007bf280  56                   push esi
// 007bf281  e8ae92feff           call 0x7a8534
// 007bf286  8b3508aa9e00         mov esi, dword ptr [0x9eaa08]
// 007bf28c  85db                 test ebx, ebx
// 007bf28e  7406                 je 0x7bf296
// 007bf290  53                   push ebx
// 007bf291  ffd6                 call esi
// 007bf293  83c404               add esp, 4
// 007bf296  85ed                 test ebp, ebp
// 007bf298  7406                 je 0x7bf2a0
// 007bf29a  55                   push ebp
// 007bf29b  ffd6                 call esi
// 007bf29d  83c404               add esp, 4
// 007bf2a0  5e                   pop esi
// 007bf2a1  5d                   pop ebp
// 007bf2a2  5b                   pop ebx
// 007bf2a3  83c40c               add esp, 0xc
// 007bf2a6  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?WriteDIBBitmap@CXTPImageManagerIcon@@AAEXAAVCArchive@@PAUHBITMAP__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPImageManager.cpp
