// from server: 100% by EspClaude
// roc 2007-08 00439700  virtual getter: ContentId(getText()) built from an MFC CString (getText @0x438e50, ContentId(const char*) @0x438690)
// roc-flags: /O2 /GS /EHsc /MD
namespace ATL {
template<typename T, bool B> class CSimpleStringT {
public:
    __declspec(dllimport) operator const T*() const;
    T* m_pszData;
};
template<typename T, class Traits> class CStringT : public CSimpleStringT<T, true> {
public:
    __declspec(dllimport) ~CStringT() throw();
};
}
template<typename T> class StrTraitMFC_DLL {};
typedef ATL::CStringT<char, StrTraitMFC_DLL<char> > CString;
namespace RBX {
class ContentId {
    char str[0x1c];
    int id;
public:
    ContentId(const char* s);
    ~ContentId();
};
class CToolItem {
public:
    CString getText() const;
    virtual ContentId getContentId() const;
};
ContentId CToolItem::getContentId() const
{
    return ContentId(getText());
}
}
