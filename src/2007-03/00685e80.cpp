// from server: 100% by auto
// roc 2007-03 00685e80  unit: seg_00680000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685e80
//
// 00685e80  8b4108               mov eax, dword ptr [ecx + 8]
// 00685e83  85c0                 test eax, eax
// 00685e85  7501                 jne 0x685e88
// 00685e87  c3                   ret 
// 00685e88  56                   push esi
// 00685e89  68dce87c00           push 0x7ce8dc
// 00685e8e  8d7110               lea esi, [ecx + 0x10]
// 00685e91  50                   push eax
// 00685e92  c70614000000         mov dword ptr [esi], 0x14
// 00685e98  ff1544d27700         call dword ptr [0x77d244]
// 00685e9e  85c0                 test eax, eax
// 00685ea0  740b                 je 0x685ead
// 00685ea2  56                   push esi
// 00685ea3  ffd0                 call eax
// 00685ea5  f7d8                 neg eax
// 00685ea7  1bc0                 sbb eax, eax
// 00685ea9  f7d8                 neg eax
// 00685eab  5e                   pop esi
// 00685eac  c3                   ret 
// 00685ead  33c0                 xor eax, eax
// 00685eaf  5e                   pop esi
// 00685eb0  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersionInfo@CXTPModuleHandle@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
