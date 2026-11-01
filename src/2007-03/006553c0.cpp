// from server: 100% by auto
// roc 2007-03 006553c0  unit: seg_00650000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006553c0
//
// 006553c0  8b442408             mov eax, dword ptr [esp + 8]
// 006553c4  8b542404             mov edx, dword ptr [esp + 4]
// 006553c8  50                   push eax
// 006553c9  52                   push edx
// 006553ca  e851ffffff           call 0x655320
// 006553cf  e8d89efcff           call 0x61f2ac
// 006553d4  d95c2408             fstp dword ptr [esp + 8]
// 006553d8  d9442408             fld dword ptr [esp + 8]
// 006553dc  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?Length@CXTPColorManager@@AAEMKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
