// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Builder {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void quad(unsigned short a, unsigned short b, unsigned short c, unsigned short d);
    void quadMapped(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    char pad[0x144];
    unsigned short* map;
};
void Builder::quadMapped(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    quad(map[a], map[b], map[c], map[d]);
}
