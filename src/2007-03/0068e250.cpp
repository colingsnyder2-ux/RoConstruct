// from server: 100% by auto
// roc 2007-03 0068e250  unit: seg_00680000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e250
//
// 0068e250  8b442404             mov eax, dword ptr [esp + 4]
// 0068e254  8b5104               mov edx, dword ptr [ecx + 4]
// 0068e257  8910                 mov dword ptr [eax], edx
// 0068e259  8b5108               mov edx, dword ptr [ecx + 8]
// 0068e25c  895004               mov dword ptr [eax + 4], edx
// 0068e25f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0068e262  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0068e265  895008               mov dword ptr [eax + 8], edx
// 0068e268  89480c               mov dword ptr [eax + 0xc], ecx
// 0068e26b  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?getDriverVersion@RenderSystemCapabilities@Ogre@@QBE?AUDriverVersion@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
