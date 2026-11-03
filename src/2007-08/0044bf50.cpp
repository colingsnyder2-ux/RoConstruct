// from server: 100% by EspClaude
// roc 2007-08 0044bf50  unit: CRobloxControlColorSelector
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
    unsigned long color;
    int id;
    CStringStub<char> name;
};
extern std::vector<ColorItem> g_colors;
class CWndBase {
public:
    void Invalidate();
};
class CRobloxControlColorSelector : public CWndBase {
    char pad[0x16c];
    int m_index;
    bool m_hasColor;
    unsigned long m_color;
public:
    void Update();
};
void CRobloxControlColorSelector::Update()
{
    if (m_index != -1) {
        m_color = g_colors[m_index].color;
        m_hasColor = true;
    }
    Invalidate();
}
