// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Info {
	int a;
	float lo;
	float hi;
	Info(int a, float lo, float hi) : a(a), lo(lo), hi(hi) {}
};
class Holder {
	char pad[0x114];
	Info* items[6];
public:
	Info get(int i) const;
};
Info Holder::get(int i) const
{
	const Info* p = items[i];
	if (!p) {
		static Info def(0, -0.5f, 0.5f);
		p = &def;
	}
	return *p;
}
