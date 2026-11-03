// from server: 100% by EspClaude
// roc 2007-08 00593c10  RBX::AnchorVerb::AnchorVerb(DataModel*) : BoolPropertyVerb("AnchorVerb", dataModel, "Anchored") (v8datamodel/StandardVerbs)
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class DataModel;
class BoolPropertyVerb {
public:
    BoolPropertyVerb(const std::string& name, DataModel* dataModel, const char* propertyName);
    virtual ~BoolPropertyVerb();
};
class AnchorVerb : public BoolPropertyVerb {
public:
    AnchorVerb(DataModel* dataModel);
};
AnchorVerb::AnchorVerb(DataModel* dataModel)
    : BoolPropertyVerb("AnchorVerb", dataModel, "Anchored")
{
}
}
