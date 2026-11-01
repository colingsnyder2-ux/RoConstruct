// from server: 100% by auto
// roc 2007-03 006dd210  unit: seg_006d0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006dd210
//
// 006dd210  8b442404             mov eax, dword ptr [esp + 4]
// 006dd214  83f81b               cmp eax, 0x1b
// 006dd217  750d                 jne 0x6dd226
// 006dd219  8b01                 mov eax, dword ptr [ecx]
// 006dd21b  8b9060010000         mov edx, dword ptr [eax + 0x160]
// 006dd221  ffd2                 call edx
// 006dd223  c20c00               ret 0xc
// 006dd226  83f80d               cmp eax, 0xd
// 006dd229  740d                 je 0x6dd238
// 006dd22b  83f873               cmp eax, 0x73
// 006dd22e  7408                 je 0x6dd238
// 006dd230  e89d14f4ff           call 0x61e6d2
// 006dd235  c20c00               ret 0xc
// 006dd238  8b01                 mov eax, dword ptr [ecx]
// 006dd23a  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 006dd240  ffd2                 call edx
// 006dd242  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceList.cpp (function ?OnKeyDown@CXTPPropertyGridInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceList.cpp
