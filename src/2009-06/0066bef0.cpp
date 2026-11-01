// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Body { char pad[0x2c]; Body* root; public: Body* getRoot() { return root; } };
class Primitive { char pad[0xe4]; Body* body; public: Body* getBody() { return body; } };
class PartInstance { char pad[0x118]; Primitive* prim; public: Primitive* getPrimitive() { return prim; } };
class InstancePad { public: virtual ~InstancePad(); char pad[0x88]; };
class Second { public: virtual Body* getRootBody() = 0; };
class Humanoid : public InstancePad, public Second { public: PartInstance* getTorsoSlow(); Body* getRootBody(); };
Body* Humanoid::getRootBody() { PartInstance* t = getTorsoSlow(); Body* b = t ? t->getPrimitive()->getBody() : 0; return b ? b->getRoot() : 0; }
}
