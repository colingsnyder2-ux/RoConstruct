// from server: 100% by auto
// roc 2008-06 004c65c0  unit: ProfiledRakPeer  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c65c0
//
// 004c65c0  83ec20               sub esp, 0x20
// 004c65c3  53                   push ebx
// 004c65c4  8bd9                 mov ebx, ecx
// 004c65c6  8a4304               mov al, byte ptr [ebx + 4]
// 004c65c9  84c0                 test al, al
// 004c65cb  0f84db000000         je 0x4c66ac
// 004c65d1  57                   push edi
// 004c65d2  e839330000           call 0x4c9910
// 004c65d7  50                   push eax
// 004c65d8  e8d3d90000           call 0x4d3fb0
// 004c65dd  83c404               add esp, 4
// 004c65e0  8bcb                 mov ecx, ebx
// 004c65e2  e8a959ffff           call 0x4bbf90
// 004c65e7  8b442434             mov eax, dword ptr [esp + 0x34]
// 004c65eb  8b542438             mov edx, dword ptr [esp + 0x38]
// 004c65ef  b101                 mov cl, 1
// 004c65f1  888b9d080000         mov byte ptr [ebx + 0x89d], cl
// 004c65f7  85c0                 test eax, eax
// 004c65f9  752f                 jne 0x4c662a
// 004c65fb  85d2                 test edx, edx
// 004c65fd  752b                 jne 0x4c662a
// 004c65ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004c6603  85ff                 test edi, edi
// 004c6605  752b                 jne 0x4c6632
// 004c6607  397c2430             cmp dword ptr [esp + 0x30], edi
// 004c660b  0f8593000000         jne 0x4c66a4
// 004c6611  888b9c080000         mov byte ptr [ebx + 0x89c], cl
// 004c6617  8d8b44070000         lea ecx, [ebx + 0x744]
// 004c661d  e85effffff           call 0x4c6580
// 004c6622  5f                   pop edi
// 004c6623  5b                   pop ebx
// 004c6624  83c420               add esp, 0x20
// 004c6627  c21000               ret 0x10
// 004c662a  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004c662e  85ff                 test edi, edi
// 004c6630  741f                 je 0x4c6651
// 004c6632  56                   push esi
// 004c6633  8b742434             mov esi, dword ptr [esp + 0x34]
// 004c6637  85f6                 test esi, esi
// 004c6639  7415                 je 0x4c6650
// 004c663b  8b0f                 mov ecx, dword ptr [edi]
// 004c663d  898b78080000         mov dword ptr [ebx + 0x878], ecx
// 004c6643  8dbb7c080000         lea edi, [ebx + 0x87c]
// 004c6649  b908000000           mov ecx, 8
// 004c664e  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c6650  5e                   pop esi
// 004c6651  85c0                 test eax, eax
// 004c6653  744f                 je 0x4c66a4
// 004c6655  85d2                 test edx, edx
// 004c6657  744b                 je 0x4c66a4
// 004c6659  8b08                 mov ecx, dword ptr [eax]
// 004c665b  894c2418             mov dword ptr [esp + 0x18], ecx
// 004c665f  8b4804               mov ecx, dword ptr [eax + 4]
// 004c6662  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004c6666  8b4808               mov ecx, dword ptr [eax + 8]
// 004c6669  8b400c               mov eax, dword ptr [eax + 0xc]
// 004c666c  894c2420             mov dword ptr [esp + 0x20], ecx
// 004c6670  8b0a                 mov ecx, dword ptr [edx]
// 004c6672  89442424             mov dword ptr [esp + 0x24], eax
// 004c6676  8b4204               mov eax, dword ptr [edx + 4]
// 004c6679  894c2408             mov dword ptr [esp + 8], ecx
// 004c667d  8b4a08               mov ecx, dword ptr [edx + 8]
// 004c6680  8b520c               mov edx, dword ptr [edx + 0xc]
// 004c6683  8944240c             mov dword ptr [esp + 0xc], eax
// 004c6687  894c2410             mov dword ptr [esp + 0x10], ecx
// 004c668b  8d442408             lea eax, [esp + 8]
// 004c668f  50                   push eax
// 004c6690  8d4c241c             lea ecx, [esp + 0x1c]
// 004c6694  51                   push ecx
// 004c6695  8d8b44070000         lea ecx, [ebx + 0x744]
// 004c669b  8954241c             mov dword ptr [esp + 0x1c], edx
// 004c669f  e88ce4ffff           call 0x4c4b30
// 004c66a4  c6839c08000000       mov byte ptr [ebx + 0x89c], 0
// 004c66ab  5f                   pop edi
// 004c66ac  5b                   pop ebx
// 004c66ad  83c420               add esp, 0x20
// 004c66b0  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?InitializeSecurity@RakPeer@@UAEXPBD000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
