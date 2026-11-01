// from server: 100% by auto
// roc 2009-12 008c6330  unit: CXTPPropertyGridInplaceButton  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6330
//
// 008c6330  8bc1                 mov eax, ecx
// 008c6332  83782c00             cmp dword ptr [eax + 0x2c], 0
// 008c6336  742f                 je 0x8c6367
// 008c6338  83785000             cmp dword ptr [eax + 0x50], 0
// 008c633c  7429                 je 0x8c6367
// 008c633e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c6342  83f920               cmp ecx, 0x20
// 008c6345  740f                 je 0x8c6356
// 008c6347  83f928               cmp ecx, 0x28
// 008c634a  740a                 je 0x8c6356
// 008c634c  83f90d               cmp ecx, 0xd
// 008c634f  7405                 je 0x8c6356
// 008c6351  83f973               cmp ecx, 0x73
// 008c6354  7511                 jne 0x8c6367
// 008c6356  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 008c6359  8b11                 mov edx, dword ptr [ecx]
// 008c635b  89442404             mov dword ptr [esp + 4], eax
// 008c635f  8b82d0000000         mov eax, dword ptr [edx + 0xd0]
// 008c6365  ffe0                 jmp eax
// 008c6367  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceButton@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
