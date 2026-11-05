// roc-cl: 21022
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_bind_factory_pairs_6be15c1ffba3b2c5.cpp

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


typedef void (DHTMLWindow::*PairFactory192Method)(InstancePtr, void*);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, void* >::type PairFactory192Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, void* >, PairFactory192Args> PairFactory192Bound;
template PairFactory192Bound boost::bind<void, DHTMLWindow, InstancePtr, void*, FactoryOwner, InstancePtr, void* >(PairFactory192Method, FactoryOwner, InstancePtr, void*);

typedef void (DHTMLWindow::*PairFactory193Method)(InstancePtr, void*);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, void* >::type PairFactory193Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, void* >, PairFactory193Args> PairFactory193Bound;
template PairFactory193Bound boost::bind<void, DHTMLWindow, InstancePtr, void*, DHTMLWindow*, InstancePtr, void* >(PairFactory193Method, DHTMLWindow*, InstancePtr, void*);

typedef void (*PairFactory194Method)(InstancePtr, void*);
typedef boost::_bi::list_av_2<InstancePtr, void* >::type PairFactory194Args;
typedef boost::_bi::bind_t<void, PairFactory194Method, PairFactory194Args> PairFactory194Bound;
template PairFactory194Bound boost::bind<void, InstancePtr, void*, InstancePtr, void* >(PairFactory194Method, InstancePtr, void*);

typedef void (DHTMLWindow::*PairFactory195Method)(InstancePtr, std::string);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, std::string >::type PairFactory195Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, std::string >, PairFactory195Args> PairFactory195Bound;
template PairFactory195Bound boost::bind<void, DHTMLWindow, InstancePtr, std::string, FactoryOwner, InstancePtr, std::string >(PairFactory195Method, FactoryOwner, InstancePtr, std::string);

typedef void (DHTMLWindow::*PairFactory196Method)(InstancePtr, std::string);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, std::string >::type PairFactory196Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, std::string >, PairFactory196Args> PairFactory196Bound;
template PairFactory196Bound boost::bind<void, DHTMLWindow, InstancePtr, std::string, DHTMLWindow*, InstancePtr, std::string >(PairFactory196Method, DHTMLWindow*, InstancePtr, std::string);

typedef void (*PairFactory197Method)(InstancePtr, std::string);
typedef boost::_bi::list_av_2<InstancePtr, std::string >::type PairFactory197Args;
typedef boost::_bi::bind_t<void, PairFactory197Method, PairFactory197Args> PairFactory197Bound;
template PairFactory197Bound boost::bind<void, InstancePtr, std::string, InstancePtr, std::string >(PairFactory197Method, InstancePtr, std::string);

typedef void (DHTMLWindow::*PairFactory198Method)(InstancePtr, InstancePtr);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, InstancePtr >::type PairFactory198Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, InstancePtr >, PairFactory198Args> PairFactory198Bound;
template PairFactory198Bound boost::bind<void, DHTMLWindow, InstancePtr, InstancePtr, FactoryOwner, InstancePtr, InstancePtr >(PairFactory198Method, FactoryOwner, InstancePtr, InstancePtr);

typedef void (DHTMLWindow::*PairFactory199Method)(InstancePtr, InstancePtr);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, InstancePtr >::type PairFactory199Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, InstancePtr >, PairFactory199Args> PairFactory199Bound;
template PairFactory199Bound boost::bind<void, DHTMLWindow, InstancePtr, InstancePtr, DHTMLWindow*, InstancePtr, InstancePtr >(PairFactory199Method, DHTMLWindow*, InstancePtr, InstancePtr);

typedef void (*PairFactory200Method)(InstancePtr, InstancePtr);
typedef boost::_bi::list_av_2<InstancePtr, InstancePtr >::type PairFactory200Args;
typedef boost::_bi::bind_t<void, PairFactory200Method, PairFactory200Args> PairFactory200Bound;
template PairFactory200Bound boost::bind<void, InstancePtr, InstancePtr, InstancePtr, InstancePtr >(PairFactory200Method, InstancePtr, InstancePtr);

typedef void (DHTMLWindow::*PairFactory201Method)(InstancePtr, FunctionRef);
typedef boost::_bi::list_av_3<FactoryOwner, InstancePtr, FunctionRef >::type PairFactory201Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, FunctionRef >, PairFactory201Args> PairFactory201Bound;
template PairFactory201Bound boost::bind<void, DHTMLWindow, InstancePtr, FunctionRef, FactoryOwner, InstancePtr, FunctionRef >(PairFactory201Method, FactoryOwner, InstancePtr, FunctionRef);

typedef void (DHTMLWindow::*PairFactory202Method)(InstancePtr, FunctionRef);
typedef boost::_bi::list_av_3<DHTMLWindow*, InstancePtr, FunctionRef >::type PairFactory202Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf2<void, DHTMLWindow, InstancePtr, FunctionRef >, PairFactory202Args> PairFactory202Bound;
template PairFactory202Bound boost::bind<void, DHTMLWindow, InstancePtr, FunctionRef, DHTMLWindow*, InstancePtr, FunctionRef >(PairFactory202Method, DHTMLWindow*, InstancePtr, FunctionRef);

typedef void (*PairFactory203Method)(InstancePtr, FunctionRef);
typedef boost::_bi::list_av_2<InstancePtr, FunctionRef >::type PairFactory203Args;
typedef boost::_bi::bind_t<void, PairFactory203Method, PairFactory203Args> PairFactory203Bound;
template PairFactory203Bound boost::bind<void, InstancePtr, FunctionRef, InstancePtr, FunctionRef >(PairFactory203Method, InstancePtr, FunctionRef);
