// from server: 100% by EspClaude
// from server: 98% by king_originala
// roc 2008-06 00632e10  unit: RBX::Rocket  size: 447 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00632e10
//
// 00632e10  6aff                 push -1
// 00632e12  6838ea7b00           push 0x7bea38
// 00632e17  64a100000000         mov eax, dword ptr fs:[0]
// 00632e1d  50                   push eax
// 00632e1e  64892500000000       mov dword ptr fs:[0], esp
// 00632e25  83ec18               sub esp, 0x18
// 00632e28  53                   push ebx
// 00632e29  56                   push esi
// 00632e2a  57                   push edi
// 00632e2b  33db                 xor ebx, ebx
// 00632e2d  895c240c             mov dword ptr [esp + 0xc], ebx
// 00632e31  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00632e35  8b542434             mov edx, dword ptr [esp + 0x34]
// 00632e39  8bf1                 mov esi, ecx
// 00632e3b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00632e3f  50                   push eax
// 00632e40  51                   push ecx
// 00632e41  52                   push edx
// 00632e42  8bce                 mov ecx, esi
// 00632e44  e897ccffff           call 0x62fae0
// 00632e49  395e04               cmp dword ptr [esi + 4], ebx
// 00632e4c  7427                 je 0x632e75
// 00632e4e  8d44240c             lea eax, [esp + 0xc]
// 00632e52  50                   push eax
// 00632e53  8d4e08               lea ecx, [esi + 8]
// 00632e56  e8a57cf9ff           call 0x5cab00
// 00632e5b  833800               cmp dword ptr [eax], 0
// 00632e5e  bb01000000           mov ebx, 1
// 00632e63  7410                 je 0x632e75
// 00632e65  807e1000             cmp byte ptr [esi + 0x10], 0
// 00632e69  740a                 je 0x632e75
// 00632e6b  807e2c00             cmp byte ptr [esi + 0x2c], 0
// 00632e6f  885c2434             mov byte ptr [esp + 0x34], bl
// 00632e73  7405                 je 0x632e7a
// 00632e75  c644243400           mov byte ptr [esp + 0x34], 0
// 00632e7a  f6c301               test bl, 1
// 00632e7d  7432                 je 0x632eb1
// 00632e7f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00632e83  85ff                 test edi, edi
// 00632e85  742a                 je 0x632eb1
// 00632e87  8d4f04               lea ecx, [edi + 4]
// 00632e8a  83caff               or edx, 0xffffffff
// 00632e8d  f00fc111             lock xadd dword ptr [ecx], edx
// 00632e91  751e                 jne 0x632eb1
// 00632e93  8b07                 mov eax, dword ptr [edi]
// 00632e95  8b5004               mov edx, dword ptr [eax + 4]
// 00632e98  8bcf                 mov ecx, edi
// 00632e9a  ffd2                 call edx
// 00632e9c  8d4708               lea eax, [edi + 8]
// 00632e9f  83c9ff               or ecx, 0xffffffff
// 00632ea2  f00fc108             lock xadd dword ptr [eax], ecx
// 00632ea6  7509                 jne 0x632eb1
// 00632ea8  8b17                 mov edx, dword ptr [edi]
// 00632eaa  8b4208               mov eax, dword ptr [edx + 8]
// 00632ead  8bcf                 mov ecx, edi
// 00632eaf  ffd0                 call eax
// 00632eb1  807c243400           cmp byte ptr [esp + 0x34], 0
// 00632eb6  0f84ff000000         je 0x632fbb
// 00632ebc  8d4c240c             lea ecx, [esp + 0xc]
// 00632ec0  51                   push ecx
// 00632ec1  8d4e08               lea ecx, [esi + 8]
// 00632ec4  e8377cf9ff           call 0x5cab00
// 00632ec9  8b08                 mov ecx, dword ptr [eax]
// 00632ecb  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00632ed3  e8d85df6ff           call 0x598cb0
// 00632ed8  d94024               fld dword ptr [eax + 0x24]
// 00632edb  83c024               add eax, 0x24
// 00632ede  d95c2418             fstp dword ptr [esp + 0x18]
// 00632ee2  d94004               fld dword ptr [eax + 4]
// 00632ee5  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00632eed  d95c241c             fstp dword ptr [esp + 0x1c]
// 00632ef1  d94008               fld dword ptr [eax + 8]
// 00632ef4  8b442410             mov eax, dword ptr [esp + 0x10]
// 00632ef8  d95c2420             fstp dword ptr [esp + 0x20]
// 00632efc  85c0                 test eax, eax
// 00632efe  742c                 je 0x632f2c
// 00632f00  8bf8                 mov edi, eax
// 00632f02  83c004               add eax, 4
// 00632f05  83caff               or edx, 0xffffffff
// 00632f08  f00fc110             lock xadd dword ptr [eax], edx
// 00632f0c  751e                 jne 0x632f2c
// 00632f0e  8b07                 mov eax, dword ptr [edi]
// 00632f10  8b5004               mov edx, dword ptr [eax + 4]
// 00632f13  8bcf                 mov ecx, edi
// 00632f15  ffd2                 call edx
// 00632f17  8d4708               lea eax, [edi + 8]
// 00632f1a  83c9ff               or ecx, 0xffffffff
// 00632f1d  f00fc108             lock xadd dword ptr [eax], ecx
// 00632f21  7509                 jne 0x632f2c
// 00632f23  8b17                 mov edx, dword ptr [edi]
// 00632f25  8b4208               mov eax, dword ptr [edx + 8]
// 00632f28  8bcf                 mov ecx, edi
// 00632f2a  ffd0                 call eax
// 00632f2c  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00632f2f  85c9                 test ecx, ecx
// 00632f31  7417                 je 0x632f4a
// 00632f33  8d561c               lea edx, [esi + 0x1c]
// 00632f36  52                   push edx
// 00632f37  8d442410             lea eax, [esp + 0x10]
// 00632f3b  50                   push eax
// 00632f3c  e86f5df6ff           call 0x598cb0
// 00632f41  8bc8                 mov ecx, eax
// 00632f43  e85837e4ff           call 0x4766a0
// 00632f48  eb03                 jmp 0x632f4d
// 00632f4a  8d461c               lea eax, [esi + 0x1c]
// 00632f4d  d900                 fld dword ptr [eax]
// 00632f4f  d94004               fld dword ptr [eax + 4]
// 00632f52  d94008               fld dword ptr [eax + 8]
// 00632f55  d9442418             fld dword ptr [esp + 0x18]
// 00632f59  dee3                 fsubrp st(3)
// 00632f5b  d944241c             fld dword ptr [esp + 0x1c]
// 00632f5f  dee2                 fsubrp st(2)
// 00632f61  d86c2420             fsubr dword ptr [esp + 0x20]
// 00632f65  d94628               fld dword ptr [esi + 0x28]
// 00632f68  d9c1                 fld st(1)
// 00632f6a  deca                 fmulp st(2)
// 00632f6c  d9c2                 fld st(2)
// 00632f6e  decb                 fmulp st(3)
// 00632f70  d9c9                 fxch st(1)
// 00632f72  dec2                 faddp st(2)
// 00632f74  d9c2                 fld st(2)
// 00632f76  decb                 fmulp st(3)
// 00632f78  d9c9                 fxch st(1)
// 00632f7a  dec2                 faddp st(2)
// 00632f7c  dcc8                 fmul st(0), st(0)
// 00632f7e  ded9                 fcompp 
// 00632f80  dfe0                 fnstsw ax
// 00632f82  f6c401               test ah, 1
// 00632f85  7534                 jne 0x632fbb
// 00632f87  8d8ec8feffff         lea ecx, [esi - 0x138]
// 00632f8d  85c9                 test ecx, ecx
// 00632f8f  7408                 je 0x632f99
// 00632f91  8d86dcfeffff         lea eax, [esi - 0x124]
// 00632f97  eb02                 jmp 0x632f9b
// 00632f99  33c0                 xor eax, eax
// 00632f9b  50                   push eax
// 00632f9c  b91cc89700           mov ecx, 0x97c81c
// 00632fa1  e87a86f3ff           call 0x56b620
// 00632fa6  85c0                 test eax, eax
// 00632fa8  740d                 je 0x632fb7
// 00632faa  8d542434             lea edx, [esp + 0x34]
// 00632fae  52                   push edx
// 00632faf  8d4810               lea ecx, [eax + 0x10]
// 00632fb2  e89929e8ff           call 0x4b5950
// 00632fb7  c6462c01             mov byte ptr [esi + 0x2c], 1
// 00632fbb  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00632fbf  5f                   pop edi
// 00632fc0  5e                   pop esi
// 00632fc1  5b                   pop ebx
// 00632fc2  64890d00000000       mov dword ptr fs:[0], ecx
// 00632fc9  83c424               add esp, 0x24
// 00632fcc  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
#pragma float_control(precise, off)

