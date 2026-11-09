// roc 2012-06 005ba890  unit: RakNet::RakPeer  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba890
//
// 005ba890  8b442408             mov eax, dword ptr [esp + 8]
// 005ba894  85c0                 test eax, eax
// 005ba896  7c48                 jl 0x5ba8e0
// 005ba898  0fb7510e             movzx edx, word ptr [ecx + 0xe]
// 005ba89c  3bc2                 cmp eax, edx
// 005ba89e  7d40                 jge 0x5ba8e0
// 005ba8a0  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 005ba8a6  69c008120000         imul eax, eax, 0x1208
// 005ba8ac  03c8                 add ecx, eax
// 005ba8ae  803900               cmp byte ptr [ecx], 0
// 005ba8b1  742d                 je 0x5ba8e0
// 005ba8b3  83b90012000007       cmp dword ptr [ecx + 0x1200], 7
// 005ba8ba  7524                 jne 0x5ba8e0
// 005ba8bc  8b442404             mov eax, dword ptr [esp + 4]
// 005ba8c0  8b5104               mov edx, dword ptr [ecx + 4]
// 005ba8c3  8910                 mov dword ptr [eax], edx
// 005ba8c5  8b5108               mov edx, dword ptr [ecx + 8]
// 005ba8c8  895004               mov dword ptr [eax + 4], edx
// 005ba8cb  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005ba8ce  895008               mov dword ptr [eax + 8], edx
// 005ba8d1  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005ba8d4  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005ba8d7  89500c               mov dword ptr [eax + 0xc], edx
// 005ba8da  894810               mov dword ptr [eax + 0x10], ecx
// 005ba8dd  c20800               ret 8
// 005ba8e0  8b442404             mov eax, dword ptr [esp + 4]
// 005ba8e4  8b154c69e200         mov edx, dword ptr [0xe2694c]
// 005ba8ea  8b0d5069e200         mov ecx, dword ptr [0xe26950]
// 005ba8f0  8910                 mov dword ptr [eax], edx
// 005ba8f2  8b155469e200         mov edx, dword ptr [0xe26954]
// 005ba8f8  894804               mov dword ptr [eax + 4], ecx
// 005ba8fb  8b0d5869e200         mov ecx, dword ptr [0xe26958]
// 005ba901  895008               mov dword ptr [eax + 8], edx
// 005ba904  8b155c69e200         mov edx, dword ptr [0xe2695c]
// 005ba90a  89480c               mov dword ptr [eax + 0xc], ecx
// 005ba90d  895010               mov dword ptr [eax + 0x10], edx
// 005ba910  c20800               ret 8
// copied from an identical function in another client (function ?GetSystemAddressFromIndex@RakPeer@RakNet@@UAE?AUSystemAddress@2@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp