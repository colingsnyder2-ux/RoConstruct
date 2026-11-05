// from server: 100% by king_originala_sol_resume_high
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_resume_high_ctor_callbacks_64792766c44c05d8.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/signals/slot.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
namespace RBX { class Instance; namespace Reflection { class PropertyDescriptor; } }
typedef boost::shared_ptr<RBX::Instance> Ancestor;
typedef boost::shared_ptr<void> Shared;
Shared __cdecl makeShared(void*);
extern const float initialValue;

struct Base {
    virtual void virtualFunction();
    unsigned char storage[212];
    Base(float, const Shared&, void*);
    ~Base();
};

typedef boost::signals::connection Result;
typedef boost::signals::scoped_connection Connection;
struct S : Base {
    Shared owner;
    Connection firstConnection;
    Connection secondConnection;

    S(void*, void*, void*);
    virtual void virtualFunction();
    void firstCallback(Ancestor);
    void secondCallback(const RBX::Reflection::PropertyDescriptor*);
};

typedef boost::slot<boost::function<void(Ancestor)> > AncestorSlot;
typedef boost::slot<boost::function<void(const RBX::Reflection::PropertyDescriptor*)> > PropertySlot;
struct ManagerA {
    Result connect(void*, const AncestorSlot&, int);
};

struct ManagerB {
    Result connect(void*, const PropertySlot&, int);
};

extern ManagerA managerA;
extern ManagerB managerB;

inline void assign(Connection& c, const Result& r) { c=r; }
S::S(void* object, void* baseObject, void* argument)
    : Base(initialValue, makeShared(baseObject), argument),
      owner(makeShared(object))
{
    firstConnection = managerA.connect(
            object ? static_cast<unsigned char*>(object) + 20 : 0,
            boost::bind(&S::firstCallback,this,_1), 10);
    secondConnection = managerB.connect(
            object ? static_cast<unsigned char*>(object) + 20 : 0,
            boost::bind(&S::secondCallback,this,_1), 10);
}
