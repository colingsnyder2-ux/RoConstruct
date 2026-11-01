// from server: 100% by auto
// roc 2007-03 00600a20  unit: seg_00600000  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600a20
//
// 00600a20  56                   push esi
// 00600a21  8b742408             mov esi, dword ptr [esp + 8]
// 00600a25  8b06                 mov eax, dword ptr [esi]
// 00600a27  57                   push edi
// 00600a28  50                   push eax
// 00600a29  e8e2c0ffff           call 0x5fcb10
// 00600a2e  8b0e                 mov ecx, dword ptr [esi]
// 00600a30  8bf8                 mov edi, eax
// 00600a32  8b4108               mov eax, dword ptr [ecx + 8]
// 00600a35  8938                 mov dword ptr [eax], edi
// 00600a37  c7400809000000       mov dword ptr [eax + 8], 9
// 00600a3e  8b06                 mov eax, dword ptr [esi]
// 00600a40  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00600a43  2b5008               sub edx, dword ptr [eax + 8]
// 00600a46  83c404               add esp, 4
// 00600a49  83fa10               cmp edx, 0x10
// 00600a4c  7f0b                 jg 0x600a59
// 00600a4e  6a01                 push 1
// 00600a50  50                   push eax
// 00600a51  e89af2fbff           call 0x5bfcf0
// 00600a56  83c408               add esp, 8
// 00600a59  8b06                 mov eax, dword ptr [esi]
// 00600a5b  83400810             add dword ptr [eax + 8], 0x10
// 00600a5f  e82cf9ffff           call 0x600390
// 00600a64  85c0                 test eax, eax
// 00600a66  894720               mov dword ptr [edi + 0x20], eax
// 00600a69  7507                 jne 0x600a72
// 00600a6b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00600a6f  894720               mov dword ptr [edi + 0x20], eax
// 00600a72  e8a9f8ffff           call 0x600320
// 00600a77  89473c               mov dword ptr [edi + 0x3c], eax
// 00600a7a  e8a1f8ffff           call 0x600320
// 00600a7f  6a01                 push 1
// 00600a81  8d4c2410             lea ecx, [esp + 0x10]
// 00600a85  894740               mov dword ptr [edi + 0x40], eax
// 00600a88  8b5604               mov edx, dword ptr [esi + 4]
// 00600a8b  51                   push ecx
// 00600a8c  52                   push edx
// 00600a8d  e8dec2ffff           call 0x5fcd70
// 00600a92  83c40c               add esp, 0xc
// 00600a95  85c0                 test eax, eax
// 00600a97  7423                 je 0x600abc
// 00600a99  8b460c               mov eax, dword ptr [esi + 0xc]
// 00600a9c  8b0e                 mov ecx, dword ptr [esi]
// 00600a9e  6898067c00           push 0x7c0698
// 00600aa3  50                   push eax
// 00600aa4  687c067c00           push 0x7c067c
// 00600aa9  51                   push ecx
// 00600aaa  e8917dffff           call 0x5f8840
// 00600aaf  8b16                 mov edx, dword ptr [esi]
// 00600ab1  6a03                 push 3
// 00600ab3  52                   push edx
// 00600ab4  e847f7fbff           call 0x5c0200
// 00600ab9  83c418               add esp, 0x18
// 00600abc  8a44240c             mov al, byte ptr [esp + 0xc]
// 00600ac0  6a01                 push 1
// 00600ac2  8d4c2410             lea ecx, [esp + 0x10]
// 00600ac6  884748               mov byte ptr [edi + 0x48], al
// 00600ac9  8b5604               mov edx, dword ptr [esi + 4]
// 00600acc  51                   push ecx
// 00600acd  52                   push edx
// 00600ace  e89dc2ffff           call 0x5fcd70
// 00600ad3  83c40c               add esp, 0xc
// 00600ad6  85c0                 test eax, eax
// 00600ad8  7423                 je 0x600afd
// 00600ada  8b460c               mov eax, dword ptr [esi + 0xc]
// 00600add  8b0e                 mov ecx, dword ptr [esi]
// 00600adf  6898067c00           push 0x7c0698
// 00600ae4  50                   push eax
// 00600ae5  687c067c00           push 0x7c067c
// 00600aea  51                   push ecx
// 00600aeb  e8507dffff           call 0x5f8840
// 00600af0  8b16                 mov edx, dword ptr [esi]
// 00600af2  6a03                 push 3
// 00600af4  52                   push edx
// 00600af5  e806f7fbff           call 0x5c0200
// 00600afa  83c418               add esp, 0x18
// 00600afd  8a44240c             mov al, byte ptr [esp + 0xc]
// 00600b01  6a01                 push 1
// 00600b03  8d4c2410             lea ecx, [esp + 0x10]
// 00600b07  884749               mov byte ptr [edi + 0x49], al
// 00600b0a  8b5604               mov edx, dword ptr [esi + 4]
// 00600b0d  51                   push ecx
// 00600b0e  52                   push edx
// 00600b0f  e85cc2ffff           call 0x5fcd70
// 00600b14  83c40c               add esp, 0xc
// 00600b17  85c0                 test eax, eax
// 00600b19  7423                 je 0x600b3e
// 00600b1b  8b460c               mov eax, dword ptr [esi + 0xc]
// 00600b1e  8b0e                 mov ecx, dword ptr [esi]
// 00600b20  6898067c00           push 0x7c0698
// 00600b25  50                   push eax
// 00600b26  687c067c00           push 0x7c067c
// 00600b2b  51                   push ecx
// 00600b2c  e80f7dffff           call 0x5f8840
// 00600b31  8b16                 mov edx, dword ptr [esi]
// 00600b33  6a03                 push 3
// 00600b35  52                   push edx
// 00600b36  e8c5f6fbff           call 0x5c0200
// 00600b3b  83c418               add esp, 0x18
// 00600b3e  8a44240c             mov al, byte ptr [esp + 0xc]
// 00600b42  6a01                 push 1
// 00600b44  8d4c2410             lea ecx, [esp + 0x10]
// 00600b48  88474a               mov byte ptr [edi + 0x4a], al
// 00600b4b  8b5604               mov edx, dword ptr [esi + 4]
// 00600b4e  51                   push ecx
// 00600b4f  52                   push edx
// 00600b50  e81bc2ffff           call 0x5fcd70
// 00600b55  83c40c               add esp, 0xc
// 00600b58  85c0                 test eax, eax
// 00600b5a  7423                 je 0x600b7f
// 00600b5c  8b460c               mov eax, dword ptr [esi + 0xc]
// 00600b5f  8b0e                 mov ecx, dword ptr [esi]
// 00600b61  6898067c00           push 0x7c0698
// 00600b66  50                   push eax
// 00600b67  687c067c00           push 0x7c067c
// 00600b6c  51                   push ecx
// 00600b6d  e8ce7cffff           call 0x5f8840
// 00600b72  8b16                 mov edx, dword ptr [esi]
// 00600b74  6a03                 push 3
// 00600b76  52                   push edx
// 00600b77  e884f6fbff           call 0x5c0200
// 00600b7c  83c418               add esp, 0x18
// 00600b7f  8a44240c             mov al, byte ptr [esp + 0xc]
// 00600b83  53                   push ebx
// 00600b84  88474b               mov byte ptr [edi + 0x4b], al
// 00600b87  8bdf                 mov ebx, edi
// 00600b89  8bc6                 mov eax, esi
// 00600b8b  e8b0f8ffff           call 0x600440
// 00600b90  57                   push edi
// 00600b91  8bc6                 mov eax, esi
// 00600b93  e828f9ffff           call 0x6004c0
// 00600b98  8bc6                 mov eax, esi
// 00600b9a  e8c1fbffff           call 0x600760
// 00600b9f  57                   push edi
// 00600ba0  e89b21fcff           call 0x5c2d40
// 00600ba5  83c408               add esp, 8
// 00600ba8  85c0                 test eax, eax
// 00600baa  5b                   pop ebx
// 00600bab  7523                 jne 0x600bd0
// 00600bad  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00600bb0  8b16                 mov edx, dword ptr [esi]
// 00600bb2  68c4067c00           push 0x7c06c4
// 00600bb7  51                   push ecx
// 00600bb8  687c067c00           push 0x7c067c
// 00600bbd  52                   push edx
// 00600bbe  e87d7cffff           call 0x5f8840
// 00600bc3  8b06                 mov eax, dword ptr [esi]
// 00600bc5  6a03                 push 3
// 00600bc7  50                   push eax
// 00600bc8  e833f6fbff           call 0x5c0200
// 00600bcd  83c418               add esp, 0x18
// 00600bd0  8b36                 mov esi, dword ptr [esi]
// 00600bd2  834608f0             add dword ptr [esi + 8], -0x10
// 00600bd6  8bc7                 mov eax, edi
// 00600bd8  5f                   pop edi
// 00600bd9  5e                   pop esi
// 00600bda  c3                   ret 
// library lua-5.1.1/lundump.c (function _LoadFunction)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
