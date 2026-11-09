// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <list>

extern char criticalSection;
extern char initializationFlag;
extern unsigned long tlsIndex;
extern int referenceCount;

extern "C" {
    extern void (__stdcall *EnterCriticalSection)(void*);
    extern void (__stdcall *LeaveCriticalSection)(void*);
    extern void* (__stdcall *TlsGetValue)(unsigned long);
    extern int (__stdcall *TlsSetValue)(unsigned long, void*);

    void __cdecl initialize(void (__cdecl *)(), void*);
    void __cdecl initializeImpl();
}

typedef void (__cdecl *thread_exit_handler)();

void cleanup()
{
    initialize(initializeImpl, &initializationFlag);
    EnterCriticalSection(&criticalSection);

    if (tlsIndex == ~0UL) {
        LeaveCriticalSection(&criticalSection);
        return;
    }

    std::list<thread_exit_handler>* exit_handlers =
        static_cast<std::list<thread_exit_handler>*>(TlsGetValue(tlsIndex));
    if (exit_handlers && TlsSetValue(tlsIndex, 0)) {
        --referenceCount;
        LeaveCriticalSection(&criticalSection);

        while (!exit_handlers->empty()) {
            if (thread_exit_handler handler = *exit_handlers->begin())
                handler();
            exit_handlers->pop_front();
        }

        delete exit_handlers;
        exit_handlers = 0;
    } else {
        LeaveCriticalSection(&criticalSection);
    }
}
