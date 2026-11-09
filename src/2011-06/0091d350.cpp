// from server: 100% by auto
// roc 2011-06 0091d350  unit: RBX::RbxCamera  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0091d350
//
// 0091d350  8bc1                 mov eax, ecx
// 0091d352  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0091d356  d901                 fld dword ptr [ecx]
// 0091d358  d918                 fstp dword ptr [eax]
// 0091d35a  d94104               fld dword ptr [ecx + 4]
// 0091d35d  d95804               fstp dword ptr [eax + 4]
// 0091d360  d94108               fld dword ptr [ecx + 8]
// 0091d363  d95808               fstp dword ptr [eax + 8]
// 0091d366  d9410c               fld dword ptr [ecx + 0xc]
// 0091d369  d9580c               fstp dword ptr [eax + 0xc]
// 0091d36c  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0091d36f  895010               mov dword ptr [eax + 0x10], edx
// 0091d372  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0091d375  895014               mov dword ptr [eax + 0x14], edx
// 0091d378  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0091d37b  895018               mov dword ptr [eax + 0x18], edx
// 0091d37e  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 0091d381  89501c               mov dword ptr [eax + 0x1c], edx
// 0091d384  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0091d387  895020               mov dword ptr [eax + 0x20], edx
// 0091d38a  8b5124               mov edx, dword ptr [ecx + 0x24]
// 0091d38d  895024               mov dword ptr [eax + 0x24], edx
// 0091d390  d94128               fld dword ptr [ecx + 0x28]
// 0091d393  d95828               fstp dword ptr [eax + 0x28]
// 0091d396  0fb6512c             movzx edx, byte ptr [ecx + 0x2c]
// 0091d39a  88502c               mov byte ptr [eax + 0x2c], dl
// 0091d39d  8b5130               mov edx, dword ptr [ecx + 0x30]
// 0091d3a0  895030               mov dword ptr [eax + 0x30], edx
// 0091d3a3  8b5134               mov edx, dword ptr [ecx + 0x34]
// 0091d3a6  895034               mov dword ptr [eax + 0x34], edx
// 0091d3a9  8b5138               mov edx, dword ptr [ecx + 0x38]
// 0091d3ac  895038               mov dword ptr [eax + 0x38], edx
// 0091d3af  d9413c               fld dword ptr [ecx + 0x3c]
// 0091d3b2  d9583c               fstp dword ptr [eax + 0x3c]
// 0091d3b5  d94140               fld dword ptr [ecx + 0x40]
// 0091d3b8  d95840               fstp dword ptr [eax + 0x40]
// 0091d3bb  d94144               fld dword ptr [ecx + 0x44]
// 0091d3be  d95844               fstp dword ptr [eax + 0x44]
// 0091d3c1  0fb65148             movzx edx, byte ptr [ecx + 0x48]
// 0091d3c5  885048               mov byte ptr [eax + 0x48], dl
// 0091d3c8  0fb65149             movzx edx, byte ptr [ecx + 0x49]
// 0091d3cc  885049               mov byte ptr [eax + 0x49], dl
// 0091d3cf  8a494a               mov cl, byte ptr [ecx + 0x4a]
// 0091d3d2  88484a               mov byte ptr [eax + 0x4a], cl
// 0091d3d5  c20400               ret 4
// library rbx2016-g3d/GLight.cpp (function ??0GLight@G3D@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GLight.cpp
