#include "../native-classes/ChatEnter.cpp"
#include <cstddef>
typedef char GuiSize[sizeof(RBX::GuiItem) == 0x144 ? 1 : -1];
typedef char ChatSize[sizeof(ChatEnter) == 0x148 ? 1 : -1];
typedef char OwnerOffset[offsetof(ChatEnter, owner) == 0x144 ? 1 : -1];
