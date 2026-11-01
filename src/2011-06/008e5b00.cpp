// from server: 100% by auto
// roc 2011-06 008e5b00  unit: CXTPPropertyGridInplaceList  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5b00
//
// 008e5b00  56                   push esi
// 008e5b01  8bf1                 mov esi, ecx
// 008e5b03  e8264bf2ff           call 0x80a62e
// 008e5b08  6a00                 push 0
// 008e5b0a  e87197f7ff           call 0x85f280
// 008e5b0f  8b06                 mov eax, dword ptr [esi]
// 008e5b11  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008e5b17  83c404               add esp, 4
// 008e5b1a  8bce                 mov ecx, esi
// 008e5b1c  ffd2                 call edx
// 008e5b1e  8b06                 mov eax, dword ptr [esi]
// 008e5b20  8b5068               mov edx, dword ptr [eax + 0x68]
// 008e5b23  8bce                 mov ecx, esi
// 008e5b25  ffd2                 call edx
// 008e5b27  5e                   pop esi
// 008e5b28  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKillFocus@CXTPPropertyGridInplaceList@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
