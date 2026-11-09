// from server: 100% by auto
// roc 2009-12 00553510  unit: RBX::Network::ClientReplicator  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00553510
//
// 00553510  53                   push ebx
// 00553511  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00553515  8b4304               mov eax, dword ptr [ebx + 4]
// 00553518  55                   push ebp
// 00553519  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0055351d  56                   push esi
// 0055351e  57                   push edi
// 0055351f  8d78ff               lea edi, [eax - 1]
// 00553522  99                   cdq 
// 00553523  2bc2                 sub eax, edx
// 00553525  d1f8                 sar eax, 1
// 00553527  8b4c8308             mov ecx, dword ptr [ebx + eax*4 + 8]
// 0055352b  33f6                 xor esi, esi
// 0055352d  3be9                 cmp ebp, ecx
// 0055352f  7421                 je 0x553552
// 00553531  7305                 jae 0x553538
// 00553533  8d78ff               lea edi, [eax - 1]
// 00553536  eb03                 jmp 0x55353b
// 00553538  8d7001               lea esi, [eax + 1]
// 0055353b  8bc7                 mov eax, edi
// 0055353d  2bc6                 sub eax, esi
// 0055353f  99                   cdq 
// 00553540  2bc2                 sub eax, edx
// 00553542  d1f8                 sar eax, 1
// 00553544  03c6                 add eax, esi
// 00553546  3bf7                 cmp esi, edi
// 00553548  7f17                 jg 0x553561
// 0055354a  8b4c8308             mov ecx, dword ptr [ebx + eax*4 + 8]
// 0055354e  3be9                 cmp ebp, ecx
// 00553550  75df                 jne 0x553531
// 00553552  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00553556  5f                   pop edi
// 00553557  5e                   pop esi
// 00553558  5d                   pop ebp
// 00553559  8901                 mov dword ptr [ecx], eax
// 0055355b  b001                 mov al, 1
// 0055355d  5b                   pop ebx
// 0055355e  c20c00               ret 0xc
// 00553561  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00553565  5f                   pop edi
// 00553566  8932                 mov dword ptr [edx], esi
// 00553568  5e                   pop esi
// 00553569  5d                   pop ebp
// 0055356a  32c0                 xor al, al
// 0055356c  5b                   pop ebx
// 0055356d  c20c00               ret 0xc
// library raknet-4.081/DS_Table.cpp (function ?GetIndexOf@?$BPlusTree@IPAURow@Table@DataStructures@@$0BA@@DataStructures@@IBE_NIPAU?$Page@IPAURow@Table@DataStructures@@$0BA@@2@PAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 DS_Table.cpp
