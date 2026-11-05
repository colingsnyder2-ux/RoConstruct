// from server: 100% by king_originala
struct S;

struct Context
{
    char storage[0x54];
    Context(S*);
    ~Context();
};

struct View;

struct ViewTable
{
    void* reserved[27];
    void (__thiscall *draw)(View*, Context*, int);
};

struct View
{
    ViewTable* table;
};

struct S
{
    char reserved[0x54];
    View view;

    void f();
};

void S::f()
{
    Context context(this);
    view.table->draw(&view, &context, 1);
}
