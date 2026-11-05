// from server: 79% by atomic.potato
extern "C" void *__cdecl sub_76b4c0(void *);
extern "C" void sub_76a190(void *, void *);

struct EnumDesc
{
	void f(void *);
};

void EnumDesc::f(void *p)
{
	void *v = sub_76b4c0((char *)p + 4);
	void *q = *(void **)v;
	sub_76a190(this, &q);
}
