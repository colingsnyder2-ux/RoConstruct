// from server: 100% by auto
// roc 2009-12 00871be0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871be0
//
// 00871be0  8b442404             mov eax, dword ptr [esp + 4]
// 00871be4  8b5104               mov edx, dword ptr [ecx + 4]
// 00871be7  8910                 mov dword ptr [eax], edx
// 00871be9  8b5108               mov edx, dword ptr [ecx + 8]
// 00871bec  895004               mov dword ptr [eax + 4], edx
// 00871bef  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00871bf2  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00871bf5  895008               mov dword ptr [eax + 8], edx
// 00871bf8  89480c               mov dword ptr [eax + 0xc], ecx
// 00871bfb  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?getDriverVersion@RenderSystemCapabilities@Ogre@@QBE?AUDriverVersion@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
