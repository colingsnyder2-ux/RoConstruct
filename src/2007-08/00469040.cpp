// from server: 100% by auto
// roc 2007-08 00469040  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00469040
//
// 00469040  8b542408             mov edx, dword ptr [esp + 8]
// 00469044  8bc1                 mov eax, ecx
// 00469046  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046904a  c7006c607900         mov dword ptr [eax], 0x79606c
// 00469050  894804               mov dword ptr [eax + 4], ecx
// 00469053  895008               mov dword ptr [eax + 8], edx
// 00469056  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
