#pragma once
// >>> native-status (generated) -- do not edit >>>
// VerbContainer | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src a311f03c | roc native-status --write
#include <map>
#include <string>

namespace RBX {
class Name;
class Verb;

// Split from the recovered Verb.h so native IDataState can be used without
// importing the donor's incompatible StateStack-based IDataState declaration.
class VerbContainer {
    friend class Verb; // 005833e0 registers itself in the verb map inline
    std::map<const Name*, Verb*> verbs;
    VerbContainer* parent;
public:
    explicit VerbContainer(VerbContainer* parent);
    virtual ~VerbContainer();
    Verb* getVerb(std::string name);
    Verb* getVerb(const Name& name);
    void setVerbParent(VerbContainer* parent);
    VerbContainer* getVerbParent() const;
private:
    void addVerb(Verb*);
    void removeVerb(Verb*);
};
}
