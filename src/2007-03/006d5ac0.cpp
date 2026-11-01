// from server: 100% by auto
// roc 2007-03 006d5ac0  unit: seg_006d0000  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d5ac0
//
// 006d5ac0  83ec10               sub esp, 0x10
// 006d5ac3  56                   push esi
// 006d5ac4  8b742418             mov esi, dword ptr [esp + 0x18]
// 006d5ac8  57                   push edi
// 006d5ac9  8d442408             lea eax, [esp + 8]
// 006d5acd  56                   push esi
// 006d5ace  50                   push eax
// 006d5acf  e81c12fbff           call 0x686cf0
// 006d5ad4  8bc8                 mov ecx, eax
// 006d5ad6  e8750dfbff           call 0x686850
// 006d5adb  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d5adf  2b4604               sub eax, dword ptr [esi + 4]
// 006d5ae2  8b3d58ed7700         mov edi, dword ptr [0x77ed58]
// 006d5ae8  83f80a               cmp eax, 0xa
// 006d5aeb  7d09                 jge 0x6d5af6
// 006d5aed  83c0f6               add eax, -0xa
// 006d5af0  50                   push eax
// 006d5af1  6a00                 push 0
// 006d5af3  56                   push esi
// 006d5af4  ffd7                 call edi
// 006d5af6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006d5af9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006d5afd  8bd1                 mov edx, ecx
// 006d5aff  2bd0                 sub edx, eax
// 006d5b01  83fa0a               cmp edx, 0xa
// 006d5b04  7d0b                 jge 0x6d5b11
// 006d5b06  2bc1                 sub eax, ecx
// 006d5b08  83c00a               add eax, 0xa
// 006d5b0b  50                   push eax
// 006d5b0c  6a00                 push 0
// 006d5b0e  56                   push esi
// 006d5b0f  ffd7                 call edi
// 006d5b11  8b442410             mov eax, dword ptr [esp + 0x10]
// 006d5b15  2b06                 sub eax, dword ptr [esi]
// 006d5b17  83f80a               cmp eax, 0xa
// 006d5b1a  7d09                 jge 0x6d5b25
// 006d5b1c  6a00                 push 0
// 006d5b1e  83c0f6               add eax, -0xa
// 006d5b21  50                   push eax
// 006d5b22  56                   push esi
// 006d5b23  ffd7                 call edi
// 006d5b25  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d5b28  8b442408             mov eax, dword ptr [esp + 8]
// 006d5b2c  8bd1                 mov edx, ecx
// 006d5b2e  2bd0                 sub edx, eax
// 006d5b30  83fa0a               cmp edx, 0xa
// 006d5b33  7d0b                 jge 0x6d5b40
// 006d5b35  2bc1                 sub eax, ecx
// 006d5b37  6a00                 push 0
// 006d5b39  83c00a               add eax, 0xa
// 006d5b3c  50                   push eax
// 006d5b3d  56                   push esi
// 006d5b3e  ffd7                 call edi
// 006d5b40  5f                   pop edi
// 006d5b41  5e                   pop esi
// 006d5b42  83c410               add esp, 0x10
// 006d5b45  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ?EnsureVisible@CXTPDockingPaneContext@@SAXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
