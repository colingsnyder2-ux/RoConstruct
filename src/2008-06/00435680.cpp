// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_77c3482b090e9b2d.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
static inline const char* cstr(const std::string& x) { return static_cast<const ImpStr<char>&>(x).c_str(); }

struct Member { int prefix; std::string name; };
struct Item { char padding[0x130]; bool visible; bool restricted; bool special; };
struct Declaration;
struct Service { Item* lookup(Declaration*); };
struct Settings { char padding[0x130]; bool showRestricted; bool showSpecial; };
struct Name { int prefix; std::string text; const std::string& str() const { return text; } };
struct Declaration {
    int prefix;
    Name* name;
    int unused08;
    int category;
    int marked;
    int unused14;
    std::list<Member*> members;
};
boost::shared_ptr<Service> getService();
Settings* getSettings();
void visitMember(int* count, std::string* text, Member* const& member);
extern const char openingText[];
extern const char closingText[];

struct CDeclarationView {
    char padding[0xa8];
    bool showAll;
    int category;
    void update(Declaration*);
    void* insert(int, const char*, int, int, int, int, int, int, int);
    void configure(void*, int, int, int, int, int, int, Declaration*);
    void associate(void*, Item*);
};

void CDeclarationView::update(Declaration* declaration)
{
    if (!showAll && declaration->category != category)
        return;
    Item* item = getService()->lookup(declaration);
    if (item) {
        Settings* settings = getSettings();
        if (item->restricted && !settings->showRestricted)
            return;
        if (item->special && !settings->showSpecial)
            return;
        if (!item->visible)
            return;
    }
    std::string text(declaration->name->str());
    text += openingText;
    int count = 0;
    std::for_each(declaration->members.begin(), declaration->members.end(),
                  boost::bind(&visitMember, &count, &text, _1));
    text += closingText;
    int image = (declaration->marked != 0) + 4;
    void* entry = insert(0x23, cstr(text), image, image, 0, 0, 0, 0xffff0000, 0xffff0002);
    configure(entry, 4, 0, 0, 0, 0, 0, declaration);
    associate(entry, item);
}
