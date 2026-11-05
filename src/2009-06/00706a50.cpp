// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void*);
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void*, int);
namespace RBX {
class Function { public: void operator()() const; };
void setThreadName(const char* name);
class ThreadPriorityScope {
    int oldPriority;
    bool changed;
public:
    ThreadPriorityScope(int priority)
    {
        oldPriority = GetThreadPriority(GetCurrentThread());
        changed = SetThreadPriority(GetCurrentThread(), priority) == 1;
    }
    ~ThreadPriorityScope()
    {
        if (changed)
            SetThreadPriority(GetCurrentThread(), oldPriority);
    }
};
void threadProc(Function* f, std::string name, int priority)
{
    setThreadName(name.c_str());
    ThreadPriorityScope scope(priority);
    (*f)();
}
}
