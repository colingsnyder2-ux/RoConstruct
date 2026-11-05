// from server: 100% by auto
// roc 2010-06 0081bbf0  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081bbf0
//
// 0081bbf0  56                   push esi
// 0081bbf1  8bf1                 mov esi, ecx
// 0081bbf3  e890c6f8ff           call 0x7a8288
// 0081bbf8  33c0                 xor eax, eax
// 0081bbfa  c7065432a600         mov dword ptr [esi], 0xa63254
// 0081bc00  89465c               mov dword ptr [esi + 0x5c], eax
// 0081bc03  c74658080ea100       mov dword ptr [esi + 0x58], 0xa10e08
// 0081bc0a  894654               mov dword ptr [esi + 0x54], eax
// 0081bc0d  8bc6                 mov eax, esi
// 0081bc0f  5e                   pop esi
// 0081bc10  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ??0CXTPPropertyGridToolTip@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
