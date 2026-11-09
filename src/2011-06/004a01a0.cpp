// from server: 100% by atomic.potato
struct S
{
	int f(void *, void *, void *);
};

int S::f(void *value, void *, void *output)
{
	if (output == 0)
		return 0x80004003;

	*(int *)output = *(int *)((char *)value + 8);
	return 0;
}
