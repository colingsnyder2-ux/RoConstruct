// from server: 100% by auto
// roc 2009-12 0079efc0  unit: seg_00790000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079efc0
//
// 0079efc0  51                   push ecx
// 0079efc1  56                   push esi
// 0079efc2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0079efc6  57                   push edi
// 0079efc7  8d442408             lea eax, [esp + 8]
// 0079efcb  50                   push eax
// 0079efcc  6a01                 push 1
// 0079efce  56                   push esi
// 0079efcf  e89cb7feff           call 0x78a770
// 0079efd4  6a00                 push 0
// 0079efd6  8bf8                 mov edi, eax
// 0079efd8  57                   push edi
// 0079efd9  6a02                 push 2
// 0079efdb  56                   push esi
// 0079efdc  e8efb7feff           call 0x78a7d0
// 0079efe1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0079efe5  50                   push eax
// 0079efe6  51                   push ecx
// 0079efe7  57                   push edi
// 0079efe8  56                   push esi
// 0079efe9  e822b5feff           call 0x78a510
// 0079efee  83c42c               add esp, 0x2c
// 0079eff1  85c0                 test eax, eax
// 0079eff3  7509                 jne 0x79effe
// 0079eff5  5f                   pop edi
// 0079eff6  b801000000           mov eax, 1
// 0079effb  5e                   pop esi
// 0079effc  59                   pop ecx
// 0079effd  c3                   ret 
// 0079effe  56                   push esi
// 0079efff  e83c9dfeff           call 0x788d40
// 0079f004  6afe                 push -2
// 0079f006  56                   push esi
// 0079f007  e84498feff           call 0x788850
// 0079f00c  83c40c               add esp, 0xc
// 0079f00f  5f                   pop edi
// 0079f010  b802000000           mov eax, 2
// 0079f015  5e                   pop esi
// 0079f016  59                   pop ecx
// 0079f017  c3                   ret 
// library lua-5.1/lbaselib.c (function _luaB_loadstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
