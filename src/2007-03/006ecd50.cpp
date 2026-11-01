// from server: 100% by auto
// roc 2007-03 006ecd50  unit: seg_006e0000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ecd50
//
// 006ecd50  56                   push esi
// 006ecd51  8bf1                 mov esi, ecx
// 006ecd53  e87a19f3ff           call 0x61e6d2
// 006ecd58  83f8ff               cmp eax, -1
// 006ecd5b  7506                 jne 0x6ecd63
// 006ecd5d  0bc0                 or eax, eax
// 006ecd5f  5e                   pop esi
// 006ecd60  c20400               ret 4
// 006ecd63  8b06                 mov eax, dword ptr [esi]
// 006ecd65  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 006ecd6b  8bce                 mov ecx, esi
// 006ecd6d  ffd2                 call edx
// 006ecd6f  33c0                 xor eax, eax
// 006ecd71  5e                   pop esi
// 006ecd72  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageStandard.cpp (function ?OnCreate@CXTPColorHex@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageStandard.cpp
