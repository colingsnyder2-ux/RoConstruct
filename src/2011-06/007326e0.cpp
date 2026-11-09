// from server: 29% by atomic.potato
struct EventDesc
{
	int __cdecl f(int);
};

int __cdecl EventDesc::f(int value)
{
	if (value == 0)
		return 1;
	if (value == 1)
		return 0;
	if (value == 2)
		return 2;
	return 1;
}
