// from server: 100% by auto
// roc 2008-06 0071dad0  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071dad0
//
// 0071dad0  8b542408             mov edx, dword ptr [esp + 8]
// 0071dad4  8bc1                 mov eax, ecx
// 0071dad6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071dada  c700d8f48500         mov dword ptr [eax], 0x85f4d8
// 0071dae0  894804               mov dword ptr [eax + 4], ecx
// 0071dae3  895008               mov dword ptr [eax + 8], edx
// 0071dae6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
