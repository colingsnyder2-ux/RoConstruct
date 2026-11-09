// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/RenderStats.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/RenderStats.h"

int RenderStats::chunkCount;
int RenderStats::aggregatedChunkCount;
int RenderStats::aggregateChunkCount;

// FUNCTION: WEBSERVICE 0x101f7040
RenderStats::RenderStats()
{
}
