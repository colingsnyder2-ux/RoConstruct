// from server: 100% by king_originala
struct String;

extern void (__thiscall *stringDestroy)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

struct String {
    char data[28];

    ~String();
    String& operator=(const String&);
};

__forceinline String::~String()
{
    stringDestroy(this);
}

__forceinline String& String::operator=(const String& other)
{
    return stringAssign(this, other);
}

struct Node {
    char padding[8];
    int count;
};

struct Reference {
    Node* pointer;
    void* control;

    void release();
};

extern "C" bool __cdecl differs(const String*, const String*);
extern "C" void* __stdcall convert(void*, int);
extern "C" void __cdecl dispose(void*);
extern char notification[];

struct S {
    char padding[0x134];
    Reference reference;
    void* resource;
    String value;
    int setting;

    void release();
    void notify(const char*);
    void f(String incoming, int newSetting);
};

void S::f(String incoming, int newSetting)
{
    String* destination = &value;

    if (differs(destination, &incoming)) {
        *destination = incoming;
        reinterpret_cast<int*>(destination)[7] = newSetting;
        release();

        if (resource) {
            dispose(convert(resource, 0));
            resource = 0;
        }

        if (reference.pointer) {
            --reference.pointer->count;
            reference.release();
        }

        notify(notification);
    }
}
