#pragma once
#include <map>
#include <string>

namespace RBX {
class Name;
class Verb;

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
