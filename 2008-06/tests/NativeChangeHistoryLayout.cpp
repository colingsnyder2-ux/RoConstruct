#include "../native-classes/ChangeHistoryLifetime.cpp"
#include <cstddef>

typedef char HistorySize[sizeof(RBX::ChangeHistoryService) == 0x1a4 ? 1 : -1];
typedef char HistoryRecordSize[sizeof(RBX::HistoryRecord) == 0x40 ? 1 : -1];
typedef char HistoryItemSize[sizeof(RBX::HistoryItem) == 0x38 ? 1 : -1];
typedef char HistoryRecordName[offsetof(RBX::HistoryRecord, name) == 0x24 ? 1 : -1];
typedef char HistoryContext[offsetof(RBX::ChangeHistoryService, context) == 0x130 ? 1 : -1];
typedef char HistoryCurrent[offsetof(RBX::ChangeHistoryService, current) == 0x134 ? 1 : -1];
typedef char HistoryList[offsetof(RBX::ChangeHistoryService, history) == 0x138 ? 1 : -1];
typedef char HistoryForward[offsetof(RBX::ChangeHistoryService, forward) == 0x154 ? 1 : -1];
typedef char HistoryBackward[offsetof(RBX::ChangeHistoryService, backward) == 0x15c ? 1 : -1];
typedef char HistoryPlaying[offsetof(RBX::ChangeHistoryService, playing) == 0x164 ? 1 : -1];
typedef char HistoryEnabled[offsetof(RBX::ChangeHistoryService, enabled) == 0x165 ? 1 : -1];
typedef char HistoryFirstConnection[offsetof(RBX::ChangeHistoryService, connectionAdded) == 0x168 ? 1 : -1];
typedef char HistoryLastConnection[offsetof(RBX::ChangeHistoryService, connectionChanged) == 0x190 ? 1 : -1];
