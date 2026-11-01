// from server: 100% by auto
// roc 2009-06 007eb790  unit: CXTPPropertyGridInplaceButton  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007eb790
//
// 007eb790  8bc1                 mov eax, ecx
// 007eb792  83782c00             cmp dword ptr [eax + 0x2c], 0
// 007eb796  742f                 je 0x7eb7c7
// 007eb798  83785000             cmp dword ptr [eax + 0x50], 0
// 007eb79c  7429                 je 0x7eb7c7
// 007eb79e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007eb7a2  83f920               cmp ecx, 0x20
// 007eb7a5  740f                 je 0x7eb7b6
// 007eb7a7  83f928               cmp ecx, 0x28
// 007eb7aa  740a                 je 0x7eb7b6
// 007eb7ac  83f90d               cmp ecx, 0xd
// 007eb7af  7405                 je 0x7eb7b6
// 007eb7b1  83f973               cmp ecx, 0x73
// 007eb7b4  7511                 jne 0x7eb7c7
// 007eb7b6  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 007eb7b9  8b11                 mov edx, dword ptr [ecx]
// 007eb7bb  89442404             mov dword ptr [esp + 4], eax
// 007eb7bf  8b82d0000000         mov eax, dword ptr [edx + 0xd0]
// 007eb7c5  ffe0                 jmp eax
// 007eb7c7  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceButton@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
