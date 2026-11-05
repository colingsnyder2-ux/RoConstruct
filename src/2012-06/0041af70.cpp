// from server: 53% by tester
// roc 2012-06 0041af70  unit: CopyVerb  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041af70

extern "C" unsigned long __stdcall FormatMessageA(
    unsigned long dwFlags, const void* lpSource, unsigned long dwMessageId,
    unsigned long dwLanguageId, char* lpBuffer, unsigned long nSize, void* Arguments);

extern "C" unsigned long __stdcall GetLastError();

struct String {
    void* rep;
    unsigned int size() const;
    const char* c_str() const;
    ~String();
};

extern "C" void __stdcall log_message(const char* fmt, ...);

struct CopyVerb {
    void __cdecl report(unsigned long hr);
};

void CopyVerb::report(unsigned long hr)
{
    char buffer[260];
    String msg;
    unsigned long ok = FormatMessageA(0x1000, 0, hr, 0, buffer, 0x100, 0);
    if (ok == 0) {
        if (GetLastError() > 0) {
            log_message("%s - HRESULT=0x%X", msg.c_str(), hr);
        } else {
            log_message("Error - HRESULT=0x%X", hr);
        }
    } else {
        if (GetLastError() > 0) {
            log_message("%s - %s", msg.c_str(), buffer);
        } else {
            log_message("Error - %s", buffer);
        }
    }
    msg.~String();
}
