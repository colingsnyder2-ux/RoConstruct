// from server: 100% by auto
// roc 2012-06 0046c740  unit: RBX::TeleportCallback  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046c740
//
// 0046c740  85c0                 test eax, eax
// 0046c742  7501                 jne 0x46c745
// 0046c744  c3                   ret 
// 0046c745  8a08                 mov cl, byte ptr [eax]
// 0046c747  56                   push esi
// 0046c748  33f6                 xor esi, esi
// 0046c74a  84c9                 test cl, cl
// 0046c74c  7427                 je 0x46c775
// 0046c74e  57                   push edi
// 0046c74f  8b3d183cb200         mov edi, dword ptr [0xb23c18]
// 0046c755  80f92e               cmp cl, 0x2e
// 0046c758  7409                 je 0x46c763
// 0046c75a  80f95c               cmp cl, 0x5c
// 0046c75d  7506                 jne 0x46c765
// 0046c75f  33f6                 xor esi, esi
// 0046c761  eb02                 jmp 0x46c765
// 0046c763  8bf0                 mov esi, eax
// 0046c765  50                   push eax
// 0046c766  ffd7                 call edi
// 0046c768  8a08                 mov cl, byte ptr [eax]
// 0046c76a  84c9                 test cl, cl
// 0046c76c  75e7                 jne 0x46c755
// 0046c76e  5f                   pop edi
// 0046c76f  85f6                 test esi, esi
// 0046c771  7402                 je 0x46c775
// 0046c773  8bc6                 mov eax, esi
// 0046c775  5e                   pop esi
// 0046c776  c3                   ret 
// library atl-9.0/atl.cpp (function ?AtlFindExtension@ATL@@YAPADPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
