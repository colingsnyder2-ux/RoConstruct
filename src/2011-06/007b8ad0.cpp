// from server: 100% by auto
// roc 2011-06 007b8ad0  unit: RBX::FilterCharacterOcclusion  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b8ad0
//
// 007b8ad0  8b542408             mov edx, dword ptr [esp + 8]
// 007b8ad4  8bc1                 mov eax, ecx
// 007b8ad6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b8ada  c700acd3ab00         mov dword ptr [eax], 0xabd3ac
// 007b8ae0  894804               mov dword ptr [eax + 4], ecx
// 007b8ae3  895008               mov dword ptr [eax + 8], edx
// 007b8ae6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
