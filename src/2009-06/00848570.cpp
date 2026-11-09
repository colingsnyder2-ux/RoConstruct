// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 007b7b10  unit: RBX::Render::Material::Level  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b7b10
//
// 007b7b10  56                   push esi
// 007b7b11  8bf1                 mov esi, ecx
// 007b7b13  8b06                 mov eax, dword ptr [esi]
// 007b7b15  8b5018               mov edx, dword ptr [eax + 0x18]
// 007b7b18  57                   push edi
// 007b7b19  ffd2                 call edx
// 007b7b1b  d900                 fld dword ptr [eax]
// 007b7b1d  d94004               fld dword ptr [eax + 4]
// 007b7b20  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007b7b24  d94008               fld dword ptr [eax + 8]
// 007b7b27  8d87a8040000         lea eax, [edi + 0x4a8]
// 007b7b2d  d9ca                 fxch st(2)
// 007b7b2f  50                   push eax
// 007b7b30  d918                 fstp dword ptr [eax]
// 007b7b32  d95804               fstp dword ptr [eax + 4]
// 007b7b35  d95808               fstp dword ptr [eax + 8]
// 007b7b38  d9e8                 fld1 
// 007b7b3a  d9580c               fstp dword ptr [eax + 0xc]
// 007b7b3d  ff150c2a8000         call dword ptr [0x802a0c]
// 007b7b43  8b06                 mov eax, dword ptr [esi]
// 007b7b45  8b501c               mov edx, dword ptr [eax + 0x1c]
// 007b7b48  8bce                 mov ecx, esi
// 007b7b4a  ffd2                 call edx
// 007b7b4c  51                   push ecx
// 007b7b4d  8bcf                 mov ecx, edi
// 007b7b4f  d91c24               fstp dword ptr [esp]
// 007b7b52  e8f90accff           call 0x478650
// 007b7b57  8b06                 mov eax, dword ptr [esi]
// 007b7b59  8b5020               mov edx, dword ptr [eax + 0x20]
// 007b7b5c  8bce                 mov ecx, esi
// 007b7b5e  ffd2                 call edx
// 007b7b60  51                   push ecx
// 007b7b61  8bcf                 mov ecx, edi
// 007b7b63  d91c24               fstp dword ptr [esp]
// 007b7b66  e8a5efcbff           call 0x476b10
// 007b7b6b  8b06                 mov eax, dword ptr [esi]
// 007b7b6d  8b5008               mov edx, dword ptr [eax + 8]
// 007b7b70  51                   push ecx
// 007b7b71  8bcc                 mov ecx, esp
// 007b7b73  89642410             mov dword ptr [esp + 0x10], esp
// 007b7b77  57                   push edi
// 007b7b78  51                   push ecx
// 007b7b79  8bce                 mov ecx, esi
// 007b7b7b  ffd2                 call edx
// 007b7b7d  6a00                 push 0
// 007b7b7f  8bcf                 mov ecx, edi
// 007b7b81  e8ca18ccff           call 0x479450
// 007b7b86  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007b7b89  85c9                 test ecx, ecx
// 007b7b8b  744f                 je 0x7b7bdc
// 007b7b8d  8b01                 mov eax, dword ptr [ecx]
// 007b7b8f  8b5008               mov edx, dword ptr [eax + 8]
// 007b7b92  ffd2                 call edx
// 007b7b94  83e800               sub eax, 0
// 007b7b97  7438                 je 0x7b7bd1
// 007b7b99  83e801               sub eax, 1
// 007b7b9c  7423                 je 0x7b7bc1
// 007b7b9e  83e801               sub eax, 1
// 007b7ba1  8bcf                 mov ecx, edi
// 007b7ba3  740e                 je 0x7b7bb3
// 007b7ba5  6a04                 push 4
// 007b7ba7  6a00                 push 0
// 007b7ba9  e8c2fdcbff           call 0x477970
// 007b7bae  5f                   pop edi
// 007b7baf  5e                   pop esi
// 007b7bb0  c20400               ret 4
// 007b7bb3  6a00                 push 0
// 007b7bb5  6a00                 push 0
// 007b7bb7  e8b4fdcbff           call 0x477970
// 007b7bbc  5f                   pop edi
// 007b7bbd  5e                   pop esi
// 007b7bbe  c20400               ret 4
// 007b7bc1  6a04                 push 4
// 007b7bc3  8bcf                 mov ecx, edi
// 007b7bc5  6a00                 push 0
// 007b7bc7  e8a4fdcbff           call 0x477970
// 007b7bcc  5f                   pop edi
// 007b7bcd  5e                   pop esi
// 007b7bce  c20400               ret 4
// 007b7bd1  6a02                 push 2
// 007b7bd3  8bcf                 mov ecx, edi
// 007b7bd5  6a00                 push 0
// 007b7bd7  e894fdcbff           call 0x477970
// 007b7bdc  5f                   pop edi
// 007b7bdd  5e                   pop esi
// 007b7bde  c20400               ret 4

#pragma float_control(precise, off)

struct Vec3 {
    float x, y, z;
};

struct Vec4 {
    float x, y, z, w;
    Vec4(const Vec3&, float);
    Vec4& operator=(const Vec4&);
};

__forceinline Vec4::Vec4(const Vec3& v, float a)
    : x(v.x), y(v.y), z(v.z), w(a)
{
}

__forceinline Vec4& Vec4::operator=(const Vec4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

struct Handle {
    void* p;
    Handle();
    Handle(const Handle&);
    ~Handle();
};

__forceinline Handle::~Handle()
{
}

struct Device {
    char padding[0x4a8];
    Vec4 color;

    void setFirst(float);
    void setSecond(float);
    void setHandle(int, Handle);
    void setMode(int, int);
};

extern "C" void (__stdcall *glColor3fv)(const float*);

struct Mode {
    virtual void slot0();
    virtual void slot1();
    virtual int value();
};

struct Level {
    virtual void slot0();
    virtual void slot1();
    virtual Handle getHandle(Device*);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual const Vec3& getColor();
    virtual float getFirst();
    virtual float getSecond();

    char padding[8];
    Mode* mode;

    void apply(Device*);
};

void Level::apply(Device* device)
{
    device->color = Vec4(getColor(), 1.0f);
    glColor3fv(&device->color.x);
    device->setFirst(getFirst());
    device->setSecond(getSecond());
    device->setHandle(0, getHandle(device));

    Mode* m = mode;
    if (m) {
        switch (m->value()) {
        case 0:
            device->setMode(0, 2);
            break;
        case 1:
            device->setMode(0, 4);
            break;
        case 2:
            device->setMode(0, 0);
            break;
        default:
            device->setMode(0, 4);
            break;
        }
    }
}
