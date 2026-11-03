// from server: 100% by EspClaude
// roc 2007-08 004615c0  MFC view message handler: parent frame title from document name (std::string @+0xc8 of object @+0x134), then refresh
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
namespace std {
template<class E> class basic_string_stub {
public:
    __declspec(dllimport) const E* c_str() const;
    char pad[0x1c];
};
typedef basic_string_stub<char> string;
}
class CObject { public: virtual ~CObject(); };
class CCmdTarget : public CObject { public: char _c[0x1c]; };
class CFrameWnd;
class CWnd : public CCmdTarget { public: void* m_hWnd; CFrameWnd* GetParentFrame() const; void SetWindowText(const char*); };
class CFrameWnd : public CWnd {};
class CView : public CWnd {};
struct NamedThing { char pad[0xc8]; std::string name; };
class CEditorView : public CView {
public:
    char _v[0x134 - 0x24];
    NamedThing* thing;
    void refresh();
    LRESULT OnUpdateTitle(WPARAM, LPARAM);
};
LRESULT CEditorView::OnUpdateTitle(WPARAM, LPARAM)
{
    if (GetParentFrame()) {
        if (thing == 0)
            GetParentFrame()->SetWindowText("");
        else
            GetParentFrame()->SetWindowText(thing->name.c_str());
    }
    refresh();
    return 0;
}
