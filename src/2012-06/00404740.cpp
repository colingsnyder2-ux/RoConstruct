// from server: 100% by auto
// roc 2012-06 00404740  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404740
//
// 00404740  8b442404             mov eax, dword ptr [esp + 4]
// 00404744  57                   push edi
// 00404745  33ff                 xor edi, edi
// 00404747  85c0                 test eax, eax
// 00404749  7502                 jne 0x40474d
// 0040474b  5f                   pop edi
// 0040474c  c3                   ret 
// 0040474d  8a08                 mov cl, byte ptr [eax]
// 0040474f  84c9                 test cl, cl
// 00404751  7424                 je 0x404777
// 00404753  53                   push ebx
// 00404754  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 00404758  56                   push esi
// 00404759  8b35183cb200         mov esi, dword ptr [0xb23c18]
// 0040475f  90                   nop 
// 00404760  3acb                 cmp cl, bl
// 00404762  740f                 je 0x404773
// 00404764  50                   push eax
// 00404765  ffd6                 call esi
// 00404767  8a08                 mov cl, byte ptr [eax]
// 00404769  84c9                 test cl, cl
// 0040476b  75f3                 jne 0x404760
// 0040476d  5e                   pop esi
// 0040476e  5b                   pop ebx
// 0040476f  8bc7                 mov eax, edi
// 00404771  5f                   pop edi
// 00404772  c3                   ret 
// 00404773  5e                   pop esi
// 00404774  8bf8                 mov edi, eax
// 00404776  5b                   pop ebx
// 00404777  8bc7                 mov eax, edi
// 00404779  5f                   pop edi
// 0040477a  c3                   ret 
// library atl-8.0/atl.cpp (function ?StrChrA@CRegParser@ATL@@KAPADPADD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
