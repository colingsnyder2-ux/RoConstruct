// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_bound_changed_callsite_e4e40d6be974493c.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<boost/function.hpp>, <roc_espeon_boost135functionheader672dcef995494068.cpp>)
#pragma include_alias(<boost/function/function0.hpp>, <roc_espeon_boost135functionheader57405a50c9beea11.cpp>)
#pragma include_alias(<boost/function/function1.hpp>, <roc_espeon_boost135functionheader54de262102ae7bc4.cpp>)
#pragma include_alias(<boost/function/function10.hpp>, <roc_espeon_boost135functionheader25854fd9e87eca57.cpp>)
#pragma include_alias(<boost/function/function2.hpp>, <roc_espeon_boost135functionheaderab3c4a9a8a29aee5.cpp>)
#pragma include_alias(<boost/function/function3.hpp>, <roc_espeon_boost135functionheader1d11d6b5b76997d8.cpp>)
#pragma include_alias(<boost/function/function4.hpp>, <roc_espeon_boost135functionheaderb9d89fa9f73a18fe.cpp>)
#pragma include_alias(<boost/function/function5.hpp>, <roc_espeon_boost135functionheaderc126e05698a03109.cpp>)
#pragma include_alias(<boost/function/function6.hpp>, <roc_espeon_boost135functionheader051609ba2d0c0985.cpp>)
#pragma include_alias(<boost/function/function7.hpp>, <roc_espeon_boost135functionheadere4e8b3783b4f4a3b.cpp>)
#pragma include_alias(<boost/function/function8.hpp>, <roc_espeon_boost135functionheader69f3516c99152e9d.cpp>)
#pragma include_alias(<boost/function/function9.hpp>, <roc_espeon_boost135functionheader91b96edc0e30e1e0.cpp>)
#pragma include_alias(<boost/function/function_base.hpp>, <roc_espeon_boost135functionheadera464fc73794f4fe5.cpp>)
#pragma include_alias(<boost/function/function_template.hpp>, <roc_espeon_boost135functionheader95fb4a51a884f45f.cpp>)
#pragma include_alias(<boost/function/detail/function_iterate.hpp>, <roc_espeon_boost135functionheader40cdef22debfc2b9.cpp>)
#pragma include_alias(<boost/function/detail/maybe_include.hpp>, <roc_espeon_boost135functionheaderb080037d4ec60e6a.cpp>)
#pragma include_alias(<boost/function/detail/prologue.hpp>, <roc_espeon_boost135functionheader1f7a0a92d6d4d42d.cpp>)
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <new>
namespace RBX {
class Instance;
namespace Reflection {class PropertyDescriptor;}
namespace Network {
struct IdSerializerView {virtual ~IdSerializerView();};
struct PluginInterfaceView {virtual ~PluginInterfaceView();};
struct Replicator:IdSerializerView,PluginInterfaceView {
 void onPropertyChanged(boost::shared_ptr<Instance>,const Reflection::PropertyDescriptor*);
};
}
}
typedef boost::shared_ptr<RBX::Instance> InstancePtr;
typedef const RBX::Reflection::PropertyDescriptor* PropertyPtr;
typedef boost::_mfi::mf2<void,RBX::Network::Replicator,InstancePtr,PropertyPtr> Method;
typedef boost::_bi::list3<boost::_bi::value<RBX::Network::Replicator*>,boost::_bi::value<InstancePtr>,boost::arg<1> > Arguments;
typedef boost::_bi::bind_t<void,Method,Arguments> BoundChanged;
typedef boost::function<void(PropertyPtr)> Function;
typedef char functor_size[sizeof(BoundChanged)==24?1:-1];
typedef char shared_size[sizeof(InstancePtr)==8?1:-1];
void construct(Function* target, const BoundChanged& b) {new(target)Function(b);}
