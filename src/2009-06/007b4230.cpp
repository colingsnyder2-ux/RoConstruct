// from server: 100% by auto
// roc 2009-06 007b4230  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b4230
//
// 007b4230  8b542408             mov edx, dword ptr [esp + 8]
// 007b4234  8bc1                 mov eax, ecx
// 007b4236  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b423a  c700b42f9000         mov dword ptr [eax], 0x902fb4
// 007b4240  894804               mov dword ptr [eax + 4], ecx
// 007b4243  895008               mov dword ptr [eax + 8], edx
// 007b4246  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
