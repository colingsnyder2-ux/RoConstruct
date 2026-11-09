// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class VerbContainer {};
class DataModel { char pad[0xd0]; public: VerbContainer verbs; };
class DeleteSelectionVerb {
public:
    DeleteSelectionVerb(VerbContainer* container, DataModel* dataModel, std::string name);
    virtual ~DeleteSelectionVerb();
private:
    char pad[0x24];
};
}
class ClipboardObject {};
class CutVerb : public RBX::DeleteSelectionVerb, public ClipboardObject {
public:
    CutVerb(RBX::DataModel* dataModel);
};
CutVerb::CutVerb(RBX::DataModel* dataModel)
    : DeleteSelectionVerb(dataModel ? &dataModel->verbs : 0, dataModel, "Cut")
{
}
