// from server: 61% by Intel
typedef int (__stdcall *DebugHookFn)(int, const char*, const char*);

extern "C" {
    DebugHookFn g_debugHook;
    unsigned char g_debugFlag;
    int STATE_TABLE[25][25];
    int STATE_TABLE2[25];
}

int __cdecl HumanoidStateTransition(int eventType, int oldState)
{
    int result;

    if (!g_debugFlag)
        return oldState * 25 + eventType;

    if (eventType * 100 + 0xBF0EE4 != eventType) {
        if (g_debugHook) {
            if (g_debugHook(0x4B, "STATE_TABLE[0][eventType+1] == eventType", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\humanoid\\HumanoidState.cpp")) {
                return oldState * 25 + eventType;
            }
        }
        g_debugHook(g_debugFlag, "STATE_TABLE[0][eventType+1] == eventType file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\humanoid\\HumanoidState.cp", "t<9<");
    }

    if (!g_debugFlag)
        return oldState * 25 + eventType;

    if (oldState * 4 + 0xBF0E84 != oldState) {
        if (g_debugHook) {
            if (g_debugHook(0x4C, "STATE_TABLE[oldState+1][0] == oldState", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\humanoid\\HumanoidState.cpp")) {
                return oldState * 25 + eventType;
            }
        }
        g_debugHook(g_debugFlag, "STATE_TABLE[oldState+1][0] == oldState file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\humanoid\\HumanoidState.cpp ", "t<9<");
    }

    return oldState * 25 + eventType;
}
