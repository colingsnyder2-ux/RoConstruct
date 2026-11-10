#include "v8datamodel/Feature.h"

namespace RBX {

class AdornG3D {
public:
    static void render3dAdorn(Adorn* adorn, const G3D::CoordinateFrame* coord, int unk, float f1, float f2, float* f3);
};

template<> template<> boost::shared_ptr<VelocityMotor> Creatable<Instance>::create<VelocityMotor>();

void MotorFeature::join(Instance* a, Instance* b) {
    if (canJoin(a, b)) {
        Instance* hole = dynamic_cast<Hole*>(a) ? a : b;
        if (hole == a) a = b;
        boost::shared_ptr<VelocityMotor> motor = Creatable<Instance>::create<VelocityMotor>();
        motor->setHole(static_cast<Hole*>(hole));
        motor->setParent(a);
    }
}

bool MotorFeature::canJoin(Instance* a, Instance* b) {
    return (dynamic_cast<Hole*>(a) && dynamic_cast<MotorFeature*>(b)) ||
           (dynamic_cast<Hole*>(b) && dynamic_cast<MotorFeature*>(a));
}

__declspec(naked) void MotorFeature::render3dAdorn(Adorn* adorn) {
    __asm {
        sub esp, 0x30
        push esi
        mov esi, ecx
        lea ecx, [esp + 4]
        call dword ptr [0x802fd8]  ; CInstanceRecord::CNameItem
        lea eax, [esp + 4]
        push eax
        lea ecx, [esi - 0x130]
        call dword ptr [0x803ed4]  ; Feature::getRenderCoord
        pop esi
        test al, al
        je end_func
        call dword ptr [0x803ed0]  ; GCamera::getCameraValue
        fld dword ptr [0x82711c]
        mov edx, dword ptr [esp + 0x34]
        push eax
        sub esp, 8
        fstp dword ptr [esp + 4]
        lea ecx, [esp + 0xc]
        fld1
        fstp dword ptr [esp]
        push 2
        push ecx
        push edx
        call dword ptr [0x803ed8]  ; AdornG3D::render3dAdorn
        add esp, 0x18
end_func:
        add esp, 0x30
        ret 4
    }
}

VelocityMotor::~VelocityMotor() {
}

} // namespace RBX
