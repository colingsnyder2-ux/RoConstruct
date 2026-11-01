// from server: 100% by auto
// roc 2009-12 0083d9c0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d9c0
//
// 0083d9c0  53                   push ebx
// 0083d9c1  56                   push esi
// 0083d9c2  57                   push edi
// 0083d9c3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0083d9c7  57                   push edi
// 0083d9c8  e8358e0e00           call 0x926802
// 0083d9cd  e8ce0e0300           call 0x86e8a0
// 0083d9d2  8bd8                 mov ebx, eax
// 0083d9d4  8b33                 mov esi, dword ptr [ebx]
// 0083d9d6  8bcf                 mov ecx, edi
// 0083d9d8  83c61c               add esi, 0x1c
// 0083d9db  e81c8e0e00           call 0x9267fc
// 0083d9e0  8b400c               mov eax, dword ptr [eax + 0xc]
// 0083d9e3  8b16                 mov edx, dword ptr [esi]
// 0083d9e5  50                   push eax
// 0083d9e6  8bcb                 mov ecx, ebx
// 0083d9e8  ffd2                 call edx
// 0083d9ea  8bf0                 mov esi, eax
// 0083d9ec  85f6                 test esi, esi
// 0083d9ee  7417                 je 0x83da07
// 0083d9f0  8bcf                 mov ecx, edi
// 0083d9f2  e8058e0e00           call 0x9267fc
// 0083d9f7  8bcf                 mov ecx, edi
// 0083d9f9  89700c               mov dword ptr [eax + 0xc], esi
// 0083d9fc  e8fb8d0e00           call 0x9267fc
// 0083da01  83c004               add eax, 4
// 0083da04  830801               or dword ptr [eax], 1
// 0083da07  5f                   pop edi
// 0083da08  5e                   pop esi
// 0083da09  5b                   pop ebx
// 0083da0a  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorDialog.cpp (function ?AddPage@CXTPColorDialog@@IAEXPAVCPropertyPage@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorDialog.cpp
