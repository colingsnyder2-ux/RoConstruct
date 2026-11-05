// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance;
class ServiceProvider {
public:
    virtual ~ServiceProvider();
    void onDescendentAdded(Instance* i);
    char pad[0xf8 - 4];
};
class IDataState {
public:
    virtual void setDirty(bool dirty) = 0;
};
class DataModel : public ServiceProvider, public IDataState {
public:
    void onDescendentAdded(Instance* i);
};
void DataModel::onDescendentAdded(Instance* i)
{
    ServiceProvider::onDescendentAdded(i);
    setDirty(true);
}
}
