// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x44];
    Instance* parent;
    Instance* getRoot();
};
inline Instance* Instance::getRoot()
{
    return parent ? parent->getRoot() : this;
}
class DataModel : public Instance {
public:
    static DataModel* get(Instance* context);
};
DataModel* DataModel::get(Instance* context)
{
    return dynamic_cast<DataModel*>(context->getRoot());
}
}
