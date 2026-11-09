// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class __declspec(novtable) EdgeBase {
public:
    virtual ~EdgeBase()
    {
        b[0] = -1;
        b[1] = -1;
        a[0] = 3;
        a[1] = 3;
        m4 = 3;
    }
protected:
    int m4;
    int m8;
    int mc;
    int a[2];
    int b[2];
};
class __declspec(novtable) Edge : public EdgeBase {
public:
    virtual ~Edge();
    void setPrimitive(int i, int p);
};
Edge::~Edge()
{
    setPrimitive(0, 0);
    setPrimitive(1, 0);
}
