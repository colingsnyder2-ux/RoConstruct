// from server: 100% by king_originala
extern char key1;
extern char key2;
extern char key3;
extern char key4;

struct S {
    void f(const void* key);
    void g();
    void h();
};

void S::f(const void* key)
{
    if (key == &key1)
        g();
    else if (key == &key2 || key == &key3 || key == &key4)
        h();
}
