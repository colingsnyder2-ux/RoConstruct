// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vec3 { float x, y, z; };
struct PV { char pad[0x30]; Vec3 a; Vec3 b; };
class Primitive { public: const PV& getPV(); };
class PartInstance {
    char pad[0x118];
    Primitive* primitive;
public:
    const Vec3& getA() const;
};
const Vec3& PartInstance::getA() const { return primitive->getPV().a; }
