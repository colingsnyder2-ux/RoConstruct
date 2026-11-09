// from server: 100% by colin
// 00422030 endDrag v1: __try/__finally with inline-called funclet.
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct ModuleState {
    char padding[0x9c];
    void* context;
};

extern "C" ModuleState* __stdcall getState(int* state);
extern "C" unsigned long __stdcall activateContext(void* context);
extern "C" void __stdcall deactivateContext(int flag, int state);
extern "C" void __stdcall reportMissingProcedure();

struct CSettingsExplorer {
    char padding[0x68];
    void* procedure;
    void** getProcedure(void** result);
    void endDrag();
};

void CSettingsExplorer::endDrag() {
    int state = 0;
    unsigned long cookie = activateContext(getState(&state)->context);
    if (cookie) {
        __try {
            void* result;
            getProcedure(&result);
            void (__stdcall *function)() =
                reinterpret_cast<void (__stdcall *)()>(procedure);
            int valid = function != 0;
            if (!valid)
                reportMissingProcedure();
            function();
        }
        __finally {
            if (cookie != 2)
                deactivateContext(0, state);
        }
    }
}
