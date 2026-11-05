// from server: 100% by auto
// roc 2007-08 006a4320  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a4320
//
// 006a4320  8b542408             mov edx, dword ptr [esp + 8]
// 006a4324  8bc1                 mov eax, ecx
// 006a4326  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a432a  c70008367d00         mov dword ptr [eax], 0x7d3608
// 006a4330  894804               mov dword ptr [eax + 4], ecx
// 006a4333  895008               mov dword ptr [eax + 8], edx
// 006a4336  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
