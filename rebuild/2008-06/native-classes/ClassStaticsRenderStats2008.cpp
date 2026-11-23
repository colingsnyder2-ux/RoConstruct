// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RenderStats static counters (inactive): chunkCount 0097288c (.bss, 0; AggregateChunk ctor/dtor
// inc/dec it) and the two aggregate counters declared beside it in native-headers/RenderLib/RenderStats.h.
// INFERRED: zero initial values (.bss); addresses of the two aggregate counters unknown.
#include "RenderLib/RenderStats.h"

int RenderStats::chunkCount = 0;
int RenderStats::aggregatedChunkCount = 0;
int RenderStats::aggregateChunkCount = 0;
