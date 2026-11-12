// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 006029c0  unit: RBX::Running  size: 473 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006029c0
//
// 006029c0  64a100000000         mov eax, dword ptr fs:[0]
// 006029c6  6aff                 push -1
// 006029c8  68c6d27500           push 0x75d2c6
// 006029cd  50                   push eax
// 006029ce  64892500000000       mov dword ptr fs:[0], esp
// 006029d5  83ec18               sub esp, 0x18
// 006029d8  55                   push ebp
// 006029d9  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 006029dd  56                   push esi
// 006029de  55                   push ebp
// 006029df  8bf1                 mov esi, ecx
// 006029e1  e87a3d0200           call 0x626760
// 006029e6  3bc6                 cmp eax, esi
// 006029e8  0f8598010000         jne 0x602b86
// 006029ee  d9ee                 fldz 
// 006029f0  d85e38               fcomp dword ptr [esi + 0x38]
// 006029f3  dfe0                 fnstsw ax
// 006029f5  f6c441               test ah, 0x41
// 006029f8  7a60                 jp 0x602a5a
// 006029fa  8b4e04               mov ecx, dword ptr [esi + 4]
// 006029fd  f6816401000001       test byte ptr [ecx + 0x164], 1
// 00602a04  7454                 je 0x602a5a
// 00602a06  6a00                 push 0
// 00602a08  e80358faff           call 0x5a8210
// 00602a0d  6a34                 push 0x34
// 00602a0f  e8e2d40200           call 0x62fef6
// 00602a14  83c404               add esp, 4
// 00602a17  89442430             mov dword ptr [esp + 0x30], eax
// 00602a1b  85c0                 test eax, eax
// 00602a1d  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00602a25  741e                 je 0x602a45
// 00602a27  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602a2a  51                   push ecx
// 00602a2b  8bc8                 mov ecx, eax
// 00602a2d  e8ce430200           call 0x626e00
// 00602a32  5e                   pop esi
// 00602a33  5d                   pop ebp
// 00602a34  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00602a38  64890d00000000       mov dword ptr fs:[0], ecx
// 00602a3f  83c424               add esp, 0x24
// 00602a42  c20400               ret 4
// 00602a45  5e                   pop esi
// 00602a46  33c0                 xor eax, eax
// 00602a48  5d                   pop ebp
// 00602a49  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00602a4d  64890d00000000       mov dword ptr fs:[0], ecx
// 00602a54  83c424               add esp, 0x24
// 00602a57  c20400               ret 4
// 00602a5a  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602a5d  6a00                 push 0
// 00602a5f  e8ac57faff           call 0x5a8210
// 00602a64  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602a67  f6816401000008       test byte ptr [ecx + 0x164], 8
// 00602a6e  743f                 je 0x602aaf
// 00602a70  6a00                 push 0
// 00602a72  e8d957faff           call 0x5a8250
// 00602a77  6a08                 push 8
// 00602a79  e878d40200           call 0x62fef6
// 00602a7e  83c404               add esp, 4
// 00602a81  89442430             mov dword ptr [esp + 0x30], eax
// 00602a85  85c0                 test eax, eax
// 00602a87  c744242801000000     mov dword ptr [esp + 0x28], 1
// 00602a8f  74b4                 je 0x602a45
// 00602a91  8b5604               mov edx, dword ptr [esi + 4]
// 00602a94  52                   push edx
// 00602a95  8bc8                 mov ecx, eax
// 00602a97  e8843f0200           call 0x626a20
// 00602a9c  5e                   pop esi
// 00602a9d  5d                   pop ebp
// 00602a9e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00602aa2  64890d00000000       mov dword ptr fs:[0], ecx
// 00602aa9  83c424               add esp, 0x24
// 00602aac  c20400               ret 4
// 00602aaf  8b4614               mov eax, dword ptr [esi + 0x14]
// 00602ab2  85c0                 test eax, eax
// 00602ab4  7412                 je 0x602ac8
// 00602ab6  8b80d8010000         mov eax, dword ptr [eax + 0x1d8]
// 00602abc  8b8998010000         mov ecx, dword ptr [ecx + 0x198]
// 00602ac2  50                   push eax
// 00602ac3  e8f866faff           call 0x5a91c0
// 00602ac8  d94620               fld dword ptr [esi + 0x20]
// 00602acb  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602ace  d95e4c               fstp dword ptr [esi + 0x4c]
// 00602ad1  e81a37faff           call 0x5a61f0
// 00602ad6  85c0                 test eax, eax
// 00602ad8  741a                 je 0x602af4
// 00602ada  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602add  e80e37faff           call 0x5a61f0
// 00602ae2  8b4860               mov ecx, dword ptr [eax + 0x60]
// 00602ae5  d94108               fld dword ptr [ecx + 8]
// 00602ae8  d80d9c7e7900         fmul dword ptr [0x797e9c]
// 00602aee  d8464c               fadd dword ptr [esi + 0x4c]
// 00602af1  d95e4c               fstp dword ptr [esi + 0x4c]
// 00602af4  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602af7  e81437faff           call 0x5a6210
// 00602afc  85c0                 test eax, eax
// 00602afe  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602b01  740d                 je 0x602b10
// 00602b03  e80837faff           call 0x5a6210
// 00602b08  8b5060               mov edx, dword ptr [eax + 0x60]
// 00602b0b  d94208               fld dword ptr [edx + 8]
// 00602b0e  eb17                 jmp 0x602b27
// 00602b10  e81b37faff           call 0x5a6230
// 00602b15  85c0                 test eax, eax
// 00602b17  7414                 je 0x602b2d
// 00602b19  8b4e04               mov ecx, dword ptr [esi + 4]
// 00602b1c  e80f37faff           call 0x5a6230
// 00602b21  8b4060               mov eax, dword ptr [eax + 0x60]
// 00602b24  d94008               fld dword ptr [eax + 8]
// 00602b27  d8464c               fadd dword ptr [esi + 0x4c]
// 00602b2a  d95e4c               fstp dword ptr [esi + 0x4c]
// 00602b2d  8b4614               mov eax, dword ptr [esi + 0x14]
// 00602b30  85c0                 test eax, eax
// 00602b32  7507                 jne 0x602b3b
// 00602b34  e87793ffff           call 0x5fbeb0
// 00602b39  eb26                 jmp 0x602b61
// 00602b3b  8b88d8010000         mov ecx, dword ptr [eax + 0x1d8]
// 00602b41  57                   push edi
// 00602b42  8b7964               mov edi, dword ptr [ecx + 0x64]
// 00602b45  8bcf                 mov ecx, edi
// 00602b47  e8b4d5f2ff           call 0x530100
// 00602b4c  8d561c               lea edx, [esi + 0x1c]
// 00602b4f  52                   push edx
// 00602b50  8d442410             lea eax, [esp + 0x10]
// 00602b54  50                   push eax
// 00602b55  8d8f84000000         lea ecx, [edi + 0x84]
// 00602b5b  e870d0f2ff           call 0x52fbd0
// 00602b60  5f                   pop edi
// 00602b61  d900                 fld dword ptr [eax]
// 00602b63  55                   push ebp
// 00602b64  d94004               fld dword ptr [eax + 4]
// 00602b67  8bce                 mov ecx, esi
// 00602b69  d94008               fld dword ptr [eax + 8]
// 00602b6c  d94010               fld dword ptr [eax + 0x10]
// 00602b6f  d9cb                 fxch st(3)
// 00602b71  d95e28               fstp dword ptr [esi + 0x28]
// 00602b74  d9c9                 fxch st(1)
// 00602b76  d95e2c               fstp dword ptr [esi + 0x2c]
// 00602b79  d95e30               fstp dword ptr [esi + 0x30]
// 00602b7c  d95e34               fstp dword ptr [esi + 0x34]
// 00602b7f  e89cfcffff           call 0x602820
// 00602b84  8bc6                 mov eax, esi
// 00602b86  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00602b8a  5e                   pop esi
// 00602b8b  5d                   pop ebp
// 00602b8c  64890d00000000       mov dword ptr fs:[0], ecx
// 00602b93  83c424               add esp, 0x24
// 00602b96  c20400               ret 4
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) { x = v.x; y = v.y; z = v.z; }
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};

