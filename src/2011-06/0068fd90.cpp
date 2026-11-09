// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_bind_factory_triples_2eee91631783cc1c.cpp

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


typedef void (DHTMLWindow::*TripleFactory228Method)(std::string, int, FunctionRef);
typedef boost::_bi::list_av_4<FactoryOwner, std::string, int, FunctionRef >::type TripleFactory228Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, int, FunctionRef >, TripleFactory228Args> TripleFactory228Bound;
template TripleFactory228Bound boost::bind<void, DHTMLWindow, std::string, int, FunctionRef, FactoryOwner, std::string, int, FunctionRef >(TripleFactory228Method, FactoryOwner, std::string, int, FunctionRef);

typedef void (DHTMLWindow::*TripleFactory229Method)(std::string, int, FunctionRef);
typedef boost::_bi::list_av_4<DHTMLWindow*, std::string, int, FunctionRef >::type TripleFactory229Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, int, FunctionRef >, TripleFactory229Args> TripleFactory229Bound;
template TripleFactory229Bound boost::bind<void, DHTMLWindow, std::string, int, FunctionRef, DHTMLWindow*, std::string, int, FunctionRef >(TripleFactory229Method, DHTMLWindow*, std::string, int, FunctionRef);

typedef void (*TripleFactory230Method)(std::string, int, FunctionRef);
typedef boost::_bi::list_av_3<std::string, int, FunctionRef >::type TripleFactory230Args;
typedef boost::_bi::bind_t<void, TripleFactory230Method, TripleFactory230Args> TripleFactory230Bound;
template TripleFactory230Bound boost::bind<void, std::string, int, FunctionRef, std::string, int, FunctionRef >(TripleFactory230Method, std::string, int, FunctionRef);

typedef void (DHTMLWindow::*TripleFactory231Method)(std::string, int, PropertyRef);
typedef boost::_bi::list_av_4<FactoryOwner, std::string, int, FactoryProperty >::type TripleFactory231Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, int, PropertyRef >, TripleFactory231Args> TripleFactory231Bound;
template TripleFactory231Bound boost::bind<void, DHTMLWindow, std::string, int, PropertyRef, FactoryOwner, std::string, int, FactoryProperty >(TripleFactory231Method, FactoryOwner, std::string, int, FactoryProperty);

typedef void (DHTMLWindow::*TripleFactory232Method)(std::string, int, PropertyRef);
typedef boost::_bi::list_av_4<DHTMLWindow*, std::string, int, FactoryProperty >::type TripleFactory232Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, int, PropertyRef >, TripleFactory232Args> TripleFactory232Bound;
template TripleFactory232Bound boost::bind<void, DHTMLWindow, std::string, int, PropertyRef, DHTMLWindow*, std::string, int, FactoryProperty >(TripleFactory232Method, DHTMLWindow*, std::string, int, FactoryProperty);

typedef void (*TripleFactory233Method)(std::string, int, PropertyRef);
typedef boost::_bi::list_av_3<std::string, int, FactoryProperty >::type TripleFactory233Args;
typedef boost::_bi::bind_t<void, TripleFactory233Method, TripleFactory233Args> TripleFactory233Bound;
template TripleFactory233Bound boost::bind<void, std::string, int, PropertyRef, std::string, int, FactoryProperty >(TripleFactory233Method, std::string, int, FactoryProperty);

typedef void (DHTMLWindow::*TripleFactory234Method)(std::string, bool, int);
typedef boost::_bi::list_av_4<FactoryOwner, std::string, bool, int >::type TripleFactory234Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, bool, int >, TripleFactory234Args> TripleFactory234Bound;
template TripleFactory234Bound boost::bind<void, DHTMLWindow, std::string, bool, int, FactoryOwner, std::string, bool, int >(TripleFactory234Method, FactoryOwner, std::string, bool, int);

typedef void (DHTMLWindow::*TripleFactory235Method)(std::string, bool, int);
typedef boost::_bi::list_av_4<DHTMLWindow*, std::string, bool, int >::type TripleFactory235Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, bool, int >, TripleFactory235Args> TripleFactory235Bound;
template TripleFactory235Bound boost::bind<void, DHTMLWindow, std::string, bool, int, DHTMLWindow*, std::string, bool, int >(TripleFactory235Method, DHTMLWindow*, std::string, bool, int);

typedef void (*TripleFactory236Method)(std::string, bool, int);
typedef boost::_bi::list_av_3<std::string, bool, int >::type TripleFactory236Args;
typedef boost::_bi::bind_t<void, TripleFactory236Method, TripleFactory236Args> TripleFactory236Bound;
template TripleFactory236Bound boost::bind<void, std::string, bool, int, std::string, bool, int >(TripleFactory236Method, std::string, bool, int);

typedef void (DHTMLWindow::*TripleFactory237Method)(std::string, bool, bool);
typedef boost::_bi::list_av_4<FactoryOwner, std::string, bool, bool >::type TripleFactory237Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, bool, bool >, TripleFactory237Args> TripleFactory237Bound;
template TripleFactory237Bound boost::bind<void, DHTMLWindow, std::string, bool, bool, FactoryOwner, std::string, bool, bool >(TripleFactory237Method, FactoryOwner, std::string, bool, bool);

typedef void (DHTMLWindow::*TripleFactory238Method)(std::string, bool, bool);
typedef boost::_bi::list_av_4<DHTMLWindow*, std::string, bool, bool >::type TripleFactory238Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf3<void, DHTMLWindow, std::string, bool, bool >, TripleFactory238Args> TripleFactory238Bound;
template TripleFactory238Bound boost::bind<void, DHTMLWindow, std::string, bool, bool, DHTMLWindow*, std::string, bool, bool >(TripleFactory238Method, DHTMLWindow*, std::string, bool, bool);

typedef void (*TripleFactory239Method)(std::string, bool, bool);
typedef boost::_bi::list_av_3<std::string, bool, bool >::type TripleFactory239Args;
typedef boost::_bi::bind_t<void, TripleFactory239Method, TripleFactory239Args> TripleFactory239Bound;
template TripleFactory239Bound boost::bind<void, std::string, bool, bool, std::string, bool, bool >(TripleFactory239Method, std::string, bool, bool);
