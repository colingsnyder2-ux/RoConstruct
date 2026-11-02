// from server: 100% by tajop
struct String {
    String(const String& other);
    ~String();
    char pad[28];
};

extern void (String::*string_copy_ctor)(const String&);
extern void (String::*string_dtor)();

inline String::String(const String& other) {
    (this->*string_copy_ctor)(other);
}

inline String::~String() {
    (this->*string_dtor)();
}

struct StringStorage {
    char pad[28];
};

struct IntStringPair {
    int first;
    StringStorage second;
    IntStringPair(const int& a, const String& b) : first(a) {
        (((String*)&second)->*string_copy_ctor)(b);
    }
    ~IntStringPair();
};

IntStringPair make_int_string_pair(int a, String b) {
    return IntStringPair(a, b);
}
