// from server: 100% by auto
// roc 2009-06 005b96c0  unit: seg_005b0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b96c0
//
// 005b96c0  55                   push ebp
// 005b96c1  8bec                 mov ebp, esp
// 005b96c3  51                   push ecx
// 005b96c4  8a45ff               mov al, byte ptr [ebp - 1]
// 005b96c7  8be5                 mov esp, ebp
// 005b96c9  5d                   pop ebp
// 005b96ca  c3                   ret 
// library rccservice/gSOAP\generated\stdsoap2.cpp (function ??$_Char_traits_cat@U?$char_traits@D@std@@@std@@YA?AU_Secure_char_traits_tag@0@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Oy- /GS- /MD
// roc-lib: rccservice gSOAP/generated/stdsoap2.cpp
