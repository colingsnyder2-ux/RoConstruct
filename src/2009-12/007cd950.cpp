// from server: 100% by auto
// roc 2009-12 007cd950  unit: RBX::PartDropTool  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd950
//
// 007cd950  55                   push ebp
// 007cd951  56                   push esi
// 007cd952  8bb78c000000         mov esi, dword ptr [edi + 0x8c]
// 007cd958  8d6f78               lea ebp, [edi + 0x78]
// 007cd95b  3bf5                 cmp esi, ebp
// 007cd95d  7429                 je 0x7cd988
// 007cd95f  90                   nop 
// 007cd960  f6460507             test byte ptr [esi + 5], 7
// 007cd964  751b                 jne 0x7cd981
// 007cd966  8b4608               mov eax, dword ptr [esi + 8]
// 007cd969  83780804             cmp dword ptr [eax + 8], 4
// 007cd96d  7c12                 jl 0x7cd981
// 007cd96f  8b00                 mov eax, dword ptr [eax]
// 007cd971  f6400503             test byte ptr [eax + 5], 3
// 007cd975  740a                 je 0x7cd981
// 007cd977  50                   push eax
// 007cd978  57                   push edi
// 007cd979  e8d2f4ffff           call 0x7cce50
// 007cd97e  83c408               add esp, 8
// 007cd981  8b7614               mov esi, dword ptr [esi + 0x14]
// 007cd984  3bf5                 cmp esi, ebp
// 007cd986  75d8                 jne 0x7cd960
// 007cd988  5e                   pop esi
// 007cd989  5d                   pop ebp
// 007cd98a  c3                   ret 
// library lua-5.1/lgc.c (function _remarkupvals)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
