// from server: 100% by auto
// roc 2007-08 0069d300  unit: CXTPPropertyGridToolTip  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069d300
//
// 0069d300  56                   push esi
// 0069d301  8bf1                 mov esi, ecx
// 0069d303  8b06                 mov eax, dword ptr [esi]
// 0069d305  8b5078               mov edx, dword ptr [eax + 0x78]
// 0069d308  6a01                 push 1
// 0069d30a  ffd2                 call edx
// 0069d30c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0069d310  3bc1                 cmp eax, ecx
// 0069d312  750b                 jne 0x69d31f
// 0069d314  8bce                 mov ecx, esi
// 0069d316  e835fbffff           call 0x69ce50
// 0069d31b  5e                   pop esi
// 0069d31c  c20c00               ret 0xc
// 0069d31f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0069d323  51                   push ecx
// 0069d324  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069d328  50                   push eax
// 0069d329  51                   push ecx
// 0069d32a  8bce                 mov ecx, esi
// 0069d32c  e883b10900           call 0x7384b4
// 0069d331  5e                   pop esi
// 0069d332  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnVScroll@CXTPPropertyGridView@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
