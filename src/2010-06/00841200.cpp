// from server: 100% by auto
// roc 2010-06 00841200  unit: CXTPHookManager::CHookSink  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841200
//
// 00841200  83ec08               sub esp, 8
// 00841203  56                   push esi
// 00841204  8bf1                 mov esi, ecx
// 00841206  8b460c               mov eax, dword ptr [esi + 0xc]
// 00841209  f7d8                 neg eax
// 0084120b  1bc0                 sbb eax, eax
// 0084120d  c744240400000000     mov dword ptr [esp + 4], 0
// 00841215  89442408             mov dword ptr [esp + 8], eax
// 00841219  742d                 je 0x841248
// 0084121b  57                   push edi
// 0084121c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00841220  8d442408             lea eax, [esp + 8]
// 00841224  50                   push eax
// 00841225  8d4c2418             lea ecx, [esp + 0x18]
// 00841229  51                   push ecx
// 0084122a  8d542414             lea edx, [esp + 0x14]
// 0084122e  52                   push edx
// 0084122f  8bce                 mov ecx, esi
// 00841231  e85af00200           call 0x870290
// 00841236  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0084123a  57                   push edi
// 0084123b  e810feffff           call 0x841050
// 00841240  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00841245  75d9                 jne 0x841220
// 00841247  5f                   pop edi
// 00841248  5e                   pop esi
// 00841249  83c408               add esp, 8
// 0084124c  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPHookManager.cpp (function ?RemoveAll@CXTPHookManager@@QAEXPAVCXTPHookManagerHookAble@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPHookManager.cpp
