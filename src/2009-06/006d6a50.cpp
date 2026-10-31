// from server: 95% by EspClaude
// from server: 100% by colin
// roc 2008-06 005e5da0  unit: RBX::MotorJoint  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e5da0
//
// 005e5da0  d9442404             fld dword ptr [esp + 4]
// 005e5da4  56                   push esi
// 005e5da5  8bf1                 mov esi, ecx
// 005e5da7  d8968c000000         fcom dword ptr [esi + 0x8c]
// 005e5dad  dfe0                 fnstsw ax
// 005e5daf  f6c444               test ah, 0x44
// 005e5db2  7b3e                 jnp 0x5e5df2
// 005e5db4  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e5db7  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 005e5dbd  85c9                 test ecx, ecx
// 005e5dbf  7433                 je 0x5e5df4
// 005e5dc1  8b01                 mov eax, dword ptr [ecx]
// 005e5dc3  8b5004               mov edx, dword ptr [eax + 4]
// 005e5dc6  ffd2                 call edx
// 005e5dc8  83f807               cmp eax, 7
// 005e5dcb  8b4604               mov eax, dword ptr [esi + 4]
// 005e5dce  7503                 jne 0x5e5dd3
// 005e5dd0  8b4004               mov eax, dword ptr [eax + 4]
// 005e5dd3  83780c00             cmp dword ptr [eax + 0xc], 0
// 005e5dd7  741b                 je 0x5e5df4
// 005e5dd9  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 005e5ddf  d9442408             fld dword ptr [esp + 8]
// 005e5de3  d999cc000000         fstp dword ptr [ecx + 0xcc]
// 005e5de9  e8c2de0200           call 0x613cb0
// 005e5dee  5e                   pop esi
// 005e5def  c20400               ret 4
// 005e5df2  ddd8                 fstp st(0)
// 005e5df4  5e                   pop esi
// 005e5df5  c20400               ret 4

struct Link {
    virtual void unused();
    virtual int type();

    Link* parent;
    int padding;
    int active;
};

struct State {
    char padding[0xcc];
    float value;

    void update();
};

struct S {
    int padding0;
    Link* parent;
    char padding1[0x80];
    State* state;
    float value;

    void setValue(float);
};

// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

void S::setValue(float v)
{
    if (value != v) {
        value = v;
        if (parent) {
            Link* p = parent->type() == 7 ? parent->parent : parent;
            if (p->active) {
                State* s = state;
                s->value = v;
                s->update();
            }
        }
    }
}

#pragma float_control(pop)
