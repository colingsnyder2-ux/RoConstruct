// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vec {
	double* first;
	double* last;
	double* front;
	int pad;
	int limit;
	int size() const { return last - first; }
	void grow(int n);
	void push(const double& d);
	void put(double x) { push(x); }
	struct Ctx { Vec* v; double* b; double* c; };
	void add(double d, Ctx& ctx);
};
void Vec::add(double d, Ctx& ctx)
{
	if (size() == limit) {
		double f = *front;
		double& b = *ctx.b;
		if (b < *ctx.c)
			ctx.v->grow(2 * ctx.v->size());
		else
			b -= f;
	}
	put(d);
}
