// from server: 100% by auto
// roc 2007-08 006fcea0  unit: CXTPPropertyGridInplaceList  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fcea0
//
// 006fcea0  8b442404             mov eax, dword ptr [esp + 4]
// 006fcea4  83f81b               cmp eax, 0x1b
// 006fcea7  750d                 jne 0x6fceb6
// 006fcea9  8b01                 mov eax, dword ptr [ecx]
// 006fceab  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 006fceb1  ffd2                 call edx
// 006fceb3  c20c00               ret 0xc
// 006fceb6  83f80d               cmp eax, 0xd
// 006fceb9  740d                 je 0x6fcec8
// 006fcebb  83f873               cmp eax, 0x73
// 006fcebe  7408                 je 0x6fcec8
// 006fcec0  e87933f3ff           call 0x63023e
// 006fcec5  c20c00               ret 0xc
// 006fcec8  8b01                 mov eax, dword ptr [ecx]
// 006fceca  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006fced0  ffd2                 call edx
// 006fced2  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
