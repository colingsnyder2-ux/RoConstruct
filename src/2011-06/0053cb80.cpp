// from server: 100% by auto
// roc 2011-06 0053cb80  unit: G3D::ReferenceCountedObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053cb80
//
// 0053cb80  8b442404             mov eax, dword ptr [esp + 4]
// 0053cb84  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0053cb87  0faf4c240c           imul ecx, dword ptr [esp + 0xc]
// 0053cb8c  8b5008               mov edx, dword ptr [eax + 8]
// 0053cb8f  034c2408             add ecx, dword ptr [esp + 8]
// 0053cb93  8b442410             mov eax, dword ptr [esp + 0x10]
// 0053cb97  89048a               mov dword ptr [edx + ecx*4], eax
// 0053cb9a  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?setPixel@GImage@G3D@@SAXAAV12@HHVColor4uint8@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
