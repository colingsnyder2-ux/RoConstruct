// from server: 100% by auto
// roc 2012-06 00635710  unit: G3D::LineSegment  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00635710
//
// 00635710  56                   push esi
// 00635711  8bf1                 mov esi, ecx
// 00635713  8b4640               mov eax, dword ptr [esi + 0x40]
// 00635716  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00635719  83c004               add eax, 4
// 0063571c  3bc8                 cmp ecx, eax
// 0063571e  7c02                 jl 0x635722
// 00635720  8bc1                 mov eax, ecx
// 00635722  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 00635725  894638               mov dword ptr [esi + 0x38], eax
// 00635728  7e0a                 jle 0x635734
// 0063572a  51                   push ecx
// 0063572b  6a04                 push 4
// 0063572d  8bce                 mov ecx, esi
// 0063572f  e88cfeffff           call 0x6355c0
// 00635734  807e2c00             cmp byte ptr [esi + 0x2c], 0
// 00635738  743b                 je 0x635775
// 0063573a  8b4640               mov eax, dword ptr [esi + 0x40]
// 0063573d  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00635740  8a54240b             mov dl, byte ptr [esp + 0xb]
// 00635744  881408               mov byte ptr [eax + ecx], dl
// 00635747  8b4640               mov eax, dword ptr [esi + 0x40]
// 0063574a  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0063574d  8a54240a             mov dl, byte ptr [esp + 0xa]
// 00635751  88540801             mov byte ptr [eax + ecx + 1], dl
// 00635755  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00635758  8b5634               mov edx, dword ptr [esi + 0x34]
// 0063575b  8b442408             mov eax, dword ptr [esp + 8]
// 0063575f  88641102             mov byte ptr [ecx + edx + 2], ah
// 00635763  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00635766  8b5634               mov edx, dword ptr [esi + 0x34]
// 00635769  88441103             mov byte ptr [ecx + edx + 3], al
// 0063576d  83464004             add dword ptr [esi + 0x40], 4
// 00635771  5e                   pop esi
// 00635772  c20400               ret 4
// 00635775  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00635778  8b4634               mov eax, dword ptr [esi + 0x34]
// 0063577b  8b542408             mov edx, dword ptr [esp + 8]
// 0063577f  891408               mov dword ptr [eax + ecx], edx
// 00635782  83464004             add dword ptr [esi + 0x40], 4
// 00635786  5e                   pop esi
// 00635787  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeUInt32@BinaryOutput@G3D@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
