// from server: 100% by auto
// roc 2009-06 00733250  unit: CXTPImageManagerResource::CBitmapDC  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00733250
//
// 00733250  83ec0c               sub esp, 0xc
// 00733253  56                   push esi
// 00733254  8bf1                 mov esi, ecx
// 00733256  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00733259  f7d8                 neg eax
// 0073325b  1bc0                 sbb eax, eax
// 0073325d  89442404             mov dword ptr [esp + 4], eax
// 00733261  742b                 je 0x73328e
// 00733263  57                   push edi
// 00733264  8d7e10               lea edi, [esi + 0x10]
// 00733267  8d44240c             lea eax, [esp + 0xc]
// 0073326b  50                   push eax
// 0073326c  8d4c2414             lea ecx, [esp + 0x14]
// 00733270  51                   push ecx
// 00733271  8d542410             lea edx, [esp + 0x10]
// 00733275  52                   push edx
// 00733276  8bcf                 mov ecx, edi
// 00733278  e8f3fd0500           call 0x793070
// 0073327d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00733281  e8225dfeff           call 0x718fa8
// 00733286  837c240800           cmp dword ptr [esp + 8], 0
// 0073328b  75da                 jne 0x733267
// 0073328d  5f                   pop edi
// 0073328e  8d4e10               lea ecx, [esi + 0x10]
// 00733291  5e                   pop esi
// 00733292  83c40c               add esp, 0xc
// 00733295  e9e6f3ffff           jmp 0x732680
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerImageList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
