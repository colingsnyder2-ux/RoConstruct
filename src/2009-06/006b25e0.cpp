// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e200  unit: RBX::BlockBlockContact  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e200
//
// 0060e200  6aff                 push -1
// 0060e202  6888257d00           push 0x7d2588
// 0060e207  64a100000000         mov eax, dword ptr fs:[0]
// 0060e20d  50                   push eax
// 0060e20e  64892500000000       mov dword ptr fs:[0], esp
// 0060e215  83ec18               sub esp, 0x18
// 0060e218  56                   push esi
// 0060e219  57                   push edi
// 0060e21a  33ff                 xor edi, edi
// 0060e21c  8bf1                 mov esi, ecx
// 0060e21e  897c240c             mov dword ptr [esp + 0xc], edi
// 0060e222  897c2410             mov dword ptr [esp + 0x10], edi
// 0060e226  897c2408             mov dword ptr [esp + 8], edi
// 0060e22a  8d442408             lea eax, [esp + 8]
// 0060e22e  50                   push eax
// 0060e22f  8d4e08               lea ecx, [esi + 8]
// 0060e232  51                   push ecx
// 0060e233  897c2430             mov dword ptr [esp + 0x30], edi
// 0060e237  e8f4080000           call 0x60eb30
// 0060e23c  83c408               add esp, 8
// 0060e23f  397c240c             cmp dword ptr [esp + 0xc], edi
// 0060e243  7e5a                 jle 0x60e29f
// 0060e245  8b5628               mov edx, dword ptr [esi + 0x28]
// 0060e248  8b442434             mov eax, dword ptr [esp + 0x34]
// 0060e24c  52                   push edx
// 0060e24d  50                   push eax
// 0060e24e  8d4c2410             lea ecx, [esp + 0x10]
// 0060e252  51                   push ecx
// 0060e253  8d542420             lea edx, [esp + 0x20]
// 0060e257  52                   push edx
// 0060e258  e863240000           call 0x6106c0
// 0060e25d  d9442424             fld dword ptr [esp + 0x24]
// 0060e261  8b742440             mov esi, dword ptr [esp + 0x40]
// 0060e265  8b442418             mov eax, dword ptr [esp + 0x18]
// 0060e269  d91e                 fstp dword ptr [esi]
// 0060e26b  d9442428             fld dword ptr [esp + 0x28]
// 0060e26f  50                   push eax
// 0060e270  d95e04               fstp dword ptr [esi + 4]
// 0060e273  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0060e27b  d9442430             fld dword ptr [esp + 0x30]
// 0060e27f  d95e08               fstp dword ptr [esi + 8]
// 0060e282  e8999aefff           call 0x507d20
// 0060e287  83c414               add esp, 0x14
// 0060e28a  5f                   pop edi
// 0060e28b  8bc6                 mov eax, esi
// 0060e28d  5e                   pop esi
// 0060e28e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060e292  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e299  83c424               add esp, 0x24
// 0060e29c  c20800               ret 8
// 0060e29f  b801000000           mov eax, 1
// 0060e2a4  840550f09600         test byte ptr [0x96f050], al
// 0060e2aa  751a                 jne 0x60e2c6
// 0060e2ac  d9ee                 fldz 
// 0060e2ae  090550f09600         or dword ptr [0x96f050], eax
// 0060e2b4  d91544f09600         fst dword ptr [0x96f044]
// 0060e2ba  d91548f09600         fst dword ptr [0x96f048]
// 0060e2c0  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0060e2c6  8b742430             mov esi, dword ptr [esp + 0x30]
// 0060e2ca  d90544f09600         fld dword ptr [0x96f044]
// 0060e2d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0060e2d4  d91e                 fstp dword ptr [esi]
// 0060e2d6  d90548f09600         fld dword ptr [0x96f048]
// 0060e2dc  51                   push ecx
// 0060e2dd  d95e04               fstp dword ptr [esi + 4]
// 0060e2e0  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0060e2e8  d9054cf09600         fld dword ptr [0x96f04c]
// 0060e2ee  d95e08               fstp dword ptr [esi + 8]
// 0060e2f1  e82a9aefff           call 0x507d20
// 0060e2f6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060e2fa  83c404               add esp, 4
// 0060e2fd  5f                   pop edi
// 0060e2fe  8bc6                 mov eax, esi
// 0060e300  5e                   pop esi
// 0060e301  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e308  83c424               add esp, 0x24
// 0060e30b  c20800               ret 8

extern void __cdecl alignedFree(void*);

struct Vector3 {
    float x, y, z;

    Vector3();
    Vector3(int);
    Vector3(const Vector3&);
};

__forceinline Vector3::Vector3()
    : x(0.0f), y(0.0f), z(0.0f)
{
}

__forceinline Vector3::Vector3(int)
{
}

__forceinline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct Array {
    void* data;
    int count;
    int capacity;

    Array();
    ~Array();
};

inline Array::Array()
    : count(0), capacity(0)
{
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

extern void __cdecl collect(const void*, Array*);
extern void __cdecl calculate(Vector3*, const Array&, const Vector3&, int);

struct Contact {
    char prefix[8];
    char geometry[32];
    int value;

    Vector3 evaluate(const Vector3&);
};

Vector3 Contact::evaluate(const Vector3& argument)
{
    Array entries;
    collect(geometry, &entries);

    if (entries.count > 0) {
        Vector3 result(0);
        calculate(&result, entries, argument, value);
        return result;
    }

    static const Vector3 zero;
    return zero;
}
