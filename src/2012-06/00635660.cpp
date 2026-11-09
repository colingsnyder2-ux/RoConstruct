// from server: 100% by auto
// roc 2012-06 00635660  unit: G3D::LineSegment  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00635660
//
// 00635660  56                   push esi
// 00635661  8bf1                 mov esi, ecx
// 00635663  8b4640               mov eax, dword ptr [esi + 0x40]
// 00635666  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00635669  57                   push edi
// 0063566a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063566e  03c7                 add eax, edi
// 00635670  3bc8                 cmp ecx, eax
// 00635672  7c02                 jl 0x635676
// 00635674  8bc1                 mov eax, ecx
// 00635676  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 00635679  894638               mov dword ptr [esi + 0x38], eax
// 0063567c  7e09                 jle 0x635687
// 0063567e  51                   push ecx
// 0063567f  57                   push edi
// 00635680  8bce                 mov ecx, esi
// 00635682  e839ffffff           call 0x6355c0
// 00635687  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0063568a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0063568e  034e40               add ecx, dword ptr [esi + 0x40]
// 00635691  57                   push edi
// 00635692  50                   push eax
// 00635693  51                   push ecx
// 00635694  e84753ffff           call 0x62a9e0
// 00635699  017e40               add dword ptr [esi + 0x40], edi
// 0063569c  83c40c               add esp, 0xc
// 0063569f  5f                   pop edi
// 006356a0  5e                   pop esi
// 006356a1  c20800               ret 8
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeBytes@BinaryOutput@G3D@@QAEXPBXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
