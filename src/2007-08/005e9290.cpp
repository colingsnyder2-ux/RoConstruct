// from server: 100% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// from server: 40% by colin
// roc 2007-08 005e9290  unit: RBX::Explosion  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e9290
//
// 005e9290  51                   push ecx
// 005e9291  53                   push ebx
// 005e9292  55                   push ebp
// 005e9293  56                   push esi
// 005e9294  57                   push edi
// 005e9295  8bf9                 mov edi, ecx
// 005e9297  85ff                 test edi, edi
// 005e9299  7405                 je 0x5e92a0
// 005e929b  8d4704               lea eax, [edi + 4]
// 005e929e  eb02                 jmp 0x5e92a2
// 005e92a0  33c0                 xor eax, eax
// 005e92a2  50                   push eax
// 005e92a3  b9a86f8c00           mov ecx, 0x8c6fa8
// 005e92a8  e8c36ff8ff           call 0x570270
// 005e92ad  85c0                 test eax, eax
// 005e92af  0f84ca000000         je 0x5e937f
// 005e92b5  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005e92b8  e873e31300           call 0x727630
// 005e92bd  84c0                 test al, al
// 005e92bf  0f85ba000000         jne 0x5e937f
// 005e92c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005e92c9  33ed                 xor ebp, ebp
// 005e92cb  396804               cmp dword ptr [eax + 4], ebp
// 005e92ce  0f8eab000000         jle 0x5e937f
// 005e92d4  8b00                 mov eax, dword ptr [eax]
// 005e92d6  d9870c010000         fld dword ptr [edi + 0x10c]
// 005e92dc  8b34a8               mov esi, dword ptr [eax + ebp*4]
// 005e92df  dcc0                 fadd st(0), st(0)
// 005e92e1  8b16                 mov edx, dword ptr [esi]
// 005e92e3  8b420c               mov eax, dword ptr [edx + 0xc]
// 005e92e6  8bce                 mov ecx, esi
// 005e92e8  d95c2410             fstp dword ptr [esp + 0x10]
// 005e92ec  ffd0                 call eax
// 005e92ee  d85c2410             fcomp dword ptr [esp + 0x10]
// 005e92f2  dfe0                 fnstsw ax
// 005e92f4  f6c405               test ah, 5
// 005e92f7  7a76                 jp 0x5e936f
// 005e92f9  56                   push esi
// 005e92fa  e841aaf8ff           call 0x573d40
// 005e92ff  8bd8                 mov ebx, eax
// 005e9301  83c404               add esp, 4
// 005e9304  85db                 test ebx, ebx
// 005e9306  7467                 je 0x5e936f
// 005e9308  8b7664               mov esi, dword ptr [esi + 0x64]
// 005e930b  8bce                 mov ecx, esi
// 005e930d  e8ee6df4ff           call 0x530100
// 005e9312  d986a8000000         fld dword ptr [esi + 0xa8]
// 005e9318  d8a700010000         fsub dword ptr [edi + 0x100]
// 005e931e  83ec0c               sub esp, 0xc
// 005e9321  d986ac000000         fld dword ptr [esi + 0xac]
// 005e9327  8bcc                 mov ecx, esp
// 005e9329  d8a704010000         fsub dword ptr [edi + 0x104]
// 005e932f  8964241c             mov dword ptr [esp + 0x1c], esp
// 005e9333  d986b0000000         fld dword ptr [esi + 0xb0]
// 005e9339  d8a708010000         fsub dword ptr [edi + 0x108]
// 005e933f  d9c2                 fld st(2)
// 005e9341  decb                 fmulp st(3)
// 005e9343  d9c1                 fld st(1)
// 005e9345  deca                 fmulp st(2)
// 005e9347  d9ca                 fxch st(2)
// 005e9349  dec1                 faddp st(1)
// 005e934b  d9c1                 fld st(1)
// 005e934d  deca                 fmulp st(2)
// 005e934f  dec1                 faddp st(1)
// 005e9351  d9fa                 fsqrt 
// 005e9353  d95c2408             fstp dword ptr [esp + 8]
// 005e9357  53                   push ebx
// 005e9358  51                   push ecx
// 005e9359  e81243ebff           call 0x49d670
// 005e935e  83c408               add esp, 8
// 005e9361  8d5704               lea edx, [edi + 4]
// 005e9364  52                   push edx
// 005e9365  b9a86f8c00           mov ecx, 0x8c6fa8
// 005e936a  e831faffff           call 0x5e8da0
// 005e936f  8b442418             mov eax, dword ptr [esp + 0x18]
// 005e9373  83c501               add ebp, 1
// 005e9376  3b6804               cmp ebp, dword ptr [eax + 4]
// 005e9379  0f8c55ffffff         jl 0x5e92d4
// 005e937f  5f                   pop edi
// 005e9380  5e                   pop esi
// 005e9381  5d                   pop ebp
// 005e9382  5b                   pop ebx
// 005e9383  59                   pop ecx
// 005e9384  c20400               ret 4

#include <math.h>

class sp_counted_base;
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r);
    ~shared_count();
};
template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
};

template<class T> class Array {
public:
    T* data;
    int num;
    int size() const { return num; }
    T& operator[](int n) { return data[n]; }
};

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator-(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
    float length() const { return (float)sqrt((double)(x * x + y * y + z * z)); }
};

class Body {
public:
    void updatePV();
    char pad[0xa8];
    Vector3 position;
};

class Primitive {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float getRadius();
    char pad[0x60];
    Body* body;
};

class Humanoid;
Humanoid* humanoidFromPrimitive(Primitive* p);
shared_ptr<Humanoid> shared_from(Humanoid* h);

class Listener { public: virtual ~Listener(); };
class Owner { public: char pad[0x10]; class Ancestor* ancestor; };
class Ancestor { public: bool isLocked(); };

class Registry {
public:
    Owner* findOwner(Listener* l);
    void onHit(Listener* l, shared_ptr<Humanoid> h, float distance);
};
extern Registry g_registry;

class InstanceBase { public: virtual ~InstanceBase(); };

class Explosion : public InstanceBase, public Listener {
public:
    char pad[0xf8];
    Vector3 position;
    float blastRadius;
    void doBlast(Array<Primitive*>& parts);
};

void Explosion::doBlast(Array<Primitive*>& parts)
{
    Owner* owner = g_registry.findOwner(this);
    if (!owner || owner->ancestor->isLocked())
        return;
    for (int i = 0; i < parts.size(); ++i) {
        Primitive* p = parts[i];
        if (blastRadius * 2.0f > p->getRadius()) {
            Humanoid* h = humanoidFromPrimitive(p);
            if (h) {
                Body* b = p->body;
                b->updatePV();
                g_registry.onHit(this, shared_from(h), (b->position - position).length());
            }
        }
    }
}
