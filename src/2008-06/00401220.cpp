// from server: 100% by king_originala
struct Primary
{
    virtual void f();
    char padding[0x70];
};

struct Secondary
{
    virtual void f();
    char padding[0x94];
    unsigned style;
};

struct Base : Primary, Secondary
{
    Base(int, int, void*);
    ~Base();
    void setStyle(unsigned);
};

struct CInsertObjectDialog : Base
{
    CInsertObjectDialog(void*);
    virtual void f();
};

CInsertObjectDialog::CInsertObjectDialog(void* arg)
    : Base(0x75, 0x76, arg)
{
    setStyle(style | 0x01844007);
}
