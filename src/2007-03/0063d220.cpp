// from server: 100% by auto
// roc 2007-03 0063d220  unit: seg_00630000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0063d220
//
// 0063d220  56                   push esi
// 0063d221  8bf1                 mov esi, ecx
// 0063d223  e8e8baffff           call 0x638d10
// 0063d228  8bc8                 mov ecx, eax
// 0063d22a  85c9                 test ecx, ecx
// 0063d22c  7422                 je 0x63d250
// 0063d22e  8b542408             mov edx, dword ptr [esp + 8]
// 0063d232  83fa02               cmp edx, 2
// 0063d235  740e                 je 0x63d245
// 0063d237  85d2                 test edx, edx
// 0063d239  740a                 je 0x63d245
// 0063d23b  83fa03               cmp edx, 3
// 0063d23e  7405                 je 0x63d245
// 0063d240  83fa01               cmp edx, 1
// 0063d243  7511                 jne 0x63d256
// 0063d245  52                   push edx
// 0063d246  56                   push esi
// 0063d247  e814e3feff           call 0x62b560
// 0063d24c  85c0                 test eax, eax
// 0063d24e  7515                 jne 0x63d265
// 0063d250  33c0                 xor eax, eax
// 0063d252  5e                   pop esi
// 0063d253  c20400               ret 4
// 0063d256  83fa04               cmp edx, 4
// 0063d259  75f5                 jne 0x63d250
// 0063d25b  56                   push esi
// 0063d25c  e81fe3feff           call 0x62b580
// 0063d261  85c0                 test eax, eax
// 0063d263  74eb                 je 0x63d250
// 0063d265  b801000000           mov eax, 1
// 0063d26a  5e                   pop esi
// 0063d26b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?SetPosition@CXTPToolBar@@UAEHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
