// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Type;
class ClassDescriptor;
template<class T> struct ExeCounter { static int n; };
struct Value;
const Type& singletonValue();
ClassDescriptor& classDescriptor();
inline const Type& countedType() { ++ExeCounter<Value>::n; return singletonValue(); }
class PropertyDescriptor {
protected:
    PropertyDescriptor(ClassDescriptor& c, const Type& t, const char* name, const char* category, int flags);
public:
    virtual ~PropertyDescriptor();
    virtual void get();
    char pad[0x50];
};
class Desc : public PropertyDescriptor {
public:
    Desc(const char* name, const char* category)
        : PropertyDescriptor(classDescriptor(), countedType(), name, category, 0) {}
    virtual void get();
};
static Desc desc_p("Front", "Data");
