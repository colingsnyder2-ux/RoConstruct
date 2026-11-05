// from server: 100% by king_originala
// from server: 99% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_binding_cref_c78f2ca586c22c48.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>
#include <boost/signals/connection.hpp>
namespace RBX {class Instance;namespace Reflection {class PropertyDescriptor;}}
typedef RBX::Reflection::PropertyDescriptor PropertyDescriptor;
class CLuaHtmlView {public:class Binder {public:void update();};};
typedef CLuaHtmlView::Binder NativeBindingView;
void __cdecl nativePropertyChanged(const PropertyDescriptor* property,const PropertyDescriptor& changed,NativeBindingView*view){if(property==&changed)view->update();}
typedef boost::slot<boost::function1<void,const PropertyDescriptor*> > NativePropertySlot;
typedef boost::_bi::bind_t<void,void (__cdecl*)(const PropertyDescriptor*,const PropertyDescriptor&,NativeBindingView*),boost::_bi::list3<boost::arg<1>,boost::reference_wrapper<const PropertyDescriptor>,boost::_bi::value<NativeBindingView*> > > NativePropertyCapture;
struct NativePropertySignal;
struct NativePropertyDescriptor {boost::signals::connection connect(NativePropertySignal*,const NativePropertySlot&,int);};
extern NativePropertyDescriptor nativePropertyDescriptor;
struct NativeBinding {
 boost::shared_ptr<RBX::Instance>owner;const PropertyDescriptor& property;
 boost::signals::scoped_connection connection;
 NativeBinding(boost::shared_ptr<RBX::Instance>,const PropertyDescriptor&,NativeBindingView*);
};
namespace boost {template<> template<> slot<function1<void,const PropertyDescriptor*> >::slot(NativePropertyCapture const&);}
NativeBinding::NativeBinding(boost::shared_ptr<RBX::Instance>value,const PropertyDescriptor& p,NativeBindingView*view):owner(value),property(p){
 NativePropertyCapture capture=boost::bind(&nativePropertyChanged,_1,boost::cref(p),view);
 NativePropertySlot callback(capture);
 connection=nativePropertyDescriptor.connect(value.get()?reinterpret_cast<NativePropertySignal*>(reinterpret_cast<char*>(value.get())+0x14):0,callback,10);
}
