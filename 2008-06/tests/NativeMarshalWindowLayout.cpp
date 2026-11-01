#include "util/MarshalWindow.h"
#include "util/EventDataBase.h"
C_ASSERT(sizeof(RBX::CMarshalWindow) == 0x44);
C_ASSERT(offsetof(RBX::CMarshalWindow, references) == 0x24);
C_ASSERT(offsetof(RBX::CMarshalWindow, threadId) == 0x28);
C_ASSERT(offsetof(RBX::CMarshalWindow, criticalSection) == 0x2c);
C_ASSERT(sizeof(RBX::EventDataBase) == 0xc);
C_ASSERT(offsetof(RBX::EventDataBase, source) == 4);
