// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_bind_factory_pairs_b0adafe46fc3a2a5.cpp

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

#include <string>
namespace RBX { class Instance; namespace Reflection { class PropertyDescriptor; } }
typedef boost::_mfi::mf0<void, DHTMLWindow> CloseCallback;
typedef boost::_bi::list1<WindowValue> CloseArguments;
typedef boost::_bi::bind_t<void, CloseCallback, CloseArguments> CloseBound;
template class boost::_mfi::mf0<void, DHTMLWindow>;
template class boost::_bi::list1<WindowValue>;
template class boost::_bi::bind_t<void, CloseCallback, CloseArguments>;
void assign_close(boost::function<void()>& f, CloseBound const& b) { f = b; }

typedef boost::_mfi::mf1<void, DHTMLWindow, std::string> StringCallback;
typedef boost::_bi::value<std::string> StringValue;
typedef boost::_bi::list2<WindowValue, StringValue> StringArguments;
typedef boost::_bi::bind_t<void, StringCallback, StringArguments> StringBound;
template void StringCallback::operator()<boost::shared_ptr<DHTMLWindow> >(boost::shared_ptr<DHTMLWindow> const&, std::string) const;
template class boost::_bi::storage2<WindowValue, StringValue>;
template class boost::_bi::list2<WindowValue, StringValue>;
template class boost::_bi::bind_t<void, StringCallback, StringArguments>;
void assign_string(boost::function<void()>& f, StringBound const& b) { f = b; }

typedef boost::_mfi::mf2<void, DHTMLWindow, int, int> ResizeCallback;
typedef boost::_bi::value<int> IntValue;
typedef boost::_bi::list3<WindowValue, IntValue, IntValue> ResizeArguments;
typedef boost::_bi::bind_t<void, ResizeCallback, ResizeArguments> ResizeBound;
template class boost::_mfi::mf2<void, DHTMLWindow, int, int>;
template class boost::_bi::list3<WindowValue, IntValue, IntValue>;
template class boost::_bi::bind_t<void, ResizeCallback, ResizeArguments>;
void assign_resize(boost::function<void()>& f, ResizeBound const& b) { f = b; }

typedef boost::shared_ptr<RBX::Instance> InstancePtr;
typedef RBX::Reflection::PropertyDescriptor const& PropertyRef;
typedef boost::_mfi::mf3<void, DHTMLWindow, InstancePtr, PropertyRef, std::string> PropertyCallback;
typedef boost::_bi::list4<WindowValue, boost::_bi::value<InstancePtr>, boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const>, StringValue> PropertyArguments;
typedef boost::_bi::bind_t<void, PropertyCallback, PropertyArguments> PropertyBound;
template class boost::_mfi::mf3<void, DHTMLWindow, InstancePtr, PropertyRef, std::string>;
template class boost::_bi::list4<WindowValue, boost::_bi::value<InstancePtr>, boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const>, StringValue>;
template class boost::_bi::bind_t<void, PropertyCallback, PropertyArguments>;
void assign_property(boost::function<void()>& f, PropertyBound const& b) { f = b; }

#include <boost/weak_ptr.hpp>
typedef boost::shared_ptr<DHTMLWindow> FactoryOwner;
typedef boost::weak_ptr<RBX::Instance> FactoryWeak;
typedef boost::reference_wrapper<RBX::Reflection::PropertyDescriptor const> FactoryProperty;


typedef void (DHTMLWindow::*PairFactory180Method)(InstancePtr, int);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, int >::type PairFactory180Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, int >, PairFactory180Args> PairFactory180Bound;
template PairFactory180Bound boost::bind<void, DHTMLWindow, InstancePtr, int, FactoryOwner, InstancePtr, int >(PairFactory180Method, FactoryOwner, InstancePtr, int);

typedef void (DHTMLWindow::*PairFactory181Method)(InstancePtr, int);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, int >::type PairFactory181Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, int >, PairFactory181Args> PairFactory181Bound;
template PairFactory181Bound boost::bind<void, DHTMLWindow, InstancePtr, int, DHTMLWindow*, InstancePtr, int >(PairFactory181Method, DHTMLWindow*, InstancePtr, int);

