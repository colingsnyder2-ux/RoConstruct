// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; }; struct Mid : virtual V { int get() const; }; struct Owner : Mid { void set(int); };
struct Functionality { bool a; bool b; int c; int d; };
Functionality makeFunctionality(int d);
struct Base {
    typedef int (Owner::*Get)() const; typedef void (Owner::*Set)(int);
    Base(const char* name, const char* category, Get get, Set set, Functionality f, int flag);
    ~Base(); char pad[0x40];
};
struct PropDescriptor : Base {
    template<class G, class S>
    __forceinline PropDescriptor(const char* name, const char* category, G get, S set, int flags) : Base(name, category, get, set, makeFunctionality(flags), 0) {}
};
static PropDescriptor desc("RotVelocity", "Data", &Mid::get, &Owner::set, 0x1f);
