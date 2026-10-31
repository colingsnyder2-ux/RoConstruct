// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060ead0  unit: RBX::BlockBlockContact  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060ead0
//
// 0060ead0  53                   push ebx
// 0060ead1  56                   push esi
// 0060ead2  57                   push edi
// 0060ead3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060ead7  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060eada  2b470c               sub eax, dword ptr [edi + 0xc]
// 0060eadd  33f6                 xor esi, esi
// 0060eadf  c1f803               sar eax, 3
// 0060eae2  85c0                 test eax, eax
// 0060eae4  763b                 jbe 0x60eb21
// 0060eae6  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0060eaec  3bf0                 cmp esi, eax
// 0060eaee  7202                 jb 0x60eaf2
// 0060eaf0  ffd3                 call ebx
// 0060eaf2  8b470c               mov eax, dword ptr [edi + 0xc]
// 0060eaf5  83ec08               sub esp, 8
// 0060eaf8  8bd4                 mov edx, esp
// 0060eafa  89642418             mov dword ptr [esp + 0x18], esp
// 0060eafe  8d0cf0               lea ecx, [eax + esi*8]
// 0060eb01  52                   push edx
// 0060eb02  e8f9bffbff           call 0x5cab00
// 0060eb07  e8e4aaf8ff           call 0x5995f0
// 0060eb0c  83c408               add esp, 8
// 0060eb0f  84c0                 test al, al
// 0060eb11  7514                 jne 0x60eb27
// 0060eb13  8b4710               mov eax, dword ptr [edi + 0x10]
// 0060eb16  2b470c               sub eax, dword ptr [edi + 0xc]
// 0060eb19  46                   inc esi
// 0060eb1a  c1f803               sar eax, 3
// 0060eb1d  3bf0                 cmp esi, eax
// 0060eb1f  72d1                 jb 0x60eaf2
// 0060eb21  32c0                 xor al, al
// 0060eb23  5f                   pop edi
// 0060eb24  5e                   pop esi
// 0060eb25  5b                   pop ebx
// 0060eb26  c3                   ret 
// 0060eb27  5f                   pop edi
// 0060eb28  5e                   pop esi
// 0060eb29  b001                 mov al, 1
// 0060eb2b  5b                   pop ebx
// 0060eb2c  c3                   ret 

struct Value
{
    void* first;
    void* second;

    Value(const Value&);
    ~Value();
    Value convert() const;
};

struct Container
{
    unsigned int reserved[3];
    Value* begin;
    Value* end;
    Value* capacity;

    __forceinline Value& operator[](unsigned int index) const;
};

__forceinline Value& Container::operator[](unsigned int index) const
{
    return begin[index];
}

extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern bool __cdecl testValue(Value value);

bool __cdecl checkValues(const Container* values)
{
    unsigned int i = 0;
    if (static_cast<unsigned int>(values->end - values->begin) > 0)
    {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do
        {
            if (i >= static_cast<unsigned int>(values->end - values->begin))
                invalid();

            if (testValue((*values)[i].convert()))
                return true;

            ++i;
        }
        while (i < static_cast<unsigned int>(values->end - values->begin));
    }
    return false;
}
