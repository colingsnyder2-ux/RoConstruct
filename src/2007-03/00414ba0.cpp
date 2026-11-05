// from server: 100% by auto
// roc 2007-03 00414ba0  unit: seg_00410000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00414ba0
//
// 00414ba0  56                   push esi
// 00414ba1  8bf1                 mov esi, ecx
// 00414ba3  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00414ba7  7510                 jne 0x414bb9
// 00414ba9  e8691b3100           call 0x726717
// 00414bae  85c0                 test eax, eax
// 00414bb0  89460c               mov dword ptr [esi + 0xc], eax
// 00414bb3  7504                 jne 0x414bb9
// 00414bb5  5e                   pop esi
// 00414bb6  c20800               ret 8
// 00414bb9  8b460c               mov eax, dword ptr [esi + 0xc]
// 00414bbc  8b542408             mov edx, dword ptr [esp + 8]
// 00414bc0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00414bc4  2bd0                 sub edx, eax
// 00414bc6  6a0d                 push 0xd
// 00414bc8  83ea0d               sub edx, 0xd
// 00414bcb  50                   push eax
// 00414bcc  c700c7442404         mov dword ptr [eax], 0x42444c7
// 00414bd2  894804               mov dword ptr [eax + 4], ecx
// 00414bd5  c64008e9             mov byte ptr [eax + 8], 0xe9
// 00414bd9  895009               mov dword ptr [eax + 9], edx
// 00414bdc  ff1554d27700         call dword ptr [0x77d254]
// 00414be2  50                   push eax
// 00414be3  ff1558d27700         call dword ptr [0x77d258]
// 00414be9  b801000000           mov eax, 1
// 00414bee  5e                   pop esi
// 00414bef  c20800               ret 8
// library atl-8.0/atl.cpp (function ?Init@CWndProcThunk@ATL@@QAEHP6GJPAUHWND__@@IIJ@ZPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
