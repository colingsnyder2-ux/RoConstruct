// from server: 100% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_828bb7342db945f1.cpp

// Candidate translation unit (score above; library headers required).
#include <malloc.h>
#include <stdlib.h>
#define alloca _malloca
extern void (*rakFree)(void*);
#define free rakFree
#include "BitStream.h"
#include "DataBlockEncryptor.h"
#define waitingForOrderedPacketWriteIndex exePadBS[0x300/sizeof(OrderingIndexType)], waitingForOrderedPacketWriteIndex
#define histogramBitsSent histogramBitsSent; char exePadA[0x48]
#define throughputCapCountdown throughputCapCountdown; char exePadB[0x800]
#define freeThreadedMemoryOnNextUpdate freeThreadedMemoryOnNextUpdate; char exePadC[0x10]
#include "ReliabilityLayer.h"
#undef waitingForOrderedPacketWriteIndex
#undef histogramBitsSent
#undef throughputCapCountdown
#undef freeThreadedMemoryOnNextUpdate
#include "ReliabilityLayer.cpp"
