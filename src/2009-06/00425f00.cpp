// from server: 82% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042d190  unit: boost::any::H::?$holder  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042d190
//
// 0042d190  55                   push ebp
// 0042d191  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0042d195  56                   push esi
// 0042d196  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042d19a  3bee                 cmp ebp, esi
// 0042d19c  7450                 je 0x42d1ee
// 0042d19e  53                   push ebx
// 0042d19f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0042d1a3  57                   push edi
// 0042d1a4  8d7b04               lea edi, [ebx + 4]
// 0042d1a7  8b46f8               mov eax, dword ptr [esi - 8]
// 0042d1aa  83ee08               sub esi, 8
// 0042d1ad  83eb08               sub ebx, 8
// 0042d1b0  8903                 mov dword ptr [ebx], eax
// 0042d1b2  8b4e04               mov ecx, dword ptr [esi + 4]
// 0042d1b5  83ef08               sub edi, 8
// 0042d1b8  85c9                 test ecx, ecx
// 0042d1ba  7409                 je 0x42d1c5
// 0042d1bc  8b11                 mov edx, dword ptr [ecx]
// 0042d1be  8b4208               mov eax, dword ptr [edx + 8]
// 0042d1c1  ffd0                 call eax
// 0042d1c3  eb02                 jmp 0x42d1c7
// 0042d1c5  33c0                 xor eax, eax
// 0042d1c7  8d4c241c             lea ecx, [esp + 0x1c]
// 0042d1cb  3bcf                 cmp ecx, edi
// 0042d1cd  7406                 je 0x42d1d5
// 0042d1cf  8bc8                 mov ecx, eax
// 0042d1d1  8b07                 mov eax, dword ptr [edi]
// 0042d1d3  890f                 mov dword ptr [edi], ecx
// 0042d1d5  85c0                 test eax, eax
// 0042d1d7  740a                 je 0x42d1e3
// 0042d1d9  8b10                 mov edx, dword ptr [eax]
// 0042d1db  8bc8                 mov ecx, eax
// 0042d1dd  8b02                 mov eax, dword ptr [edx]
// 0042d1df  6a01                 push 1
// 0042d1e1  ffd0                 call eax
// 0042d1e3  3bf5                 cmp esi, ebp
// 0042d1e5  75c0                 jne 0x42d1a7
// 0042d1e7  5f                   pop edi
// 0042d1e8  8bc3                 mov eax, ebx
// 0042d1ea  5b                   pop ebx
// 0042d1eb  5e                   pop esi
// 0042d1ec  5d                   pop ebp
// 0042d1ed  c3                   ret 
// 0042d1ee  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042d1f2  5e                   pop esi
// 0042d1f3  5d                   pop ebp
// 0042d1f4  c3                   ret 

struct Holder
{
    virtual ~Holder();
    virtual void type() const = 0;
    virtual Holder* clone() const = 0;
};

struct Element
{
    int first;
    Holder* second;
};

Element* __cdecl copy_backward(Element* first, Element* last, Element* result)
{
    while (first != last)
    {
        --last;
        --result;
        result->first = last->first;

        Holder* source = last->second;
        Holder* temporary = source ? source->clone() : 0;
        if (&temporary != &result->second)
        {
            Holder* old = temporary;
            temporary = result->second;
            result->second = old;
        }

        if (temporary)
            delete temporary;
    }

    return result;
}
