// from server: 100% by EspClaude
// from server: 62% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct S;

struct Color3uint8 {
    unsigned char r, g, b, a;
};

struct VTable {
    void* slots[58];
    Color3uint8 (__thiscall *getColor)(S*);
};


struct Color3 {
    float r, g, b;
    Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {}
    Color3(const Color3uint8& c) : r(c.r / 255.0f), g(c.g / 255.0f), b(c.b / 255.0f) {}
};

struct Result {
    float data[4];
    Result(const Result&);
};

extern Result __cdecl makeResult(Color3);

struct S {
    VTable* vtable;
    Result convert();
};

Result S::convert()
{
    return makeResult(Color3(vtable->getColor(this)));
}
