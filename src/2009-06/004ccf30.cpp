// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchange(long volatile*, long);
#pragma intrinsic(_InterlockedExchange)
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
void __cdecl operator delete(void*) throw();

struct Storage2009 {
	void** map;
	~Storage2009() { operator delete(map); }
};
struct Queue2009 {
	Storage2009 storage;
	char pad[0x1c];
	void clear();
	~Queue2009() { clear(); }
};
struct Mutex2009 {
	long active_count;
	void* event;
	~Mutex2009() {
		void* const old_event = (void*)_InterlockedExchange((long volatile*)&event, 0);
		if (old_event)
			CloseHandle(old_event);
	}
};
struct Owner2009 {
	Queue2009 queue;
	Mutex2009 mutex;
	~Owner2009();
};
Owner2009::~Owner2009() {}
