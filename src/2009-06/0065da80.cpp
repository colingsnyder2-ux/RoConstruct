// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0059aa90  unit: RBX::PartInstance  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059aa90
//
// 0059aa90  83ec68               sub esp, 0x68
// 0059aa93  53                   push ebx
// 0059aa94  56                   push esi
// 0059aa95  8bf1                 mov esi, ecx
// 0059aa97  57                   push edi
// 0059aa98  8d44240c             lea eax, [esp + 0xc]
// 0059aa9c  8d9e30030000         lea ebx, [esi + 0x330]
// 0059aaa2  50                   push eax
// 0059aaa3  8bcb                 mov ecx, ebx
// 0059aaa5  e8c6f0ffff           call 0x599b70
// 0059aaaa  8d8e28020000         lea ecx, [esi + 0x228]
// 0059aab0  e80bd80400           call 0x5e82c0
// 0059aab5  8d5338               lea edx, [ebx + 0x38]
// 0059aab8  8bf0                 mov esi, eax
// 0059aaba  b909000000           mov ecx, 9
// 0059aabf  8bfa                 mov edi, edx
// 0059aac1  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0059aac3  d94024               fld dword ptr [eax + 0x24]
// 0059aac6  d95a24               fstp dword ptr [edx + 0x24]
// 0059aac9  d94028               fld dword ptr [eax + 0x28]
// 0059aacc  d95a28               fstp dword ptr [edx + 0x28]
// 0059aacf  d9402c               fld dword ptr [eax + 0x2c]
// 0059aad2  d95a2c               fstp dword ptr [edx + 0x2c]
// 0059aad5  5f                   pop edi
// 0059aad6  5e                   pop esi
// 0059aad7  8bc3                 mov eax, ebx
// 0059aad9  5b                   pop ebx
// 0059aada  83c468               add esp, 0x68
// 0059aadd  c3                   ret 

struct Vector3 {
    float x, y, z;
};

struct Body {
    char pad[0x94];
    Vector3 value;
    void updatePV();
};

struct Primitive {
    char pad[0xa0];
    Body* body;
    const Vector3& getValue();
};

struct Matrix3 {
    float elements[9];
};

struct Frame {
    Matrix3 rotation;
    Vector3 position;

    Frame& operator=(const Frame& value);
};

__forceinline Frame& Frame::operator=(const Frame& value)
{
    rotation = value.rotation;
    position.x = value.position.x;
    position.y = value.position.y;
    position.z = value.position.z;
    return *this;
}

struct Temporary {
    char data[0x68];
};

struct Cache {
    char pad[0x38];
    Frame frame;
    void prepare(Temporary* value);
};

struct Part {
    char pad[0x228];
    Primitive primitive;
    char gap[0x64];
    Cache cache;

    Cache& getCache();
};

Cache& Part::getCache()
{
    Temporary temporary;
    Cache& result = cache;
    result.prepare(&temporary);
    result.frame =
        *reinterpret_cast<const Frame*>(&primitive.getValue());
    return result;
}
