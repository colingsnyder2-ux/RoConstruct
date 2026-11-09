// from server: 100% by EspClaude
// roc 2007-08 0044c410  unit: CRobloxControlColorSelector
#include <vector>
extern "C" void __cdecl free(void*);
template<class T> class CStringStub {
public:
    __declspec(noinline) CStringStub(const CStringStub& s) throw() : m_pszData(s.m_pszData) {}
    __declspec(noinline) ~CStringStub() throw() { free(m_pszData); }
    __declspec(noinline) CStringStub& operator=(const CStringStub& s) throw() { m_pszData = s.m_pszData; return *this; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringStub<char>;
struct ColorItem {
    int a;
    int b;
    CStringStub<char> name;
};
template void std::vector<ColorItem>::_Tidy();
