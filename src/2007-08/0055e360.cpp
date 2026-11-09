// from server: 100% by tajop
#include <string>

namespace RBX {

class VerbContainer {
};

class Verb {
public:
    Verb(VerbContainer* container, std::string name);
    virtual ~Verb();
    virtual void doIt();
private:
    void* field_4;
    void* field_8;
};

class DataModelBase {
    char pad[0x14c];
};

class DataModel : public DataModelBase, public VerbContainer {
};

class ForceAssertionVerb : public Verb {
public:
    ForceAssertionVerb(DataModel* dataModel);
    virtual void doIt();
};

ForceAssertionVerb::ForceAssertionVerb(DataModel* dataModel)
    : Verb(dataModel, "ForceAssertion")
{
}

}
