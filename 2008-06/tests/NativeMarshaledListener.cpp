#include "util/MarshaledListener.h"
namespace RBX { class Selection; class SelectionChanged; }
template RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged>::MarshaledListener();
template RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged>::~MarshaledListener();
typedef RBX::MarshaledListener<RBX::Selection, RBX::SelectionChanged> SelectionListener;
typedef RBX::FilteredListener<RBX::Selection, RBX::SelectionChanged> FilteredSelectionListener;
C_ASSERT(sizeof(RBX::EventDataBase) == 0xc);
C_ASSERT(sizeof(SelectionListener) == 0x24);
C_ASSERT(sizeof(FilteredSelectionListener) == 0x24);
C_ASSERT(offsetof(SelectionListener, pending) == 4);
C_ASSERT(offsetof(SelectionListener, threadId) == 0x1c);
C_ASSERT(offsetof(SelectionListener, window) == 0x20);
