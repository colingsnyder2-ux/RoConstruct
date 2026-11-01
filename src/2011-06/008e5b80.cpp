// from server: 100% by auto
// roc 2011-06 008e5b80  unit: CXTPPropertyGridInplaceList  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5b80
//
// 008e5b80  8b442404             mov eax, dword ptr [esp + 4]
// 008e5b84  83f81b               cmp eax, 0x1b
// 008e5b87  750d                 jne 0x8e5b96
// 008e5b89  8b01                 mov eax, dword ptr [ecx]
// 008e5b8b  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008e5b91  ffd2                 call edx
// 008e5b93  c20c00               ret 0xc
// 008e5b96  83f80d               cmp eax, 0xd
// 008e5b99  740d                 je 0x8e5ba8
// 008e5b9b  83f873               cmp eax, 0x73
// 008e5b9e  7408                 je 0x8e5ba8
// 008e5ba0  e8894af2ff           call 0x80a62e
// 008e5ba5  c20c00               ret 0xc
// 008e5ba8  8b01                 mov eax, dword ptr [ecx]
// 008e5baa  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 008e5bb0  ffd2                 call edx
// 008e5bb2  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
