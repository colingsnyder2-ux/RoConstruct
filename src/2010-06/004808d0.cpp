// from server: 100% by auto
// roc 2010-06 004808d0  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004808d0
//
// 004808d0  8b542408             mov edx, dword ptr [esp + 8]
// 004808d4  8bc1                 mov eax, ecx
// 004808d6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004808da  c7005c2ea100         mov dword ptr [eax], 0xa12e5c
// 004808e0  894804               mov dword ptr [eax + 4], ecx
// 004808e3  895008               mov dword ptr [eax + 8], edx
// 004808e6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
