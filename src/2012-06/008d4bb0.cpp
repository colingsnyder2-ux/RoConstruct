// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// The property value is a 4-byte class type passed by value (e.g. BrickColor);
// a class-type parameter blocks the tail call that an int parameter would get.
struct Desc { int x; };
extern Desc desc;
struct Value { int v; bool operator!=(const Value& o) const { return v != o.v; } };
struct S {
    char padding[0x18c];
    Value member;
    void raisePropertyChanged(const Desc&);
    void f(Value);
};
void S::f(Value value)
{
    if (member != value) {
        member = value;
        raisePropertyChanged(desc);
    }
}