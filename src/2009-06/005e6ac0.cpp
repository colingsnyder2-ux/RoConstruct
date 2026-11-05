// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e550  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e550
//
// 0056e550  51                   push ecx
// 0056e551  33c0                 xor eax, eax
// 0056e553  56                   push esi
// 0056e554  8d542404             lea edx, [esp + 4]
// 0056e558  6689442404           mov word ptr [esp + 4], ax
// 0056e55d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056e561  8bf1                 mov esi, ecx
// 0056e563  52                   push edx
// 0056e564  33c9                 xor ecx, ecx
// 0056e566  50                   push eax
// 0056e567  66894c240e           mov word ptr [esp + 0xe], cx
// 0056e56c  e8df030500           call 0x5be950
// 0056e571  83c408               add esp, 8
// 0056e574  84c0                 test al, al
// 0056e576  741b                 je 0x56e593
// 0056e578  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e57b  8b11                 mov edx, dword ptr [ecx]
// 0056e57d  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e580  8d442404             lea eax, [esp + 4]
// 0056e584  50                   push eax
// 0056e585  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056e589  50                   push eax
// 0056e58a  ffd2                 call edx
// 0056e58c  b001                 mov al, 1
// 0056e58e  5e                   pop esi
// 0056e58f  59                   pop ecx
// 0056e590  c20800               ret 8
// 0056e593  32c0                 xor al, al
// 0056e595  5e                   pop esi
// 0056e596  59                   pop ecx
// 0056e597  c20800               ret 8

struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Vector2int16
{
    short x;
    short y;
};

extern bool __cdecl parseVector(const String&, Vector2int16&);

struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Vector2int16&);
};

struct Descriptor
{
    unsigned char padding[24];
    Setter* setter;

    bool setFromString(void*, const String&);
};

bool Descriptor::setFromString(void* object, const String& text)
{
    Vector2int16 value = { 0, 0 };
    if (parseVector(text, value))
    {
        setter->set(object, value);
        return true;
    }
    return false;
}
