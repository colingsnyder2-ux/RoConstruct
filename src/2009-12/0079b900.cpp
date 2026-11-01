// from server: 100% by auto
// roc 2009-12 0079b900  unit: seg_00790000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b900
//
// 0079b900  8b442404             mov eax, dword ptr [esp + 4]
// 0079b904  50                   push eax
// 0079b905  e8361f0300           call 0x7cd840
// 0079b90a  59                   pop ecx
// 0079b90b  c3                   ret 
// library lua-5.1/lstate.c (function _callallgcTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstate.c
