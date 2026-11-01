// from server: 100% by auto
// roc 2007-03 00685480  unit: seg_00680000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685480
//
// 00685480  56                   push esi
// 00685481  8b742408             mov esi, dword ptr [esp + 8]
// 00685485  56                   push esi
// 00685486  e835f4ffff           call 0x6848c0
// 0068548b  830619               add dword ptr [esi], 0x19
// 0068548e  8bc6                 mov eax, esi
// 00685490  5e                   pop esi
// 00685491  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemColor.cpp (function ?GetValueRect@CXTPPropertyGridItemColor@@MAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemColor.cpp
