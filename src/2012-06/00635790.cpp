// from server: 100% by auto
// roc 2012-06 00635790  unit: G3D::LineSegment  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00635790
//
// 00635790  53                   push ebx
// 00635791  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00635795  56                   push esi
// 00635796  8bc3                 mov eax, ebx
// 00635798  57                   push edi
// 00635799  8bf1                 mov esi, ecx
// 0063579b  8d5001               lea edx, [eax + 1]
// 0063579e  8bff                 mov edi, edi
// 006357a0  8a08                 mov cl, byte ptr [eax]
// 006357a2  40                   inc eax
// 006357a3  84c9                 test cl, cl
// 006357a5  75f9                 jne 0x6357a0
// 006357a7  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006357aa  2bc2                 sub eax, edx
// 006357ac  8d7801               lea edi, [eax + 1]
// 006357af  8b4640               mov eax, dword ptr [esi + 0x40]
// 006357b2  03c7                 add eax, edi
// 006357b4  3bc8                 cmp ecx, eax
// 006357b6  7c02                 jl 0x6357ba
// 006357b8  8bc1                 mov eax, ecx
// 006357ba  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 006357bd  894638               mov dword ptr [esi + 0x38], eax
// 006357c0  7e09                 jle 0x6357cb
// 006357c2  51                   push ecx
// 006357c3  57                   push edi
// 006357c4  8bce                 mov ecx, esi
// 006357c6  e8f5fdffff           call 0x6355c0
// 006357cb  8b4634               mov eax, dword ptr [esi + 0x34]
// 006357ce  034640               add eax, dword ptr [esi + 0x40]
// 006357d1  57                   push edi
// 006357d2  53                   push ebx
// 006357d3  50                   push eax
// 006357d4  e80752ffff           call 0x62a9e0
// 006357d9  017e40               add dword ptr [esi + 0x40], edi
// 006357dc  83c40c               add esp, 0xc
// 006357df  5f                   pop edi
// 006357e0  5e                   pop esi
// 006357e1  5b                   pop ebx
// 006357e2  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeString@BinaryOutput@G3D@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
