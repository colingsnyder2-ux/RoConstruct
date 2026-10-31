// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
typedef long LONG;
typedef int BOOL;
struct _EXCEPTION_POINTERS;
typedef _EXCEPTION_POINTERS EXCEPTION_POINTERS;
typedef LONG (__stdcall *LPTOP_LEVEL_EXCEPTION_FILTER)(EXCEPTION_POINTERS*);
extern "C" __declspec(dllimport) LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER);
class CrashReporter {
public:
    void Start();
    LONG ProcessException(EXCEPTION_POINTERS* ExceptionInfo);
    static CrashReporter* singleton;
};
LONG __stdcall CrashExceptionFilter(EXCEPTION_POINTERS* ExceptionInfo);
BOOL PreventSetUnhandledExceptionFilter();
void CrashReporter::Start()
{
	SetUnhandledExceptionFilter(&CrashExceptionFilter);
	PreventSetUnhandledExceptionFilter();
}
