// from server: 100% by auto
// roc 2009-06 0080aa90  unit: CXTCaptionButton  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080aa90
//
// 0080aa90  8b442404             mov eax, dword ptr [esp + 4]
// 0080aa94  56                   push esi
// 0080aa95  50                   push eax
// 0080aa96  8bf1                 mov esi, ecx
// 0080aa98  e81fe0f0ff           call 0x718abc
// 0080aa9d  85c0                 test eax, eax
// 0080aa9f  7504                 jne 0x80aaa5
// 0080aaa1  5e                   pop esi
// 0080aaa2  c20400               ret 4
// 0080aaa5  c6467400             mov byte ptr [esi + 0x74], 0
// 0080aaa9  b801000000           mov eax, 1
// 0080aaae  5e                   pop esi
// 0080aaaf  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?PreCreateWindow@CXTButton@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
