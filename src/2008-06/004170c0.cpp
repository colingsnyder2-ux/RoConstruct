// from server: 100% by auto
// roc 2008-06 004170c0  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004170c0
//
// 004170c0  56                   push esi
// 004170c1  8bf1                 mov esi, ecx
// 004170c3  837e0c00             cmp dword ptr [esi + 0xc], 0
// 004170c7  7510                 jne 0x4170d9
// 004170c9  e8efef3800           call 0x7a60bd
// 004170ce  89460c               mov dword ptr [esi + 0xc], eax
// 004170d1  85c0                 test eax, eax
// 004170d3  7504                 jne 0x4170d9
// 004170d5  5e                   pop esi
// 004170d6  c20800               ret 8
// 004170d9  8b460c               mov eax, dword ptr [esi + 0xc]
// 004170dc  8b542408             mov edx, dword ptr [esp + 8]
// 004170e0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004170e4  2bd0                 sub edx, eax
// 004170e6  6a0d                 push 0xd
// 004170e8  83ea0d               sub edx, 0xd
// 004170eb  50                   push eax
// 004170ec  c700c7442404         mov dword ptr [eax], 0x42444c7
// 004170f2  894804               mov dword ptr [eax + 4], ecx
// 004170f5  c64008e9             mov byte ptr [eax + 8], 0xe9
// 004170f9  895009               mov dword ptr [eax + 9], edx
// 004170fc  ff15e4218000         call dword ptr [0x8021e4]
// 00417102  50                   push eax
// 00417103  ff15e0218000         call dword ptr [0x8021e0]
// 00417109  b801000000           mov eax, 1
// 0041710e  5e                   pop esi
// 0041710f  c20800               ret 8
// library atl-9.0/atl.cpp (function ?Init@CWndProcThunk@ATL@@QAEHP6GJPAUHWND__@@IIJ@ZPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
