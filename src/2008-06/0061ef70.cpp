// from server: 100% by tester
struct String {
    char storage[28];
    ~String();
};

String __cdecl makeString(const char *);

struct RuntimeError {
    char storage[40];
    RuntimeError(const String &);
    RuntimeError(const RuntimeError &);
    ~RuntimeError();
};

void __cdecl rejectEnumModification()
{
    throw RuntimeError(makeString("EnumItem cannot be modified"));
}
