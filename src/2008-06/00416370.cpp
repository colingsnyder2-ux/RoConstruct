// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: atl-9.0-dll-rtm roc_espeon_varianttypeaccessor21691409a28158c7.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#include <new>
#include <typeinfo>
#include <string>
#include <vector>
#include <atlbase.h>
namespace boost {
class any { public: void* content; };
template<class T> T any_cast(const any& operand);
template<class T> class shared_ptr { public: T* px; void* pn; };
}
class StdString {
public:
    __declspec(dllimport) ~StdString();
    __declspec(dllimport) const char* c_str() const;
    char storage[0x20];
};
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
namespace Reflection {
class Type {
public:
    char pad[8];
    const std::type_info& type;
};
class Value {
public:
    const Type* type;
    boost::any value;
    const Type& getType() const { return *type; }
    template<class T> bool isType() const { return typeid(T) == getType().type; }
    bool isVoid() const { return isType<void>(); }
    bool isString() const;
    bool isContent() const;
    bool isInstances() const;
    template<class T> T cast() const { return boost::any_cast<T>(value); }
    StdString castString() const;
    StdString castContent() const;
};
}
}
SAFEARRAY* createSafeArray(const RBX::Instances* instances);
const RBX::Instances* getInstances(const boost::any* a);
class CopyVerb {
public:
    static void toVariant(const RBX::Reflection::Value& value, VARIANT* result);
};
void CopyVerb::toVariant(const RBX::Reflection::Value& value, VARIANT* result)
{
    if (value.isVoid()) {
        result->vt = VT_NULL;
        return;
    }
    if (value.isType<int>()) {
        CComVariant v(boost::any_cast<int>(value.value));
        v.Detach(result);
        return;
    }
    if (value.isType<bool>()) {
        CComVariant v(boost::any_cast<bool>(value.value));
        v.Detach(result);
        return;
    }
    if (value.isType<float>()) {
        CComVariant v(boost::any_cast<float>(value.value));
        v.Detach(result);
        return;
    }
    if (value.isType<double>()) {
        CComVariant v(boost::any_cast<double>(value.value));
        v.Detach(result);
        return;
    }
    if (value.isString()) {
        CComVariant v(value.castString().c_str());
        v.Detach(result);
        return;
    }
    if (value.isContent()) {
        CComVariant v(value.castContent().c_str());
        v.Detach(result);
        return;
    }
    if (value.isInstances()) {
        CComVariant v(createSafeArray(getInstances(&value.value)));
        v.Detach(result);
        return;
    }
    result->vt = VT_EMPTY;
}
