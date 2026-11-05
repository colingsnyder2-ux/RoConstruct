// roc 2012-06 00b11355  unit: seg_00b10000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11355
//
// 00b11355  6800090000           push 0x900
// 00b1135a  6a00                 push 0
// 00b1135c  e8da8af8ff           call 0xa99e3b
// 00b11361  a24d03e600           mov byte ptr [0xe6034d], al
// 00b11366  c3                   ret 
// copied from an identical function in another client (function ??__E_afxInitAppState@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm mfcs90.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/mfc/ansireleasedllstatic/objr/i386/appmodul.obj