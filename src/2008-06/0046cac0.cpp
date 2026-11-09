// from server: 100% by auto
// roc 2008-06 0046cac0  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046cac0
//
// 0046cac0  8b542408             mov edx, dword ptr [esp + 8]
// 0046cac4  8bc1                 mov eax, ecx
// 0046cac6  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046caca  c700b8c88100         mov dword ptr [eax], 0x81c8b8
// 0046cad0  894804               mov dword ptr [eax + 4], ecx
// 0046cad3  895008               mov dword ptr [eax + 8], edx
// 0046cad6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??0Image@Gdiplus@@IAE@PAVGpImage@1@W4Status@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
