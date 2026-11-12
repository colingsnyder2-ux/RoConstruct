// from server: 100% by colin
// roc 2007-08 004bfbb0  unit: RakPeer  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bfbb0
//
// 004bfbb0  6aff                 push -1
// 004bfbb2  689bb97400           push 0x74b99b
// 004bfbb7  64a100000000         mov eax, dword ptr fs:[0]
// 004bfbbd  50                   push eax
// 004bfbbe  81ec20010000         sub esp, 0x120
// 004bfbc4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004bfbc9  33c4                 xor eax, esp
// 004bfbcb  8984241c010000       mov dword ptr [esp + 0x11c], eax
// 004bfbd2  55                   push ebp
// 004bfbd3  56                   push esi
// 004bfbd4  57                   push edi
// 004bfbd5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004bfbda  33c4                 xor eax, esp
// 004bfbdc  50                   push eax
// 004bfbdd  8d842430010000       lea eax, [esp + 0x130]
// 004bfbe4  64a300000000         mov dword ptr fs:[0], eax
// 004bfbea  8bf1                 mov esi, ecx
// 004bfbec  8b06                 mov eax, dword ptr [esi]
// 004bfbee  8b502c               mov edx, dword ptr [eax + 0x2c]
// 004bfbf1  ffd2                 call edx
// 004bfbf3  84c0                 test al, al
// 004bfbf5  0f84d0000000         je 0x4bfccb
// 004bfbfb  6a05                 push 5
// 004bfbfd  8d4c241c             lea ecx, [esp + 0x1c]
// 004bfc01  e84afcfdff           call 0x49f850
// 004bfc06  6a01                 push 1
// 004bfc08  6a08                 push 8
// 004bfc0a  8d442418             lea eax, [esp + 0x18]
// 004bfc0e  50                   push eax
// 004bfc0f  8d4c2424             lea ecx, [esp + 0x24]
// 004bfc13  c784244401000000000000 mov dword ptr [esp + 0x144], 0
// 004bfc1e  c644241c00           mov byte ptr [esp + 0x1c], 0
// 004bfc23  e86801feff           call 0x49fd90
// 004bfc28  e81382ffff           call 0x4b7e40
// 004bfc2d  8bf8                 mov edi, eax
// 004bfc2f  8bea                 mov ebp, edx
// 004bfc31  e83a83ffff           call 0x4b7f70
// 004bfc36  6a01                 push 1
// 004bfc38  6a20                 push 0x20
// 004bfc3a  8d4c241c             lea ecx, [esp + 0x1c]
// 004bfc3e  51                   push ecx
// 004bfc3f  8d4c2424             lea ecx, [esp + 0x24]
// 004bfc43  89442420             mov dword ptr [esp + 0x20], eax
// 004bfc47  e84401feff           call 0x49fd90
// 004bfc4c  80bc244801000000     cmp byte ptr [esp + 0x148], 0
// 004bfc54  7435                 je 0x4bfc8b
// 004bfc56  8b942444010000       mov edx, dword ptr [esp + 0x144]
// 004bfc5d  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 004bfc64  8b8c244c010000       mov ecx, dword ptr [esp + 0x14c]
// 004bfc6b  55                   push ebp
// 004bfc6c  57                   push edi
// 004bfc6d  6a00                 push 0
// 004bfc6f  6a00                 push 0
// 004bfc71  52                   push edx
// 004bfc72  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004bfc76  50                   push eax
// 004bfc77  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004bfc7b  6a00                 push 0
// 004bfc7d  51                   push ecx
// 004bfc7e  6a00                 push 0
// 004bfc80  52                   push edx
// 004bfc81  50                   push eax
// 004bfc82  8bce                 mov ecx, esi
// 004bfc84  e8f7d4ffff           call 0x4bd180
// 004bfc89  eb2c                 jmp 0x4bfcb7
// 004bfc8b  8b842444010000       mov eax, dword ptr [esp + 0x144]
// 004bfc92  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 004bfc99  8b16                 mov edx, dword ptr [esi]
// 004bfc9b  8b5234               mov edx, dword ptr [edx + 0x34]
// 004bfc9e  6a00                 push 0
// 004bfca0  50                   push eax
// 004bfca1  8b842454010000       mov eax, dword ptr [esp + 0x154]
// 004bfca8  51                   push ecx
// 004bfca9  6a00                 push 0
// 004bfcab  50                   push eax
// 004bfcac  6a00                 push 0
// 004bfcae  8d4c2430             lea ecx, [esp + 0x30]
// 004bfcb2  51                   push ecx
// 004bfcb3  8bce                 mov ecx, esi
// 004bfcb5  ffd2                 call edx
// 004bfcb7  8d4c2418             lea ecx, [esp + 0x18]
// 004bfcbb  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 004bfcc6  e865fcfdff           call 0x49f930
// 004bfccb  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 004bfcd2  64890d00000000       mov dword ptr fs:[0], ecx
// 004bfcd9  59                   pop ecx
// 004bfcda  5f                   pop edi
// 004bfcdb  5e                   pop esi
// 004bfcdc  5d                   pop ebp
// 004bfcdd  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 004bfce4  33cc                 xor ecx, esp
// 004bfce6  e8330d1700           call 0x630a1e
// 004bfceb  81c42c010000         add esp, 0x12c
// 004bfcf1  c21000               ret 0x10
// copied from an identical function in another client (function ?PingInternal@RakPeer@@IAEXUSystemAddress@@_NW4PacketReliability@@@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp