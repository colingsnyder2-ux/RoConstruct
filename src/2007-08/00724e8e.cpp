// from server: 100% by auto
// roc 2007-08 00724e8e  unit: CXTIconHandle  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00724e8e
//
// 00724e8e  56                   push esi
// 00724e8f  8bf1                 mov esi, ecx
// 00724e91  8b06                 mov eax, dword ptr [esi]
// 00724e93  85c0                 test eax, eax
// 00724e95  740a                 je 0x724ea1
// 00724e97  50                   push eax
// 00724e98  e875bbf0ff           call 0x630a12
// 00724e9d  832600               and dword ptr [esi], 0
// 00724ea0  59                   pop ecx
// 00724ea1  83660400             and dword ptr [esi + 4], 0
// 00724ea5  83660800             and dword ptr [esi + 8], 0
// 00724ea9  5e                   pop esi
// 00724eaa  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?RemoveAll@?$CSimpleArray@PAVCDHtmlControlSink@@V?$CSimpleArrayEqualHelper@PAVCDHtmlControlSink@@@ATL@@@ATL@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
