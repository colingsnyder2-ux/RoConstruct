// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_bind_factory_matrix_88fcf2790ed4c606.cpp

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

typedef void (DHTMLWindow::*Factory12Method)(double);
typedef boost::_bi::list_av_2<FactoryOwner, double >::type Factory12Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, double >, Factory12Args> Factory12Bound;
template Factory12Bound boost::bind<void, DHTMLWindow, double, FactoryOwner, double >(Factory12Method, FactoryOwner, double);
typedef void (DHTMLWindow::*Factory13Method)(double);
typedef boost::_bi::list_av_2<DHTMLWindow*, double >::type Factory13Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, double >, Factory13Args> Factory13Bound;
template Factory13Bound boost::bind<void, DHTMLWindow, double, DHTMLWindow*, double >(Factory13Method, DHTMLWindow*, double);
typedef void (*Factory14Method)(double);
typedef boost::_bi::list_av_1<double >::type Factory14Args;
typedef boost::_bi::bind_t<void, Factory14Method, Factory14Args> Factory14Bound;
template Factory14Bound boost::bind<void, double, double >(Factory14Method, double);
typedef void (DHTMLWindow::*Factory15Method)(void*);
typedef boost::_bi::list_av_2<FactoryOwner, void* >::type Factory15Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, void* >, Factory15Args> Factory15Bound;
template Factory15Bound boost::bind<void, DHTMLWindow, void*, FactoryOwner, void* >(Factory15Method, FactoryOwner, void*);
typedef void (DHTMLWindow::*Factory16Method)(void*);
typedef boost::_bi::list_av_2<DHTMLWindow*, void* >::type Factory16Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, void* >, Factory16Args> Factory16Bound;
template Factory16Bound boost::bind<void, DHTMLWindow, void*, DHTMLWindow*, void* >(Factory16Method, DHTMLWindow*, void*);
typedef void (*Factory17Method)(void*);
typedef boost::_bi::list_av_1<void* >::type Factory17Args;
typedef boost::_bi::bind_t<void, Factory17Method, Factory17Args> Factory17Bound;
template Factory17Bound boost::bind<void, void*, void* >(Factory17Method, void*);
typedef void (DHTMLWindow::*Factory18Method)(std::string);
typedef boost::_bi::list_av_2<FactoryOwner, std::string >::type Factory18Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, std::string >, Factory18Args> Factory18Bound;
template Factory18Bound boost::bind<void, DHTMLWindow, std::string, FactoryOwner, std::string >(Factory18Method, FactoryOwner, std::string);
typedef void (DHTMLWindow::*Factory19Method)(std::string);
typedef boost::_bi::list_av_2<DHTMLWindow*, std::string >::type Factory19Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, std::string >, Factory19Args> Factory19Bound;
template Factory19Bound boost::bind<void, DHTMLWindow, std::string, DHTMLWindow*, std::string >(Factory19Method, DHTMLWindow*, std::string);
typedef void (*Factory20Method)(std::string);
typedef boost::_bi::list_av_1<std::string >::type Factory20Args;
typedef boost::_bi::bind_t<void, Factory20Method, Factory20Args> Factory20Bound;
template Factory20Bound boost::bind<void, std::string, std::string >(Factory20Method, std::string);
typedef void (DHTMLWindow::*Factory21Method)(InstancePtr);
typedef boost::_bi::list_av_2<FactoryOwner, InstancePtr >::type Factory21Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, InstancePtr >, Factory21Args> Factory21Bound;
template Factory21Bound boost::bind<void, DHTMLWindow, InstancePtr, FactoryOwner, InstancePtr >(Factory21Method, FactoryOwner, InstancePtr);
typedef void (DHTMLWindow::*Factory22Method)(InstancePtr);
typedef boost::_bi::list_av_2<DHTMLWindow*, InstancePtr >::type Factory22Args;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, DHTMLWindow, InstancePtr >, Factory22Args> Factory22Bound;
template Factory22Bound boost::bind<void, DHTMLWindow, InstancePtr, DHTMLWindow*, InstancePtr >(Factory22Method, DHTMLWindow*, InstancePtr);
typedef void (*Factory23Method)(InstancePtr);
typedef boost::_bi::list_av_1<InstancePtr >::type Factory23Args;
typedef boost::_bi::bind_t<void, Factory23Method, Factory23Args> Factory23Bound;
template Factory23Bound boost::bind<void, InstancePtr, InstancePtr >(Factory23Method, InstancePtr);
