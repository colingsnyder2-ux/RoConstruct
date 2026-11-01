// from server: 100% by auto
// roc 2007-08 00709bb0  unit: CXTColorHex  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00709bb0
//
// 00709bb0  56                   push esi
// 00709bb1  8bf1                 mov esi, ecx
// 00709bb3  e88666f2ff           call 0x63023e
// 00709bb8  83f8ff               cmp eax, -1
// 00709bbb  7506                 jne 0x709bc3
// 00709bbd  0bc0                 or eax, eax
// 00709bbf  5e                   pop esi
// 00709bc0  c20400               ret 4
// 00709bc3  8b06                 mov eax, dword ptr [esi]
// 00709bc5  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 00709bcb  8bce                 mov ecx, esi
// 00709bcd  ffd2                 call edx
// 00709bcf  33c0                 xor eax, eax
// 00709bd1  5e                   pop esi
// 00709bd2  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?OnCreate@CXTPColorHex@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
