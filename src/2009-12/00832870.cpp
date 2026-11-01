// from server: 100% by auto
// roc 2009-12 00832870  unit: CRobloxTreeCtrl  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832870
//
// 00832870  837c240800           cmp dword ptr [esp + 8], 0
// 00832875  56                   push esi
// 00832876  57                   push edi
// 00832877  8bf1                 mov esi, ecx
// 00832879  0f8491000000         je 0x832910
// 0083287f  53                   push ebx
// 00832880  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00832884  f6c304               test bl, 4
// 00832887  744a                 je 0x8328d3
// 00832889  837e0c00             cmp dword ptr [esi + 0xc], 0
// 0083288d  7519                 jne 0x8328a8
// 0083288f  8b4634               mov eax, dword ptr [esi + 0x34]
// 00832892  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832895  6a00                 push 0
// 00832897  6a09                 push 9
// 00832899  680a110000           push 0x110a
// 0083289e  50                   push eax
// 0083289f  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008328a5  89460c               mov dword ptr [esi + 0xc], eax
// 008328a8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008328ac  6a01                 push 1
// 008328ae  6a01                 push 1
// 008328b0  57                   push edi
// 008328b1  8bce                 mov ecx, esi
// 008328b3  e898f8ffff           call 0x832150
// 008328b8  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008328bb  c1eb03               shr ebx, 3
// 008328be  f7d3                 not ebx
// 008328c0  83e301               and ebx, 1
// 008328c3  53                   push ebx
// 008328c4  57                   push edi
// 008328c5  51                   push ecx
// 008328c6  8bce                 mov ecx, esi
// 008328c8  e853feffff           call 0x832720
// 008328cd  5b                   pop ebx
// 008328ce  5f                   pop edi
// 008328cf  5e                   pop esi
// 008328d0  c20c00               ret 0xc
// 008328d3  f6c308               test bl, 8
// 008328d6  752b                 jne 0x832903
// 008328d8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008328dc  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008328df  6a02                 push 2
// 008328e1  57                   push edi
// 008328e2  e81f3e0f00           call 0x926706
// 008328e7  a802                 test al, 2
// 008328e9  750c                 jne 0x8328f7
// 008328eb  8b16                 mov edx, dword ptr [esi]
// 008328ed  8b4250               mov eax, dword ptr [edx + 0x50]
// 008328f0  57                   push edi
// 008328f1  6a00                 push 0
// 008328f3  8bce                 mov ecx, esi
// 008328f5  ffd0                 call eax
// 008328f7  6a03                 push 3
// 008328f9  6a03                 push 3
// 008328fb  57                   push edi
// 008328fc  8bce                 mov ecx, esi
// 008328fe  e84df8ffff           call 0x832150
// 00832903  5b                   pop ebx
// 00832904  5f                   pop edi
// 00832905  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0083290c  5e                   pop esi
// 0083290d  c20c00               ret 0xc
// 00832910  8a442414             mov al, byte ptr [esp + 0x14]
// 00832914  a80c                 test al, 0xc
// 00832916  7410                 je 0x832928
// 00832918  a804                 test al, 4
// 0083291a  75b2                 jne 0x8328ce
// 0083291c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00832920  5f                   pop edi
// 00832921  894e0c               mov dword ptr [esi + 0xc], ecx
// 00832924  5e                   pop esi
// 00832925  c20c00               ret 0xc
// 00832928  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083292c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0083292f  6a02                 push 2
// 00832931  57                   push edi
// 00832932  e8cf3d0f00           call 0x926706
// 00832937  a802                 test al, 2
// 00832939  750c                 jne 0x832947
// 0083293b  8b16                 mov edx, dword ptr [esi]
// 0083293d  8b4250               mov eax, dword ptr [edx + 0x50]
// 00832940  57                   push edi
// 00832941  6a00                 push 0
// 00832943  8bce                 mov ecx, esi
// 00832945  ffd0                 call eax
// 00832947  6a03                 push 3
// 00832949  6a03                 push 3
// 0083294b  57                   push edi
// 0083294c  8bce                 mov ecx, esi
// 0083294e  e8fdf7ffff           call 0x832150
// 00832953  5f                   pop edi
// 00832954  5e                   pop esi
// 00832955  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?DoPreSelection@CXTPTreeBase@@MAEXPAU_TREEITEM@@HI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
