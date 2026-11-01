#include "CDataModelPropGrid.h"
C_ASSERT(sizeof(CXTPPropertyGrid) == 0x188);
C_ASSERT(sizeof(CPropGrid) == 0x238);
C_ASSERT(sizeof(CSelectionPropGrid) == 0x244);
C_ASSERT(sizeof(CDataModelPropGrid) == 0x248);
C_ASSERT(offsetof(CPropGrid, mutex) == 0x18c);
C_ASSERT(offsetof(CPropGrid, dataModel) == 0x198);
C_ASSERT(offsetof(CPropGrid, instances) == 0x19c);
C_ASSERT(offsetof(CPropGrid, propertyItems) == 0x1b4);
C_ASSERT(offsetof(CPropGrid, itemProperties) == 0x1d4);
C_ASSERT(offsetof(CPropGrid, posted) == 0x1f4);
C_ASSERT(offsetof(CPropGrid, dirty) == 0x1f5);
C_ASSERT(offsetof(CPropGrid, pendingItems) == 0x1f8);
C_ASSERT(offsetof(CPropGrid, names) == 0x218);
C_ASSERT(offsetof(CSelectionPropGrid, selection) == 0x23c);
