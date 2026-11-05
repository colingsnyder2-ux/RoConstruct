// from server: 100% by auto
// roc 2011-06 0089f670  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089f670
//
// 0089f670  8b542408             mov edx, dword ptr [esp + 8]
// 0089f674  8bc1                 mov eax, ecx
// 0089f676  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089f67a  c700901ead00         mov dword ptr [eax], 0xad1e90
// 0089f680  894804               mov dword ptr [eax + 4], ecx
// 0089f683  895008               mov dword ptr [eax + 8], edx
// 0089f686  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
