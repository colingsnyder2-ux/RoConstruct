// from server: 100% by king_originala
struct String {
    char storage[28];
    ~String();
};

extern void (__thiscall* string_destroy)(String*);

inline String::~String()
{
    string_destroy(this);
}

struct TextDisplay {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual String text();

    char padding[0x160];
    float first[4];
    float second[4];
    int value;

    void render(void*, const String&, const float*, const float*, int);
    void display(void*);
};

void TextDisplay::display(void* output)
{
    render(output, text(), first, second, value);
}
