// from server: 100% by auto
// roc 2009-12 006f2d70  unit: RBX::$01::?$SurfaceDescriptor  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f2d70
//
// 006f2d70  8b442408             mov eax, dword ptr [esp + 8]
// 006f2d74  56                   push esi
// 006f2d75  8bf1                 mov esi, ecx
// 006f2d77  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f2d7b  50                   push eax
// 006f2d7c  51                   push ecx
// 006f2d7d  e82ef8f3ff           call 0x6325b0
// 006f2d82  83c404               add esp, 4
// 006f2d85  50                   push eax
// 006f2d86  8bce                 mov ecx, esi
// 006f2d88  e873a1f5ff           call 0x64cf00
// 006f2d8d  5e                   pop esi
// 006f2d8e  c20800               ret 8
// library boost-1.44.0/libs\iostreams\src\file_descriptor.cpp (function ?open@file_descriptor_impl@detail@iostreams@boost@@QAEXHW4flags@1234@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.44.0 libs/iostreams/src/file_descriptor.cpp
