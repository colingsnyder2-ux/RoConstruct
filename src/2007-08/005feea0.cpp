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

class UndoVerb : public Verb {
public:
    UndoVerb(DataModel* dataModel);
    virtual void doIt();
private:
    DataModel* dataModel;
};

UndoVerb::UndoVerb(DataModel* dataModel)
    : Verb(dataModel, "Undo"), dataModel(dataModel)
{
}

}
