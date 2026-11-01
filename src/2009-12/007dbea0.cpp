// from server: 100% by auto
// roc 2009-12 007dbea0  unit: RBX::GroupDragTool  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dbea0
//
// 007dbea0  56                   push esi
// 007dbea1  57                   push edi
// 007dbea2  83faff               cmp edx, -1
// 007dbea5  7449                 je 0x7dbef0
// 007dbea7  8b08                 mov ecx, dword ptr [eax]
// 007dbea9  8b790c               mov edi, dword ptr [ecx + 0xc]
// 007dbeac  8d642400             lea esp, [esp]
// 007dbeb0  83fa01               cmp edx, 1
// 007dbeb3  8d0497               lea eax, [edi + edx*4]
// 007dbeb6  7c14                 jl 0x7dbecc
// 007dbeb8  8b70fc               mov esi, dword ptr [eax - 4]
// 007dbebb  8d48fc               lea ecx, [eax - 4]
// 007dbebe  83e63f               and esi, 0x3f
// 007dbec1  f6867cf29e0080       test byte ptr [esi + 0x9ef27c], 0x80
// 007dbec8  8bf1                 mov esi, ecx
// 007dbeca  7502                 jne 0x7dbece
// 007dbecc  8bf0                 mov esi, eax
// 007dbece  8b0e                 mov ecx, dword ptr [esi]
// 007dbed0  83e13f               and ecx, 0x3f
// 007dbed3  80f91b               cmp cl, 0x1b
// 007dbed6  751d                 jne 0x7dbef5
// 007dbed8  8b00                 mov eax, dword ptr [eax]
// 007dbeda  c1e80e               shr eax, 0xe
// 007dbedd  2dffff0100           sub eax, 0x1ffff
// 007dbee2  83f8ff               cmp eax, -1
// 007dbee5  7409                 je 0x7dbef0
// 007dbee7  8d540201             lea edx, [edx + eax + 1]
// 007dbeeb  83faff               cmp edx, -1
// 007dbeee  75c0                 jne 0x7dbeb0
// 007dbef0  5f                   pop edi
// 007dbef1  33c0                 xor eax, eax
// 007dbef3  5e                   pop esi
// 007dbef4  c3                   ret 
// 007dbef5  5f                   pop edi
// 007dbef6  b801000000           mov eax, 1
// 007dbefb  5e                   pop esi
// 007dbefc  c3                   ret 
// library lua-5.1/lcode.c (function _need_value)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
