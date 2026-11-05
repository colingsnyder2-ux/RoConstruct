// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066ce20  unit: RBX::GroupDragTool  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ce20
//
// 0066ce20  83ec30               sub esp, 0x30
// 0066ce23  53                   push ebx
// 0066ce24  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 0066ce28  8bcb                 mov ecx, ebx
// 0066ce2a  e8b1bff2ff           call 0x598de0
// 0066ce2f  8bc8                 mov ecx, eax
// 0066ce31  e81afef7ff           call 0x5ecc50
// 0066ce36  84c0                 test al, al
// 0066ce38  0f8487000000         je 0x66cec5
// 0066ce3e  56                   push esi
// 0066ce3f  8bcb                 mov ecx, ebx
// 0066ce41  e86abef2ff           call 0x598cb0
// 0066ce46  8bf0                 mov esi, eax
// 0066ce48  56                   push esi
// 0066ce49  8d4c240c             lea ecx, [esp + 0xc]
// 0066ce4d  e8ce63eaff           call 0x513220
// 0066ce52  d94624               fld dword ptr [esi + 0x24]
// 0066ce55  f605a428970001       test byte ptr [0x9728a4], 1
// 0066ce5c  d95c242c             fstp dword ptr [esp + 0x2c]
// 0066ce60  d94628               fld dword ptr [esi + 0x28]
// 0066ce63  d95c2430             fstp dword ptr [esp + 0x30]
// 0066ce67  d9462c               fld dword ptr [esi + 0x2c]
// 0066ce6a  d95c2434             fstp dword ptr [esp + 0x34]
// 0066ce6e  751d                 jne 0x66ce8d
// 0066ce70  d9ee                 fldz 
// 0066ce72  830da428970001       or dword ptr [0x9728a4], 1
// 0066ce79  d91598289700         fst dword ptr [0x972898]
// 0066ce7f  d9e8                 fld1 
// 0066ce81  d91d9c289700         fstp dword ptr [0x97289c]
// 0066ce87  d91da0289700         fstp dword ptr [0x9728a0]
// 0066ce8d  8d442408             lea eax, [esp + 8]
// 0066ce91  50                   push eax
// 0066ce92  6898289700           push 0x972898
// 0066ce97  e8c416f7ff           call 0x5de560
// 0066ce9c  83c408               add esp, 8
// 0066ce9f  83f801               cmp eax, 1
// 0066cea2  7420                 je 0x66cec4
// 0066cea4  57                   push edi
// 0066cea5  e8766feaff           call 0x513e20
// 0066ceaa  8bf0                 mov esi, eax
// 0066ceac  b909000000           mov ecx, 9
// 0066ceb1  8d7c240c             lea edi, [esp + 0xc]
// 0066ceb5  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0066ceb7  8d4c240c             lea ecx, [esp + 0xc]
// 0066cebb  51                   push ecx
// 0066cebc  8bcb                 mov ecx, ebx
// 0066cebe  e8dd09f3ff           call 0x59d8a0
// 0066cec3  5f                   pop edi
// 0066cec4  5e                   pop esi
// 0066cec5  5b                   pop ebx
// 0066cec6  83c430               add esp, 0x30
// 0066cec9  c3                   ret 

struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;

    Frame(const Frame& f)
        : rotation(f.rotation), translation(f.translation) {}
};

struct State {
    bool enabled();
};

struct Object {
    int* state();
    const Frame* frame();
    void setFrame(const Frame&);
};

extern int __cdecl classify(const Vector3&, const Frame&);
extern const Matrix3& __cdecl identity();

void __cdecl update(Object* object)
{
    if (reinterpret_cast<State*>(object->state())->enabled()) {
        const Frame* source = object->frame();
        Frame value(*source);
        static Vector3 up(0.0f, 1.0f, 0.0f);

        if (classify(up, value) != 1) {
            value.rotation = identity();
            object->setFrame(value);
        }
    }
}
