// from server: 100% by auto
// roc 2009-12 0047a430  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047a430
//
// 0047a430  8b542408             mov edx, dword ptr [esp + 8]
// 0047a434  8bc1                 mov eax, ecx
// 0047a436  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0047a43a  c700341d9b00         mov dword ptr [eax], 0x9b1d34
// 0047a440  894804               mov dword ptr [eax + 4], ecx
// 0047a443  895008               mov dword ptr [eax + 8], edx
// 0047a446  c20800               ret 8
// library ogre-1.6.4/OgrePredefinedControllers.cpp (function ??0FloatGpuParameterControllerValue@Ogre@@QAE@PAVGpuProgramParameters@1@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePredefinedControllers.cpp
