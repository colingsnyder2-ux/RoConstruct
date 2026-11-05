// from server: 80% by colin
struct Humanoid;
struct JointStage;

struct HumanoidState
{
    char pad[8];
    void* stateMachine;
};

struct GettingUp
{
    char pad[8];
    void* stateMachine;
    void onStepImpl(Humanoid* humanoid);
};

extern bool g_assertEnabled;
extern bool (__fastcall *g_assertHandler)(const char*, const char*, unsigned int);
extern void __cdecl assertFail(unsigned char, const char*);

bool __fastcall edgeHasPrimitivesHere(GettingUp* self, void* unused, Humanoid* humanoid, int edge);

void GettingUp::onStepImpl(Humanoid* humanoid)
{
    if (g_assertEnabled)
    {
        if (!edgeHasPrimitivesHere(this, 0, humanoid, *(int*)((char*)humanoid + 0xc)))
        {
            if (!edgeHasPrimitivesHere(this, 0, humanoid, *(int*)((char*)humanoid + 0x10)))
            {
                if (g_assertHandler)
                {
                    if (g_assertHandler("edgeHasPrimitivesHere(e)", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\JointStage.cpp", 0x27))
                        goto done;
                }
                assertFail(g_assertEnabled, "edgeHasPrimitivesHere(e) file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\v8world\\JointStage.cpp line: 39");
            }
        }
    }
done:
    void** vtbl = *(void***)stateMachine;
    ((void (__thiscall*)(void*, Humanoid*))vtbl[3])(stateMachine, humanoid);
}
