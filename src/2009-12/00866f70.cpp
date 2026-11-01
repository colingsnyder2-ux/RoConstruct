// from server: 100% by auto
// roc 2009-12 00866f70  unit: CPropertyGridItemBrickColor  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00866f70
//
// 00866f70  56                   push esi
// 00866f71  8b742408             mov esi, dword ptr [esp + 8]
// 00866f75  56                   push esi
// 00866f76  e845f2ffff           call 0x8661c0
// 00866f7b  830619               add dword ptr [esi], 0x19
// 00866f7e  8bc6                 mov eax, esi
// 00866f80  5e                   pop esi
// 00866f81  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemColor.cpp (function ?GetValueRect@CXTPPropertyGridItemColor@@MAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemColor.cpp
