// from server: 96% by atomic.potato
struct S
{
	bool __cdecl f(int);
};

extern "C" void* __cdecl GetObject(int);

bool S::f(int value)
{
	return *((unsigned char*)GetObject(value) + 0x180) == 0;
}
