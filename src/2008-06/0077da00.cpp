// from server: 100% by auto
// roc 2008-06 0077da00  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0077da00
//
// 0077da00  56                   push esi
// 0077da01  8bf1                 mov esi, ecx
// 0077da03  e8b8b6faff           call 0x7290c0
// 0077da08  c70624968600         mov dword ptr [esi], 0x869624
// 0077da0e  8bc6                 mov eax, esi
// 0077da10  5e                   pop esi
// 0077da11  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??0?$basic_regex_implementation@DU?$regex_traits@DV?$w32_regex_traits@D@boost@@@boost@@@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
