// from server: 100% by auto
// roc 2007-08 006fcee0  unit: CXTPPropertyGridInplaceList  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fcee0
//
// 006fcee0  8b442404             mov eax, dword ptr [esp + 4]
// 006fcee4  83f828               cmp eax, 0x28
// 006fcee7  740d                 je 0x6fcef6
// 006fcee9  83f826               cmp eax, 0x26
// 006fceec  7408                 je 0x6fcef6
// 006fceee  e84b33f3ff           call 0x63023e
// 006fcef3  c20c00               ret 0xc
// 006fcef6  8b01                 mov eax, dword ptr [ecx]
// 006fcef8  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006fcefe  ffd2                 call edx
// 006fcf00  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnSysKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
