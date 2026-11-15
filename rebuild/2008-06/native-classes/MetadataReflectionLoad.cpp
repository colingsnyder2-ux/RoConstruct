// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/metadata-load /I{headers}/writer-2008 /I{headers}/std-noinline-string
#include "reflection/Metadata.h"
#include "v8xml/SerializerV2.h"
#include <fstream>
namespace RBX {
namespace Metadata {
void Reflection::load(std::string filename)
{
    if (filename.size() == 0) return;
    std::ifstream stream(filename.c_str(), std::ios::in | std::ios::binary);
    TextXmlParser parser(stream.rdbuf());
    std::auto_ptr<XmlElement> root(parser.parse());
    MergeBinder binder;
    readChildren(root.get(), binder);
    binder.resolveRefs();
    classes = findFirstChildOfType<RBX::Reflection::Metadata::Classes>();
    if (classes) {
        classes->addClass(RBX::Reflection::ClassDescriptor::rootDescriptor());
        classes->addClass(Instance::classDescriptor());
        classes->addClass(Reflection::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Classes::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Item::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Class::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Member::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Properties::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Functions::classDescriptor());
        classes->addClass(RBX::Reflection::Metadata::Events::classDescriptor());
    }
}
}}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MergeBinder::IDREFItem> >;
template class std::_Vector_val<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
