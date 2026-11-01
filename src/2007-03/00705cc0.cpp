// from server: 100% by auto
// roc 2007-03 00705cc0  unit: seg_00700000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00705cc0
//
// 00705cc0  8b442404             mov eax, dword ptr [esp + 4]
// 00705cc4  56                   push esi
// 00705cc5  50                   push eax
// 00705cc6  8bf1                 mov esi, ecx
// 00705cc8  e8b984f1ff           call 0x61e186
// 00705ccd  85c0                 test eax, eax
// 00705ccf  7504                 jne 0x705cd5
// 00705cd1  5e                   pop esi
// 00705cd2  c20400               ret 4
// 00705cd5  c6467400             mov byte ptr [esi + 0x74], 0
// 00705cd9  b801000000           mov eax, 1
// 00705cde  5e                   pop esi
// 00705cdf  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?PreCreateWindow@CXTButton@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
