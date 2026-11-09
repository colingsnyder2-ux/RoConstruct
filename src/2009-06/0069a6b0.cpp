// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Value;
struct Target { void set(Value* const& v); };
struct Desc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Value* get(const void* obj) const;
    void copy(const void* obj, Target* t) const;
};
void Desc::copy(const void* obj, Target* t) const
{
    t->set(get(obj));
}
