// from server: 100% by auto
// roc 2009-06 0078cbd0  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078cbd0
//
// 0078cbd0  56                   push esi
// 0078cbd1  8bf1                 mov esi, ecx
// 0078cbd3  e848c7f8ff           call 0x719320
// 0078cbd8  33c0                 xor eax, eax
// 0078cbda  c706d4ea8f00         mov dword ptr [esi], 0x8fead4
// 0078cbe0  89465c               mov dword ptr [esi + 0x5c], eax
// 0078cbe3  c74658e8bb8b00       mov dword ptr [esi + 0x58], 0x8bbbe8
// 0078cbea  894654               mov dword ptr [esi + 0x54], eax
// 0078cbed  8bc6                 mov eax, esi
// 0078cbef  5e                   pop esi
// 0078cbf0  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ??0CXTPPropertyGridToolTip@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
