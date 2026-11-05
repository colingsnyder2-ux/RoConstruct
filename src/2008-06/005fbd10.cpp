// from server: 100% by king_originala
extern unsigned char sourceType;
extern unsigned char targetType;

extern "C" void* __cdecl castObject(void*, long, void*, void*, int);

struct Parameter
{
    void* object;
    unsigned long storage[3];
    ~Parameter();
};

struct S
{
    void accept(void*);
    void f(unsigned long, Parameter);
};

void S::f(unsigned long, Parameter value)
{
    void* object = castObject(value.object, 0, &sourceType, &targetType, 0);
    if (object)
        reinterpret_cast<S*>(reinterpret_cast<char*>(this) - 0x174)->accept(object);
}
