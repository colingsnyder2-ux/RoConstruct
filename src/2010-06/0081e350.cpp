// from server: 100% by auto
// roc 2010-06 0081e350  unit: CXTPPropertyGridToolTip  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e350
//
// 0081e350  56                   push esi
// 0081e351  8bf1                 mov esi, ecx
// 0081e353  8b06                 mov eax, dword ptr [esi]
// 0081e355  8b9080000000         mov edx, dword ptr [eax + 0x80]
// 0081e35b  6a01                 push 1
// 0081e35d  ffd2                 call edx
// 0081e35f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0081e363  3bc1                 cmp eax, ecx
// 0081e365  750b                 jne 0x81e372
// 0081e367  8bce                 mov ecx, esi
// 0081e369  e8d2fbffff           call 0x81df40
// 0081e36e  5e                   pop esi
// 0081e36f  c20c00               ret 0xc
// 0081e372  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0081e376  51                   push ecx
// 0081e377  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0081e37b  50                   push eax
// 0081e37c  51                   push ecx
// 0081e37d  8bce                 mov ecx, esi
// 0081e37f  e8c2eb1500           call 0x97cf46
// 0081e384  5e                   pop esi
// 0081e385  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnVScroll@CXTPPropertyGridView@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridView.cpp
