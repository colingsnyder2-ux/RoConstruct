// from server: 100% by auto
// roc 2007-03 00686ac0  unit: seg_00680000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686ac0
//
// 00686ac0  56                   push esi
// 00686ac1  57                   push edi
// 00686ac2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00686ac6  57                   push edi
// 00686ac7  8bf1                 mov esi, ecx
// 00686ac9  e842feffff           call 0x686910
// 00686ace  85c0                 test eax, eax
// 00686ad0  7511                 jne 0x686ae3
// 00686ad2  57                   push edi
// 00686ad3  8bce                 mov ecx, esi
// 00686ad5  e876feffff           call 0x686950
// 00686ada  85c0                 test eax, eax
// 00686adc  7505                 jne 0x686ae3
// 00686ade  5f                   pop edi
// 00686adf  5e                   pop esi
// 00686ae0  c20400               ret 4
// 00686ae3  5f                   pop edi
// 00686ae4  b801000000           mov eax, 1
// 00686ae9  5e                   pop esi
// 00686aea  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?Init@CXTPModuleHandle@@QAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
