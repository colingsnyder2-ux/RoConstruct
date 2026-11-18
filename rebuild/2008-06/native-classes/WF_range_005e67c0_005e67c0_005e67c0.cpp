// native-flags: /O2 /Oy; cdecl; unit RBX::Clump; range 005e67c0-005e67c0; size 103
// NEEDS-DECL: RBX::Primitive::setClump(RBX::Clump*) is the function at 0x5e7550; its real name is a guess.
// NEEDS-DECL: RBX::Primitive::clump (offset 0x5c) and RBX::Primitive::body (offset 0xa0) are unidentified members.
// NEEDS-DECL: RBX::Clump members at 0x14, 0x20, 0x54 and 0x69 are unidentified.

namespace G3D {
class CoordinateFrame {
    char data[0x30];
};
}

namespace RBX {
class Primitive;
class RigidJoint;
class Clump;
}

void transfer(RBX::Primitive* first, RBX::RigidJoint* helper, RBX::Primitive* second);

namespace RBX {

class Body {
public:
    void setParent(Body*);
    void setMeInParent(const G3D::CoordinateFrame&);
};

class Clump {
public:
    char pad0[0x14];
    volatile bool dirty14;
    char pad15[0x0b];
    Clump* volatile parent;
    char pad24[0x30];
    volatile bool dirty54;
    char pad55[0x14];
    volatile bool dirty69;
    friend void ::transfer(Primitive*, RigidJoint*, Primitive*);
private:
    void onPrimitivesChanged();
};

class Primitive {
public:
    char pad0[0x5c];
    Clump* clump;
    char pad60[0x40];
    Body* body;
    void setClump(Clump*);
};

class RigidJoint {
public:
    G3D::CoordinateFrame getChildInParent(Primitive*, Primitive*);
};
}

void transfer(RBX::Primitive* first, RBX::RigidJoint* helper, RBX::Primitive* second)
{
    RBX::Clump* clump = first->clump;
    second->setClump(first->clump);
    second->body->setParent(first->body);

    clump->dirty14 = true;
    clump->dirty54 = true;
    clump->dirty69 = true;

    RBX::Clump* owner = clump->parent;
    if (owner)
        owner->onPrimitivesChanged();

    RBX::Body* body = second->body;
    body->setMeInParent(helper->getChildInParent(first, second));
}
