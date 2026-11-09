// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 100% by king_originala
// roc 2008-06 0053f280  unit: RBX::RenderBase::AggregatingSceneManager  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f280
//
// 0053f280  55                   push ebp
// 0053f281  8bec                 mov ebp, esp
// 0053f283  51                   push ecx
// 0053f284  894dfc               mov dword ptr [ebp - 4], ecx
// 0053f287  8b4508               mov eax, dword ptr [ebp + 8]
// 0053f28a  83c008               add eax, 8
// 0053f28d  50                   push eax
// 0053f28e  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f291  83c108               add ecx, 8
// 0053f294  e857120000           call 0x5404f0
// 0053f299  0fb6c8               movzx ecx, al
// 0053f29c  85c9                 test ecx, ecx
// 0053f29e  7407                 je 0x53f2a7
// 0053f2a0  b001                 mov al, 1
// 0053f2a2  e98f000000           jmp 0x53f336
// 0053f2a7  8b5508               mov edx, dword ptr [ebp + 8]
// 0053f2aa  83c208               add edx, 8
// 0053f2ad  52                   push edx
// 0053f2ae  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f2b1  83c108               add ecx, 8
// 0053f2b4  e857120000           call 0x540510
// 0053f2b9  0fb6c0               movzx eax, al
// 0053f2bc  85c0                 test eax, eax
// 0053f2be  7404                 je 0x53f2c4
// 0053f2c0  32c0                 xor al, al
// 0053f2c2  eb72                 jmp 0x53f336
// 0053f2c4  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f2c7  0fb611               movzx edx, byte ptr [ecx]
// 0053f2ca  8b4508               mov eax, dword ptr [ebp + 8]
// 0053f2cd  0fb608               movzx ecx, byte ptr [eax]
// 0053f2d0  3bd1                 cmp edx, ecx
// 0053f2d2  7d04                 jge 0x53f2d8
// 0053f2d4  b001                 mov al, 1
// 0053f2d6  eb5e                 jmp 0x53f336
// 0053f2d8  8b55fc               mov edx, dword ptr [ebp - 4]
// 0053f2db  0fb602               movzx eax, byte ptr [edx]
// 0053f2de  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f2e1  0fb611               movzx edx, byte ptr [ecx]
// 0053f2e4  3bc2                 cmp eax, edx
// 0053f2e6  7e04                 jle 0x53f2ec
// 0053f2e8  32c0                 xor al, al
// 0053f2ea  eb4a                 jmp 0x53f336
// 0053f2ec  8b45fc               mov eax, dword ptr [ebp - 4]
// 0053f2ef  d94004               fld dword ptr [eax + 4]
// 0053f2f2  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f2f5  d94104               fld dword ptr [ecx + 4]
// 0053f2f8  ded9                 fcompp 
// 0053f2fa  dfe0                 fnstsw ax
// 0053f2fc  f6c441               test ah, 0x41
// 0053f2ff  7504                 jne 0x53f305
// 0053f301  b001                 mov al, 1
// 0053f303  eb31                 jmp 0x53f336
// 0053f305  8b55fc               mov edx, dword ptr [ebp - 4]
// 0053f308  d94204               fld dword ptr [edx + 4]
// 0053f30b  8b4508               mov eax, dword ptr [ebp + 8]
// 0053f30e  d94004               fld dword ptr [eax + 4]
// 0053f311  ded9                 fcompp 
// 0053f313  dfe0                 fnstsw ax
// 0053f315  f6c405               test ah, 5
// 0053f318  7a04                 jp 0x53f31e
// 0053f31a  32c0                 xor al, al
// 0053f31c  eb18                 jmp 0x53f336
// 0053f31e  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f321  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0053f325  8b4508               mov eax, dword ptr [ebp + 8]
// 0053f328  0fb64801             movzx ecx, byte ptr [eax + 1]
// 0053f32c  3bd1                 cmp edx, ecx
// 0053f32e  7d04                 jge 0x53f334
// 0053f330  b001                 mov al, 1
// 0053f332  eb02                 jmp 0x53f336
// 0053f334  32c0                 xor al, al
// 0053f336  8be5                 mov esp, ebp
// 0053f338  5d                   pop ebp
// 0053f339  c20400               ret 4

struct Key
{
    bool less(const Key& other) const;
    bool greater(const Key& other) const;
};

struct S
{
    unsigned char first;
    unsigned char second;
    float value;
    Key key;

    bool operator<(const S& other) const;
};

#pragma optimize("", off)

bool S::operator<(const S& other) const
{
    if (key.less(other.key))
        return true;

    if (key.greater(other.key))
        return false;

    if (first < other.first)
        return true;

    if (first > other.first)
        return false;

    if (value < other.value)
        return true;

    if (value > other.value)
        return false;

    if (second < other.second)
        return true;

    return false;
}
