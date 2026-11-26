// from server: 100% by Xemicl
// roc 2012-06 00430c50  unit: CSelectionTreeCtrl  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00430c50
//
// 00430c50  6aff                 push -1
// 00430c52  68b3c8a900           push 0xa9c8b3
// 00430c57  64a100000000         mov eax, dword ptr fs:[0]
// 00430c5d  50                   push eax
// 00430c5e  64892500000000       mov dword ptr fs:[0], esp
// 00430c65  51                   push ecx
// 00430c66  56                   push esi
// 00430c67  8bf1                 mov esi, ecx
// 00430c69  89742404             mov dword ptr [esp + 4], esi
// 00430c6d  8b4614               mov eax, dword ptr [esi + 0x14]
// 00430c70  50                   push eax
// 00430c71  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00430c79  ff150c23b200         call dword ptr [0xb2230c]
// 00430c7f  8bce                 mov ecx, esi
// 00430c81  e8ba355400           call 0x974240
// 00430c86  8b4614               mov eax, dword ptr [esi + 0x14]
// 00430c89  85c0                 test eax, eax
// 00430c8b  740e                 je 0x430c9b
// 00430c8d  50                   push eax
// 00430c8e  ff15e821b200         call dword ptr [0xb221e8]
// 00430c94  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00430c9b  8bce                 mov ecx, esi
// 00430c9d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00430ca5  e8a6345400           call 0x974150
// 00430caa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00430cae  5e                   pop esi
// 00430caf  64890d00000000       mov dword ptr fs:[0], ecx
// 00430cb6  83c410               add esp, 0x10
// 00430cb9  c3                   ret 
// copied from an identical function in another client (function ??1EventWorker@RBX@@QAE@XZ)

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