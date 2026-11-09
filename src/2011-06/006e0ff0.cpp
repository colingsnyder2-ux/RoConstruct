// from server: 100% by auto
// roc 2011-06 006e0ff0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e0ff0
//
// 006e0ff0  8b01                 mov eax, dword ptr [ecx]
// 006e0ff2  50                   push eax
// 006e0ff3  ff15cc1ca400         call dword ptr [0xa41ccc]
// 006e0ff9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
