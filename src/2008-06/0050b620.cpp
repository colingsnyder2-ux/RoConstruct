// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;
extern const char messageText[];
extern unsigned char exceptionInfo[];

struct String {
    unsigned char storage[28];
    String(const char *text);
    ~String();
};

inline String::String(const char *text) {
    constructString(this, text);
}

struct Exception {
    unsigned char storage[96];
    Exception(const String &, const String &);
};

extern "C" __declspec(noreturn) void __stdcall raiseException(void *, void *);

void fail(int, const char *text) {
    String message(messageText);
    String detail(text);
    Exception exception(detail, message);
    raiseException(&exception, exceptionInfo);
}
