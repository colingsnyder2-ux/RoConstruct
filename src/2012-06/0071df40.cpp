// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct L { char d[0x2c]; L(const L&); ~L(); };
struct L2 : L { }; struct F { void* f; L2 l; };
struct function0 {
    void* vtable;
    template<class Fn> void assign_to(Fn f);
    template<class Fn> function0(Fn f, int = 0) : vtable(0) { this->assign_to(f); }
};

inline void* operator new(unsigned int, void* p) { return p; }
function0* make(void* p, const F& f) { return new (p) function0(f); }
