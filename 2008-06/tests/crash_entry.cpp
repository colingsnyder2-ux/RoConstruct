#include <windows.h>
static int write_crash(EXCEPTION_POINTERS* ep) {
    HANDLE h = CreateFileA("crash.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        char buf[128];
        int n = wsprintfA(buf, "code=%08lx addr=%p\n", (unsigned long)ep->ExceptionRecord->ExceptionCode, ep->ExceptionRecord->ExceptionAddress);
        DWORD w; WriteFile(h, buf, n, &w, NULL);
        CloseHandle(h);
    }
    return EXCEPTION_EXECUTE_HANDLER;
}
extern "C" void mainCRTStartup();
extern "C" void my_entry() {
    __try {
        mainCRTStartup();
    } __except (write_crash(GetExceptionInformation())) {
    }
}
int main() { return 0; }
