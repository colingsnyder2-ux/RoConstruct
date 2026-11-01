// from server: 87% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060a490  unit: RBX::Feature  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060a490
//
// 0060a490  83ec60               sub esp, 0x60
// 0060a493  56                   push esi
// 0060a494  57                   push edi
// 0060a495  6a00                 push 0
// 0060a497  6850dd9200           push 0x92dd50
// 0060a49c  8bf1                 mov esi, ecx
// 0060a49e  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 0060a4a4  687c909200           push 0x92907c
// 0060a4a9  6a00                 push 0
// 0060a4ab  50                   push eax
// 0060a4ac  e815730900           call 0x6a17c6
// 0060a4b1  8bf8                 mov edi, eax
// 0060a4b3  83c414               add esp, 0x14
// 0060a4b6  85ff                 test edi, edi
// 0060a4b8  744f                 je 0x60a509
// 0060a4ba  8d4c2408             lea ecx, [esp + 8]
// 0060a4be  51                   push ecx
// 0060a4bf  8bce                 mov ecx, esi
// 0060a4c1  e8daf8ffff           call 0x609da0
// 0060a4c6  8d542408             lea edx, [esp + 8]
// 0060a4ca  52                   push edx
// 0060a4cb  8d44243c             lea eax, [esp + 0x3c]
// 0060a4cf  50                   push eax
// 0060a4d0  8bcf                 mov ecx, edi
// 0060a4d2  e8d9e7f8ff           call 0x598cb0
// 0060a4d7  8bc8                 mov ecx, eax
// 0060a4d9  e822c2e6ff           call 0x476700
// 0060a4de  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 0060a4e2  8bf0                 mov esi, eax
// 0060a4e4  b909000000           mov ecx, 9
// 0060a4e9  8bfa                 mov edi, edx
// 0060a4eb  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0060a4ed  d94024               fld dword ptr [eax + 0x24]
// 0060a4f0  d95a24               fstp dword ptr [edx + 0x24]
// 0060a4f3  d94028               fld dword ptr [eax + 0x28]
// 0060a4f6  d95a28               fstp dword ptr [edx + 0x28]
// 0060a4f9  d9402c               fld dword ptr [eax + 0x2c]
// 0060a4fc  d95a2c               fstp dword ptr [edx + 0x2c]
// 0060a4ff  5f                   pop edi
// 0060a500  b001                 mov al, 1
// 0060a502  5e                   pop esi
// 0060a503  83c460               add esp, 0x60
// 0060a506  c20400               ret 4
// 0060a509  5f                   pop edi
// 0060a50a  32c0                 xor al, al
// 0060a50c  5e                   pop esi
// 0060a50d  83c460               add esp, 0x60
// 0060a510  c20400               ret 4

struct Matrix3 {
    float m[9];
};

struct Transform {
    Matrix3 rotation;
    float x, y, z;

    const Transform& get() const;
};

struct Part {
    Transform convert(const Transform& value);
};

extern char instanceType;
extern char partType;

extern "C" void* __cdecl runtimeCast(
    void* object, long displacement, void* sourceType,
    void* destinationType, int isReference);

struct Feature {
    char padding[0x104];
    void* object;

    Transform localTransform();
    bool f(Transform& result);
};

bool Feature::f(Transform& result)
{
    Part* part = static_cast<Part*>(
        runtimeCast(object, 0, &instanceType, &partType, 0));

    if (part) {
        Transform local = localTransform();
        const Transform& value = part->convert(local).get();

        result.rotation = value.rotation;
        result.x = value.x;
        result.y = value.y;
        result.z = value.z;
        return true;
    }

    return false;
}
