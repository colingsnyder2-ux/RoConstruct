// from server: 100% by auto
// roc 2007-03 006dd250  unit: seg_006d0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dd250
//
// 006dd250  8b442404             mov eax, dword ptr [esp + 4]
// 006dd254  83f828               cmp eax, 0x28
// 006dd257  740d                 je 0x6dd266
// 006dd259  83f826               cmp eax, 0x26
// 006dd25c  7408                 je 0x6dd266
// 006dd25e  e86f14f4ff           call 0x61e6d2
// 006dd263  c20c00               ret 0xc
// 006dd266  8b01                 mov eax, dword ptr [ecx]
// 006dd268  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006dd26e  ffd2                 call edx
// 006dd270  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnSysKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
