// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e350  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e350
//
// 0056e350  83ec0c               sub esp, 0xc
// 0056e353  d9ee                 fldz 
// 0056e355  56                   push esi
// 0056e356  8d442404             lea eax, [esp + 4]
// 0056e35a  d9542404             fst dword ptr [esp + 4]
// 0056e35e  8bf1                 mov esi, ecx
// 0056e360  d9542408             fst dword ptr [esp + 8]
// 0056e364  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056e368  d95c240c             fstp dword ptr [esp + 0xc]
// 0056e36c  50                   push eax
// 0056e36d  51                   push ecx
// 0056e36e  e83d080500           call 0x5bebb0
// 0056e373  83c408               add esp, 8
// 0056e376  84c0                 test al, al
// 0056e378  741d                 je 0x56e397
// 0056e37a  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e37d  8b11                 mov edx, dword ptr [ecx]
// 0056e37f  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e382  8d442404             lea eax, [esp + 4]
// 0056e386  50                   push eax
// 0056e387  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056e38b  50                   push eax
// 0056e38c  ffd2                 call edx
// 0056e38e  b001                 mov al, 1
// 0056e390  5e                   pop esi
// 0056e391  83c40c               add esp, 0xc
// 0056e394  c20800               ret 8
// 0056e397  32c0                 xor al, al
// 0056e399  5e                   pop esi
// 0056e39a  83c40c               add esp, 0xc
// 0056e39d  c20800               ret 8

struct Vector3
{
    float x, y, z;
};

extern bool __cdecl convert(void* source, Vector3* value);

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const Vector3* value);
};

struct Descriptor
{
    char padding[24];
    Accessor* accessor;

    bool write(void* object, void* source);
};

bool Descriptor::write(void* object, void* source)
{
    Vector3 value = { 0.0f, 0.0f, 0.0f };
    if (convert(source, &value))
    {
        accessor->set(object, &value);
        return true;
    }
    return false;
}
