// from server: 100% by auto
// roc 2010-06 00881ef0  unit: CXTPPropertyGridInplaceList  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00881ef0
//
// 00881ef0  8b442404             mov eax, dword ptr [esp + 4]
// 00881ef4  83f81b               cmp eax, 0x1b
// 00881ef7  750d                 jne 0x881f06
// 00881ef9  8b01                 mov eax, dword ptr [ecx]
// 00881efb  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 00881f01  ffd2                 call edx
// 00881f03  c20c00               ret 0xc
// 00881f06  83f80d               cmp eax, 0xd
// 00881f09  740d                 je 0x881f18
// 00881f0b  83f873               cmp eax, 0x73
// 00881f0e  7408                 je 0x881f18
// 00881f10  e85b60f2ff           call 0x7a7f70
// 00881f15  c20c00               ret 0xc
// 00881f18  8b01                 mov eax, dword ptr [ecx]
// 00881f1a  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 00881f20  ffd2                 call edx
// 00881f22  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
