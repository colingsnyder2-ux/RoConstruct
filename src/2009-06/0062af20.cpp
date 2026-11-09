// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    bool isDescendentOf2(const Instance* ancestor) const;
    bool isDescendentOf(const Instance* ancestor) const {
        if (ancestor == parent) return true;
        return parent && parent->isDescendentOf2(ancestor);
    }
};
class Script : public Instance {};
class LocalScript : public Script {};
class IScriptFilter { public: virtual bool scriptShouldRun(Script* script) = 0; };
class Workspace;
namespace Network {
class Players {
public:
    static bool backendProcessing(const Instance* context, bool testInDatamodel);
    static Instance* findLocalCharacter(const Instance* context);
};
}
class WorkspacePad : public Instance { public: char wpad[0x1ac - 0x4c]; };
class Workspace : public WorkspacePad, public IScriptFilter {
public:
    bool scriptShouldRun(Script* script);
};
bool Workspace::scriptShouldRun(Script* script)
{
    if (!dynamic_cast<LocalScript*>(script))
        return Network::Players::backendProcessing(this, true);
    Instance* character = Network::Players::findLocalCharacter(this);
    if (character)
        return script->isDescendentOf(character);
    return false;
}
}
