// from server: 100% by auto
// roc 2008-06 004bc380  unit: ProfiledRakPeer  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc380
//
// 004bc380  53                   push ebx
// 004bc381  56                   push esi
// 004bc382  57                   push edi
// 004bc383  6a40                 push 0x40
// 004bc385  8bf1                 mov esi, ecx
// 004bc387  e894451e00           call 0x6a0920
// 004bc38c  894608               mov dword ptr [esi + 8], eax
// 004bc38f  33db                 xor ebx, ebx
// 004bc391  885838               mov byte ptr [eax + 0x38], bl
// 004bc394  8b4608               mov eax, dword ptr [esi + 8]
// 004bc397  6a40                 push 0x40
// 004bc399  89460c               mov dword ptr [esi + 0xc], eax
// 004bc39c  e87f451e00           call 0x6a0920
// 004bc3a1  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc3a4  83c408               add esp, 8
// 004bc3a7  89413c               mov dword ptr [ecx + 0x3c], eax
// 004bc3aa  8d7b06               lea edi, [ebx + 6]
// 004bc3ad  8d4900               lea ecx, [ecx]
// 004bc3b0  8b5608               mov edx, dword ptr [esi + 8]
// 004bc3b3  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bc3b6  6a40                 push 0x40
// 004bc3b8  894608               mov dword ptr [esi + 8], eax
// 004bc3bb  e860451e00           call 0x6a0920
// 004bc3c0  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc3c3  89413c               mov dword ptr [ecx + 0x3c], eax
// 004bc3c6  8b5608               mov edx, dword ptr [esi + 8]
// 004bc3c9  83c404               add esp, 4
// 004bc3cc  83ef01               sub edi, 1
// 004bc3cf  885a38               mov byte ptr [edx + 0x38], bl
// 004bc3d2  75dc                 jne 0x4bc3b0
// 004bc3d4  8b4608               mov eax, dword ptr [esi + 8]
// 004bc3d7  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bc3da  8b560c               mov edx, dword ptr [esi + 0xc]
// 004bc3dd  89513c               mov dword ptr [ecx + 0x3c], edx
// 004bc3e0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc3e3  894608               mov dword ptr [esi + 8], eax
// 004bc3e6  8906                 mov dword ptr [esi], eax
// 004bc3e8  894604               mov dword ptr [esi + 4], eax
// 004bc3eb  5f                   pop edi
// 004bc3ec  895e14               mov dword ptr [esi + 0x14], ebx
// 004bc3ef  895e10               mov dword ptr [esi + 0x10], ebx
// 004bc3f2  8bc6                 mov eax, esi
// 004bc3f4  5e                   pop esi
// 004bc3f5  5b                   pop ebx
// 004bc3f6  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??0?$SingleProducerConsumer@UBufferedCommandStruct@RakPeer@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
