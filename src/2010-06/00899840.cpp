// from server: 100% by auto
// roc 2010-06 00899840  unit: CXTCaptionButton  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899840
//
// 00899840  8b442404             mov eax, dword ptr [esp + 4]
// 00899844  56                   push esi
// 00899845  50                   push eax
// 00899846  8bf1                 mov esi, ecx
// 00899848  e8d7e1f0ff           call 0x7a7a24
// 0089984d  85c0                 test eax, eax
// 0089984f  7504                 jne 0x899855
// 00899851  5e                   pop esi
// 00899852  c20400               ret 4
// 00899855  c6467400             mov byte ptr [esi + 0x74], 0
// 00899859  b801000000           mov eax, 1
// 0089985e  5e                   pop esi
// 0089985f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?PreCreateWindow@CXTButton@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
