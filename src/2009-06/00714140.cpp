// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct CS2009 { char d[0x18]; };
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CS2009*);
extern CS2009 g_cs2009;
class State2009 {
public:
	State2009() { reset(); }
	~State2009();
	void reset() throw();
	char d[0xb98];
};
static __forceinline State2009& state2009() { static State2009 s; return s; }
void cleanup2009();
void shutdown2009()
{
	state2009();
	cleanup2009();
	DeleteCriticalSection(&g_cs2009);
	state2009().reset();
}
