// from server: 94% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C3 { int a, b, c; C3() : a(0), b(0), c(0) {} ~C3(); };
struct Block {
    int v0; C3 m1; int v10; C3 m2; int v20; C3 m3;
    Block(int a);
    void init(int a);
};
Block::Block(int a) { init(a); }