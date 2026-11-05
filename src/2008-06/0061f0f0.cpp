// from server: 100% by king_originala
struct String {
    char storage[28];
    ~String();
};

struct RuntimeError {
    char storage[40];
    RuntimeError(const String&);
    RuntimeError(const RuntimeError&);
    ~RuntimeError();
};

extern const char invalidEnumFormat[];
extern "C" const char* __cdecl sub_554290(int);
extern "C" void* __cdecl sub_61f080(const char*);
extern "C" void __cdecl sub_5a9b30(int, void*);
String __cdecl sub_509b10(const char*, ...);

int __cdecl sub_61f0f0(int, int value, int destination)
{
    void* item = sub_61f080(sub_554290(value));
    if (item) {
        sub_5a9b30(destination, item);
        return 1;
    }
    throw RuntimeError(sub_509b10(invalidEnumFormat, value));
}
