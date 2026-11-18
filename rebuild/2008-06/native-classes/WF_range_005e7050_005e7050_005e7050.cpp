// native-flags: __cdecl, 3 stack args, plain ret (0 bytes popped), MSVC 2008 x86, /O2, range 005e7050-005e7050
// NEEDS-DECL: class RBX::Assembly { public: void setParent(RBX::Assembly* parent); };
// NEEDS-DECL: class RBX::Body { public: void setParent(RBX::Body* parent); void setMeInParent(RBX::Link* link); };
// NEEDS-DECL: class RBX::MotorJoint { public: RBX::RevoluteLink* resetLink(); };
// NEEDS-DECL: class RBX::Clump { char pad0[0x5c]; RBX::Assembly* assembly; char pad1[0x40]; RBX::Body* body; };

#pragma optimize("gty", on)

namespace RBX {

class Link {};
class RevoluteLink : public Link {};

class Assembly {
public:
    void setParent(Assembly* parent);
};

class Body {
public:
    void setParent(Body* parent);
    void setMeInParent(Link* link);
};

class MotorJoint {
public:
    RevoluteLink* resetLink();
};

class Clump {
public:
    char pad0[0x5c];
    Assembly* assembly;
    char pad1[0x40];
    Body* body;
};

}

void __cdecl sub_005e7050(RBX::Clump* first, RBX::MotorJoint* source, RBX::Clump* third)
{
    third->assembly->setParent(first->assembly);
    third->body->setParent(first->body);
    RBX::Body* body = third->body;
    body->setMeInParent(source->resetLink());
}
