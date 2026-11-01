// from server: 100% by auto
// roc 2011-06 00878920  unit: CXTPPropertyGridToolTip  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00878920
//
// 00878920  56                   push esi
// 00878921  8bf1                 mov esi, ecx
// 00878923  8b06                 mov eax, dword ptr [esi]
// 00878925  8b9080000000         mov edx, dword ptr [eax + 0x80]
// 0087892b  6a01                 push 1
// 0087892d  ffd2                 call edx
// 0087892f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00878933  3bc1                 cmp eax, ecx
// 00878935  750b                 jne 0x878942
// 00878937  8bce                 mov ecx, esi
// 00878939  e872fbffff           call 0x8784b0
// 0087893e  5e                   pop esi
// 0087893f  c20c00               ret 0xc
// 00878942  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00878946  51                   push ecx
// 00878947  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0087894b  50                   push eax
// 0087894c  51                   push ecx
// 0087894d  8bce                 mov ecx, esi
// 0087894f  e80e3e1500           call 0x9cc762
// 00878954  5e                   pop esi
// 00878955  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnVScroll@CXTPPropertyGridView@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridView.cpp
