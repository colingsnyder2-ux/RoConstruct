// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void* HANDLE; typedef int BOOL;
extern "C" __declspec(dllimport) HANDLE __stdcall CreateEventA(void*, BOOL, BOOL, const char*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
__declspec(noreturn) void throwLastError();
extern long eventCount;
class Event {
	HANDLE handle;
public:
	Event(BOOL manualReset, BOOL initialState);
};
Event::Event(BOOL manualReset, BOOL initialState) : handle(0)
{
	HANDLE h = CreateEventA(0, manualReset, initialState, 0);
	if (!h) throwLastError();
	handle = h;
	InterlockedIncrement(&eventCount);
}
