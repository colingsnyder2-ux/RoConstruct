// from server: 100% by auto
// roc 2012-06 004b96c0  unit: Ogre::VResource::?$SharedPtr  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b96c0
//
// 004b96c0  8bc1                 mov eax, ecx
// 004b96c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004b96c6  d901                 fld dword ptr [ecx]
// 004b96c8  d918                 fstp dword ptr [eax]
// 004b96ca  d94104               fld dword ptr [ecx + 4]
// 004b96cd  d95804               fstp dword ptr [eax + 4]
// 004b96d0  d94108               fld dword ptr [ecx + 8]
// 004b96d3  d95808               fstp dword ptr [eax + 8]
// 004b96d6  d9410c               fld dword ptr [ecx + 0xc]
// 004b96d9  d9580c               fstp dword ptr [eax + 0xc]
// 004b96dc  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004b96df  895010               mov dword ptr [eax + 0x10], edx
// 004b96e2  8b5114               mov edx, dword ptr [ecx + 0x14]
// 004b96e5  895014               mov dword ptr [eax + 0x14], edx
// 004b96e8  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004b96eb  895018               mov dword ptr [eax + 0x18], edx
// 004b96ee  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 004b96f1  89501c               mov dword ptr [eax + 0x1c], edx
// 004b96f4  8b5120               mov edx, dword ptr [ecx + 0x20]
// 004b96f7  895020               mov dword ptr [eax + 0x20], edx
// 004b96fa  8b5124               mov edx, dword ptr [ecx + 0x24]
// 004b96fd  895024               mov dword ptr [eax + 0x24], edx
// 004b9700  d94128               fld dword ptr [ecx + 0x28]
// 004b9703  d95828               fstp dword ptr [eax + 0x28]
// 004b9706  0fb6512c             movzx edx, byte ptr [ecx + 0x2c]
// 004b970a  88502c               mov byte ptr [eax + 0x2c], dl
// 004b970d  8b5130               mov edx, dword ptr [ecx + 0x30]
// 004b9710  895030               mov dword ptr [eax + 0x30], edx
// 004b9713  8b5134               mov edx, dword ptr [ecx + 0x34]
// 004b9716  895034               mov dword ptr [eax + 0x34], edx
// 004b9719  8b5138               mov edx, dword ptr [ecx + 0x38]
// 004b971c  895038               mov dword ptr [eax + 0x38], edx
// 004b971f  d9413c               fld dword ptr [ecx + 0x3c]
// 004b9722  d9583c               fstp dword ptr [eax + 0x3c]
// 004b9725  d94140               fld dword ptr [ecx + 0x40]
// 004b9728  d95840               fstp dword ptr [eax + 0x40]
// 004b972b  d94144               fld dword ptr [ecx + 0x44]
// 004b972e  d95844               fstp dword ptr [eax + 0x44]
// 004b9731  0fb65148             movzx edx, byte ptr [ecx + 0x48]
// 004b9735  885048               mov byte ptr [eax + 0x48], dl
// 004b9738  0fb65149             movzx edx, byte ptr [ecx + 0x49]
// 004b973c  885049               mov byte ptr [eax + 0x49], dl
// 004b973f  8a494a               mov cl, byte ptr [ecx + 0x4a]
// 004b9742  88484a               mov byte ptr [eax + 0x4a], cl
// 004b9745  c20400               ret 4
// library rbx2016-g3d/GLight.cpp (function ??0GLight@G3D@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GLight.cpp
