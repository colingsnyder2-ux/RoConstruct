// roc 2009-12 007d30b0  unit: seg_007d0000  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d30b0
//
// 007d30b0  83ec18               sub esp, 0x18
// 007d30b3  53                   push ebx
// 007d30b4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007d30b8  8b4334               mov eax, dword ptr [ebx + 0x34]
// 007d30bb  55                   push ebp
// 007d30bc  56                   push esi
// 007d30bd  be01000000           mov esi, 1
// 007d30c2  66017034             add word ptr [eax + 0x34], si
// 007d30c6  8b4334               mov eax, dword ptr [ebx + 0x34]
// 007d30c9  b9c8000000           mov ecx, 0xc8
// 007d30ce  66394834             cmp word ptr [eax + 0x34], cx
// 007d30d2  7610                 jbe 0x7d30e4
// 007d30d4  6a00                 push 0
// 007d30d6  6890ee9e00           push 0x9eee90
// 007d30db  53                   push ebx
// 007d30dc  e8bf210000           call 0x7d52a0
// 007d30e1  83c40c               add esp, 0xc
// 007d30e4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d30e7  83f823               cmp eax, 0x23
// 007d30ea  0f8499000000         je 0x7d3189
// 007d30f0  83f82d               cmp eax, 0x2d
// 007d30f3  0f848c000000         je 0x7d3185
// 007d30f9  3d0e010000           cmp eax, 0x10e
// 007d30fe  0f848a000000         je 0x7d318e
// 007d3104  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 007d3108  8bc5                 mov eax, ebp
// 007d310a  e811fcffff           call 0x7d2d20
// 007d310f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d3112  e8e9fdffff           call 0x7d2f00
// 007d3117  8bf0                 mov esi, eax
// 007d3119  83fe0f               cmp esi, 0xf
// 007d311c  7452                 je 0x7d3170
// 007d311e  57                   push edi
// 007d311f  90                   nop 
// 007d3120  0fb60475b0ed9e00     movzx eax, byte ptr [esi*2 + 0x9eedb0]
// 007d3128  3b442434             cmp eax, dword ptr [esp + 0x34]
// 007d312c  7641                 jbe 0x7d316f
// 007d312e  53                   push ebx
// 007d312f  e8fc350000           call 0x7d6730
// 007d3134  8b4b30               mov ecx, dword ptr [ebx + 0x30]
// 007d3137  55                   push ebp
// 007d3138  56                   push esi
// 007d3139  51                   push ecx
// 007d313a  e821a30000           call 0x7dd460
// 007d313f  0fb61475b1ed9e00     movzx edx, byte ptr [esi*2 + 0x9eedb1]
// 007d3147  52                   push edx
// 007d3148  8d442424             lea eax, [esp + 0x24]
// 007d314c  50                   push eax
// 007d314d  53                   push ebx
// 007d314e  e85dffffff           call 0x7d30b0
// 007d3153  8b5330               mov edx, dword ptr [ebx + 0x30]
// 007d3156  8d4c242c             lea ecx, [esp + 0x2c]
// 007d315a  51                   push ecx
// 007d315b  55                   push ebp
// 007d315c  56                   push esi
// 007d315d  52                   push edx
// 007d315e  8bf8                 mov edi, eax
// 007d3160  e8aba30000           call 0x7dd510
// 007d3165  83c42c               add esp, 0x2c
// 007d3168  8bf7                 mov esi, edi
// 007d316a  83ff0f               cmp edi, 0xf
// 007d316d  75b1                 jne 0x7d3120
// 007d316f  5f                   pop edi
// 007d3170  8b5b34               mov ebx, dword ptr [ebx + 0x34]
// 007d3173  b8ffff0000           mov eax, 0xffff
// 007d3178  66014334             add word ptr [ebx + 0x34], ax
// 007d317c  8bc6                 mov eax, esi
// 007d317e  5e                   pop esi
// 007d317f  5d                   pop ebp
// 007d3180  5b                   pop ebx
// 007d3181  83c418               add esp, 0x18
// 007d3184  c3                   ret 
// 007d3185  33f6                 xor esi, esi
// 007d3187  eb05                 jmp 0x7d318e
// 007d3189  be02000000           mov esi, 2
// 007d318e  53                   push ebx
// 007d318f  e89c350000           call 0x7d6730
// 007d3194  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 007d3198  6a08                 push 8
// 007d319a  55                   push ebp
// 007d319b  53                   push ebx
// 007d319c  e80fffffff           call 0x7d30b0
// 007d31a1  8b5330               mov edx, dword ptr [ebx + 0x30]
// 007d31a4  55                   push ebp
// 007d31a5  56                   push esi
// 007d31a6  52                   push edx
// 007d31a7  e814a20000           call 0x7dd3c0
// 007d31ac  83c41c               add esp, 0x1c
// 007d31af  e95bffffff           jmp 0x7d310f
// library lua-5.1/lparser.c (function _subexpr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
