// from server: 100% by auto
// roc 2010-06 0044d000  unit: CRobloxApp  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044d000
//
// 0044d000  51                   push ecx
// 0044d001  56                   push esi
// 0044d002  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0044d006  8b4608               mov eax, dword ptr [esi + 8]
// 0044d009  c744240400000000     mov dword ptr [esp + 4], 0
// 0044d011  85c0                 test eax, eax
// 0044d013  7505                 jne 0x44d01a
// 0044d015  5e                   pop esi
// 0044d016  59                   pop ecx
// 0044d017  c20c00               ret 0xc
// 0044d01a  8b560c               mov edx, dword ptr [esi + 0xc]
// 0044d01d  57                   push edi
// 0044d01e  8d4c2408             lea ecx, [esp + 8]
// 0044d022  51                   push ecx
// 0044d023  684007a000           push 0xa00740
// 0044d028  52                   push edx
// 0044d029  ffd0                 call eax
// 0044d02b  8bf8                 mov edi, eax
// 0044d02d  85ff                 test edi, edi
// 0044d02f  7c1e                 jl 0x44d04f
// 0044d031  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044d035  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044d039  8d4614               lea eax, [esi + 0x14]
// 0044d03c  50                   push eax
// 0044d03d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044d041  51                   push ecx
// 0044d042  8b0e                 mov ecx, dword ptr [esi]
// 0044d044  52                   push edx
// 0044d045  50                   push eax
// 0044d046  51                   push ecx
// 0044d047  ff15e8d09e00         call dword ptr [0x9ed0e8]
// 0044d04d  8bf8                 mov edi, eax
// 0044d04f  8b442408             mov eax, dword ptr [esp + 8]
// 0044d053  85c0                 test eax, eax
// 0044d055  7408                 je 0x44d05f
// 0044d057  8b10                 mov edx, dword ptr [eax]
// 0044d059  50                   push eax
// 0044d05a  8b4208               mov eax, dword ptr [edx + 8]
// 0044d05d  ffd0                 call eax
// 0044d05f  8bc7                 mov eax, edi
// 0044d061  5f                   pop edi
// 0044d062  5e                   pop esi
// 0044d063  59                   pop ecx
// 0044d064  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
