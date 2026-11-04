#include "util/MarshaledListener.h"
#include <map>
#include <stdio.h>

namespace RBX {
std::map<DWORD, CMarshalWindow*> marshalWindows;
ATL::CCriticalSection marshalRegistryLock;
}

static LONG executed;
static LONG deleted;
static HANDLE ready;
static HANDLE proceed;

class ProbeEvent : public RBX::EventDataBase {
public:
    virtual void execute() { InterlockedIncrement(&executed); }
    virtual ~ProbeEvent() { InterlockedIncrement(&deleted); }
};

static void drain(RBX::CMarshalWindow* window)
{
    MSG message;
    while (PeekMessage(&message, window->m_hWnd, WM_USER + 101, WM_USER + 101, PM_REMOVE))
        DispatchMessage(&message);
}

static DWORD WINAPI worker(void*)
{
    RBX::CMarshalWindow* window = RBX::acquireMarshalWindow();
    if (!window->m_hWnd || window->threadId != GetCurrentThreadId()) return 10;
    if (RBX::acquireMarshalWindow() != window || window->references != 2) return 11;
    RBX::releaseMarshalWindow(window);
    window->post(new ProbeEvent);
    drain(window);
    SetEvent(ready);
    if (WaitForSingleObject(proceed, 5000) != WAIT_OBJECT_0) return 12;
    window->post(new ProbeEvent);
    HWND handle = window->m_hWnd;
    RBX::releaseMarshalWindow(window);
    return IsWindow(handle) ? 13 : 0;
}

int main()
{
    ready = CreateEvent(NULL, TRUE, FALSE, NULL);
    proceed = CreateEvent(NULL, TRUE, FALSE, NULL);
    RBX::CMarshalWindow* window = RBX::acquireMarshalWindow();
    if (!window->m_hWnd || IsWindowVisible(window->m_hWnd)) return 1;
    if (RBX::acquireMarshalWindow() != window || window->references != 2) return 2;
    RBX::releaseMarshalWindow(window);
    HANDLE thread = CreateThread(NULL, 0, worker, NULL, 0, NULL);
    if (WaitForSingleObject(ready, 5000) != WAIT_OBJECT_0) return 3;
    {
        ATL::CCritSecLock lock(RBX::marshalRegistryLock);
        if (RBX::marshalWindows.size() != 2) return 4;
    }
    SetEvent(proceed);
    if (WaitForSingleObject(thread, 5000) != WAIT_OBJECT_0) return 5;
    DWORD result;
    GetExitCodeThread(thread, &result);
    if (result) return result;
    CloseHandle(thread);
    CloseHandle(ready);
    CloseHandle(proceed);
    window->post(new ProbeEvent);
    drain(window);
    window->post(new ProbeEvent);
    HWND handle = window->m_hWnd;
    RBX::releaseMarshalWindow(window);
    if (IsWindow(handle) || !RBX::marshalWindows.empty()) return 6;
    printf("executed=%ld deleted=%ld registry=%u\n", executed, deleted, RBX::marshalWindows.size());
    return executed == 2 && deleted == 4 ? 0 : 7;
}
