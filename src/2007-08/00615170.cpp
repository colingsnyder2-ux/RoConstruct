// from server: 100% by auto
// roc 2007-08 00615170  unit: seg_00610000  size: 431 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00615170
//
// 00615170  83c0db               add eax, -0x25
// 00615173  3df6000000           cmp eax, 0xf6
// 00615178  7765                 ja 0x6151df
// 0061517a  0fb68028526100       movzx eax, byte ptr [eax + 0x615228]
// 00615181  ff2485e8516100       jmp dword ptr [eax*4 + 0x6151e8]
// 00615188  33c0                 xor eax, eax
// 0061518a  c3                   ret 
// 0061518b  b801000000           mov eax, 1
// 00615190  c3                   ret 
// 00615191  b802000000           mov eax, 2
// 00615196  c3                   ret 
// 00615197  b803000000           mov eax, 3
// 0061519c  c3                   ret 
// 0061519d  b804000000           mov eax, 4
// 006151a2  c3                   ret 
// 006151a3  b805000000           mov eax, 5
// 006151a8  c3                   ret 
// 006151a9  b806000000           mov eax, 6
// 006151ae  c3                   ret 
// 006151af  b807000000           mov eax, 7
// 006151b4  c3                   ret 
// 006151b5  b808000000           mov eax, 8
// 006151ba  c3                   ret 
// 006151bb  b809000000           mov eax, 9
// 006151c0  c3                   ret 
// 006151c1  b80a000000           mov eax, 0xa
// 006151c6  c3                   ret 
// 006151c7  b80b000000           mov eax, 0xb
// 006151cc  c3                   ret 
// 006151cd  b80c000000           mov eax, 0xc
// 006151d2  c3                   ret 
// 006151d3  b80d000000           mov eax, 0xd
// 006151d8  c3                   ret 
// 006151d9  b80e000000           mov eax, 0xe
// 006151de  c3                   ret 
// 006151df  b80f000000           mov eax, 0xf
// 006151e4  c3                   ret 
// 006151e5  8d4900               lea ecx, [ecx]
// 006151e8  9d                   popfd 
// 006151e9  51                   push ecx
// 006151ea  61                   popal 
// 006151eb  009151610088         add byte ptr [ecx - 0x77ff9eaf], dl
// 006151f1  51                   push ecx
// 006151f2  61                   popal 
// 006151f3  008b51610097         add byte ptr [ebx - 0x68ff9eaf], cl
// 006151f9  51                   push ecx
// 006151fa  61                   popal 
// 006151fb  00bb516100c7         add byte ptr [ebx - 0x38ff9eaf], bh
// 00615201  51                   push ecx
// 00615202  61                   popal 
// 00615203  00a3516100d3         add byte ptr [ebx - 0x2cff9eaf], ah
// 00615209  51                   push ecx
// 0061520a  61                   popal 
// 0061520b  00d9                 add cl, bl
// 0061520d  51                   push ecx
// 0061520e  61                   popal 
// 0061520f  00a9516100b5         add byte ptr [ecx - 0x4aff9eaf], ch
// 00615215  51                   push ecx
// 00615216  61                   popal 
// 00615217  00cd                 add ch, cl
// 00615219  51                   push ecx
// 0061521a  61                   popal 
// 0061521b  00c1                 add cl, al
// 0061521d  51                   push ecx
// 0061521e  61                   popal 
// 0061521f  00af516100df         add byte ptr [edi - 0x20ff9eaf], ch
// 00615225  51                   push ecx
// 00615226  61                   popal 
// 00615227  0000                 add byte ptr [eax], al
// library lua-5.1/lparser.c (function _getbinopr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
