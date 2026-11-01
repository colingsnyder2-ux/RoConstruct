// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
extern "C" void __cdecl free(void*);

struct S {
    void* field0;
    char field4;
    void f();
};

void S::f() {
    if (field4 != 0) {
        void* p = field0;
        CloseHandle(p);
        free(p);
    } else {
        DeleteCriticalSection(field0);
    }
}
