#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

// CRobloxReportView::setDataModel 00458700 lives in CRobloxReportView.cpp (this unit held a duplicate copy until
// batch 29); this unit keeps the template members below.

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>;
template class RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::vector<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
