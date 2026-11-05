// from server: 100% by auto
// roc 2009-06 00809a80  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809a80
//
// 00809a80  56                   push esi
// 00809a81  8bf1                 mov esi, ecx
// 00809a83  e868ffffff           call 0x8099f0
// 00809a88  c7069cbf9000         mov dword ptr [esi], 0x90bf9c
// 00809a8e  8bc6                 mov eax, esi
// 00809a90  5e                   pop esi
// 00809a91  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
