// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Reflection {
class Value { public: Value& operator=(const double& v); };
class GetSet {
public:
    virtual void a();
    virtual void b();
    virtual double get(const void* obj) const;
};
class Desc {
    char pad[0x18];
    GetSet* getset;
public:
    void getValue(const void* obj, Value& value) const;
};
void Desc::getValue(const void* obj, Value& value) const
{
    value = getset->get(obj);
}
}}
