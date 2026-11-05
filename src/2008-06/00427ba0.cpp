// from server: 100% by king_originala
struct String;
struct Path;

extern const char *(__thiscall *string_c_str)(const String *);
extern void (__thiscall *string_destroy)(String *);
extern void (__thiscall *path_construct)(Path *, const char *);

struct String {
    unsigned char data[28];
    const char *c_str() const;
    ~String();
};

struct Path {
    unsigned char data[28];
    Path(const char *);
    ~Path();
};

inline const char *String::c_str() const {
    return string_c_str(this);
}

inline String::~String() {
    string_destroy(this);
}

inline Path::Path(const char *text) {
    path_construct(this, text);
}

extern String __cdecl make_string(int, const char *);

Path __stdcall make_log_path() {
    String text = make_string(1, "logs");
    return Path(text.c_str());
}
