// from server: 77% by atomic.potato
extern "C" void __cdecl func_004545b0();

struct EngineStatsCommand
{
    int f();
    void* field0C;
};

int EngineStatsCommand::f()
{
    void* a = *(void**)((char*)field0C + 0xaa0);
    void* b = *(void**)((char*)a + 0x140);
    void* c = *(void**)((char*)b + 0xd0);
    func_004545b0();
    return (int)c;
}
