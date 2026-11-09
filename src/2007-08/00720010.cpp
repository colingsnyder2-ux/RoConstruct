// from server: 100% by auto
// roc 2007-08 00720010  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00720010
//
// 00720010  56                   push esi
// 00720011  8bf1                 mov esi, ecx
// 00720013  e858ffffff           call 0x71ff70
// 00720018  c70608227e00         mov dword ptr [esi], 0x7e2208
// 0072001e  8bc6                 mov eax, esi
// 00720020  5e                   pop esi
// 00720021  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
