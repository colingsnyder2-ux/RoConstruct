// from server: 100% by auto
// roc 2011-06 00545280  unit: G3D::BinaryInput  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00545280
//
// 00545280  56                   push esi
// 00545281  8bf1                 mov esi, ecx
// 00545283  8b4640               mov eax, dword ptr [esi + 0x40]
// 00545286  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00545289  83c004               add eax, 4
// 0054528c  3bc8                 cmp ecx, eax
// 0054528e  7c02                 jl 0x545292
// 00545290  8bc1                 mov eax, ecx
// 00545292  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 00545295  894638               mov dword ptr [esi + 0x38], eax
// 00545298  7e0a                 jle 0x5452a4
// 0054529a  51                   push ecx
// 0054529b  6a04                 push 4
// 0054529d  8bce                 mov ecx, esi
// 0054529f  e88cfeffff           call 0x545130
// 005452a4  807e2c00             cmp byte ptr [esi + 0x2c], 0
// 005452a8  743b                 je 0x5452e5
// 005452aa  8b4640               mov eax, dword ptr [esi + 0x40]
// 005452ad  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005452b0  8a54240b             mov dl, byte ptr [esp + 0xb]
// 005452b4  881408               mov byte ptr [eax + ecx], dl
// 005452b7  8b4640               mov eax, dword ptr [esi + 0x40]
// 005452ba  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005452bd  8a54240a             mov dl, byte ptr [esp + 0xa]
// 005452c1  88540801             mov byte ptr [eax + ecx + 1], dl
// 005452c5  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005452c8  8b5634               mov edx, dword ptr [esi + 0x34]
// 005452cb  8b442408             mov eax, dword ptr [esp + 8]
// 005452cf  88641102             mov byte ptr [ecx + edx + 2], ah
// 005452d3  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005452d6  8b5634               mov edx, dword ptr [esi + 0x34]
// 005452d9  88441103             mov byte ptr [ecx + edx + 3], al
// 005452dd  83464004             add dword ptr [esi + 0x40], 4
// 005452e1  5e                   pop esi
// 005452e2  c20400               ret 4
// 005452e5  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005452e8  8b4634               mov eax, dword ptr [esi + 0x34]
// 005452eb  8b542408             mov edx, dword ptr [esp + 8]
// 005452ef  891408               mov dword ptr [eax + ecx], edx
// 005452f2  83464004             add dword ptr [esi + 0x40], 4
// 005452f6  5e                   pop esi
// 005452f7  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeUInt32@BinaryOutput@G3D@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
