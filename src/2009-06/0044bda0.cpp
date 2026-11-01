// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
class RefObj {
public:
    virtual ~RefObj();
    long refCount;
    void release();
};
class Manager {
public:
    ~Manager();
    int x;
};
extern RefObj* g_refObj;
extern Manager* g_manager;
void cleanupGlobals()
{
    if (g_refObj) {
        if (InterlockedDecrement(&g_refObj->refCount) == 0) {
            g_refObj->release();
            delete g_refObj;
        }
        g_refObj = 0;
    }
    if (g_manager) {
        delete g_manager;
        g_manager = 0;
    }
}
