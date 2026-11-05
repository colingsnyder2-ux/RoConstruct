// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <list>
#include <algorithm>

struct CStr {
    char* m_pszData;
    __declspec(dllimport) CStr(const char* psz);
    __declspec(dllimport) ~CStr() throw();
};

class CBrowserListener {
public:
    void OnNavigate(const CStr& url);
};

class CHtmlView {
public:
    virtual void OnNavigateComplete2(const char* strURL);
    char m_data[0xf8];
};

class CBrowserView : public CHtmlView {
public:
    std::list<std::string> m_ignoredUrls;
    CBrowserListener* m_listener;

    virtual void OnNavigateComplete2(const char* strURL);
};

void CBrowserView::OnNavigateComplete2(const char* strURL)
{
    CHtmlView::OnNavigateComplete2(strURL);
    if (m_listener)
    {
        if (std::find(m_ignoredUrls.begin(), m_ignoredUrls.end(), std::string(strURL)) == m_ignoredUrls.end())
        {
            CStr url(strURL);
            m_listener->OnNavigate(url);
        }
    }
}
