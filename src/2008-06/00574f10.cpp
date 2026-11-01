// from server: 100% by king_originala
struct String;

extern String& (__thiscall *string_assign)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

struct String {
    char storage[28];
    ~String() { string_destroy(this); }
};

struct S_func_00574f10 {
    char pad0[564];
    String text;
    void f(String value);
};

void S_func_00574f10::f(String value)
{
    string_assign(&text, value);
}
