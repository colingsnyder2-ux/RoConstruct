// from server: 100% by Xemicl
void* __cdecl operator new(unsigned int);
struct T { char pad[0x2b4]; T(); };
T* f() { return new T; }