struct Velocity {
    Vector3 linear;       // +0
    Vector3 rotational;   // +0xc
    static const Velocity& zero();
};

struct Geometry {
    int pad0;
    Vector3 size;         // +4
};

struct Primitive {
    char pad0[0x60];
    Geometry* geometry;   // +0x60
};

struct PV {
    Velocity velocityAtPoint(const Vector3& point) const;
};

struct Body {
    char pad0[0x84];
    PV pv;                // +0x84
    void updatePV();
};

struct BodyOwner {
    char pad0[0x64];
    Body* body;           // +0x64
};

struct FloorPart {
    char pad0[0x1d8];
    BodyOwner* owner;     // +0x1d8
};

struct Floors {
    void setFloor(BodyOwner* owner);
};

struct Humanoid {
    char pad0[0x164];
    unsigned char jump : 1;   // +0x164 bit 0
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char sit : 1;    // +0x164 bit 3
    char pad165[0x198 - 0x165];
    Floors* floors;           // +0x198
    void setJump(bool);
    void setSit(bool);
    Primitive* getTorsoSlow();
    Primitive* getRightLegSlow();
    Primitive* getLeftLegSlow();
};

struct Controller;
struct HumanoidState;

struct Jumping {
    char pad0[0x34];
    Jumping(Humanoid* h);
};

