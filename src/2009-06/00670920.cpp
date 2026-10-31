// from server: 89% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e8470  unit: RBX::Primitive  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e8470
//
// 005e8470  8b442404             mov eax, dword ptr [esp + 4]
// 005e8474  83ec0c               sub esp, 0xc
// 005e8477  56                   push esi
// 005e8478  8bf1                 mov esi, ecx
// 005e847a  50                   push eax
// 005e847b  8d4c2408             lea ecx, [esp + 8]
// 005e847f  51                   push ecx
// 005e8480  8bce                 mov ecx, esi
// 005e8482  e839ffffff           call 0x5e83c0
// 005e8487  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e848d  d94104               fld dword ptr [ecx + 4]
// 005e8490  d85c2404             fcomp dword ptr [esp + 4]
// 005e8494  dfe0                 fnstsw ax
// 005e8496  f6c444               test ah, 0x44
// 005e8499  7a1c                 jp 0x5e84b7
// 005e849b  d94108               fld dword ptr [ecx + 8]
// 005e849e  d85c2408             fcomp dword ptr [esp + 8]
// 005e84a2  dfe0                 fnstsw ax
// 005e84a4  f6c444               test ah, 0x44
// 005e84a7  7a0e                 jp 0x5e84b7
// 005e84a9  d9410c               fld dword ptr [ecx + 0xc]
// 005e84ac  d85c240c             fcomp dword ptr [esp + 0xc]
// 005e84b0  dfe0                 fnstsw ax
// 005e84b2  f6c444               test ah, 0x44
// 005e84b5  7b42                 jnp 0x5e84f9
// 005e84b7  c78698000000feffffff mov dword ptr [esi + 0x98], 0xfffffffe
// 005e84c1  8b11                 mov edx, dword ptr [ecx]
// 005e84c3  8b520c               mov edx, dword ptr [edx + 0xc]
// 005e84c6  8d442404             lea eax, [esp + 4]
// 005e84ca  50                   push eax
// 005e84cb  ffd2                 call edx
// 005e84cd  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e84d3  8b01                 mov eax, dword ptr [ecx]
// 005e84d5  8b501c               mov edx, dword ptr [eax + 0x1c]
// 005e84d8  ffd2                 call edx
// 005e84da  51                   push ecx
// 005e84db  8bce                 mov ecx, esi
// 005e84dd  d91c24               fstp dword ptr [esp]
// 005e84e0  e81bfbffff           call 0x5e8000
// 005e84e5  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 005e84e8  85c9                 test ecx, ecx
// 005e84ea  7406                 je 0x5e84f2
// 005e84ec  56                   push esi
// 005e84ed  e8ce0c0000           call 0x5e91c0
// 005e84f2  c686f000000001       mov byte ptr [esi + 0xf0], 1
// 005e84f9  5e                   pop esi
// 005e84fa  83c40c               add esp, 0xc
// 005e84fd  c20400               ret 4

struct Vector {
    float x, y, z;
};

struct S;

struct Listener {
    char pad[132];
    void* member;
    void f(S*);
};

struct Shape {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void setVector(const Vector&) = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual float getValue() = 0;

    Vector value;
};

struct S {
    char pad0[0x58];
    Listener* listener;
    char pad1[0x3c];
    int state;
    Shape* shape;
    char pad2[0x50];
    unsigned char changed;

    Vector prepare(const Vector&);
    void update(float);
    void f(const Vector&);
};

#pragma float_control(precise, off, push)

void S::f(const Vector& input)
{
    Vector value = prepare(input);
    if (value.x != shape->value.x ||
        value.y != shape->value.y ||
        value.z != shape->value.z)
    {
        state = -2;
        shape->setVector(value);
        update(shape->getValue());
        if (listener)
            listener->f(this);
        changed = 1;
    }
}

#pragma float_control(pop)
