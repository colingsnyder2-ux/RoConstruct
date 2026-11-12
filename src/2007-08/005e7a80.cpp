// from server: 99% by EspClaude
// from server: 51% by colin
// roc 2007-08 005e7a80  unit: RBX::VExplosion::?$FactoryProduct  size: 691 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e7a80
//
// 005e7a80  d9ee                 fldz 
// 005e7a82  83ec48               sub esp, 0x48
// 005e7a85  53                   push ebx
// 005e7a86  8bd9                 mov ebx, ecx
// 005e7a88  d89b10010000         fcomp dword ptr [ebx + 0x110]
// 005e7a8e  dfe0                 fnstsw ax
// 005e7a90  f6c405               test ah, 5
// 005e7a93  0f8a93020000         jp 0x5e7d2c
// 005e7a99  55                   push ebp
// 005e7a9a  53                   push ebx
// 005e7a9b  e81033f9ff           call 0x57adb0
// 005e7aa0  89442410             mov dword ptr [esp + 0x10], eax
// 005e7aa4  8b442458             mov eax, dword ptr [esp + 0x58]
// 005e7aa8  33ed                 xor ebp, ebp
// 005e7aaa  83c404               add esp, 4
// 005e7aad  396804               cmp dword ptr [eax + 4], ebp
// 005e7ab0  0f8e75020000         jle 0x5e7d2b
// 005e7ab6  56                   push esi
// 005e7ab7  57                   push edi
// 005e7ab8  eb06                 jmp 0x5e7ac0
// 005e7aba  8d9b00000000         lea ebx, [ebx]
// 005e7ac0  8b00                 mov eax, dword ptr [eax]
// 005e7ac2  d9830c010000         fld dword ptr [ebx + 0x10c]
// 005e7ac8  8b34a8               mov esi, dword ptr [eax + ebp*4]
// 005e7acb  dcc0                 fadd st(0), st(0)
// 005e7acd  8b16                 mov edx, dword ptr [esi]
// 005e7acf  8b420c               mov eax, dword ptr [edx + 0xc]
// 005e7ad2  8bce                 mov ecx, esi
// 005e7ad4  d95c2410             fstp dword ptr [esp + 0x10]
// 005e7ad8  ffd0                 call eax
// 005e7ada  d85c2410             fcomp dword ptr [esp + 0x10]
// 005e7ade  dfe0                 fnstsw ax
// 005e7ae0  f6c405               test ah, 5
// 005e7ae3  0f8a30020000         jp 0x5e7d19
// 005e7ae9  56                   push esi
// 005e7aea  e851c2f8ff           call 0x573d40
// 005e7aef  83c404               add esp, 4
// 005e7af2  8bc8                 mov ecx, eax
// 005e7af4  e867c2f8ff           call 0x573d60
// 005e7af9  8b7e64               mov edi, dword ptr [esi + 0x64]
// 005e7afc  8bcf                 mov ecx, edi
// 005e7afe  e8fd85f4ff           call 0x530100
// 005e7b03  d987a8000000         fld dword ptr [edi + 0xa8]
// 005e7b09  f60538d18b0001       test byte ptr [0x8bd138], 1
// 005e7b10  d8a300010000         fsub dword ptr [ebx + 0x100]
// 005e7b16  d987ac000000         fld dword ptr [edi + 0xac]
// 005e7b1c  d8a304010000         fsub dword ptr [ebx + 0x104]
// 005e7b22  d987b0000000         fld dword ptr [edi + 0xb0]
// 005e7b28  d8a308010000         fsub dword ptr [ebx + 0x108]
// 005e7b2e  d9ee                 fldz 
// 005e7b30  7519                 jne 0x5e7b4b
// 005e7b32  830d38d18b0001       or dword ptr [0x8bd138], 1
// 005e7b39  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e7b3f  d91530d18b00         fst dword ptr [0x8bd130]
// 005e7b45  d91534d18b00         fst dword ptr [0x8bd134]
// 005e7b4b  d9052cd18b00         fld dword ptr [0x8bd12c]
// 005e7b51  ddec                 fucomp st(4)
// 005e7b53  dfe0                 fnstsw ax
// 005e7b55  f6c444               test ah, 0x44
// 005e7b58  7a58                 jp 0x5e7bb2
// 005e7b5a  d90530d18b00         fld dword ptr [0x8bd130]
// 005e7b60  ddeb                 fucomp st(3)
// 005e7b62  dfe0                 fnstsw ax
// 005e7b64  f6c444               test ah, 0x44
// 005e7b67  7a49                 jp 0x5e7bb2
// 005e7b69  d90534d18b00         fld dword ptr [0x8bd134]
// 005e7b6f  ddea                 fucomp st(2)
// 005e7b71  dfe0                 fnstsw ax
// 005e7b73  f6c444               test ah, 0x44
// 005e7b76  7a3a                 jp 0x5e7bb2
// 005e7b78  f605f4fb8b0001       test byte ptr [0x8bfbf4], 1
// 005e7b7f  dddb                 fstp st(3)
// 005e7b81  ddd9                 fstp st(1)
// 005e7b83  ddd8                 fstp st(0)
// 005e7b85  7522                 jne 0x5e7ba9
// 005e7b87  830df4fb8b0001       or dword ptr [0x8bfbf4], 1
// 005e7b8e  d915e8fb8b00         fst dword ptr [0x8bfbe8]
// 005e7b94  d9e8                 fld1 
// 005e7b96  b8e8fb8b00           mov eax, 0x8bfbe8
// 005e7b9b  d91decfb8b00         fstp dword ptr [0x8bfbec]
// 005e7ba1  d91df0fb8b00         fstp dword ptr [0x8bfbf0]
// 005e7ba7  eb3b                 jmp 0x5e7be4
// 005e7ba9  ddd8                 fstp st(0)
// 005e7bab  b8e8fb8b00           mov eax, 0x8bfbe8
// 005e7bb0  eb32                 jmp 0x5e7be4
// 005e7bb2  ddd8                 fstp st(0)
// 005e7bb4  8d44244c             lea eax, [esp + 0x4c]
// 005e7bb8  d9c0                 fld st(0)
// 005e7bba  d8c9                 fmul st(1)
// 005e7bbc  d9c2                 fld st(2)
// 005e7bbe  d8cb                 fmul st(3)
// 005e7bc0  dec1                 faddp st(1)
// 005e7bc2  d9c3                 fld st(3)
// 005e7bc4  d8cc                 fmul st(4)
// 005e7bc6  dec1                 faddp st(1)
// 005e7bc8  d9fa                 fsqrt 
// 005e7bca  d9e8                 fld1 
// 005e7bcc  def1                 fdivrp st(1)
// 005e7bce  dccb                 fmul st(3), st(0)
// 005e7bd0  d9cb                 fxch st(3)
// 005e7bd2  d95c244c             fstp dword ptr [esp + 0x4c]
// 005e7bd6  d9c9                 fxch st(1)
// 005e7bd8  d8ca                 fmul st(2)
// 005e7bda  d95c2450             fstp dword ptr [esp + 0x50]
// 005e7bde  dec9                 fmulp st(1)
// 005e7be0  d95c2454             fstp dword ptr [esp + 0x54]
// 005e7be4  d900                 fld dword ptr [eax]
// 005e7be6  8b16                 mov edx, dword ptr [esi]
// 005e7be8  d95c2428             fstp dword ptr [esp + 0x28]
// 005e7bec  8bce                 mov ecx, esi
// 005e7bee  d94004               fld dword ptr [eax + 4]
// 005e7bf1  d95c242c             fstp dword ptr [esp + 0x2c]
// 005e7bf5  d94008               fld dword ptr [eax + 8]
// 005e7bf8  8b420c               mov eax, dword ptr [edx + 0xc]
// 005e7bfb  d95c2430             fstp dword ptr [esp + 0x30]
// 005e7bff  ffd0                 call eax
// 005e7c01  d9542418             fst dword ptr [esp + 0x18]
// 005e7c05  dcc8                 fmul st(0), st(0)
// 005e7c07  d98310010000         fld dword ptr [ebx + 0x110]
// 005e7c0d  d9442428             fld dword ptr [esp + 0x28]
// 005e7c11  d8c9                 fmul st(1)
// 005e7c13  d944242c             fld dword ptr [esp + 0x2c]
// 005e7c17  d8ca                 fmul st(2)
// 005e7c19  d9442430             fld dword ptr [esp + 0x30]
// 005e7c1d  decb                 fmulp st(3)
// 005e7c1f  d9c9                 fxch st(1)
// 005e7c21  d8cb                 fmul st(3)
// 005e7c23  d9c9                 fxch st(1)
// 005e7c25  d8cb                 fmul st(3)
// 005e7c27  d9ca                 fxch st(2)
// 005e7c29  decb                 fmulp st(3)
// 005e7c2b  d90540d97b00         fld dword ptr [0x7bd940]
// 005e7c31  dcc9                 fmul st(1), st(0)
// 005e7c33  d9c9                 fxch st(1)
// 005e7c35  d95c2434             fstp dword ptr [esp + 0x34]
// 005e7c39  dcc9                 fmul st(1), st(0)
// 005e7c3b  d9c9                 fxch st(1)
// 005e7c3d  d95c2438             fstp dword ptr [esp + 0x38]
// 005e7c41  dec9                 fmulp st(1)
// 005e7c43  d95c243c             fstp dword ptr [esp + 0x3c]
// 005e7c47  e8040a0200           call 0x608650
// 005e7c4c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005e7c50  89442410             mov dword ptr [esp + 0x10], eax
// 005e7c54  db442410             fild dword ptr [esp + 0x10]
// 005e7c58  56                   push esi
// 005e7c59  d9442438             fld dword ptr [esp + 0x38]
// 005e7c5d  d8c9                 fmul st(1)
// 005e7c5f  d95c2420             fstp dword ptr [esp + 0x20]
// 005e7c63  d944243c             fld dword ptr [esp + 0x3c]
// 005e7c67  d8c9                 fmul st(1)
// 005e7c69  d95c2424             fstp dword ptr [esp + 0x24]
// 005e7c6d  d84c2440             fmul dword ptr [esp + 0x40]
// 005e7c71  d95c2428             fstp dword ptr [esp + 0x28]
// 005e7c75  e84615fcff           call 0x5a91c0
// 005e7c7a  8b7e64               mov edi, dword ptr [esi + 0x64]
// 005e7c7d  8bcf                 mov ecx, edi
// 005e7c7f  e87c84f4ff           call 0x530100
// 005e7c84  8b4f04               mov ecx, dword ptr [edi + 4]
// 005e7c87  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 005e7c8a  85c9                 test ecx, ecx
// 005e7c8c  7411                 je 0x5e7c9f
// 005e7c8e  81c7a8000000         add edi, 0xa8
// 005e7c94  57                   push edi
// 005e7c95  8d542420             lea edx, [esp + 0x20]
// 005e7c99  52                   push edx
// 005e7c9a  e89173feff           call 0x5cf030
// 005e7c9f  d944241c             fld dword ptr [esp + 0x1c]
// 005e7ca3  8b4664               mov eax, dword ptr [esi + 0x64]
// 005e7ca6  d9059c7e7900         fld dword ptr [0x797e9c]
// 005e7cac  8b4804               mov ecx, dword ptr [eax + 4]
// 005e7caf  dcc9                 fmul st(1), st(0)
// 005e7cb1  8b7120               mov esi, dword ptr [ecx + 0x20]
// 005e7cb4  85f6                 test esi, esi
// 005e7cb6  d9442420             fld dword ptr [esp + 0x20]
// 005e7cba  d8c9                 fmul st(1)
// 005e7cbc  d9442424             fld dword ptr [esp + 0x24]
// 005e7cc0  deca                 fmulp st(2)
// 005e7cc2  d9442418             fld dword ptr [esp + 0x18]
// 005e7cc6  dccb                 fmul st(3), st(0)
// 005e7cc8  d9cb                 fxch st(3)
// 005e7cca  d95c2440             fstp dword ptr [esp + 0x40]
// 005e7cce  d8ca                 fmul st(2)
// 005e7cd0  d95c2444             fstp dword ptr [esp + 0x44]
// 005e7cd4  dec9                 fmulp st(1)
// 005e7cd6  d95c2448             fstp dword ptr [esp + 0x48]
// 005e7cda  743d                 je 0x5e7d19
// 005e7cdc  807e0400             cmp byte ptr [esi + 4], 0
// 005e7ce0  7407                 je 0x5e7ce9
// 005e7ce2  8bce                 mov ecx, esi
// 005e7ce4  e827280300           call 0x61a510
// 005e7ce9  d9868c000000         fld dword ptr [esi + 0x8c]
// 005e7cef  d8442440             fadd dword ptr [esp + 0x40]
// 005e7cf3  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 005e7cf9  d98690000000         fld dword ptr [esi + 0x90]
// 005e7cff  d8442444             fadd dword ptr [esp + 0x44]
// 005e7d03  d99e90000000         fstp dword ptr [esi + 0x90]
// 005e7d09  d98694000000         fld dword ptr [esi + 0x94]
// 005e7d0f  d8442448             fadd dword ptr [esp + 0x48]
// 005e7d13  d99e94000000         fstp dword ptr [esi + 0x94]
// 005e7d19  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 005e7d1d  83c501               add ebp, 1
// 005e7d20  3b6804               cmp ebp, dword ptr [eax + 4]
// 005e7d23  0f8c97fdffff         jl 0x5e7ac0
// 005e7d29  5f                   pop edi
// 005e7d2a  5e                   pop esi
// 005e7d2b  5d                   pop ebp
// 005e7d2c  5b                   pop ebx
// 005e7d2d  83c448               add esp, 0x48
// 005e7d30  c20400               ret 4

// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    bool operator==(const Vector3& r) const { return x == r.x && y == r.y && z == r.z; }
    Vector3 operator-(const Vector3& r) const { return Vector3(x - r.x, y - r.y, z - r.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3& operator+=(const Vector3& r) { x += r.x; y += r.y; z += r.z; return *this; }
    float squaredLength() const { return x * x + y * y + z * z; }
    Vector3 direction() const {
        const float lenSquared = squaredLength();
        const float invSqrt = 1.0f / (float)sqrt(lenSquared);
        return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
    }
    static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
    static const Vector3& unitY() { static Vector3 v(0, 1, 0); return v; }
};

// Offsets below are read off the target: Body +4 dirty flag, +0x8c accumulator;
// Link +0x20 body; Primitive +4 link, +0xa8 position; PartInstance +0x64 primitive,
// vtable slot +0xc size; Explosion +0x100 position, +0x10c radius, +0x110 pressure.
struct Body {
    int pad0_;
    unsigned char dirty;
    char pad1_[0x8c - 5];
    Vector3 accumulated;
    void update();
    void addForce(const Vector3& f) { if (dirty) update(); accumulated += f; }
    void apply(const Vector3* force, const Vector3* point);
};

struct Link {
    char pad_[0x20];
    Body* body;
};

struct Primitive {
    int pad0_;
    Link* link;
    char pad1_[0xa8 - 8];
    Vector3 position;
    void computeCoordinateFrame();
    const Vector3& getPosition() { computeCoordinateFrame(); return position; }
};

struct Joints { void breakJoints(); };

struct PartInstance {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual float size();
    char pad_[0x60];
    Primitive* primitive;
};

struct GetSetImpl { static Joints* get(PartInstance*); };

struct Context { void insert(PartInstance*); };

struct Parts {
    PartInstance** data;
    int count;
};

extern Context* __cdecl getContext(struct Explosion*);
extern int __cdecl getMultiplier();
extern const float forceScale;
extern const float secondaryScale;

struct Explosion {
    char pad_[0x100];
    Vector3 position;
    float radius;
    float pressure;
    void explode(Parts* parts);
};

void Explosion::explode(Parts* parts)
{
    if (pressure > 0.0f) {
        Context* context = getContext(this);
        for (int i = 0; i < parts->count; ++i) {
            PartInstance* part = parts->data[i];
            float limit = radius + radius;
            if (part->size() < limit) {
                GetSetImpl::get(part)->breakJoints();
                Vector3 delta = part->primitive->getPosition() - position;
                Vector3 unit = delta == Vector3::zero() ? Vector3::unitY() : delta.direction();
                float size = part->size();
                float square = size * size;
                Vector3 force = ((unit * pressure) * square) * forceScale;
                Vector3 scaled = force * (float)getMultiplier();
                context->insert(part);

                Primitive* prim = part->primitive;
                const Vector3* point = &prim->getPosition();
                Body* body = prim->link->body;
                if (body)
                    body->apply(&scaled, point);

                Body* secondary = part->primitive->link->body;
                Vector3 impulse = (scaled * secondaryScale) * size;
                if (secondary)
                    secondary->addForce(impulse);
            }
        }
    }
}
