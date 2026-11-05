// from server: 100% by king_originala
// from server: 96% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_binder_list_af0894f4303eeb8b.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>
namespace RBX {class Instance;namespace Reflection {class PropertyDescriptor;}}
typedef RBX::Reflection::PropertyDescriptor PropertyDescriptor;
struct NativeBinding;
class CLuaHtmlView {public:class Binder {
public:
 char prefix[12];
 std::list<boost::shared_ptr<NativeBinding> > bindings;
 void update();
 void applyBindings();
 void bind(boost::shared_ptr<RBX::Instance>,const PropertyDescriptor&);
};};
struct NativeBinding {
 boost::shared_ptr<RBX::Instance>owner;
 const PropertyDescriptor& property;
 boost::signals::scoped_connection connection;
 NativeBinding(boost::shared_ptr<RBX::Instance>,const PropertyDescriptor&,CLuaHtmlView::Binder*);
};
void CLuaHtmlView::Binder::bind(boost::shared_ptr<RBX::Instance>instance,const PropertyDescriptor&property){
 NativeBinding*added=new NativeBinding(instance,property,this);
 bindings.push_back(boost::shared_ptr<NativeBinding>(added));
 applyBindings();
}
