// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" {
    extern int (__cdecl *sprintf)(char *, const char *, ...);
}

struct Text;
extern void (__thiscall *constructText)(Text *, const char *);

struct __declspec(dllimport) Text {
    void *data;
    Text(const char *);
    Text(const Text &);
    ~Text();
};

struct Vector3ComponentItem {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void setText(Text);

    char padding[0x12c];
    volatile int component;
    volatile float x;
    volatile float y;
    volatile float z;

    void setValue(const volatile float *);
};

void Vector3ComponentItem::setValue(const volatile float *value)
{
    char buffer[32];
    x = value[0];
    y = value[1];
    z = value[2];
    sprintf(buffer, "%.3g", value[component]);
    setText(Text(buffer));
}