// from server: 100% by auto
// roc 2009-12 0088e250  unit: CXTPShortcutManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088e250
//
// 0088e250  8b542408             mov edx, dword ptr [esp + 8]
// 0088e254  8bc1                 mov eax, ecx
// 0088e256  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0088e25a  c7007431a000         mov dword ptr [eax], 0xa03174
// 0088e260  894804               mov dword ptr [eax + 4], ecx
// 0088e263  895008               mov dword ptr [eax + 8], edx
// 0088e266  c20800               ret 8
// library ogre-1.6.4/OgrePredefinedControllers.cpp (function ??0FloatGpuParameterControllerValue@Ogre@@QAE@PAVGpuProgramParameters@1@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePredefinedControllers.cpp
