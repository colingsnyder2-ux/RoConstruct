// from server: 100% by auto
// roc 2008-06 004bbbd0  unit: ProfiledRakPeer  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbbd0
//
// 004bbbd0  8b442404             mov eax, dword ptr [esp + 4]
// 004bbbd4  56                   push esi
// 004bbbd5  8bf1                 mov esi, ecx
// 004bbbd7  57                   push edi
// 004bbbd8  33c9                 xor ecx, ecx
// 004bbbda  33ff                 xor edi, edi
// 004bbbdc  8986d4080000         mov dword ptr [esi + 0x8d4], eax
// 004bbbe2  663b4e08             cmp cx, word ptr [esi + 8]
// 004bbbe6  732e                 jae 0x4bbc16
// 004bbbe8  eb06                 jmp 0x4bbbf0
// 004bbbea  8d9b00000000         lea ebx, [ebx]
// 004bbbf0  8b96d4080000         mov edx, dword ptr [esi + 0x8d4]
// 004bbbf6  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 004bbbfc  0fb7c7               movzx eax, di
// 004bbbff  69c050080000         imul eax, eax, 0x850
// 004bbc05  52                   push edx
// 004bbc06  8d4c0818             lea ecx, [eax + ecx + 0x18]
// 004bbc0a  e821300100           call 0x4cec30
// 004bbc0f  47                   inc edi
// 004bbc10  663b7e08             cmp di, word ptr [esi + 8]
// 004bbc14  72da                 jb 0x4bbbf0
// 004bbc16  5f                   pop edi
// 004bbc17  5e                   pop esi
// 004bbc18  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?SetUnreliableTimeout@RakPeer@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
