// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_bind_factory_triples_3ef9d3fdf85fc7a5.cpp

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


typedef void (DHTMLWindow::*TripleFactory636Method)(PropertyRef, PropertyRef, std::string);
typedef boost::_bi::list_av_4<FactoryOwner, FactoryProperty, FactoryProperty, std::string >::type TripleFactory636Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, std::string >, TripleFactory636Args> TripleFactory636Bound;
template TripleFactory636Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, std::string, FactoryOwner, FactoryProperty, FactoryProperty, std::string >(TripleFactory636Method, FactoryOwner, FactoryProperty, FactoryProperty, std::string);

typedef void (DHTMLWindow::*TripleFactory637Method)(PropertyRef, PropertyRef, std::string);
typedef boost::_bi::list_av_4<DHTMLWindow*, FactoryProperty, FactoryProperty, std::string >::type TripleFactory637Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, std::string >, TripleFactory637Args> TripleFactory637Bound;
template TripleFactory637Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, std::string, DHTMLWindow*, FactoryProperty, FactoryProperty, std::string >(TripleFactory637Method, DHTMLWindow*, FactoryProperty, FactoryProperty, std::string);

typedef void (*TripleFactory638Method)(PropertyRef, PropertyRef, std::string);
typedef boost::_bi::list_av_3<FactoryProperty, FactoryProperty, std::string >::type TripleFactory638Args;
typedef boost::_bi::bind_t<void, TripleFactory638Method, TripleFactory638Args> TripleFactory638Bound;
template TripleFactory638Bound boost::bind<void, PropertyRef, PropertyRef, std::string, FactoryProperty, FactoryProperty, std::string >(TripleFactory638Method, FactoryProperty, FactoryProperty, std::string);

typedef void (DHTMLWindow::*TripleFactory639Method)(PropertyRef, PropertyRef, InstancePtr);
typedef boost::_bi::list_av_4<FactoryOwner, FactoryProperty, FactoryProperty, InstancePtr >::type TripleFactory639Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, InstancePtr >, TripleFactory639Args> TripleFactory639Bound;
template TripleFactory639Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, InstancePtr, FactoryOwner, FactoryProperty, FactoryProperty, InstancePtr >(TripleFactory639Method, FactoryOwner, FactoryProperty, FactoryProperty, InstancePtr);

typedef void (DHTMLWindow::*TripleFactory640Method)(PropertyRef, PropertyRef, InstancePtr);
typedef boost::_bi::list_av_4<DHTMLWindow*, FactoryProperty, FactoryProperty, InstancePtr >::type TripleFactory640Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, InstancePtr >, TripleFactory640Args> TripleFactory640Bound;
template TripleFactory640Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, InstancePtr, DHTMLWindow*, FactoryProperty, FactoryProperty, InstancePtr >(TripleFactory640Method, DHTMLWindow*, FactoryProperty, FactoryProperty, InstancePtr);

typedef void (*TripleFactory641Method)(PropertyRef, PropertyRef, InstancePtr);
typedef boost::_bi::list_av_3<FactoryProperty, FactoryProperty, InstancePtr >::type TripleFactory641Args;
typedef boost::_bi::bind_t<void, TripleFactory641Method, TripleFactory641Args> TripleFactory641Bound;
template TripleFactory641Bound boost::bind<void, PropertyRef, PropertyRef, InstancePtr, FactoryProperty, FactoryProperty, InstancePtr >(TripleFactory641Method, FactoryProperty, FactoryProperty, InstancePtr);

typedef void (DHTMLWindow::*TripleFactory642Method)(PropertyRef, PropertyRef, FunctionRef);
typedef boost::_bi::list_av_4<FactoryOwner, FactoryProperty, FactoryProperty, FunctionRef >::type TripleFactory642Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, FunctionRef >, TripleFactory642Args> TripleFactory642Bound;
template TripleFactory642Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, FunctionRef, FactoryOwner, FactoryProperty, FactoryProperty, FunctionRef >(TripleFactory642Method, FactoryOwner, FactoryProperty, FactoryProperty, FunctionRef);

typedef void (DHTMLWindow::*TripleFactory643Method)(PropertyRef, PropertyRef, FunctionRef);
typedef boost::_bi::list_av_4<DHTMLWindow*, FactoryProperty, FactoryProperty, FunctionRef >::type TripleFactory643Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, FunctionRef >, TripleFactory643Args> TripleFactory643Bound;
template TripleFactory643Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, FunctionRef, DHTMLWindow*, FactoryProperty, FactoryProperty, FunctionRef >(TripleFactory643Method, DHTMLWindow*, FactoryProperty, FactoryProperty, FunctionRef);

typedef void (*TripleFactory644Method)(PropertyRef, PropertyRef, FunctionRef);
typedef boost::_bi::list_av_3<FactoryProperty, FactoryProperty, FunctionRef >::type TripleFactory644Args;
typedef boost::_bi::bind_t<void, TripleFactory644Method, TripleFactory644Args> TripleFactory644Bound;
template TripleFactory644Bound boost::bind<void, PropertyRef, PropertyRef, FunctionRef, FactoryProperty, FactoryProperty, FunctionRef >(TripleFactory644Method, FactoryProperty, FactoryProperty, FunctionRef);

typedef void (DHTMLWindow::*TripleFactory645Method)(PropertyRef, PropertyRef, PropertyRef);
typedef boost::_bi::list_av_4<FactoryOwner, FactoryProperty, FactoryProperty, FactoryProperty >::type TripleFactory645Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, PropertyRef >, TripleFactory645Args> TripleFactory645Bound;
template TripleFactory645Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, PropertyRef, FactoryOwner, FactoryProperty, FactoryProperty, FactoryProperty >(TripleFactory645Method, FactoryOwner, FactoryProperty, FactoryProperty, FactoryProperty);

typedef void (DHTMLWindow::*TripleFactory646Method)(PropertyRef, PropertyRef, PropertyRef);
typedef boost::_bi::list_av_4<DHTMLWindow*, FactoryProperty, FactoryProperty, FactoryProperty >::type TripleFactory646Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, PropertyRef, PropertyRef, PropertyRef >, TripleFactory646Args> TripleFactory646Bound;
template TripleFactory646Bound boost::bind<void, DHTMLWindow, PropertyRef, PropertyRef, PropertyRef, DHTMLWindow*, FactoryProperty, FactoryProperty, FactoryProperty >(TripleFactory646Method, DHTMLWindow*, FactoryProperty, FactoryProperty, FactoryProperty);

typedef void (*TripleFactory647Method)(PropertyRef, PropertyRef, PropertyRef);
typedef boost::_bi::list_av_3<FactoryProperty, FactoryProperty, FactoryProperty >::type TripleFactory647Args;
typedef boost::_bi::bind_t<void, TripleFactory647Method, TripleFactory647Args> TripleFactory647Bound;
template TripleFactory647Bound boost::bind<void, PropertyRef, PropertyRef, PropertyRef, FactoryProperty, FactoryProperty, FactoryProperty >(TripleFactory647Method, FactoryProperty, FactoryProperty, FactoryProperty);
