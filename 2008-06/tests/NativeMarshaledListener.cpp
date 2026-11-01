#include "util/MarshaledListener.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/SelectionChanged.h"
template class RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged>;
template class RBX::FilteredListener<RBX::Selection, RBX::SelectionChanged>;
template class RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged>::EventData;

typedef RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged> SelectionListener;
typedef RBX::FilteredListener<RBX::Selection, RBX::SelectionChanged> FilteredSelectionListener;
C_ASSERT(sizeof(RBX::EventDataBase) == 4);
C_ASSERT(sizeof(SelectionListener) == 0x24);
C_ASSERT(sizeof(FilteredSelectionListener) == 0x24);
C_ASSERT(offsetof(SelectionListener, pending) == 4);
C_ASSERT(offsetof(SelectionListener, threadId) == 0x1c);
C_ASSERT(offsetof(SelectionListener, window) == 0x20);

typedef SelectionListener::EventData SelectionEventData;
C_ASSERT(sizeof(SelectionEventData) == 0x20);
C_ASSERT(offsetof(SelectionEventData, source) == 4);
C_ASSERT(offsetof(SelectionEventData, listener) == 0xc);
C_ASSERT(offsetof(SelectionEventData, event) == 0x10);
