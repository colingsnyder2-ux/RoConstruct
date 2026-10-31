// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e240  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e240
//
// 0056e240  83ec08               sub esp, 8
// 0056e243  56                   push esi
// 0056e244  8d442404             lea eax, [esp + 4]
// 0056e248  8bf1                 mov esi, ecx
// 0056e24a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056e24e  50                   push eax
// 0056e24f  51                   push ecx
// 0056e250  e82b040500           call 0x5be680
// 0056e255  83c408               add esp, 8
// 0056e258  84c0                 test al, al
// 0056e25a  741d                 je 0x56e279
// 0056e25c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e25f  8b11                 mov edx, dword ptr [ecx]
// 0056e261  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e264  8d442404             lea eax, [esp + 4]
// 0056e268  50                   push eax
// 0056e269  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056e26d  50                   push eax
// 0056e26e  ffd2                 call edx
// 0056e270  b001                 mov al, 1
// 0056e272  5e                   pop esi
// 0056e273  83c408               add esp, 8
// 0056e276  c20800               ret 8
// 0056e279  32c0                 xor al, al
// 0056e27b  5e                   pop esi
// 0056e27c  83c408               add esp, 8
// 0056e27f  c20800               ret 8

extern "C" bool __cdecl convert(const void *, double *);

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const double &);
};

struct S {
    unsigned char padding[24];
    Setter *setter;
    bool assign(void *, const void *);
};

bool S::assign(void *object, const void *source)
{
    double value;
    if (convert(source, &value)) {
        setter->set(object, value);
        return true;
    }
    return false;
}
