// from server: 100% by auto
// roc 2011-06 008e5bc0  unit: CXTPPropertyGridInplaceList  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5bc0
//
// 008e5bc0  8b442404             mov eax, dword ptr [esp + 4]
// 008e5bc4  83f828               cmp eax, 0x28
// 008e5bc7  740d                 je 0x8e5bd6
// 008e5bc9  83f826               cmp eax, 0x26
// 008e5bcc  7408                 je 0x8e5bd6
// 008e5bce  e85b4af2ff           call 0x80a62e
// 008e5bd3  c20c00               ret 0xc
// 008e5bd6  8b01                 mov eax, dword ptr [ecx]
// 008e5bd8  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 008e5bde  ffd2                 call edx
// 008e5be0  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnSysKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
