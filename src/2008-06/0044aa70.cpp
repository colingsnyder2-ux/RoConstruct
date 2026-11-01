// from server: 100% by king_originala
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern void (__thiscall* stringConstruct)(void*, const char*);
extern void (__thiscall* stringDestroy)(void*);

struct String {
    char storage[28];

    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

struct Source {
    virtual void slot0() = 0;
    virtual const char* text() = 0;
};

struct Product {
    virtual ~Product();
    char storage[36];

    Product(const String&);
};

struct Holder {
    Product* value;

    void replace(Product* p)
    {
        Product* old = value;
        value = p;
        if (old)
            delete old;
    }
};

extern Holder current;

void __cdecl update(Source* source)
{
    current.replace(new Product(String(source->text())));
}
