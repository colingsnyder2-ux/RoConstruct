// from server: 100% by king_originala
extern "C" unsigned long (__stdcall *GetCurrentThreadId)();

struct LogState {
    unsigned char storage[8];
    void apply();
};

LogState* __cdecl currentLogState();

struct MainLogManager {
    unsigned char storage[4];
    LogState state;
    unsigned long threadId;
    void apply();
};

void MainLogManager::apply()
{
    if (GetCurrentThreadId() == threadId)
        state.apply();
    else
        currentLogState()->apply();
}
