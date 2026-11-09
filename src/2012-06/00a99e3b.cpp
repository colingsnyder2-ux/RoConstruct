// roc 2012-06 00a99e3b  unit: CSpinButtonCtrl  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a99e3b
//
// 00a99e3b  8bff                 mov edi, edi
// 00a99e3d  55                   push ebp
// 00a99e3e  8bec                 mov ebp, esp
// 00a99e40  e88d85eeff           call 0x9823d2
// 00a99e45  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00a99e48  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00a99e4b  884814               mov byte ptr [eax + 0x14], cl
// 00a99e4e  895044               mov dword ptr [eax + 0x44], edx
// 00a99e51  85c9                 test ecx, ecx
// 00a99e53  7509                 jne 0xa99e5e
// 00a99e55  6afd                 push -3
// 00a99e57  ff15ac2ab200         call dword ptr [0xb22aac]
// 00a99e5d  59                   pop ecx
// 00a99e5e  33c0                 xor eax, eax
// 00a99e60  40                   inc eax
// 00a99e61  5d                   pop ebp
// 00a99e62  c20800               ret 8
// copied from an identical function in another client (function ?AfxInitialize@@YGHHK@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm mfcs90.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/mfc/ansireleasedllstatic/objr/i386/appmodul.obj