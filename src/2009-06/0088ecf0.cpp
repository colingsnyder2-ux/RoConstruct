// from server: 100% by EspClaude
// roc 2009-06 0088ecf0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ExeVBase { virtual ~ExeVBase(); };
class Owner : public virtual ExeVBase {
public:
    int getDraggingV1() const;
    void setDraggingV1(int);
};
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
static Reflection::PropDescriptor<Owner, int> desc_DraggingV1("DraggingV1", "Behavior", &Owner::getDraggingV1, &Owner::setDraggingV1, 6);
}
