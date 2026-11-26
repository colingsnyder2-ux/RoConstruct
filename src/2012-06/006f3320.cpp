// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class VerbContainer { public: int v; };
class Debugable {};
class Verb : public Debugable {
public:
    Verb(VerbContainer* container, const std::string& name);
    virtual ~Verb();
    int a;
    int b;
};
class DataModelBase { public: char pad[0xac]; };
class DataModel : public DataModelBase, public VerbContainer {};
class FirstPersonCommand : public Verb {
    DataModel* dataModel;
public:
    FirstPersonCommand(DataModel* dataModel);
    virtual ~FirstPersonCommand();
};
FirstPersonCommand::FirstPersonCommand(DataModel* dataModel)
    : Verb(dataModel, "SetGridToOff"), dataModel(dataModel)
{
}
}
