// from server: 61% by atomic.potato
extern "C" void __cdecl helper(int);

extern "C" int __cdecl imported_call(const char *, float);

struct S
{
	int f(const char *, float);
};

int S::f(const char *text, float value)
{
	helper(1);
	return imported_call(text, value);
}
