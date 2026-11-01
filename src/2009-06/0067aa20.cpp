// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
class Instance;
class PropertyDescriptor;
void update(Instance*, bool);
struct Visitor { void (*fn)(Instance*, bool); bool flag; };
class World { public: void visit(Visitor v); };
extern const PropertyDescriptor prop_value;
class Lighting {
public:
    void raisePropertyChanged(const PropertyDescriptor&);
    void setValue(float value);
    char pad0[0x1e8];
    float value;
    char pad1[0x234 - 0x1e8 - 4];
    World* world;
};
void Lighting::setValue(float v)
{
    if (v != value) {
        value = v;
        raisePropertyChanged(prop_value);
        Visitor vis = { &update, false };
        if (world)
            world->visit(vis);
    }
}
