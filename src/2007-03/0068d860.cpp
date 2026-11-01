// from server: 100% by auto
// roc 2007-03 0068d860  unit: seg_00680000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d860
//
// 0068d860  837c240400           cmp dword ptr [esp + 4], 0
// 0068d865  56                   push esi
// 0068d866  8bf1                 mov esi, ecx
// 0068d868  7423                 je 0x68d88d
// 0068d86a  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0068d86e  7532                 jne 0x68d8a2
// 0068d870  ff1584d27700         call dword ptr [0x77d284]
// 0068d876  50                   push eax
// 0068d877  6a00                 push 0
// 0068d879  68f0d66800           push 0x68d6f0
// 0068d87e  6a07                 push 7
// 0068d880  ff15f0ee7700         call dword ptr [0x77eef0]
// 0068d886  89461c               mov dword ptr [esi + 0x1c], eax
// 0068d889  5e                   pop esi
// 0068d88a  c20400               ret 4
// 0068d88d  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0068d890  85c0                 test eax, eax
// 0068d892  740e                 je 0x68d8a2
// 0068d894  50                   push eax
// 0068d895  ff15ecee7700         call dword ptr [0x77eeec]
// 0068d89b  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0068d8a2  5e                   pop esi
// 0068d8a3  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?SetupHook@CXTPMouseManager@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
