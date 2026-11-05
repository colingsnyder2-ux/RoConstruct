// from server: 100% by auto
// roc 2012-06 00628a70  unit: G3D::ReferenceCountedObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628a70
//
// 00628a70  8b442404             mov eax, dword ptr [esp + 4]
// 00628a74  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00628a77  0faf4c240c           imul ecx, dword ptr [esp + 0xc]
// 00628a7c  8b5008               mov edx, dword ptr [eax + 8]
// 00628a7f  034c2408             add ecx, dword ptr [esp + 8]
// 00628a83  8b442410             mov eax, dword ptr [esp + 0x10]
// 00628a87  89048a               mov dword ptr [edx + ecx*4], eax
// 00628a8a  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?setPixel@GImage@G3D@@SAXAAV12@HHVColor4uint8@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
