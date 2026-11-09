// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall WSACleanup();

struct S
{
	void f();
};

void S::f()
{
	extern int g;
	if (g)
	{
		if (g > 1)
			--g;
		else
		{
			WSACleanup();
			g = 0;
		}
	}
}
