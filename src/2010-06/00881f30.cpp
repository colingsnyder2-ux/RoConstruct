// from server: 100% by auto
// roc 2010-06 00881f30  unit: CXTPPropertyGridInplaceList  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00881f30
//
// 00881f30  8b442404             mov eax, dword ptr [esp + 4]
// 00881f34  83f828               cmp eax, 0x28
// 00881f37  740d                 je 0x881f46
// 00881f39  83f826               cmp eax, 0x26
// 00881f3c  7408                 je 0x881f46
// 00881f3e  e82d60f2ff           call 0x7a7f70
// 00881f43  c20c00               ret 0xc
// 00881f46  8b01                 mov eax, dword ptr [ecx]
// 00881f48  8b906c010000         mov edx, dword ptr [eax + 0x16c]
// 00881f4e  ffd2                 call edx
// 00881f50  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnSysKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
