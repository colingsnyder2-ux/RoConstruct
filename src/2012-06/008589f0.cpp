// roc 2012-06 008589f0  unit: seg_00850000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008589f0
//
// 008589f0  56                   push esi
// 008589f1  8b742408             mov esi, dword ptr [esp + 8]
// 008589f5  6a01                 push 1
// 008589f7  56                   push esi
// 008589f8  e8f3aefdff           call 0x8338f0
// 008589fd  68541bbd00           push 0xbd1b54
// 00858a02  6a01                 push 1
// 00858a04  56                   push esi
// 00858a05  e8b6a5fdff           call 0x832fc0
// 00858a0a  83c414               add esp, 0x14
// 00858a0d  85c0                 test eax, eax
// 00858a0f  0f85b2000000         jne 0x858ac7
// 00858a15  6a01                 push 1
// 00858a17  56                   push esi
// 00858a18  e8c392fdff           call 0x831ce0
// 00858a1d  83c408               add esp, 8
// 00858a20  83f804               cmp eax, 4
// 00858a23  7775                 ja 0x858a9a
// 00858a25  ff2485d08a8500       jmp dword ptr [eax*4 + 0x858ad0]
// 00858a2c  6a00                 push 0
// 00858a2e  6a01                 push 1
// 00858a30  56                   push esi
// 00858a31  e8ba94fdff           call 0x831ef0
// 00858a36  50                   push eax
// 00858a37  56                   push esi
// 00858a38  e8f396fdff           call 0x832130
// 00858a3d  83c414               add esp, 0x14
// 00858a40  b801000000           mov eax, 1
// 00858a45  5e                   pop esi
// 00858a46  c3                   ret 
// 00858a47  6a01                 push 1
// 00858a49  56                   push esi
// 00858a4a  e86192fdff           call 0x831cb0
// 00858a4f  83c408               add esp, 8
// 00858a52  b801000000           mov eax, 1
// 00858a57  5e                   pop esi
// 00858a58  c3                   ret 
// 00858a59  6a01                 push 1
// 00858a5b  56                   push esi
// 00858a5c  e85f94fdff           call 0x831ec0
// 00858a61  83c408               add esp, 8
// 00858a64  85c0                 test eax, eax
// 00858a66  b83c37b800           mov eax, 0xb8373c
// 00858a6b  7505                 jne 0x858a72
// 00858a6d  b80016b500           mov eax, 0xb51600
// 00858a72  50                   push eax
// 00858a73  56                   push esi
// 00858a74  e8b796fdff           call 0x832130
// 00858a79  83c408               add esp, 8
// 00858a7c  b801000000           mov eax, 1
// 00858a81  5e                   pop esi
// 00858a82  c3                   ret 
// 00858a83  6a03                 push 3
// 00858a85  68386ab900           push 0xb96a38
// 00858a8a  56                   push esi
// 00858a8b  e86096fdff           call 0x8320f0
// 00858a90  83c40c               add esp, 0xc
// 00858a93  b801000000           mov eax, 1
// 00858a98  5e                   pop esi
// 00858a99  c3                   ret 
// 00858a9a  6a01                 push 1
// 00858a9c  56                   push esi
// 00858a9d  e87e95fdff           call 0x832020
// 00858aa2  83c408               add esp, 8
// 00858aa5  50                   push eax
// 00858aa6  6a01                 push 1
// 00858aa8  56                   push esi
// 00858aa9  e83292fdff           call 0x831ce0
// 00858aae  50                   push eax
// 00858aaf  56                   push esi
// 00858ab0  e84b92fdff           call 0x831d00
// 00858ab5  83c410               add esp, 0x10
// 00858ab8  50                   push eax
// 00858ab9  683c43bd00           push 0xbd433c
// 00858abe  56                   push esi
// 00858abf  e80c97fdff           call 0x8321d0
// 00858ac4  83c410               add esp, 0x10
// 00858ac7  b801000000           mov eax, 1
// 00858acc  5e                   pop esi
// 00858acd  c3                   ret 
// 00858ace  8bff                 mov edi, edi
// 00858ad0  838a8500598a85       or dword ptr [edx - 0x75a6ff7b], 0xffffff85
// 00858ad7  009a8a85002c         add byte ptr [edx + 0x2c00858a], bl
// 00858add  8a8500478a85         mov al, byte ptr [ebp - 0x7a75b900]
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
