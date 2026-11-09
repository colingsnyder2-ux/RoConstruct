// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-render roc_manual_renderstats_83d111017938a6a8.cpp

// Candidate translation unit (score above; library headers required).
struct Base {
    Base();
    ~Base();
};

struct StatsItem : Base {
    char padding[0x174];
    StatsItem(char* stats);
    StatsItem* addTime(const char*, void*);
    StatsItem* addCount(const char*, void*);
    StatsItem* addGroup(const char*);
};

extern char vt0, vt10, vt14, vt20, vt24, vt44, vt64, vt84, vta4, vtc4;
extern int aggregateChunkCount, aggregatedChunkCount, chunkCount;

StatsItem::StatsItem(char* stats)
{
    *(void**)((char*)this + 0x00) = &vt0;
    *(void**)((char*)this + 0x10) = &vt10;
    *(void**)((char*)this + 0x14) = &vt14;
    *(void**)((char*)this + 0x20) = &vt20;
    *(void**)((char*)this + 0x24) = &vt24;
    *(void**)((char*)this + 0x44) = &vt44;
    *(void**)((char*)this + 0x64) = &vt64;
    *(void**)((char*)this + 0x84) = &vt84;
    *(void**)((char*)this + 0xa4) = &vta4;
    *(void**)((char*)this + 0xc4) = &vtc4;
    *(char**)((char*)this + 0x170) = stats;

    addTime("2D CPU Render", stats);
    StatsItem* cpu = addTime("3D CPU Total", stats + 0x108);
    cpu->addTime("CPU Shadow", stats + 0x160);
    cpu->addTime("computeProxyArrays", stats + 0x1b8);
    cpu->addTime("Sort", stats + 0xb0);
    cpu->addCount("Proxy count", stats + 0x220);
    cpu = cpu->addCount("Total Triangles", stats + 0x228);
    cpu->addCount("Ambient + Unshadowed", stats + 0x234);
    cpu->addCount("Mark Shadows", stats + 0x22c);
    cpu->addCount("Shadowed Light", stats + 0x230);
    addTime("SwapBuffer", stats + 0x58);

    *(StatsItem**)((char*)this + 0x158) = addGroup("Aggregation");
    (*(StatsItem**)((char*)this + 0x158))->addCount("Total Chunks", &chunkCount);
    (*(StatsItem**)((char*)this + 0x158))->addCount("Aggregated Chunks", &aggregatedChunkCount);
    (*(StatsItem**)((char*)this + 0x158))->addCount("AggregateChunks", &aggregateChunkCount);

    StatsItem* memory = addGroup("Memory");
    *(StatsItem**)((char*)this + 0x15c) = memory->addGroup("Tex");
    *(StatsItem**)((char*)this + 0x160) = memory->addGroup("VAR");
    *(StatsItem**)((char*)this + 0x164) = memory->addGroup("Video");

    StatsItem* changes = addGroup("State Changes");
    *(StatsItem**)((char*)this + 0x168) = changes->addGroup("Major");
    *(StatsItem**)((char*)this + 0x16c) = changes->addGroup("Minor");
}
