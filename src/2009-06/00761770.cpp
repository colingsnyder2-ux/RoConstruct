// from server: 100% by auto
// roc 2009-06 00761770  unit: CXTPModuleHandle  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761770
//
// 00761770  56                   push esi
// 00761771  57                   push edi
// 00761772  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00761776  57                   push edi
// 00761777  8bf1                 mov esi, ecx
// 00761779  e842feffff           call 0x7615c0
// 0076177e  85c0                 test eax, eax
// 00761780  7511                 jne 0x761793
// 00761782  57                   push edi
// 00761783  8bce                 mov ecx, esi
// 00761785  e876feffff           call 0x761600
// 0076178a  85c0                 test eax, eax
// 0076178c  7505                 jne 0x761793
// 0076178e  5f                   pop edi
// 0076178f  5e                   pop esi
// 00761790  c20400               ret 4
// 00761793  5f                   pop edi
// 00761794  b801000000           mov eax, 1
// 00761799  5e                   pop esi
// 0076179a  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?Init@CXTPModuleHandle@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
