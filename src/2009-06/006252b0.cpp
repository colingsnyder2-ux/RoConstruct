// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Backpack : public Instance { public: virtual ~Backpack(); };
}
struct Holder {
    char pad[0x48];
    RBX::Instance* parent;
    int isInBackpack();
};
int Holder::isInBackpack()
{
    if (parent && dynamic_cast<RBX::Backpack*>(parent))
        return 1;
    return 0;
}
