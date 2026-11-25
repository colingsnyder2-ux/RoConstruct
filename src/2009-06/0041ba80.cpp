// from server: 100% by Xemicl
void* __cdecl operator new(unsigned int);
struct T { char pad[0x3bc]; T(); };
T* f() { return new T; }
