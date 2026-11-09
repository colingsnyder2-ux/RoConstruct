// from server: 100% by auto
// roc 2011-06 005451d0  unit: G3D::BinaryInput  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005451d0
//
// 005451d0  56                   push esi
// 005451d1  8bf1                 mov esi, ecx
// 005451d3  8b4640               mov eax, dword ptr [esi + 0x40]
// 005451d6  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005451d9  57                   push edi
// 005451da  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005451de  03c7                 add eax, edi
// 005451e0  3bc8                 cmp ecx, eax
// 005451e2  7c02                 jl 0x5451e6
// 005451e4  8bc1                 mov eax, ecx
// 005451e6  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 005451e9  894638               mov dword ptr [esi + 0x38], eax
// 005451ec  7e09                 jle 0x5451f7
// 005451ee  51                   push ecx
// 005451ef  57                   push edi
// 005451f0  8bce                 mov ecx, esi
// 005451f2  e839ffffff           call 0x545130
// 005451f7  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005451fa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005451fe  034e40               add ecx, dword ptr [esi + 0x40]
// 00545201  57                   push edi
// 00545202  50                   push eax
// 00545203  51                   push ecx
// 00545204  e8d798ffff           call 0x53eae0
// 00545209  017e40               add dword ptr [esi + 0x40], edi
// 0054520c  83c40c               add esp, 0xc
// 0054520f  5f                   pop edi
// 00545210  5e                   pop esi
// 00545211  c20800               ret 8
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeBytes@BinaryOutput@G3D@@QAEXPBXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
