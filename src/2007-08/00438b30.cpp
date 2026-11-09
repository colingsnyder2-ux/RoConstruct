// from server: 100% by EspClaude
// roc 2007-08 00438b30  VBrickColor XItem: BrickColor::closest(Color3 of the item's COLORREF)
#define LOBYTE(w) ((unsigned char)((unsigned long)(w) & 0xff))
#define GetRValue(rgb) (LOBYTE(rgb))
#define GetGValue(rgb) (LOBYTE(((unsigned short)(rgb)) >> 8))
#define GetBValue(rgb) (LOBYTE((rgb)>>16))

struct Color3 {
    float r, g, b;
    Color3() {}
    Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {}
    Color3(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {}
};

class BrickColor {
    int number;
public:
    BrickColor(int n);
    static BrickColor closest(Color3 c);
};

struct Item {
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7();
    virtual void v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47();
    virtual void v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55();
    virtual void v56();
    virtual void setColor(unsigned long value);
    virtual unsigned long getColor();
    BrickColor value();
};

BrickColor Item::value()
{
    unsigned long c = getColor();
    return BrickColor::closest(Color3(GetRValue(c) / 255.0f, GetGValue(c) / 255.0f, GetBValue(c) / 255.0f));
}
