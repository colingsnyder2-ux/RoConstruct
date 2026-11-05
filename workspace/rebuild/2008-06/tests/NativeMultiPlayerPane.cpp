#include "../native-classes/CMultiPlayerPane.cpp"
#include <cstddef>
typedef char PaneSize[sizeof(CMultiPlayerPane) == 0x58 ? 1 : -1];
typedef char ChildOffset[offsetof(CMultiPlayerPane, chatPrompt) == 0x54 ? 1 : -1];
