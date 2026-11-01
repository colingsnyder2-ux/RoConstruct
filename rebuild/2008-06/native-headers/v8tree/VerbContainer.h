#pragma once
#include <map>
#include <string>

namespace RBX {
class Name;
class Verb;

// Split from the recovered Verb.h so native IDataState can be used without
// importing the donor's incompatible StateStack-based IDataState declaration.
class VerbContainer {
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
