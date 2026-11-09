// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    float getPartAlpha() const;
};
class PartInstance : public Instance {
public:
    char pad2[0x128 - 0x4c];
    float transparency;
    char pad3[0x16c - 0x12c];
    float alpha;
};
float Instance::getPartAlpha() const
{
    if (parent) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(parent))
            return 1.0f - (1.0f - part->transparency) * part->alpha;
    }
    return 0.0f;
}
}
