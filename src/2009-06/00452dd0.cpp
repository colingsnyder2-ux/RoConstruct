// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
class CRobloxDoc {
public:
    CRobloxDoc();
    virtual ~CRobloxDoc();
    char pad[0x70];
};
class CDoc : public CRobloxDoc {
public:
    CDoc();
    virtual ~CDoc();
    template<class T> struct scoped_ptr { T* p; scoped_ptr() : p(0) {} ~scoped_ptr(); };
    scoped_ptr<int> a;
    scoped_ptr<char> b;
    scoped_ptr<short> c;
    std::vector<int> v;
    int x, y;
};
CDoc::CDoc() : x(0), y(0) {}
