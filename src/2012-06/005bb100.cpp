// roc 2012-06 005bb100  unit: RakNet::RakPeer  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb100
//
// 005bb100  8b442404             mov eax, dword ptr [esp + 4]
// 005bb104  56                   push esi
// 005bb105  8bf1                 mov esi, ecx
// 005bb107  57                   push edi
// 005bb108  33c9                 xor ecx, ecx
// 005bb10a  33ff                 xor edi, edi
// 005bb10c  898688040000         mov dword ptr [esi + 0x488], eax
// 005bb112  663b4e0e             cmp cx, word ptr [esi + 0xe]
// 005bb116  7331                 jae 0x5bb149
// 005bb118  eb06                 jmp 0x5bb120
// 005bb11a  8d9b00000000         lea ebx, [ebx]
// 005bb120  8b9688040000         mov edx, dword ptr [esi + 0x488]
// 005bb126  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bb12c  0fb7c7               movzx eax, di
// 005bb12f  69c008120000         imul eax, eax, 0x1208
// 005bb135  52                   push edx
// 005bb136  8d8c08f8000000       lea ecx, [eax + ecx + 0xf8]
// 005bb13d  e86eeffdff           call 0x59a0b0
// 005bb142  47                   inc edi
// 005bb143  663b7e0e             cmp di, word ptr [esi + 0xe]
// 005bb147  72d7                 jb 0x5bb120
// 005bb149  5f                   pop edi
// 005bb14a  5e                   pop esi
// 005bb14b  c20400               ret 4
// copied from an identical function in another client (function ?SetUnreliableTimeout@RakPeer@RakNet@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp