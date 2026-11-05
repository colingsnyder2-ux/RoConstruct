// from server: 100% by colin
struct DataModel;

struct EngineStatsCommand {
    char pad[0xc];
    DataModel* dataModel;
    void doIt(void* dataState);
};

struct Sub1 {
    char pad[0x188];
    void* field188;
};

struct Sub2 {
    char pad[0x27c];
    void* field27c;
};

struct Sub3 {
    char pad[0x30];
    void* field30;
};

extern "C" void __fastcall sub_5dff40(void* p);

void EngineStatsCommand::doIt(void* dataState)
{
    Sub1* a = *(Sub1**)((char*)dataModel + 0x188);
    Sub2* b = *(Sub2**)((char*)a + 0x27c);
    Sub3* c = *(Sub3**)((char*)b + 0x30);
    void* d = *(void**)c;
    sub_5dff40(d);
}
