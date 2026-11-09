// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_unit_c054a2084880d614.cpp

// Candidate translation unit (score above; library headers required).
// Declaration excerpt from RBLXDecomp/RBXGSdecomp at
// 3c9c0c32ac5e7ba320767bfcd2bd3c54f86ef461, ThreadRef.h.
// Out-of-line copy/destructor are the already-exact 005944e0/00594470.
#define NDEBUG
#include <boost/shared_ptr.hpp>
#include <boost/mem_fn.hpp>

struct lua_State;
namespace boost { class mutex; }
namespace RBX { namespace Lua {
class ThreadRef {
public:
    class Node;
private:
    const boost::shared_ptr<boost::mutex> sync;
    Node* node;
    ThreadRef* previous;
    ThreadRef* next;
    lua_State* L;
    int threadId;
protected:
    virtual void removeRef();
public:
    ThreadRef(const ThreadRef&);
    ~ThreadRef();
};
class FunctionRef : public ThreadRef {
public:
    int functionId;
    FunctionRef(const FunctionRef&);
    ~FunctionRef();
    FunctionRef& operator=(const FunctionRef&);
    bool operator==(const FunctionRef&) const;
    bool operator!=(const FunctionRef&) const;
protected:
    virtual void removeRef();
};
}}

// Target stores an eight-byte member-function pointer (entry + this adjustment).
class __multiple_inheritance DHTMLWindow;
typedef RBX::Lua::FunctionRef FunctionRef;
typedef boost::_mfi::mf1<void, DHTMLWindow, FunctionRef> Callback;
template void Callback::operator()<boost::shared_ptr<DHTMLWindow> >(
    boost::shared_ptr<DHTMLWindow> const&, FunctionRef) const;

#include <boost/bind.hpp>
#include <boost/function.hpp>
typedef boost::_bi::value<boost::shared_ptr<DHTMLWindow> > WindowValue;
typedef boost::_bi::value<FunctionRef> FunctionValue;
typedef boost::_bi::list2<WindowValue, FunctionValue> Arguments;
typedef boost::_bi::bind_t<void, Callback, Arguments> Bound;
// Full observed RTTI bind_t type: genuine list/storage constructors and manager.
template class boost::_bi::value<FunctionRef>;
template class boost::_bi::storage2<WindowValue, FunctionValue>;
template class boost::_bi::list2<WindowValue, FunctionValue>;
template class boost::_bi::bind_t<void, Callback, Arguments>;
void invoke_bound(Bound& bound) { bound(); }
void assign_bound(boost::function<void()>& function, Bound const& bound) { function = bound; }
