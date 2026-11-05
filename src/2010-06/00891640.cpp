// from server: 100% by auto
// roc 2010-06 00891640  unit: CXTColorBase  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891640
//
// 00891640  8b442404             mov eax, dword ptr [esp + 4]
// 00891644  56                   push esi
// 00891645  50                   push eax
// 00891646  8bf1                 mov esi, ecx
// 00891648  e8d763f1ff           call 0x7a7a24
// 0089164d  85c0                 test eax, eax
// 0089164f  7504                 jne 0x891655
// 00891651  5e                   pop esi
// 00891652  c20400               ret 4
// 00891655  c6465400             mov byte ptr [esi + 0x54], 0
// 00891659  b801000000           mov eax, 1
// 0089165e  5e                   pop esi
// 0089165f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?PreCreateWindow@CXTColorBase@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
