// from server: 100% by EspClaude
// from server: 87% by EspClaude
// roc 2009-06 00698aa0  unit: RBX::Feature  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00698aa0
//
// 00698aa0  83ec60               sub esp, 0x60
// 00698aa3  56                   push esi
// 00698aa4  57                   push edi
// 00698aa5  6a00                 push 0
// 00698aa7  6850f99d00           push 0x9df950
// 00698aac  8bf1                 mov esi, ecx
// 00698aae  8b4648               mov eax, dword ptr [esi + 0x48]
// 00698ab1  6840be9d00           push 0x9dbe40
// 00698ab6  6a00                 push 0
// 00698ab8  50                   push eax
// 00698ab9  e8bc110800           call 0x719c7a
// 00698abe  8bf8                 mov edi, eax
// 00698ac0  83c414               add esp, 0x14
// 00698ac3  85ff                 test edi, edi
// 00698ac5  744f                 je 0x698b16
// 00698ac7  8d4c2408             lea ecx, [esp + 8]
// 00698acb  51                   push ecx
// 00698acc  8bce                 mov ecx, esi
// 00698ace  e87dfaffff           call 0x698550
// 00698ad3  8d542408             lea edx, [esp + 8]
// 00698ad7  52                   push edx
// 00698ad8  8d44243c             lea eax, [esp + 0x3c]
// 00698adc  50                   push eax
// 00698add  8bcf                 mov ecx, edi
// 00698adf  e86c3afcff           call 0x65c550
// 00698ae4  8bc8                 mov ecx, eax
// 00698ae6  e88552e0ff           call 0x49dd70
// 00698aeb  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 00698aef  8bf0                 mov esi, eax
// 00698af1  b909000000           mov ecx, 9
// 00698af6  8bfa                 mov edi, edx
// 00698af8  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00698afa  d94024               fld dword ptr [eax + 0x24]
// 00698afd  d95a24               fstp dword ptr [edx + 0x24]
// 00698b00  d94028               fld dword ptr [eax + 0x28]
// 00698b03  d95a28               fstp dword ptr [edx + 0x28]
// 00698b06  d9402c               fld dword ptr [eax + 0x2c]
// 00698b09  d95a2c               fstp dword ptr [edx + 0x2c]
// 00698b0c  5f                   pop edi
// 00698b0d  b001                 mov al, 1
// 00698b0f  5e                   pop esi
// 00698b10  83c460               add esp, 0x60
// 00698b13  c20400               ret 4
// 00698b16  5f                   pop edi
// 00698b17  32c0                 xor al, al
// 00698b19  5e                   pop esi
// 00698b1a  83c460               add esp, 0x60
// 00698b1d  c20400               ret 4

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
    char padding[0x48];
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
