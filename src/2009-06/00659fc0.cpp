// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005ccb50  unit: RBX::P8Camera::?$GetSetImpl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ccb50
//
// 005ccb50  83ec30               sub esp, 0x30
// 005ccb53  56                   push esi
// 005ccb54  8bf1                 mov esi, ecx
// 005ccb56  8b86dc010000         mov eax, dword ptr [esi + 0x1dc]
// 005ccb5c  85c0                 test eax, eax
// 005ccb5e  7451                 je 0x5ccbb1
// 005ccb60  57                   push edi
// 005ccb61  6a00                 push 0
// 005ccb63  6804839400           push 0x948304
// 005ccb68  687c909200           push 0x92907c
// 005ccb6d  6a00                 push 0
// 005ccb6f  50                   push eax
// 005ccb70  e8514c0d00           call 0x6a17c6
// 005ccb75  8b4804               mov ecx, dword ptr [eax + 4]
// 005ccb78  8b5104               mov edx, dword ptr [ecx + 4]
// 005ccb7b  8d4c0204             lea ecx, [edx + eax + 4]
// 005ccb7f  8b01                 mov eax, dword ptr [ecx]
// 005ccb81  8b00                 mov eax, dword ptr [eax]
// 005ccb83  83c414               add esp, 0x14
// 005ccb86  8d542408             lea edx, [esp + 8]
// 005ccb8a  52                   push edx
// 005ccb8b  ffd0                 call eax
// 005ccb8d  8d96a4010000         lea edx, [esi + 0x1a4]
// 005ccb93  b909000000           mov ecx, 9
// 005ccb98  8bf0                 mov esi, eax
// 005ccb9a  8bfa                 mov edi, edx
// 005ccb9c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005ccb9e  d94024               fld dword ptr [eax + 0x24]
// 005ccba1  d95a24               fstp dword ptr [edx + 0x24]
// 005ccba4  d94028               fld dword ptr [eax + 0x28]
// 005ccba7  d95a28               fstp dword ptr [edx + 0x28]
// 005ccbaa  d9402c               fld dword ptr [eax + 0x2c]
// 005ccbad  d95a2c               fstp dword ptr [edx + 0x2c]
// 005ccbb0  5f                   pop edi
// 005ccbb1  5e                   pop esi
// 005ccbb2  83c430               add esp, 0x30
// 005ccbb5  c3                   ret 

struct Matrix
{
    float m[9];
};

struct Vector
{
    float x, y, z;
    Vector& operator=(const Vector& other);
};

inline Vector& Vector::operator=(const Vector& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Transform
{
    Matrix rotation;
    Vector position;
};

namespace RBX
{
    class Instance
    {
    public:
        virtual ~Instance();
    };

    class Camera
    {
    public:
        virtual Transform getTransform() = 0;
    };

    class CameraSubject : public virtual Camera
    {
    public:
        virtual ~CameraSubject();
    };
}

struct S
{
    char padding[0x10c];
    Transform transform;
    char gap[4];
    RBX::Instance* subject;

    void f();
};

void S::f()
{
    if (subject)
        transform = dynamic_cast<RBX::CameraSubject*>(subject)->getTransform();
}
