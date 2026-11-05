// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 90% by king_originala
// roc 2008-06 006140b0  unit: RBX::RevoluteLink  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006140b0
//
// 006140b0  d9442404             fld dword ptr [esp + 4]
// 006140b4  8bd1                 mov edx, ecx
// 006140b6  d8928c000000         fcom dword ptr [edx + 0x8c]
// 006140bc  dfe0                 fnstsw ax
// 006140be  f6c444               test ah, 0x44
// 006140c1  7b3a                 jnp 0x6140fd
// 006140c3  8b4228               mov eax, dword ptr [edx + 0x28]
// 006140c6  85c0                 test eax, eax
// 006140c8  7406                 je 0x6140d0
// 006140ca  80780400             cmp byte ptr [eax + 4], 0
// 006140ce  7524                 jne 0x6140f4
// 006140d0  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 006140d3  85c9                 test ecx, ecx
// 006140d5  7407                 je 0x6140de
// 006140d7  e894feffff           call 0x613f70
// 006140dc  eb0b                 jmp 0x6140e9
// 006140de  8b422c               mov eax, dword ptr [edx + 0x2c]
// 006140e1  85c0                 test eax, eax
// 006140e3  7404                 je 0x6140e9
// 006140e5  c6400801             mov byte ptr [eax + 8], 1
// 006140e9  8b4228               mov eax, dword ptr [edx + 0x28]
// 006140ec  85c0                 test eax, eax
// 006140ee  7404                 je 0x6140f4
// 006140f0  c6400401             mov byte ptr [eax + 4], 1
// 006140f4  d99a8c000000         fstp dword ptr [edx + 0x8c]
// 006140fa  c20400               ret 4
// 006140fd  ddd8                 fstp st(0)
// 006140ff  c20400               ret 4

struct Link {
    char reserved0[0x14];
    Link* parent;
    char reserved1[0x10];
    char* flag28;
    char* flag2c;
    char reserved2[0x5c];
    float value;

    __declspec(noinline) void reset();
    void setValue(float v);
};

void Link::reset()
{
    if (flag28 && flag28[4])
        return;

    if (parent)
        parent->reset();
    else if (flag2c)
        flag2c[8] = 1;

    if (flag28)
        flag28[4] = 1;
}

void Link::setValue(float v)
{
    if (value != v) {
        if (!flag28 || !flag28[4]) {
            if (parent)
                parent->reset();
            else if (flag2c)
                flag2c[8] = 1;

            if (flag28)
                flag28[4] = 1;
        }
        value = v;
    }
}
