// from server: 100% by auto
// roc 2007-03 00401ca0  unit: seg_00400000  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401ca0
//
// 00401ca0  51                   push ecx
// 00401ca1  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00401ca5  56                   push esi
// 00401ca6  8d442404             lea eax, [esp + 4]
// 00401caa  50                   push eax
// 00401cab  8b442410             mov eax, dword ptr [esp + 0x10]
// 00401caf  8bf1                 mov esi, ecx
// 00401cb1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00401cb5  51                   push ecx
// 00401cb6  6a00                 push 0
// 00401cb8  52                   push edx
// 00401cb9  50                   push eax
// 00401cba  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00401cc2  ff1524d07700         call dword ptr [0x77d024]
// 00401cc8  85c0                 test eax, eax
// 00401cca  7519                 jne 0x401ce5
// 00401ccc  8b0e                 mov ecx, dword ptr [esi]
// 00401cce  85c9                 test ecx, ecx
// 00401cd0  740d                 je 0x401cdf
// 00401cd2  51                   push ecx
// 00401cd3  ff152cd07700         call dword ptr [0x77d02c]
// 00401cd9  c70600000000         mov dword ptr [esi], 0
// 00401cdf  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00401ce3  890e                 mov dword ptr [esi], ecx
// 00401ce5  5e                   pop esi
// 00401ce6  59                   pop ecx
// 00401ce7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
