// roc 2012-06 005bb0a0  unit: RakNet::RakPeer  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb0a0
//
// 005bb0a0  8b442404             mov eax, dword ptr [esp + 4]
// 005bb0a4  56                   push esi
// 005bb0a5  8bf1                 mov esi, ecx
// 005bb0a7  57                   push edi
// 005bb0a8  33c9                 xor ecx, ecx
// 005bb0aa  33ff                 xor edi, edi
// 005bb0ac  898684040000         mov dword ptr [esi + 0x484], eax
// 005bb0b2  663b4e0e             cmp cx, word ptr [esi + 0xe]
// 005bb0b6  7331                 jae 0x5bb0e9
// 005bb0b8  eb06                 jmp 0x5bb0c0
// 005bb0ba  8d9b00000000         lea ebx, [ebx]
// 005bb0c0  8b9684040000         mov edx, dword ptr [esi + 0x484]
// 005bb0c6  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bb0cc  0fb7c7               movzx eax, di
// 005bb0cf  69c008120000         imul eax, eax, 0x1208
// 005bb0d5  52                   push edx
// 005bb0d6  8d8c08f8000000       lea ecx, [eax + ecx + 0xf8]
// 005bb0dd  e87ea14700           call 0xa35260
// 005bb0e2  47                   inc edi
// 005bb0e3  663b7e0e             cmp di, word ptr [esi + 0xe]
// 005bb0e7  72d7                 jb 0x5bb0c0
// 005bb0e9  5f                   pop edi
// 005bb0ea  5e                   pop esi
// 005bb0eb  c20400               ret 4
// copied from an identical function in another client (function ?SetSplitMessageProgressInterval@RakPeer@RakNet@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp