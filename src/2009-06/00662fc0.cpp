// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Surface;
namespace Reflection {
class Type { public: Type(const char* name, const char* tag, int x); virtual ~Type(); };
class CplxType : public Type {
public:
    CplxType(const char* name) : Type(name, "Complex", 0) {}
    virtual ~CplxType() {}
    template<class T> static const CplxType& singleton()
    {
        static CplxType type("Surface");
        return type;
    }
};
template const CplxType& CplxType::singleton<Surface>();
}}
