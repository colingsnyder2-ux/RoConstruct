// from server: 100% by tester
extern "C" __declspec(dllimport) void free(void* ptr);

void f(void* a, void* b) {
    free(b);
}
