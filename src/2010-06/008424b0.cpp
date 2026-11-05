// from server: 100% by auto
// roc 2010-06 008424b0  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008424b0
//
// 008424b0  8b542408             mov edx, dword ptr [esp + 8]
// 008424b4  8bc1                 mov eax, ecx
// 008424b6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008424ba  c7007074a600         mov dword ptr [eax], 0xa67470
// 008424c0  894804               mov dword ptr [eax + 4], ecx
// 008424c3  895008               mov dword ptr [eax + 8], edx
// 008424c6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
