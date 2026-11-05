// from server: 100% by auto
// roc 2011-06 00545220  unit: G3D::BinaryInput  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00545220
//
// 00545220  56                   push esi
// 00545221  8bf1                 mov esi, ecx
// 00545223  8b4640               mov eax, dword ptr [esi + 0x40]
// 00545226  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00545229  83c002               add eax, 2
// 0054522c  3bc8                 cmp ecx, eax
// 0054522e  7c02                 jl 0x545232
// 00545230  8bc1                 mov eax, ecx
// 00545232  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 00545235  894638               mov dword ptr [esi + 0x38], eax
// 00545238  7e0a                 jle 0x545244
// 0054523a  51                   push ecx
// 0054523b  6a02                 push 2
// 0054523d  8bce                 mov ecx, esi
// 0054523f  e8ecfeffff           call 0x545130
// 00545244  807e2c00             cmp byte ptr [esi + 0x2c], 0
// 00545248  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054524b  741d                 je 0x54526a
// 0054524d  8b5634               mov edx, dword ptr [esi + 0x34]
// 00545250  668b442408           mov ax, word ptr [esp + 8]
// 00545255  882411               mov byte ptr [ecx + edx], ah
// 00545258  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054525b  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054525e  88441101             mov byte ptr [ecx + edx + 1], al
// 00545262  83464002             add dword ptr [esi + 0x40], 2
// 00545266  5e                   pop esi
// 00545267  c20400               ret 4
// 0054526a  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054526d  668b542408           mov dx, word ptr [esp + 8]
// 00545272  66891408             mov word ptr [eax + ecx], dx
// 00545276  83464002             add dword ptr [esi + 0x40], 2
// 0054527a  5e                   pop esi
// 0054527b  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeUInt16@BinaryOutput@G3D@@QAEXG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
