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
