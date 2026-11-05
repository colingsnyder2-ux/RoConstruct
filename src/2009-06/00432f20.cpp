// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <map>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	long use_count_;
	long weak_count_;
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct WeakCount {
	sp_counted_base* pi_;
	~WeakCount() { if (pi_ != 0) pi_->weak_release(); }
};
struct WeakRef {
	void* px;
	WeakCount pn;
};
template<class T> class Countable {
	static long count;
public:
	~Countable() { InterlockedDecrement(&count); }
};
struct Entry : public Countable<Entry> {
	WeakRef w;
};
template class std::map<void*, Entry>;
