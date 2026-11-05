// from server: 67% by king_originala
struct String;

extern void (__thiscall* copyString)(String*, const String&);
extern void (__thiscall* destroyString)(String*);

struct String {
    char* data;
    String(const String&);
    ~String() throw();
};

inline String::String(const String& other)
{
    copyString(this, other);
}

inline String::~String() throw()
{
    destroyString(this);
}

struct Color {
    unsigned long value;
};

struct Item {
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7();
    virtual void v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47();
    virtual void v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55();
    virtual void v56(), v57(), v58(), v59();
    virtual Color getColor();

    void setValue(String value);
    void apply(const Color& color);
    void changed(String value);
};

void Item::changed(String value)
{
    setValue(value);
    apply(getColor());
}
