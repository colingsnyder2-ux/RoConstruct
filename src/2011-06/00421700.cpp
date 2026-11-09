// from server: 100% by auto
// roc 2011-06 00421700  unit: RBX::FunctionMarshaller  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00421700
//
// 00421700  56                   push esi
// 00421701  8bf1                 mov esi, ecx
// 00421703  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00421707  7510                 jne 0x421719
// 00421709  e8f3244e00           call 0x903c01
// 0042170e  89460c               mov dword ptr [esi + 0xc], eax
// 00421711  85c0                 test eax, eax
// 00421713  7504                 jne 0x421719
// 00421715  5e                   pop esi
// 00421716  c20800               ret 8
// 00421719  8b460c               mov eax, dword ptr [esi + 0xc]
// 0042171c  8b542408             mov edx, dword ptr [esp + 8]
// 00421720  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00421724  2bd0                 sub edx, eax
// 00421726  6a0d                 push 0xd
// 00421728  83ea0d               sub edx, 0xd
// 0042172b  50                   push eax
// 0042172c  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00421732  894804               mov dword ptr [eax + 4], ecx
// 00421735  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00421739  895009               mov dword ptr [eax + 9], edx
// 0042173c  ff150802a400         call dword ptr [0xa40208]
// 00421742  50                   push eax
// 00421743  ff152802a400         call dword ptr [0xa40228]
// 00421749  b801000000           mov eax, 1
// 0042174e  5e                   pop esi
// 0042174f  c20800               ret 8
// library atl-9.0/atl.cpp (function ?Init@CWndProcThunk@ATL@@QAEHP6GJPAUHWND__@@IIJ@ZPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
