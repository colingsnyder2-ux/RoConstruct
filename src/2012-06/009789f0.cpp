// from server: 100% by Xemicl
// roc 2012-06 009789f0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009789f0
//
// 009789f0  6aff                 push -1
// 009789f2  688bb4ad00           push 0xadb48b
// 009789f7  64a100000000         mov eax, dword ptr fs:[0]
// 009789fd  50                   push eax
// 009789fe  64892500000000       mov dword ptr fs:[0], esp
// 00978a05  51                   push ecx
// 00978a06  d9ee                 fldz 
// 00978a08  8b442414             mov eax, dword ptr [esp + 0x14]
// 00978a0c  56                   push esi
// 00978a0d  8bf1                 mov esi, ecx
// 00978a0f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00978a13  dd1e                 fstp qword ptr [esi]
// 00978a15  894608               mov dword ptr [esi + 8], eax
// 00978a18  894e0c               mov dword ptr [esi + 0xc], ecx
// 00978a1b  6880000000           push 0x80
// 00978a20  89742408             mov dword ptr [esp + 8], esi
// 00978a24  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00978a2b  e8ea960000           call 0x98211a
// 00978a30  8d9080000000         lea edx, [eax + 0x80]
// 00978a36  894610               mov dword ptr [esi + 0x10], eax
// 00978a39  895614               mov dword ptr [esi + 0x14], edx
// 00978a3c  89461c               mov dword ptr [esi + 0x1c], eax
// 00978a3f  894618               mov dword ptr [esi + 0x18], eax
// 00978a42  8d4628               lea eax, [esi + 0x28]
// 00978a45  50                   push eax
// 00978a46  c744241803000000     mov dword ptr [esp + 0x18], 3
// 00978a4e  e8fdccffff           call 0x975750
// 00978a53  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00978a57  83c408               add esp, 8
// 00978a5a  8bc6                 mov eax, esi
// 00978a5c  5e                   pop esi
// 00978a5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00978a64  83c410               add esp, 0x10
// 00978a67  c20800               ret 8
// copied from an identical function in another client (function ??0Queue@@QAE@HH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct E1 { E1() {} ~E1(); };
struct E2 { E2() {} ~E2(); };
struct E3 { E3() {} ~E3(); };
struct Lock;
Lock* initLock(Lock* l);
struct Lock {
	int cs[6];
	Lock() { initLock(this); }
	~Lock();
};
struct Buffer {
	char* begin;
	char* end;
	char* read;
	char* write;
	int count;
	Buffer() : count(0) { begin = new char[0x80]; end = begin + 0x80; read = write = begin; }
	~Buffer();
};
class Queue {
public:
	double time;
	int a;
	int b;
	Buffer buffer;
	E1 e1;
	E2 e2;
	E3 e3;
	Lock lock;
	Queue(int a, int b);
};
Queue::Queue(int a_, int b_) : time(0), a(a_), b(b_) {}