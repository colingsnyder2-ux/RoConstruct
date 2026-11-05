// from server: 77% by atomic.potato
struct CVideoStreamFilter
{
	void f(void *);
};

extern "C" int __stdcall sub_68c9a0(void *, void *);
extern "C" void __stdcall sub_a40a60(void *);
extern "C" void __stdcall sub_80b0ac(void *, void *);

void CVideoStreamFilter::f(void *arg)
{
	if (sub_68c9a0(*(void **)this, arg))
		return;

	char buf[12];
	sub_a40a60(buf);
	sub_80b0ac(buf, (void *)0xb93f78);
}
