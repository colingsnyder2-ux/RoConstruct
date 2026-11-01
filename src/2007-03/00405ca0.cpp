// from server: 100% by auto
// roc 2007-03 00405ca0  unit: seg_00400000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00405ca0
//
// 00405ca0  53                   push ebx
// 00405ca1  56                   push esi
// 00405ca2  57                   push edi
// 00405ca3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00405ca7  8d7704               lea esi, [edi + 4]
// 00405caa  56                   push esi
// 00405cab  ff15a8d27700         call dword ptr [0x77d2a8]
// 00405cb1  8bd8                 mov ebx, eax
// 00405cb3  85db                 test ebx, ebx
// 00405cb5  752d                 jne 0x405ce4
// 00405cb7  85ff                 test edi, edi
// 00405cb9  7429                 je 0x405ce4
// 00405cbb  8d4604               lea eax, [esi + 4]
// 00405cbe  c706010000c0         mov dword ptr [esi], 0xc0000001
// 00405cc4  c707c83e7800         mov dword ptr [edi], 0x783ec8
// 00405cca  385818               cmp byte ptr [eax + 0x18], bl
// 00405ccd  740a                 je 0x405cd9
// 00405ccf  50                   push eax
// 00405cd0  885818               mov byte ptr [eax + 0x18], bl
// 00405cd3  ff15c4d27700         call dword ptr [0x77d2c4]
// 00405cd9  57                   push edi
// 00405cda  e811842100           call 0x61e0f0
// 00405cdf  83c404               add esp, 4
// 00405ce2  8bc3                 mov eax, ebx
// 00405ce4  5f                   pop edi
// 00405ce5  5e                   pop esi
// 00405ce6  5b                   pop ebx
// 00405ce7  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
