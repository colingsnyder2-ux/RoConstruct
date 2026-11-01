// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Big {
    double d;
    char rest[0x38];
    Big(const Big&);
    ~Big();
};
struct Entry {
    Big big;
    int b;
};
struct Node {
    int a;
    Entry entry;
};
class Factory {
public:
    void create(Node n, Node** out, int extra);
};
void Factory::create(Node n, Node** out, int extra)
{
    *out = new Node(n);
}
