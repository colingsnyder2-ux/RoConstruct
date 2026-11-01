// from server: 100% by auto
// roc 2007-03 006f7500  unit: seg_006f0000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f7500
//
// 006f7500  51                   push ecx
// 006f7501  56                   push esi
// 006f7502  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f7506  83c15c               add ecx, 0x5c
// 006f7509  51                   push ecx
// 006f750a  8bce                 mov ecx, esi
// 006f750c  c744240800000000     mov dword ptr [esp + 8], 0
// 006f7514  ff152cdd7700         call dword ptr [0x77dd2c]
// 006f751a  8bc6                 mov eax, esi
// 006f751c  5e                   pop esi
// 006f751d  59                   pop ecx
// 006f751e  c20400               ret 4
// library ogre-1.7.0/OgreTechnique.cpp (function ?getShadowCasterMaterial@Technique@Ogre@@QBE?AVMaterialPtr@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTechnique.cpp
