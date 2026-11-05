#include "CDataModelPropGrid.h"
#include "v8tree/PropertyChanged.h"
C_ASSERT(sizeof(CXTPPropertyGrid) == 0x188);
C_ASSERT(sizeof(CPropGrid) == 0x238);
C_ASSERT(sizeof(CSelectionPropGrid) == 0x244);
C_ASSERT(sizeof(CDataModelPropGrid) == 0x248);
C_ASSERT(offsetof(CPropGrid, mutex) == 0x18c);
C_ASSERT(offsetof(CPropGrid, dataModel) == 0x198);
C_ASSERT(offsetof(CPropGrid, items) == 0x19c);
C_ASSERT(offsetof(CPropGrid, propertyItems) == 0x1b4);
C_ASSERT(offsetof(CPropGrid, itemProperties) == 0x1d4);
C_ASSERT(offsetof(CPropGrid, posted) == 0x1f4);
C_ASSERT(offsetof(CPropGrid, dirty) == 0x1f5);
C_ASSERT(offsetof(CPropGrid, pendingItems) == 0x1f8);
C_ASSERT(offsetof(CPropGrid, groups) == 0x218);
C_ASSERT(offsetof(CSelectionPropGrid, selection) == 0x23c);

C_ASSERT(sizeof(RBX::SelectionGroup) == 0x20);
C_ASSERT(sizeof(RBX::PropertyChanged) == 8);
C_ASSERT(sizeof(RBX::Reflection::Property) == 8);

C_ASSERT(sizeof(CPropGrid::Item) == 0x20);

C_ASSERT(offsetof(CPropGrid::Item, classes) == 4);
C_ASSERT(offsetof(CPropGrid::Item, grid) == 0x1c);
