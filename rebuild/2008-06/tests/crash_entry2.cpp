#include <windows.h>
static void write_crash(EXCEPTION_POINTERS* ep) {
    HANDLE h = CreateFileA("crash.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        char buf[128];
        int n = wsprintfA(buf, "code=%08lx addr=%p\n", (unsigned long)ep->ExceptionRecord->ExceptionCode, ep->ExceptionRecord->ExceptionAddress);
        DWORD w; WriteFile(h, buf, n, &w, NULL);
        CloseHandle(h);
    }
}
extern "C" void mainCRTStartup();
extern "C" void my_entry() {
    __try {
        *(int*)0 = 0;
    } __except (1) {
        write_crash(GetExceptionInformation());
    }
    mainCRTStartup();
}
int main() { return 0; }
