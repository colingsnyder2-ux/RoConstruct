// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
class Primitive { public: void setPreventCollide(bool b); };
class PartInstance {
public:
    void setName(const std::string& name);
    void setName2(const std::string& name);
    char pad[0x118];
    Primitive* primitive;
};
void PartInstance::setName2(const std::string& name)
{
    setName(name);
    if (name == "Torso")
        primitive->setPreventCollide(true);
    else
        primitive->setPreventCollide(false);
}
