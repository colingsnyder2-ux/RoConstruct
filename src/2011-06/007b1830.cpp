// from server: 100% by atomic.potato
struct S_func_007ee430
{
	void f(void *);
};

struct S_func_007a1cf0
{
	char pad0[4];
	int m_x;
	void f(int);
};

struct CleanStage
{
	char pad0[8];
	S_func_007ee430 *m_stage;
	void f(void *);
};

void CleanStage::f(void *a1)
{
	m_stage->f(a1);
	((S_func_007a1cf0 *)a1)->f((int)this);
}
