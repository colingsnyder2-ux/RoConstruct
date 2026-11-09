// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class VerbContainer { public: virtual ~VerbContainer(); };
class Verb {
public:
    Verb(VerbContainer* container, std::string name);
    virtual ~Verb();
    int a, b;
};
class OwnerPad { public: virtual ~OwnerPad(); char pad[0xcc]; };
class Workspace : public OwnerPad, public VerbContainer {};
class ClearBackpackVerb : public Verb {
public:
    Workspace* workspace;
    ClearBackpackVerb(Workspace* w);
};
ClearBackpackVerb::ClearBackpackVerb(Workspace* w)
    : Verb(w, "ClearBackpack"), workspace(w)
{
}
}
