// from server: 61% by atomic.potato
extern "C" int *Function556BA0(int);

struct S
{
	int f(int);
};

int S::f(int value)
{
	int *result = (int *)Function556BA0(value + 4);
	return result[0];
}
