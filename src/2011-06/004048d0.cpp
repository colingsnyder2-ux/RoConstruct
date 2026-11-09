// from server: 100% by auto
// roc 2011-06 004048d0  unit: VCApp::?$CComObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004048d0
//
// 004048d0  56                   push esi
// 004048d1  8bf1                 mov esi, ecx
// 004048d3  8b06                 mov eax, dword ptr [esi]
// 004048d5  85c0                 test eax, eax
// 004048d7  740d                 je 0x4048e6
// 004048d9  50                   push eax
// 004048da  ff150400a400         call dword ptr [0xa40004]
// 004048e0  c70600000000         mov dword ptr [esi], 0
// 004048e6  c7460400000000       mov dword ptr [esi + 4], 0
// 004048ed  5e                   pop esi
// 004048ee  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
