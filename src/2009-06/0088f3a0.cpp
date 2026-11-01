// from server: 100% by EspClaude
// roc 2009-06 0088f3a0
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
class Owner : public virtual ExeVBase {
public:
    int getstyle() const;
    void setstyle(int);
};
extern const char* category_Appearance;
namespace Reflection {
template<class C, class V>
class PropDescriptor {
public:
    template<class Getter, class Setter>
    PropDescriptor(const char* name, const char* category, Getter getter, Setter setter, int f);
    ~PropDescriptor();
private:
    char data[0x50];
};
}
static Reflection::PropDescriptor<Owner, int> desc_style("style", category_Appearance, &Owner::getstyle, &Owner::setstyle, 6);
}
