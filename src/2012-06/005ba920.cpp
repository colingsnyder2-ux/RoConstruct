// roc 2012-06 005ba920  unit: RakNet::RakPeer  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba920
//
// 005ba920  8b442408             mov eax, dword ptr [esp + 8]
// 005ba924  85c0                 test eax, eax
// 005ba926  7c4e                 jl 0x5ba976
// 005ba928  0fb7510e             movzx edx, word ptr [ecx + 0xe]
// 005ba92c  3bc2                 cmp eax, edx
// 005ba92e  7d46                 jge 0x5ba976
// 005ba930  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 005ba936  69c008120000         imul eax, eax, 0x1208
// 005ba93c  03c8                 add ecx, eax
// 005ba93e  803900               cmp byte ptr [ecx], 0
// 005ba941  7433                 je 0x5ba976
// 005ba943  83b90012000007       cmp dword ptr [ecx + 0x1200], 7
// 005ba94a  752a                 jne 0x5ba976
// 005ba94c  8b442404             mov eax, dword ptr [esp + 4]
// 005ba950  8b91e0110000         mov edx, dword ptr [ecx + 0x11e0]
// 005ba956  8910                 mov dword ptr [eax], edx
// 005ba958  8b91e4110000         mov edx, dword ptr [ecx + 0x11e4]
// 005ba95e  895004               mov dword ptr [eax + 4], edx
// 005ba961  8b91e8110000         mov edx, dword ptr [ecx + 0x11e8]
// 005ba967  8b89ec110000         mov ecx, dword ptr [ecx + 0x11ec]
// 005ba96d  895008               mov dword ptr [eax + 8], edx
// 005ba970  89480c               mov dword ptr [eax + 0xc], ecx
// 005ba973  c20800               ret 8
// 005ba976  8b442404             mov eax, dword ptr [esp + 4]
// 005ba97a  8b15f815d900         mov edx, dword ptr [0xd915f8]
// 005ba980  8b0dfc15d900         mov ecx, dword ptr [0xd915fc]
// 005ba986  8910                 mov dword ptr [eax], edx
// 005ba988  8b150016d900         mov edx, dword ptr [0xd91600]
// 005ba98e  894804               mov dword ptr [eax + 4], ecx
// 005ba991  8b0d0416d900         mov ecx, dword ptr [0xd91604]
// 005ba997  895008               mov dword ptr [eax + 8], edx
// 005ba99a  89480c               mov dword ptr [eax + 0xc], ecx
// 005ba99d  c20800               ret 8
// copied from an identical function in another client (function ?GetGUIDFromIndex@RakPeer@RakNet@@UAE?AURakNetGUID@2@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp