// from server: 100% by auto
// roc 2007-03 00694800  unit: seg_00690000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00694800
//
// 00694800  8b442404             mov eax, dword ptr [esp + 4]
// 00694804  8b4804               mov ecx, dword ptr [eax + 4]
// 00694807  8b542408             mov edx, dword ptr [esp + 8]
// 0069480b  33c0                 xor eax, eax
// 0069480d  3b4a04               cmp ecx, dword ptr [edx + 4]
// 00694810  0f9dc0               setge al
// 00694813  8d4400ff             lea eax, [eax + eax - 1]
// 00694817  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?CompareFunc@CDockInfoArray@CXTPDockBar@@SAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
