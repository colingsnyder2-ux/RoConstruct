// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7A8BEA(int, int, int, int, int);

struct ConstrainedValue
{
	int f(int);
};

int ConstrainedValue::f(int value)
{
	int result = sub_7A8BEA(value, 0, 0xB78E40, 0xBA7EA4, 0);
	return result ? 1 : 0;
}
