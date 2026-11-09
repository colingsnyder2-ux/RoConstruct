// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct TypeBase {
    TypeBase(const char* name, const void* extra);
    ~TypeBase();
};

struct ProtectedStringType : TypeBase {
    ProtectedStringType() : TypeBase("ProtectedString", 0) {}
    virtual void describe() const;
};

const ProtectedStringType& protectedStringType()
{
    static ProtectedStringType type;
    return type;
}