// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
template<class C> typename C::iterator adl_begin(C& c) { return c.begin(); }
template<class C> typename C::iterator adl_end(C& c) { return c.end(); }
template<class It> struct iterator_range {
	It m_Begin, m_End;
	template<class R> iterator_range(R& r) : m_Begin(adl_begin(r)), m_End(adl_end(r)) {}
};
iterator_range<std::string::const_iterator> make_range(std::string& s)
{
	(std::string)s;
	return iterator_range<std::string::const_iterator>(s);
}
