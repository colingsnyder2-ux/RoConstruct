// from server: 100% by EspClaude
// roc 2007-08 00592f80  RBX::CanCollideVerb::CanCollideVerb(DataModel*) : BoolPropertyVerb("CanCollideVerb", dataModel, "CanCollide") (v8datamodel/StandardVerbs)
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class DataModel;
class BoolPropertyVerb {
public:
    BoolPropertyVerb(const std::string& name, DataModel* dataModel, const char* propertyName);
    virtual ~BoolPropertyVerb();
};
class CanCollideVerb : public BoolPropertyVerb {
public:
    CanCollideVerb(DataModel* dataModel);
};
CanCollideVerb::CanCollideVerb(DataModel* dataModel)
    : BoolPropertyVerb("CanCollideVerb", dataModel, "CanCollide")
{
}
}
