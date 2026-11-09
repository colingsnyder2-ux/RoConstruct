// from server: 100% by auto
// roc 2012-06 006356b0  unit: G3D::LineSegment  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006356b0
//
// 006356b0  56                   push esi
// 006356b1  8bf1                 mov esi, ecx
// 006356b3  8b4640               mov eax, dword ptr [esi + 0x40]
// 006356b6  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006356b9  83c002               add eax, 2
// 006356bc  3bc8                 cmp ecx, eax
// 006356be  7c02                 jl 0x6356c2
// 006356c0  8bc1                 mov eax, ecx
// 006356c2  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 006356c5  894638               mov dword ptr [esi + 0x38], eax
// 006356c8  7e0a                 jle 0x6356d4
// 006356ca  51                   push ecx
// 006356cb  6a02                 push 2
// 006356cd  8bce                 mov ecx, esi
// 006356cf  e8ecfeffff           call 0x6355c0
// 006356d4  807e2c00             cmp byte ptr [esi + 0x2c], 0
// 006356d8  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 006356db  741d                 je 0x6356fa
// 006356dd  8b5634               mov edx, dword ptr [esi + 0x34]
// 006356e0  668b442408           mov ax, word ptr [esp + 8]
// 006356e5  882411               mov byte ptr [ecx + edx], ah
// 006356e8  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 006356eb  8b5634               mov edx, dword ptr [esi + 0x34]
// 006356ee  88441101             mov byte ptr [ecx + edx + 1], al
// 006356f2  83464002             add dword ptr [esi + 0x40], 2
// 006356f6  5e                   pop esi
// 006356f7  c20400               ret 4
// 006356fa  8b4634               mov eax, dword ptr [esi + 0x34]
// 006356fd  668b542408           mov dx, word ptr [esp + 8]
// 00635702  66891408             mov word ptr [eax + ecx], dx
// 00635706  83464002             add dword ptr [esi + 0x40], 2
// 0063570a  5e                   pop esi
// 0063570b  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeUInt16@BinaryOutput@G3D@@QAEXG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
