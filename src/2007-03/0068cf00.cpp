// from server: 100% by auto
// roc 2007-03 0068cf00  unit: seg_00680000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068cf00
//
// 0068cf00  837c240400           cmp dword ptr [esp + 4], 0
// 0068cf05  56                   push esi
// 0068cf06  8bf1                 mov esi, ecx
// 0068cf08  742c                 je 0x68cf36
// 0068cf0a  837e0800             cmp dword ptr [esi + 8], 0
// 0068cf0e  753b                 jne 0x68cf4b
// 0068cf10  57                   push edi
// 0068cf11  e87a14f9ff           call 0x61e390
// 0068cf16  8b7808               mov edi, dword ptr [eax + 8]
// 0068cf19  ff1584d27700         call dword ptr [0x77d284]
// 0068cf1f  50                   push eax
// 0068cf20  57                   push edi
// 0068cf21  6860cb6800           push 0x68cb60
// 0068cf26  6a04                 push 4
// 0068cf28  ff15f0ee7700         call dword ptr [0x77eef0]
// 0068cf2e  5f                   pop edi
// 0068cf2f  894608               mov dword ptr [esi + 8], eax
// 0068cf32  5e                   pop esi
// 0068cf33  c20400               ret 4
// 0068cf36  8b4608               mov eax, dword ptr [esi + 8]
// 0068cf39  85c0                 test eax, eax
// 0068cf3b  740e                 je 0x68cf4b
// 0068cf3d  50                   push eax
// 0068cf3e  ff15ecee7700         call dword ptr [0x77eeec]
// 0068cf44  c7460800000000       mov dword ptr [esi + 8], 0
// 0068cf4b  5e                   pop esi
// 0068cf4c  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPKeyboardManager.cpp (function ?SetupCallWndProcHook@CXTPKeyboardManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPKeyboardManager.cpp
