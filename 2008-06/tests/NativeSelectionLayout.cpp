#include "../native-headers/v8datamodel/Selection.h"
#include <cstddef>
typedef char SelectionSize[sizeof(RBX::Selection) == 0x174 ? 1 : -1];
typedef char SelectionField[offsetof(RBX::Selection, selection) == 0x154 ? 1 : -1];
typedef char SelectionFilters[offsetof(RBX::Selection, filteredSelections) == 0x15c ? 1 : -1];
