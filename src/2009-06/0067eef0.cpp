// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <algorithm>
struct Hook { Hook* next; };
struct A { virtual void f(); int pad[11]; };
struct T : A, Hook {};
struct It {
	Hook* n;
	T* operator*() const { return static_cast<T*>(n); }
	It& operator++() { n = n->next; return *this; }
	bool operator!=(const It& o) const { return n != o.n; }
};
typedef void (*Fn)(T*);
template Fn std::for_each<It, Fn>(It, It, Fn);
