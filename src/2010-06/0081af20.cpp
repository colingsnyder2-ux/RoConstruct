// from server: 100% by auto
// roc 2010-06 0081af20  unit: CPropertyGridItemBrickColor  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081af20
//
// 0081af20  56                   push esi
// 0081af21  8b742408             mov esi, dword ptr [esp + 8]
// 0081af25  56                   push esi
// 0081af26  e855f2ffff           call 0x81a180
// 0081af2b  830619               add dword ptr [esi], 0x19
// 0081af2e  8bc6                 mov eax, esi
// 0081af30  5e                   pop esi
// 0081af31  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridItemColor.cpp (function ?GetValueRect@CXTPPropertyGridItemColor@@MAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridItemColor.cpp
