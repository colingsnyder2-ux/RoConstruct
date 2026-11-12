// from server: 100% by auto
// roc 2008-06 004bc9a0  unit: ProfiledRakPeer  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc9a0
//
// 004bc9a0  51                   push ecx
// 004bc9a1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bc9a5  55                   push ebp
// 004bc9a6  8bd0                 mov edx, eax
// 004bc9a8  83e01f               and eax, 0x1f
// 004bc9ab  56                   push esi
// 004bc9ac  8b742410             mov esi, dword ptr [esp + 0x10]
// 004bc9b0  c1ea05               shr edx, 5
// 004bc9b3  8be8                 mov ebp, eax
// 004bc9b5  57                   push edi
// 004bc9b6  896c2418             mov dword ptr [esp + 0x18], ebp
// 004bc9ba  85d2                 test edx, edx
// 004bc9bc  742f                 je 0x4bc9ed
// 004bc9be  b80f000000           mov eax, 0xf
// 004bc9c3  2bc2                 sub eax, edx
// 004bc9c5  7816                 js 0x4bc9dd
// 004bc9c7  8d0c10               lea ecx, [eax + edx]
// 004bc9ca  8d0c8e               lea ecx, [esi + ecx*4]
// 004bc9cd  8d4900               lea ecx, [ecx]
// 004bc9d0  8b3c86               mov edi, dword ptr [esi + eax*4]
// 004bc9d3  8939                 mov dword ptr [ecx], edi
// 004bc9d5  48                   dec eax
// 004bc9d6  83e904               sub ecx, 4
// 004bc9d9  85c0                 test eax, eax
// 004bc9db  7df3                 jge 0x4bc9d0
// 004bc9dd  03d2                 add edx, edx
// 004bc9df  03d2                 add edx, edx
// 004bc9e1  52                   push edx
// 004bc9e2  6a00                 push 0
// 004bc9e4  56                   push esi
// 004bc9e5  e81a4d1e00           call 0x6a1704
// 004bc9ea  83c40c               add esp, 0xc
// 004bc9ed  85ed                 test ebp, ebp
// 004bc9ef  7435                 je 0x4bca26
// 004bc9f1  53                   push ebx
// 004bc9f2  bb20000000           mov ebx, 0x20
// 004bc9f7  33ff                 xor edi, edi
// 004bc9f9  33d2                 xor edx, edx
// 004bc9fb  2bdd                 sub ebx, ebp
// 004bc9fd  eb05                 jmp 0x4bca04
// 004bc9ff  90                   nop 
// 004bca00  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004bca04  8b0496               mov eax, dword ptr [esi + edx*4]
// 004bca07  8bc8                 mov ecx, eax
// 004bca09  894c2410             mov dword ptr [esp + 0x10], ecx
// 004bca0d  8bcd                 mov ecx, ebp
// 004bca0f  8be8                 mov ebp, eax
// 004bca11  d3e5                 shl ebp, cl
// 004bca13  8bcb                 mov ecx, ebx
// 004bca15  d3e8                 shr eax, cl
// 004bca17  42                   inc edx
// 004bca18  0bef                 or ebp, edi
// 004bca1a  896c96fc             mov dword ptr [esi + edx*4 - 4], ebp
// 004bca1e  8bf8                 mov edi, eax
// 004bca20  83fa10               cmp edx, 0x10
// 004bca23  72db                 jb 0x4bca00
// 004bca25  5b                   pop ebx
// 004bca26  5f                   pop edi
// 004bca27  5e                   pop esi
// 004bca28  5d                   pop ebp
// 004bca29  59                   pop ecx
// 004bca2a  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$shiftLeft@$$BY0BA@I@big@@YAXAAY0BA@II@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
