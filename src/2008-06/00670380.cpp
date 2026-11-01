// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String {
    unsigned char data[28];
};

struct Object {
    unsigned char data[96];
    Object(const String&);
};

struct Result {
    Object* value;
    Result(Object*);
    ~Result();
    void reset(Object*);
};

__forceinline Result::Result(Object* p)
{
    value = 0;
    reset(p);
}

Result __stdcall create(const String& str)
{
    return Result(new Object(str));
}
