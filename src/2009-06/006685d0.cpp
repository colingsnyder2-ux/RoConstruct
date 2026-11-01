// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Y { public: void g(); };
class Part { public: Y* getY(); };
class Sel { public: void add(Part* p); };
class H {
public:
    Part* getHead();
    void f(Sel* sel);
};
void H::f(Sel* sel)
{
    Part* p = getHead();
    if (p) {
        if (Y* y = p->getY())
            y->g();
        sel->add(p);
    }
}
