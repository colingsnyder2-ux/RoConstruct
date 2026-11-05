// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
namespace RBX {
class worker_thread {
public:
    ~worker_thread();
    void join();
private:
    char data[0x14];
};
class Event {
    void* handle;
public:
    Event();
    ~Event() { if (handle) { CloseHandle(handle); handle = 0; } }
    void set() { SetEvent(handle); }
};
class EventWorker {
public:
    worker_thread thread;
    Event event;
    ~EventWorker();
};
EventWorker::~EventWorker()
{
    event.set();
    thread.join();
}
}
