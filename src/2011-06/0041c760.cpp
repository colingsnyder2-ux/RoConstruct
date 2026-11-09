// from server: 100% by auto
// roc 2011-06 0041c760  unit: RBX::VTool::?$FactoryProduct::Creator  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0041c760
//
// 0041c760  8b01                 mov eax, dword ptr [ecx]
// 0041c762  50                   push eax
// 0041c763  ff158003a400         call dword ptr [0xa40380]
// 0041c769  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
