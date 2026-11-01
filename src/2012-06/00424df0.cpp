// from server: 100% by auto
// roc 2012-06 00424df0  unit: RBX::FunctionMarshaller  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00424df0
//
// 00424df0  56                   push esi
// 00424df1  8bf1                 mov esi, ecx
// 00424df3  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00424df7  7510                 jne 0x424e09
// 00424df9  e8eb6d6500           call 0xa7bbe9
// 00424dfe  89460c               mov dword ptr [esi + 0xc], eax
// 00424e01  85c0                 test eax, eax
// 00424e03  7504                 jne 0x424e09
// 00424e05  5e                   pop esi
// 00424e06  c20800               ret 8
// 00424e09  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424e0c  8b542408             mov edx, dword ptr [esp + 8]
// 00424e10  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00424e14  2bd0                 sub edx, eax
// 00424e16  6a0d                 push 0xd
// 00424e18  83ea0d               sub edx, 0xd
// 00424e1b  50                   push eax
// 00424e1c  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00424e22  894804               mov dword ptr [eax + 4], ecx
// 00424e25  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00424e29  895009               mov dword ptr [eax + 9], edx
// 00424e2c  ff159422b200         call dword ptr [0xb22294]
// 00424e32  50                   push eax
// 00424e33  ff159022b200         call dword ptr [0xb22290]
// 00424e39  b801000000           mov eax, 1
// 00424e3e  5e                   pop esi
// 00424e3f  c20800               ret 8
// library atl-9.0/atl.cpp (function ?Init@CWndProcThunk@ATL@@QAEHP6GJPAUHWND__@@IIJ@ZPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
