// from server: 100% by king_originala
struct String {};

extern String* (__thiscall *copyString)(String*, const String&);

struct S {
    unsigned char padding[8];
    int offset;
    String* f(String* result, void* object);
};

String* S::f(String* result, void* object)
{
    volatile int state = 0;
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    copyString(result, *reinterpret_cast<const String*>(base + offset));
    return result;
}
