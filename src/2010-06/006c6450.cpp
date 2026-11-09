// from server: 100% by atomic.potato
typedef int BOOL;

extern "C" BOOL __cdecl sub_7A8BEA(void*, void*, void*, void*, void*);

struct ForceField
{
	int f(void*);
};

int ForceField::f(void* a)
{
	BOOL result = sub_7A8BEA(a, 0, (void*)0xB78E40, (void*)0xBAACF4, 0);
	return result == 0;
}
