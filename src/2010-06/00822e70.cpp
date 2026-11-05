// from server: 100% by auto
// roc 2010-06 00822e70  unit: CXTPResourceManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822e70
//
// 00822e70  83ec18               sub esp, 0x18
// 00822e73  56                   push esi
// 00822e74  8b742420             mov esi, dword ptr [esp + 0x20]
// 00822e78  56                   push esi
// 00822e79  ff1528bc9e00         call dword ptr [0x9ebc28]
// 00822e7f  85c0                 test eax, eax
// 00822e81  7532                 jne 0x822eb5
// 00822e83  8b442428             mov eax, dword ptr [esp + 0x28]
// 00822e87  50                   push eax
// 00822e88  56                   push esi
// 00822e89  ff1560ba9e00         call dword ptr [0x9eba60]
// 00822e8f  68e0a57a00           push 0x7aa5e0
// 00822e94  b90062c200           mov ecx, 0xc26200
// 00822e99  e8da9e1500           call 0x97cd78
// 00822e9e  85c0                 test eax, eax
// 00822ea0  7505                 jne 0x822ea7
// 00822ea2  e8a54df8ff           call 0x7a7c4c
// 00822ea7  c7402400000000       mov dword ptr [eax + 0x24], 0
// 00822eae  5e                   pop esi
// 00822eaf  83c418               add esp, 0x18
// 00822eb2  c21000               ret 0x10
// 00822eb5  57                   push edi
// 00822eb6  8d4c2410             lea ecx, [esp + 0x10]
// 00822eba  51                   push ecx
// 00822ebb  56                   push esi
// 00822ebc  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 00822ec2  8d542408             lea edx, [esp + 8]
// 00822ec6  52                   push edx
// 00822ec7  ff1574bc9e00         call dword ptr [0x9ebc74]
// 00822ecd  56                   push esi
// 00822ece  ff154cba9e00         call dword ptr [0x9eba4c]
// 00822ed4  85c0                 test eax, eax
// 00822ed6  741e                 je 0x822ef6
// 00822ed8  6af0                 push -0x10
// 00822eda  56                   push esi
// 00822edb  ff15fcbb9e00         call dword ptr [0x9ebbfc]
// 00822ee1  85c0                 test eax, eax
// 00822ee3  7811                 js 0x822ef6
// 00822ee5  56                   push esi
// 00822ee6  e805ffffff           call 0x822df0
// 00822eeb  83c404               add esp, 4
// 00822eee  85c0                 test eax, eax
// 00822ef0  7504                 jne 0x822ef6
// 00822ef2  33ff                 xor edi, edi
// 00822ef4  eb05                 jmp 0x822efb
// 00822ef6  bf01000000           mov edi, 1
// 00822efb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00822eff  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00822f03  50                   push eax
// 00822f04  51                   push ecx
// 00822f05  8d542418             lea edx, [esp + 0x18]
// 00822f09  52                   push edx
// 00822f0a  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 00822f10  85c0                 test eax, eax
// 00822f12  7404                 je 0x822f18
// 00822f14  85ff                 test edi, edi
// 00822f16  753b                 jne 0x822f53
// 00822f18  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00822f1c  50                   push eax
// 00822f1d  56                   push esi
// 00822f1e  ff1560ba9e00         call dword ptr [0x9eba60]
// 00822f24  68e0a57a00           push 0x7aa5e0
// 00822f29  b90062c200           mov ecx, 0xc26200
// 00822f2e  e8459e1500           call 0x97cd78
// 00822f33  85c0                 test eax, eax
// 00822f35  7505                 jne 0x822f3c
// 00822f37  e8104df8ff           call 0x7a7c4c
// 00822f3c  6a00                 push 0
// 00822f3e  6a00                 push 0
// 00822f40  68a3020000           push 0x2a3
// 00822f45  56                   push esi
// 00822f46  c7402400000000       mov dword ptr [eax + 0x24], 0
// 00822f4d  ff1548ba9e00         call dword ptr [0x9eba48]
// 00822f53  5f                   pop edi
// 00822f54  5e                   pop esi
// 00822f55  83c418               add esp, 0x18
// 00822f58  c21000               ret 0x10
// library xtp-13.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseTimerProc@CXTPMouseManager@@CGXPAUHWND__@@IIK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMouseManager.cpp
