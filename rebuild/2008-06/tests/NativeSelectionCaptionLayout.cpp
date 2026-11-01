#include "CSelectionCaption.h"
C_ASSERT(sizeof(CXTCaption) == 0x190);
C_ASSERT(sizeof(CSelectionCaption) == 0x1c8);
C_ASSERT(offsetof(CSelectionCaption, dataModel) == 0x1b8);
C_ASSERT(offsetof(CSelectionCaption, selection) == 0x1c0);
