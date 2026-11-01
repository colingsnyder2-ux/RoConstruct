// from server: 80% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Instance;
class PropertyDescriptor;
struct Color3 {
    float r, g, b;
    Color3& operator=(const Color3& o) { r = o.r; g = o.g; b = o.b; return *this; }
    bool operator==(const Color3& o) const { return r == o.r && g == o.g && b == o.b; }
    bool operator!=(const Color3& o) const { return r != o.r || g != o.g || b != o.b; }
};
void update(Instance*, bool);
struct Visitor { void (*fn)(Instance*, bool); bool flag; };
class World { public: void visit(Visitor v); };
extern const PropertyDescriptor prop_color;
class Lighting {
public:
    void raisePropertyChanged(const PropertyDescriptor&);
    void setColor(Color3 value);
    char pad0[0x1dc];
    Color3 color;
    char pad1[0x234 - 0x1e8];
    World* world;
};
void Lighting::setColor(Color3 value)
{
    if (color != value) {
        color = value;
        raisePropertyChanged(prop_color);
        Visitor v = { &update, false };
        if (world)
            world->visit(v);
    }
}
