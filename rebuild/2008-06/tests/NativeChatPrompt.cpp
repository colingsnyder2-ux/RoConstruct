#include "../native-classes/CChatPrompt.cpp"
#include <cstddef>
typedef char ChatSize[sizeof(CChatPrompt) == 0xa8 ? 1 : -1];
typedef char SelectionOffset[offsetof(CChatPrompt, hostWindow) == 0x88 ? 1 : -1];
typedef char ChatOffset[offsetof(CChatPrompt, chat) == 0x8c ? 1 : -1];
typedef char BrushOffset[offsetof(CChatPrompt, brush) == 0x94 ? 1 : -1];
typedef char ContextOffset[offsetof(CChatPrompt, context) == 0x9c ? 1 : -1];
typedef char ResultOffset[offsetof(CChatPrompt, players) == 0xa4 ? 1 : -1];
