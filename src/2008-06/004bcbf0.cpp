// from server: 100% by auto
// roc 2008-06 004bcbf0  unit: ProfiledRakPeer  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bcbf0
//
// 004bcbf0  53                   push ebx
// 004bcbf1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 004bcbf5  8bd3                 mov edx, ebx
// 004bcbf7  56                   push esi
// 004bcbf8  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004bcbfc  c1ea05               shr edx, 5
// 004bcbff  83e31f               and ebx, 0x1f
// 004bcc02  57                   push edi
// 004bcc03  85d2                 test edx, edx
// 004bcc05  742c                 je 0x4bcc33
// 004bcc07  b803000000           mov eax, 3
// 004bcc0c  2bc2                 sub eax, edx
// 004bcc0e  7813                 js 0x4bcc23
// 004bcc10  8d0c10               lea ecx, [eax + edx]
// 004bcc13  8d0c8e               lea ecx, [esi + ecx*4]
// 004bcc16  8b3c86               mov edi, dword ptr [esi + eax*4]
// 004bcc19  8939                 mov dword ptr [ecx], edi
// 004bcc1b  48                   dec eax
// 004bcc1c  83e904               sub ecx, 4
// 004bcc1f  85c0                 test eax, eax
// 004bcc21  7df3                 jge 0x4bcc16
// 004bcc23  03d2                 add edx, edx
// 004bcc25  03d2                 add edx, edx
// 004bcc27  52                   push edx
// 004bcc28  6a00                 push 0
// 004bcc2a  56                   push esi
// 004bcc2b  e8d44a1e00           call 0x6a1704
// 004bcc30  83c40c               add esp, 0xc
// 004bcc33  85db                 test ebx, ebx
// 004bcc35  7447                 je 0x4bcc7e
// 004bcc37  8b06                 mov eax, dword ptr [esi]
// 004bcc39  8b7e04               mov edi, dword ptr [esi + 4]
// 004bcc3c  8bd0                 mov edx, eax
// 004bcc3e  8bcb                 mov ecx, ebx
// 004bcc40  d3e2                 shl edx, cl
// 004bcc42  55                   push ebp
// 004bcc43  8bef                 mov ebp, edi
// 004bcc45  8916                 mov dword ptr [esi], edx
// 004bcc47  ba20000000           mov edx, 0x20
// 004bcc4c  2bd3                 sub edx, ebx
// 004bcc4e  8bca                 mov ecx, edx
// 004bcc50  d3e8                 shr eax, cl
// 004bcc52  8bcb                 mov ecx, ebx
// 004bcc54  d3e5                 shl ebp, cl
// 004bcc56  8bca                 mov ecx, edx
// 004bcc58  d3ef                 shr edi, cl
// 004bcc5a  8bcb                 mov ecx, ebx
// 004bcc5c  0be8                 or ebp, eax
// 004bcc5e  8b4608               mov eax, dword ptr [esi + 8]
// 004bcc61  896e04               mov dword ptr [esi + 4], ebp
// 004bcc64  8be8                 mov ebp, eax
// 004bcc66  d3e5                 shl ebp, cl
// 004bcc68  8bca                 mov ecx, edx
// 004bcc6a  8b560c               mov edx, dword ptr [esi + 0xc]
// 004bcc6d  d3e8                 shr eax, cl
// 004bcc6f  8bcb                 mov ecx, ebx
// 004bcc71  d3e2                 shl edx, cl
// 004bcc73  0bef                 or ebp, edi
// 004bcc75  896e08               mov dword ptr [esi + 8], ebp
// 004bcc78  5d                   pop ebp
// 004bcc79  0bd0                 or edx, eax
// 004bcc7b  89560c               mov dword ptr [esi + 0xc], edx
// 004bcc7e  5f                   pop edi
// 004bcc7f  5e                   pop esi
// 004bcc80  5b                   pop ebx
// 004bcc81  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$shiftLeft@$$BY03I@big@@YAXAAY03II@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
