// from server: 100% by auto
// roc 2009-06 0073a480  unit: CXTPToolBar  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073a480
//
// 0073a480  56                   push esi
// 0073a481  8bf1                 mov esi, ecx
// 0073a483  e8082fffff           call 0x72d390
// 0073a488  8bc8                 mov ecx, eax
// 0073a48a  85c9                 test ecx, ecx
// 0073a48c  7422                 je 0x73a4b0
// 0073a48e  8b542408             mov edx, dword ptr [esp + 8]
// 0073a492  83fa02               cmp edx, 2
// 0073a495  740e                 je 0x73a4a5
// 0073a497  85d2                 test edx, edx
// 0073a499  740a                 je 0x73a4a5
// 0073a49b  83fa03               cmp edx, 3
// 0073a49e  7405                 je 0x73a4a5
// 0073a4a0  83fa01               cmp edx, 1
// 0073a4a3  7511                 jne 0x73a4b6
// 0073a4a5  52                   push edx
// 0073a4a6  56                   push esi
// 0073a4a7  e854f0feff           call 0x729500
// 0073a4ac  85c0                 test eax, eax
// 0073a4ae  7515                 jne 0x73a4c5
// 0073a4b0  33c0                 xor eax, eax
// 0073a4b2  5e                   pop esi
// 0073a4b3  c20400               ret 4
// 0073a4b6  83fa04               cmp edx, 4
// 0073a4b9  75f5                 jne 0x73a4b0
// 0073a4bb  56                   push esi
// 0073a4bc  e87ff0feff           call 0x729540
// 0073a4c1  85c0                 test eax, eax
// 0073a4c3  74eb                 je 0x73a4b0
// 0073a4c5  b801000000           mov eax, 1
// 0073a4ca  5e                   pop esi
// 0073a4cb  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPToolBar.cpp (function ?SetPosition@CXTPToolBar@@UAEHW4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPToolBar.cpp
