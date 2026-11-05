// from server: 100% by auto
// roc 2010-06 007f06a0  unit: CXTPModuleHandle  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f06a0
//
// 007f06a0  56                   push esi
// 007f06a1  57                   push edi
// 007f06a2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f06a6  57                   push edi
// 007f06a7  8bf1                 mov esi, ecx
// 007f06a9  e842feffff           call 0x7f04f0
// 007f06ae  85c0                 test eax, eax
// 007f06b0  7511                 jne 0x7f06c3
// 007f06b2  57                   push edi
// 007f06b3  8bce                 mov ecx, esi
// 007f06b5  e876feffff           call 0x7f0530
// 007f06ba  85c0                 test eax, eax
// 007f06bc  7505                 jne 0x7f06c3
// 007f06be  5f                   pop edi
// 007f06bf  5e                   pop esi
// 007f06c0  c20400               ret 4
// 007f06c3  5f                   pop edi
// 007f06c4  b801000000           mov eax, 1
// 007f06c9  5e                   pop esi
// 007f06ca  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?Init@CXTPModuleHandle@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
