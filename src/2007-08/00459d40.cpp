// from server: 100% by EspClaude
// roc 2007-08 00459d40  (trial): implicit (compiler-generated) destructor,
// emitted out of line for the scalar deleting destructor (0x459da0).
// Member at +8 is a Table whose inline virtual dtor stores its vftable and
// calls the out-of-line clear helper (0x459700, as in 0x459bf0).
// The class's constructor is 0x459ce0 (vftable 0x79362c, slot 0 = 0x459da0).
struct Table {
    Table(int n);
    virtual ~Table() { deleteAll(); }
    void deleteAll();
};

struct Base {
    virtual ~Base() {}
};

struct Derived : public Base {
    int m_arg;
    Table m_table;
    Derived(int a);
};

Derived::Derived(int a) : m_arg(a), m_table(0xa00000)
{
}
