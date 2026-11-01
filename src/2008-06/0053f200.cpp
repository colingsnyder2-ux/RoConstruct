// from server: 100% by king_originala
#pragma optimize("", off)

struct S_func_0071f210 {
    int m_x;
    int f();
};

struct Color {
    float r, g, b;
};

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool first();
    virtual bool second();
    virtual Color color();

    unsigned char padding[20];
    float value;
};

struct S {
    bool first;
    bool second;
    float value;
    Color color;

    S(S_func_0071f210* source);
};

S::S(S_func_0071f210* source)
    : first(reinterpret_cast<Source*>(source->f())->first()),
      second(reinterpret_cast<Source*>(source->f())->second()),
      value(reinterpret_cast<Source*>(source->f())->value),
      color(reinterpret_cast<Source*>(source->f())->color())
{
}