typedef void (*PairFactory182Method)(InstancePtr, int);
typedef boost::_bi::list_av_2<InstancePtr, int >::type PairFactory182Args;
typedef boost::_bi::bind_t<void, PairFactory182Method, PairFactory182Args> PairFactory182Bound;
template PairFactory182Bound boost::bind<void, InstancePtr, int, InstancePtr, int >(PairFactory182Method, InstancePtr, int);

typedef void (DHTMLWindow::*PairFactory183Method)(InstancePtr, bool);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, bool >::type PairFactory183Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, bool >, PairFactory183Args> PairFactory183Bound;
template PairFactory183Bound boost::bind<void, DHTMLWindow, InstancePtr, bool, FactoryOwner, InstancePtr, bool >(PairFactory183Method, FactoryOwner, InstancePtr, bool);

typedef void (DHTMLWindow::*PairFactory184Method)(InstancePtr, bool);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, bool >::type PairFactory184Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, bool >, PairFactory184Args> PairFactory184Bound;
template PairFactory184Bound boost::bind<void, DHTMLWindow, InstancePtr, bool, DHTMLWindow*, InstancePtr, bool >(PairFactory184Method, DHTMLWindow*, InstancePtr, bool);

typedef void (*PairFactory185Method)(InstancePtr, bool);
typedef boost::_bi::list_av_2<InstancePtr, bool >::type PairFactory185Args;
typedef boost::_bi::bind_t<void, PairFactory185Method, PairFactory185Args> PairFactory185Bound;
template PairFactory185Bound boost::bind<void, InstancePtr, bool, InstancePtr, bool >(PairFactory185Method, InstancePtr, bool);

typedef void (DHTMLWindow::*PairFactory186Method)(InstancePtr, float);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, float >::type PairFactory186Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, float >, PairFactory186Args> PairFactory186Bound;
template PairFactory186Bound boost::bind<void, DHTMLWindow, InstancePtr, float, FactoryOwner, InstancePtr, float >(PairFactory186Method, FactoryOwner, InstancePtr, float);

typedef void (DHTMLWindow::*PairFactory187Method)(InstancePtr, float);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, float >::type PairFactory187Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, float >, PairFactory187Args> PairFactory187Bound;
template PairFactory187Bound boost::bind<void, DHTMLWindow, InstancePtr, float, DHTMLWindow*, InstancePtr, float >(PairFactory187Method, DHTMLWindow*, InstancePtr, float);

typedef void (*PairFactory188Method)(InstancePtr, float);
typedef boost::_bi::list_av_2<InstancePtr, float >::type PairFactory188Args;
typedef boost::_bi::bind_t<void, PairFactory188Method, PairFactory188Args> PairFactory188Bound;
template PairFactory188Bound boost::bind<void, InstancePtr, float, InstancePtr, float >(PairFactory188Method, InstancePtr, float);

typedef void (DHTMLWindow::*PairFactory189Method)(InstancePtr, double);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, double >::type PairFactory189Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, double >, PairFactory189Args> PairFactory189Bound;
template PairFactory189Bound boost::bind<void, DHTMLWindow, InstancePtr, double, FactoryOwner, InstancePtr, double >(PairFactory189Method, FactoryOwner, InstancePtr, double);

typedef void (DHTMLWindow::*PairFactory190Method)(InstancePtr, double);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, double >::type PairFactory190Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, double >, PairFactory190Args> PairFactory190Bound;
template PairFactory190Bound boost::bind<void, DHTMLWindow, InstancePtr, double, DHTMLWindow*, InstancePtr, double >(PairFactory190Method, DHTMLWindow*, InstancePtr, double);

typedef void (*PairFactory191Method)(InstancePtr, double);
typedef boost::_bi::list_av_2<InstancePtr, double >::type PairFactory191Args;
typedef boost::_bi::bind_t<void, PairFactory191Method, PairFactory191Args> PairFactory191Bound;
template PairFactory191Bound boost::bind<void, InstancePtr, double, InstancePtr, double >(PairFactory191Method, InstancePtr, double);
