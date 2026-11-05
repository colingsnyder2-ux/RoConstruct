// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claudeA_valueitemb5d48fac1928085d.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <exception>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include "G3D/Vector3.h"
// 2008-06 0043ee40 (float), 0043fc00 / 004402d0 siblings: Studio property-grid item applies a
// value to every instance selected under its keys (same key/map walk as 0043e140), then takes
// the DataModel lock, records a waypoint named after the property and marks the data dirty.
namespace RBX {
class Instance;
template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
class Name { int dictionaryIndex; public: const std::string name; const char* c_str() const { return static_cast<const ImpStr<char>&>(name).c_str(); } };
namespace Reflection { class PropertyDescriptor { public: virtual ~PropertyDescriptor(); const Name& name; }; }
class IDataState { public: virtual void setDirty(bool); };
class DataModel { char prefix[0x1f0]; public: IDataState state; void setDirty(bool dirty) { state.setDirty(dirty); }
	class Lock {
		boost::shared_ptr<void> mutex;
		void* lock;
		void doLock(const DataModel* dataModel);
	public:
		Lock(const DataModel* dataModel) : lock(0) { doLock(dataModel); }
		~Lock();
	};
};
struct ChangeHistoryService { static void __cdecl requestWaypoint(const char* name, DataModel* dataModel); };
}

int __stdcall AfxMessageBox(const char* text, unsigned int type = 0, unsigned int helpId = 0);

struct KeyBase { int x; };
struct KeyDerived : KeyBase {};
typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;
typedef std::map<KeyBase*, Instances> InstanceMap;

struct OwnerPrefix {
    char pad[0x198];
    RBX::DataModel* dataModel;
    char pad19c[0x218 - 0x19c];
};
// claudeA 2026-10-26: find goes through a by-value KeyBase* wrapper of a map-owning base at +0x218
// (owner->findB(*it)): yields owner in ecx, add ecx,0x218 as base adjust, and the target's arg scheduling.
struct MapHolder {
    InstanceMap instances;
    InstanceMap::iterator findB(KeyBase* key) { return instances.find(key); }
};
struct Owner : OwnerPrefix, MapHolder {};

#define V(N) virtual void slot##N();
#define V10(N) V(N##0) V(N##1) V(N##2) V(N##3) V(N##4) V(N##5) V(N##6) V(N##7) V(N##8) V(N##9)
// Primary bases: 60 virtuals before apply() (float/string items, apply at vtable +0xf0) and
// 64 virtuals with 8 more bytes of data (enum item, apply at +0x100, keys at 0x118).
class GridItemBase { public: V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) char data[0x108]; };
class EnumGridItemBase { public: V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V(60) V(61) V(62) V(63) char data[0x110]; };
// Bases sized from the key-vector offsets in 0043f890 (keys 0x11c) and 0043ead0 (keys 0x124).
class IntGridItemBase { public: V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V(60) V(61) V(62) char data[0x114]; };
class BoolGridItemBase { public: V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V(60) V(61) V(62) char data[0x11c]; };
class GridItemSink { public: virtual void sink(); };
#undef V10
#undef V

template<class Base, class T>
class ValueItem : public Base, public GridItemSink {
public:
    std::vector<KeyDerived*> keys;
    Owner* owner;
    const RBX::Reflection::PropertyDescriptor* descriptor;
    virtual void apply(RBX::Instance* instance, const T& value);
    void setValue(const T& value);
};

template<class Base, class T>
void ValueItem<Base, T>::setValue(const T& value)
{
    try {
        Instances instances;
        InstanceMap::iterator mapEnd = owner->instances.end();
        std::vector<KeyDerived*>::const_iterator end = keys.end();
        for (std::vector<KeyDerived*>::const_iterator it = keys.begin(); it != end; ++it) {
            InstanceMap::iterator found = owner->findB(*it);
            if (found != mapEnd) {
                for (Instances::iterator j = found->second.begin(), jEnd = found->second.end(); j != jEnd; j++)
                    instances.push_back(*j);
            }
        }
        std::for_each(instances.begin(), instances.end(),
            boost::bind(&ValueItem::apply, this, boost::bind(&boost::shared_ptr<RBX::Instance>::get, _1), value));
        if (owner->dataModel) {
            RBX::DataModel::Lock lock(owner->dataModel);
            RBX::ChangeHistoryService::requestWaypoint(descriptor->name.c_str(), owner->dataModel);
            owner->dataModel->setDirty(true);
        }
    } catch (std::exception& e) {
        AfxMessageBox(e.what());
    }
}

// agE 2026-10-26: one unit for the 2008-06 ValueItem::setValue family; the target T is read from how the
// bound value is copied (float fld, 4-byte int mov, bool byte mov, 3-float x87 copy, string/ContentId ctor),
// the base from keys offset (0x110/0x118/0x11c/0x124). /fp:fast drops the 3-float temp copy (0043ff70).
namespace RBX { class ContentId { std::string id; const Name* mimeTypePtr; }; }
template class ValueItem<GridItemBase, float>;
template class ValueItem<GridItemBase, std::string>;
template class ValueItem<GridItemBase, RBX::ContentId>;
template class ValueItem<GridItemBase, G3D::Vector3>;
template class ValueItem<EnumGridItemBase, int>;
template class ValueItem<IntGridItemBase, int>;
template class ValueItem<BoolGridItemBase, bool>;
template class ValueItem<GridItemBase, int>;
template class ValueItem<IntGridItemBase, G3D::Vector3>;
