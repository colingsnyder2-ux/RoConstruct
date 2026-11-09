// from server: 43% by atomic.potato
typedef unsigned long DWORD;

struct String
{
    String(const String&);
};

extern "C" String* __stdcall StringCopy(String*, const String*);
typedef void (__fastcall *Method)(void*, int);

struct S
{
    int f();
};

int S::f()
{
    void** vtable = *(void***)this;
    Method method = (Method)vtable[5];
    method(this, 0);

    String* source = *(String**)((char*)this + 0x0c);
    String* result = (String*)0;
    StringCopy(result, source);
    return (int)source;
}
