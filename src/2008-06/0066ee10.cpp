// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_cc48483f573f994a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals/connection.hpp>
namespace RBX {
class Name;
class INamed { public: virtual const Name& getName() const = 0; };
class HitTestFilter { public: virtual ~HitTestFilter(); };
namespace HUMAN {
class HumanoidState : public INamed, public HitTestFilter {
public:
    char hpad[0xa0 - 8];
    virtual ~HumanoidState();
};
}
template<class Base, const char* nameValue> class Named : public Base {
public:
    virtual const Name& getName() const;
};
struct JobData { int a, b; };
class SimJob : boost::noncopyable {
public:
    std::vector<int> items;
    virtual ~SimJob() {}
};
namespace HUMAN {
extern const char sMovingNoPhysicsBase[];
class Thing;
class MovingNoPhysicsBase : public Named<HumanoidState, sMovingNoPhysicsBase>, public SimJob {
public:
    int x, x2;
    boost::shared_ptr<Thing> thing;
    int y;
    boost::signals::scoped_connection connection;
    void release();
    virtual ~MovingNoPhysicsBase();
};
MovingNoPhysicsBase::~MovingNoPhysicsBase()
{
    if (thing.get())
        release();
}
}
}
