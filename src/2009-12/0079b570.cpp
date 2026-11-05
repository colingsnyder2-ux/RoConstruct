// from server: 100% by auto
// roc 2009-12 0079b570  unit: seg_00790000  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b570
//
// 0079b570  51                   push ecx
// 0079b571  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0079b575  8b4808               mov ecx, dword ptr [eax + 8]
// 0079b578  53                   push ebx
// 0079b579  8b1c8da0eb9e00       mov ebx, dword ptr [ecx*4 + 0x9eeba0]
// 0079b580  56                   push esi
// 0079b581  57                   push edi
// 0079b582  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0079b586  8b5714               mov edx, dword ptr [edi + 0x14]
// 0079b589  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0079b591  8b0a                 mov ecx, dword ptr [edx]
// 0079b593  8b7208               mov esi, dword ptr [edx + 8]
// 0079b596  3bce                 cmp ecx, esi
// 0079b598  7311                 jae 0x79b5ab
// 0079b59a  8d9b00000000         lea ebx, [ebx]
// 0079b5a0  3bc1                 cmp eax, ecx
// 0079b5a2  7420                 je 0x79b5c4
// 0079b5a4  83c110               add ecx, 0x10
// 0079b5a7  3bce                 cmp ecx, esi
// 0079b5a9  72f5                 jb 0x79b5a0
// 0079b5ab  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0079b5af  53                   push ebx
// 0079b5b0  51                   push ecx
// 0079b5b1  68e4ab9e00           push 0x9eabe4
// 0079b5b6  57                   push edi
// 0079b5b7  e884fdffff           call 0x79b340
// 0079b5bc  83c410               add esp, 0x10
// 0079b5bf  5f                   pop edi
// 0079b5c0  5e                   pop esi
// 0079b5c1  5b                   pop ebx
// 0079b5c2  59                   pop ecx
// 0079b5c3  c3                   ret 
// 0079b5c4  2b470c               sub eax, dword ptr [edi + 0xc]
// 0079b5c7  8d4c240c             lea ecx, [esp + 0xc]
// 0079b5cb  51                   push ecx
// 0079b5cc  52                   push edx
// 0079b5cd  c1f804               sar eax, 4
// 0079b5d0  57                   push edi
// 0079b5d1  e84afaffff           call 0x79b020
// 0079b5d6  83c40c               add esp, 0xc
// 0079b5d9  85c0                 test eax, eax
// 0079b5db  74ce                 je 0x79b5ab
// 0079b5dd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079b5e1  53                   push ebx
// 0079b5e2  52                   push edx
// 0079b5e3  50                   push eax
// 0079b5e4  8b442428             mov eax, dword ptr [esp + 0x28]
// 0079b5e8  50                   push eax
// 0079b5e9  68c0ab9e00           push 0x9eabc0
// 0079b5ee  57                   push edi
// 0079b5ef  e84cfdffff           call 0x79b340
// 0079b5f4  83c418               add esp, 0x18
// 0079b5f7  5f                   pop edi
// 0079b5f8  5e                   pop esi
// 0079b5f9  5b                   pop ebx
// 0079b5fa  59                   pop ecx
// 0079b5fb  c3                   ret 
// library lua-5.1/ldebug.c (function _luaG_typeerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
