// from server: 100% by Xemicl
// roc 2012-06 0054fab0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0054fab0
//
// 0054fab0  6aff                 push -1
// 0054fab2  681890ad00           push 0xad9018
// 0054fab7  64a100000000         mov eax, dword ptr fs:[0]
// 0054fabd  50                   push eax
// 0054fabe  64892500000000       mov dword ptr fs:[0], esp
// 0054fac5  51                   push ecx
// 0054fac6  56                   push esi
// 0054fac7  8bf1                 mov esi, ecx
// 0054fac9  89742404             mov dword ptr [esp + 4], esi
// 0054facd  33c0                 xor eax, eax
// 0054facf  8d4e24               lea ecx, [esi + 0x24]
// 0054fad2  8701                 xchg dword ptr [ecx], eax
// 0054fad4  85c0                 test eax, eax
// 0054fad6  7407                 je 0x54fadf
// 0054fad8  50                   push eax
// 0054fad9  ff15e821b200         call dword ptr [0xb221e8]
// 0054fadf  8bce                 mov ecx, esi
// 0054fae1  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0054fae9  e852bcffff           call 0x54b740
// 0054faee  8b16                 mov edx, dword ptr [esi]
// 0054faf0  52                   push edx
// 0054faf1  e81e264300           call 0x982114
// 0054faf6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054fafa  83c404               add esp, 4
// 0054fafd  5e                   pop esi
// 0054fafe  64890d00000000       mov dword ptr fs:[0], ecx
// 0054fb05  83c410               add esp, 0x10
// 0054fb08  c3                   ret 
// copied from an identical function in another client (function ??1Owner2009@@QAE@XZ)

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