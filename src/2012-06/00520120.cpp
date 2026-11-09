// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

#include <typeinfo>

class DescribedBase;

class Type
{
public:
    virtual ~Type();
protected:
    Type(const char* name, const type_info& type, const char* tag);
    char pad[0x18];
};

class RefType : public Type
{
public:
    RefType(const char* name, const type_info& type)
        : Type(name, type, 0)
    {
    }
    virtual ~RefType() {}
};

const RefType& objectTypeSingleton()
{
    static RefType type("Object", typeid(DescribedBase*));
    return type;
}
