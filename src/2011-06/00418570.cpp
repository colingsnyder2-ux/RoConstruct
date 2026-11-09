// from server: 88% by atomic.potato
extern "C" int __cdecl call_5ba5e0();
extern "C" void call_40bc50(void*);

int global_cca450;

struct S
{
	int value;
	int f(void*);
};

int S::f(void* arg)
{
	++global_cca450;
	value = call_5ba5e0();
	call_40bc50(arg);
	return (int)this;
}
