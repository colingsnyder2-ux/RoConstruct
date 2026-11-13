// Pending-proposal safety check (compiled only against the generated PropertyGridItems.h copy in
// out/propgrid/pending): the proposed XItem::OnValueChanged body `applyValue(readValue());` must keep the
// already-exact float/int instantiations 004413e0/00441460 byte-identical.
#include "PropertyGridItems.h"

template void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::OnValueChanged(CString);
template void XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::OnValueChanged(CString);