struct Counted {
    virtual ~Counted();
    virtual void dispose();
    virtual void destroy();
    volatile long use;
    volatile long weak;
    void release();
};

inline void Counted::release()
{
    if (_InterlockedDecrement(&use) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Vector {
    float x, y, z;
    Vector();
    Vector(const Vector&);
};

inline Vector::Vector(const Vector& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct Frame {
    float rotation[9];
    Vector position;
    Vector transform(const Vector&) const;
};

struct Part {
    const Frame& frame() const;
};

struct Shared {
    Part* pointer;
    Counted* count;
    ~Shared();
};

inline Shared::~Shared()
{
    if (count)
        count->release();
}

struct Weak {
    Part* pointer;
    Counted* count;
    Shared lock() const;
};

struct Event {};

struct Signal {
    void fire(const Event&);
};

struct Receiver {
    char padding[16];
    Signal signal;
};

struct Registry {
    Receiver* find(void*);
};

extern Registry registry;

struct Stepped { const float time; const float step; Stepped(float t,float s):time(t),step(s){} };

struct Rocket {
    int unused;
    int active;
    Weak target;
    bool enabled;
    char padding0[3];
    Part* relative;
    int unused18;
    Vector destination;
    float radius;
    bool fired;

    void update(const void*, Stepped);
    void baseUpdate(const void*, Stepped);
};

void Rocket::update(const void* source, Stepped event)
{
    baseUpdate(source, event);

    if (active && target.lock().pointer && enabled && !fired) {
        Vector position = target.lock().pointer->frame().position;
        const Vector& goal =
            relative ? relative->frame().transform(destination) : destination;

        float x = position.x - goal.x;
        float y = position.y - goal.y;
        float z = position.z - goal.z;

        if (x * x + y * y + z * z <= radius * radius) {
            Rocket* base = reinterpret_cast<Rocket*>(
                reinterpret_cast<char*>(this) - 0x138);
            Receiver* receiver = registry.find(
                base ? reinterpret_cast<char*>(this) - 0x124 : 0);
            if (receiver) {
                Event event;
                receiver->signal.fire(event);
            }
            fired = true;
        }
    }
}
