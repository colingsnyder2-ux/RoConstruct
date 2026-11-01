// from server: 100% by auto
// roc 2009-12 0083c540  unit: CXTPModuleHandle  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c540
//
// 0083c540  56                   push esi
// 0083c541  57                   push edi
// 0083c542  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c546  57                   push edi
// 0083c547  8bf1                 mov esi, ecx
// 0083c549  e842feffff           call 0x83c390
// 0083c54e  85c0                 test eax, eax
// 0083c550  7511                 jne 0x83c563
// 0083c552  57                   push edi
// 0083c553  8bce                 mov ecx, esi
// 0083c555  e876feffff           call 0x83c3d0
// 0083c55a  85c0                 test eax, eax
// 0083c55c  7505                 jne 0x83c563
// 0083c55e  5f                   pop edi
// 0083c55f  5e                   pop esi
// 0083c560  c20400               ret 4
// 0083c563  5f                   pop edi
// 0083c564  b801000000           mov eax, 1
// 0083c569  5e                   pop esi
// 0083c56a  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?Init@CXTPModuleHandle@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
