// from server: 100% by Xemicl
// roc 2012-06 0096f6a0  unit: W4_D3DFORMAT::?$EnumDesc  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096f6a0
//
// 0096f6a0  53                   push ebx
// 0096f6a1  bb01000000           mov ebx, 1
// 0096f6a6  841df87fe500         test byte ptr [0xe57ff8], bl
// 0096f6ac  751d                 jne 0x96f6cb
// 0096f6ae  091df87fe500         or dword ptr [0xe57ff8], ebx
// 0096f6b4  b96074e500           mov ecx, 0xe57460
// 0096f6b9  e892efffff           call 0x96e650
// 0096f6be  68c014b200           push 0xb214c0
// 0096f6c3  e82d3b0100           call 0x9831f5
// 0096f6c8  83c404               add esp, 4
// 0096f6cb  e8d0feffff           call 0x96f5a0
// 0096f6d0  684474e500           push 0xe57444
// 0096f6d5  ff15d821b200         call dword ptr [0xb221d8]
// 0096f6db  841df87fe500         test byte ptr [0xe57ff8], bl
// 0096f6e1  751d                 jne 0x96f700
// 0096f6e3  091df87fe500         or dword ptr [0xe57ff8], ebx
// 0096f6e9  b96074e500           mov ecx, 0xe57460
// 0096f6ee  e85defffff           call 0x96e650
// 0096f6f3  68c014b200           push 0xb214c0
// 0096f6f8  e8f83a0100           call 0x9831f5
// 0096f6fd  83c404               add esp, 4
// 0096f700  b96074e500           mov ecx, 0xe57460
// 0096f705  5b                   pop ebx
// 0096f706  e945efffff           jmp 0x96e650
// copied from an identical function in another client (function ?shutdown2009@@YAXXZ)

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