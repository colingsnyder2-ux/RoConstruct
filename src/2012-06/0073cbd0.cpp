// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { int p[3]; Base(const Base&); ~Base(); };
struct M { int q[3]; M(const M&); };
struct NonFactoryProduct : Base {
    M m;
    int x; char y;
    NonFactoryProduct(const NonFactoryProduct& o);
};
NonFactoryProduct::NonFactoryProduct(const NonFactoryProduct& o) : Base(o), m(o.m) { x = o.x; y = o.y; }