// from server: 100% by EspClaude
// roc 2007-08 00592f00  RBX::TranslucentVerb::TranslucentVerb(DataModel*) : BoolPropertyVerb("TranslucentVerb", dataModel, "Transparent") (v8datamodel/StandardVerbs)
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class DataModel;
class BoolPropertyVerb {
public:
    BoolPropertyVerb(const std::string& name, DataModel* dataModel, const char* propertyName);
    virtual ~BoolPropertyVerb();
};
class TranslucentVerb : public BoolPropertyVerb {
public:
    TranslucentVerb(DataModel* dataModel);
};
TranslucentVerb::TranslucentVerb(DataModel* dataModel)
    : BoolPropertyVerb("TranslucentVerb", dataModel, "Transparent")
{
}
}
