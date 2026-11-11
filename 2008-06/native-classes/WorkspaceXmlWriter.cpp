// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/writer-2008
#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8xml/XmlSerializer.h"

HRESULT CWorkspace::write(XmlElement* element, std::ostream& stream)
{
    TextXmlWriterWithEmbeddedContent writer(dataModel ? RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get()) : 0, stream);
    writer.serialize(element);
    return S_OK;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::ContentId> >;
template class std::_Tree<std::_Tset_traits<RBX::ContentId,std::less<RBX::ContentId>,std::allocator<RBX::ContentId>,0> >;
template class std::allocator<RBX::ContentId>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::ContentId,std::less<RBX::ContentId>,std::allocator<RBX::ContentId>,0> >::_Node *>;
