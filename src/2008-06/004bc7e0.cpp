// from server: 100% by auto
// roc 2008-06 004bc7e0  unit: ProfiledRakPeer  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc7e0
//
// 004bc7e0  53                   push ebx
// 004bc7e1  56                   push esi
// 004bc7e2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004bc7e6  57                   push edi
// 004bc7e7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004bc7eb  8bd7                 mov edx, edi
// 004bc7ed  c1ea05               shr edx, 5
// 004bc7f0  83e71f               and edi, 0x1f
// 004bc7f3  85d2                 test edx, edx
// 004bc7f5  742c                 je 0x4bc823
// 004bc7f7  b807000000           mov eax, 7
// 004bc7fc  2bc2                 sub eax, edx
// 004bc7fe  7813                 js 0x4bc813
// 004bc800  8d0c10               lea ecx, [eax + edx]
// 004bc803  8d0c8e               lea ecx, [esi + ecx*4]
// 004bc806  8b1c86               mov ebx, dword ptr [esi + eax*4]
// 004bc809  8919                 mov dword ptr [ecx], ebx
// 004bc80b  48                   dec eax
// 004bc80c  83e904               sub ecx, 4
// 004bc80f  85c0                 test eax, eax
// 004bc811  7df3                 jge 0x4bc806
// 004bc813  03d2                 add edx, edx
// 004bc815  03d2                 add edx, edx
// 004bc817  52                   push edx
// 004bc818  6a00                 push 0
// 004bc81a  56                   push esi
// 004bc81b  e8e44e1e00           call 0x6a1704
// 004bc820  83c40c               add esp, 0xc
// 004bc823  85ff                 test edi, edi
// 004bc825  0f848f000000         je 0x4bc8ba
// 004bc82b  8b16                 mov edx, dword ptr [esi]
// 004bc82d  8b5e04               mov ebx, dword ptr [esi + 4]
// 004bc830  8bc2                 mov eax, edx
// 004bc832  55                   push ebp
// 004bc833  8bcf                 mov ecx, edi
// 004bc835  d3e0                 shl eax, cl
// 004bc837  8beb                 mov ebp, ebx
// 004bc839  8906                 mov dword ptr [esi], eax
// 004bc83b  b820000000           mov eax, 0x20
// 004bc840  2bc7                 sub eax, edi
// 004bc842  8bc8                 mov ecx, eax
// 004bc844  d3ea                 shr edx, cl
// 004bc846  8bcf                 mov ecx, edi
// 004bc848  d3e5                 shl ebp, cl
// 004bc84a  8bc8                 mov ecx, eax
// 004bc84c  d3eb                 shr ebx, cl
// 004bc84e  8bcf                 mov ecx, edi
// 004bc850  0bea                 or ebp, edx
// 004bc852  8b5608               mov edx, dword ptr [esi + 8]
// 004bc855  896e04               mov dword ptr [esi + 4], ebp
// 004bc858  8bea                 mov ebp, edx
// 004bc85a  d3e5                 shl ebp, cl
// 004bc85c  8bc8                 mov ecx, eax
// 004bc85e  d3ea                 shr edx, cl
// 004bc860  8bcf                 mov ecx, edi
// 004bc862  0beb                 or ebp, ebx
// 004bc864  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004bc867  896e08               mov dword ptr [esi + 8], ebp
// 004bc86a  8beb                 mov ebp, ebx
// 004bc86c  d3e5                 shl ebp, cl
// 004bc86e  8bc8                 mov ecx, eax
// 004bc870  d3eb                 shr ebx, cl
// 004bc872  8bcf                 mov ecx, edi
// 004bc874  0bea                 or ebp, edx
// 004bc876  8b5610               mov edx, dword ptr [esi + 0x10]
// 004bc879  896e0c               mov dword ptr [esi + 0xc], ebp
// 004bc87c  8bea                 mov ebp, edx
// 004bc87e  d3e5                 shl ebp, cl
// 004bc880  8bc8                 mov ecx, eax
// 004bc882  d3ea                 shr edx, cl
// 004bc884  8bcf                 mov ecx, edi
// 004bc886  0beb                 or ebp, ebx
// 004bc888  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 004bc88b  896e10               mov dword ptr [esi + 0x10], ebp
// 004bc88e  8beb                 mov ebp, ebx
// 004bc890  d3e5                 shl ebp, cl
// 004bc892  8bc8                 mov ecx, eax
// 004bc894  d3eb                 shr ebx, cl
// 004bc896  8bcf                 mov ecx, edi
// 004bc898  0bea                 or ebp, edx
// 004bc89a  8b5618               mov edx, dword ptr [esi + 0x18]
// 004bc89d  896e14               mov dword ptr [esi + 0x14], ebp
// 004bc8a0  8bea                 mov ebp, edx
// 004bc8a2  d3e5                 shl ebp, cl
// 004bc8a4  8bc8                 mov ecx, eax
// 004bc8a6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004bc8a9  d3ea                 shr edx, cl
// 004bc8ab  8bcf                 mov ecx, edi
// 004bc8ad  d3e0                 shl eax, cl
// 004bc8af  0beb                 or ebp, ebx
// 004bc8b1  896e18               mov dword ptr [esi + 0x18], ebp
// 004bc8b4  5d                   pop ebp
// 004bc8b5  0bc2                 or eax, edx
// 004bc8b7  89461c               mov dword ptr [esi + 0x1c], eax
// 004bc8ba  5f                   pop edi
// 004bc8bb  5e                   pop esi
// 004bc8bc  5b                   pop ebx
// 004bc8bd  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$shiftLeft@$$BY07I@big@@YAXAAY07II@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
