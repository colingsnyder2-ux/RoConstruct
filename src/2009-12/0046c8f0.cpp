// from server: 100% by auto
// roc 2009-12 0046c8f0  unit: Scintilla::CScintillaView  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046c8f0
//
// 0046c8f0  83ec18               sub esp, 0x18
// 0046c8f3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046c8f7  8b5004               mov edx, dword ptr [eax + 4]
// 0046c8fa  56                   push esi
// 0046c8fb  8bf1                 mov esi, ecx
// 0046c8fd  8b08                 mov ecx, dword ptr [eax]
// 0046c8ff  8d44240c             lea eax, [esp + 0xc]
// 0046c903  894c2404             mov dword ptr [esp + 4], ecx
// 0046c907  50                   push eax
// 0046c908  8d4c2408             lea ecx, [esp + 8]
// 0046c90c  8954240c             mov dword ptr [esp + 0xc], edx
// 0046c910  e8fbe9ffff           call 0x46b310
// 0046c915  84c0                 test al, al
// 0046c917  7420                 je 0x46c939
// 0046c919  8d4c240c             lea ecx, [esp + 0xc]
// 0046c91d  56                   push esi
// 0046c91e  51                   push ecx
// 0046c91f  e83ce9ffff           call 0x46b260
// 0046c924  83c408               add esp, 8
// 0046c927  85c0                 test eax, eax
// 0046c929  740e                 je 0x46c939
// 0046c92b  33c0                 xor eax, eax
// 0046c92d  894608               mov dword ptr [esi + 8], eax
// 0046c930  8bc6                 mov eax, esi
// 0046c932  5e                   pop esi
// 0046c933  83c418               add esp, 0x18
// 0046c936  c20400               ret 4
// 0046c939  b801000000           mov eax, 1
// 0046c93e  894608               mov dword ptr [esi + 8], eax
// 0046c941  8bc6                 mov eax, esi
// 0046c943  5e                   pop esi
// 0046c944  83c418               add esp, 0x18
// 0046c947  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxshelllistctrl.cpp (function ??4COleDateTime@ATL@@QAEAAV01@AB_J@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxshelllistctrl.cpp
