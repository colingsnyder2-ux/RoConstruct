// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class VerbContainer {};
class DataModel { char pad[0xd0]; public: VerbContainer verbs; };
class Verb {
public:
    Verb(VerbContainer* container, std::string name);
    virtual ~Verb();
private:
    char pad[8];
};
class JoinCommand : public Verb {
public:
    JoinCommand(DataModel* dataModel);
private:
    DataModel* dataModel;
};
JoinCommand::JoinCommand(DataModel* dataModel)
    : Verb(dataModel ? &dataModel->verbs : 0, "JoinCommand"), dataModel(dataModel)
{
}
}
