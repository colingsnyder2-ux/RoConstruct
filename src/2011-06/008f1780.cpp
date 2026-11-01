// from server: 100% by auto
// roc 2011-06 008f1780  unit: CXTCaptionThemeOfficeXP  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f1780
//
// 008f1780  83ec10               sub esp, 0x10
// 008f1783  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008f1787  8b08                 mov ecx, dword ptr [eax]
// 008f1789  8b5004               mov edx, dword ptr [eax + 4]
// 008f178c  56                   push esi
// 008f178d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f1791  894c2404             mov dword ptr [esp + 4], ecx
// 008f1795  8b4808               mov ecx, dword ptr [eax + 8]
// 008f1798  57                   push edi
// 008f1799  8954240c             mov dword ptr [esp + 0xc], edx
// 008f179d  8b500c               mov edx, dword ptr [eax + 0xc]
// 008f17a0  894c2410             mov dword ptr [esp + 0x10], ecx
// 008f17a4  6a01                 push 1
// 008f17a6  8bce                 mov ecx, esi
// 008f17a8  89542418             mov dword ptr [esp + 0x18], edx
// 008f17ac  e83dae0d00           call 0x9cc5ee
// 008f17b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f17b5  8b4770               mov eax, dword ptr [edi + 0x70]
// 008f17b8  50                   push eax
// 008f17b9  8d4c240c             lea ecx, [esp + 0xc]
// 008f17bd  51                   push ecx
// 008f17be  8bce                 mov ecx, esi
// 008f17c0  e85b96f1ff           call 0x80ae20
// 008f17c5  80bf8100000000       cmp byte ptr [edi + 0x81], 0
// 008f17cc  7534                 jne 0x8f1802
// 008f17ce  e80d3cf5ff           call 0x8453e0
// 008f17d3  6a10                 push 0x10
// 008f17d5  8bc8                 mov ecx, eax
// 008f17d7  e8d433f5ff           call 0x844bb0
// 008f17dc  8bf8                 mov edi, eax
// 008f17de  e8fd3bf5ff           call 0x8453e0
// 008f17e3  6a14                 push 0x14
// 008f17e5  8bc8                 mov ecx, eax
// 008f17e7  e8c433f5ff           call 0x844bb0
// 008f17ec  57                   push edi
// 008f17ed  50                   push eax
// 008f17ee  8d542410             lea edx, [esp + 0x10]
// 008f17f2  52                   push edx
// 008f17f3  8bce                 mov ecx, esi
// 008f17f5  e82096f1ff           call 0x80ae1a
// 008f17fa  5f                   pop edi
// 008f17fb  5e                   pop esi
// 008f17fc  83c410               add esp, 0x10
// 008f17ff  c20c00               ret 0xc
// 008f1802  8b476c               mov eax, dword ptr [edi + 0x6c]
// 008f1805  f7d8                 neg eax
// 008f1807  50                   push eax
// 008f1808  50                   push eax
// 008f1809  8d442410             lea eax, [esp + 0x10]
// 008f180d  50                   push eax
// 008f180e  ff15e41ba400         call dword ptr [0xa41be4]
// 008f1814  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 008f1817  51                   push ecx
// 008f1818  8d54240c             lea edx, [esp + 0xc]
// 008f181c  52                   push edx
// 008f181d  8bce                 mov ecx, esi
// 008f181f  e8fc95f1ff           call 0x80ae20
// 008f1824  5f                   pop edi
// 008f1825  5e                   pop esi
// 008f1826  83c410               add esp, 0x10
// 008f1829  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOfficeXP@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
