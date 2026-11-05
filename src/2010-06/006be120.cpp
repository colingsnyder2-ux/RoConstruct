// from server: 100% by atomic.potato
extern "C" int sub_007A8BEA(void *, void *, void *, void *, void *);

struct Configuration
{
	int f(void *);
};

int Configuration::f(void *arg)
{
	int result = sub_007A8BEA(arg, 0, (void *)0xB78E40, (void *)0xBA7BC0, 0);
	return result == 0;
}
