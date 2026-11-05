// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

namespace RBX {
class Debugable {
public:
    virtual ~Debugable() {}
};
class VerbContainer;
class Verb : public Debugable {
public:
    Verb(VerbContainer* container, std::string name);
    virtual ~Verb();
    int data[2];
};
}

double __cdecl readTime();

class ToggleIDEModeVerb : public RBX::Verb {
public:
    double lastToggle;
    ToggleIDEModeVerb(RBX::VerbContainer* container);
    virtual ~ToggleIDEModeVerb() {}
};

ToggleIDEModeVerb::ToggleIDEModeVerb(RBX::VerbContainer* container)
    : RBX::Verb(container, "TogglePlayMode")
{
    lastToggle = readTime();
}
