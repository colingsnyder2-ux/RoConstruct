// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e310  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e310
//
// 0056e310  83ec10               sub esp, 0x10
// 0056e313  8b542418             mov edx, dword ptr [esp + 0x18]
// 0056e317  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0056e31a  8b01                 mov eax, dword ptr [ecx]
// 0056e31c  8b4008               mov eax, dword ptr [eax + 8]
// 0056e31f  56                   push esi
// 0056e320  52                   push edx
// 0056e321  8d54240c             lea edx, [esp + 0xc]
// 0056e325  52                   push edx
// 0056e326  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0056e32e  ffd0                 call eax
// 0056e330  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056e334  8d4c2408             lea ecx, [esp + 8]
// 0056e338  51                   push ecx
// 0056e339  56                   push esi
// 0056e33a  e8d1060500           call 0x5bea10
// 0056e33f  83c408               add esp, 8
// 0056e342  8bc6                 mov eax, esi
// 0056e344  5e                   pop esi
// 0056e345  83c410               add esp, 0x10
// 0056e348  c20800               ret 8

struct Vector3
{
    float x, y, z;
};

struct Result;

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual Vector3* get(Vector3* value, void* object);
};

extern void __cdecl convert(Result* result, const Vector3* value);

struct Descriptor
{
    char padding[24];
    Accessor* accessor;

    Result* read(Result* result, void* object);
};

Result* Descriptor::read(Result* result, void* object)
{
    volatile int state = 0;
    Vector3 temporary;
    accessor->get(&temporary, object);
    convert(result, &temporary);
    return result;
}