struct Seated {
    char pad0[8];
    Seated(Humanoid* h);
};

struct Balancing {
    char pad0[4];
    Humanoid* humanoid;       // +4
    char pad8[0xc];
    FloorPart* floorPart;     // +0x14
    char pad18[4];
    Vector3 floorPoint;       // +0x1c
    Vector3 floorVelocity;    // +0x28
    float floorRotationalVelocity; // +0x34
    float floorDistance;      // +0x38
    char pad3c[0x10];
    float desiredAltitude;    // +0x4c
    HumanoidState* computeEvent(Controller* controller);
    void computeForces(Controller* controller);
};

struct RunningBase : Balancing {
    HumanoidState* onComputeEvent(Controller* controller);
};

HumanoidState* RunningBase::onComputeEvent(Controller* controller)
{
    HumanoidState* result = Balancing::computeEvent(controller);
    if (result != (HumanoidState*)this)
        return result;

    if (floorDistance >= 0.0f && humanoid->jump) {
        humanoid->setJump(false);
        return (HumanoidState*)new Jumping(humanoid);
    }
    humanoid->setJump(false);
    if (humanoid->sit) {
        humanoid->setSit(false);
        return (HumanoidState*)new Seated(humanoid);
    }

    if (floorPart)
        humanoid->floors->setFloor(floorPart->owner);

    desiredAltitude = floorPoint.y;
    if (humanoid->getTorsoSlow())
        desiredAltitude += humanoid->getTorsoSlow()->geometry->size.y * 0.5f;
    if (humanoid->getRightLegSlow())
        desiredAltitude += humanoid->getRightLegSlow()->geometry->size.y;
    else if (humanoid->getLeftLegSlow())
        desiredAltitude += humanoid->getLeftLegSlow()->geometry->size.y;

    Body* body;
    const Velocity& v = !floorPart
        ? Velocity::zero()
        : (body = floorPart->owner->body, body->updatePV(), body->pv.velocityAtPoint(floorPoint));
    floorVelocity = v.linear;
    floorRotationalVelocity = v.rotational.y;

    computeForces(controller);
    return (HumanoidState*)this;
}

}
