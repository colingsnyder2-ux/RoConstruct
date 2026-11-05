// from server: 100% by king_originala
struct String;

extern void (__thiscall *constructString)(String *);
extern void (__thiscall *destroyString)(String *);
extern String &(__thiscall *appendCharacter)(String *, unsigned int);
extern void (__cdecl *invalidParameter)();

struct String {
    unsigned int proxy;
    union {
        char local[16];
        char *heap;
    } storage;
    unsigned int length;
    unsigned int capacity;

    String();
    ~String();
    String &operator+=(unsigned int);
    unsigned char at(unsigned int, void (__cdecl *)());
};

inline String::String() {
    constructString(this);
}

inline String::~String() {
    destroyString(this);
}

inline String &String::operator+=(unsigned int c) {
    return appendCharacter(this, c);
}

inline unsigned char String::at(unsigned int index, void (__cdecl *invalid)()) {
    if (index > length)
        invalid();
    char *data = storage.heap;
    if (capacity < 16)
        data = storage.local;
    return static_cast<unsigned char>(data[index]);
}

String transform(String input) {
    String result;
    void (__cdecl *invalid)() = invalidParameter;
    for (int i = 0; i < 32; i += 2) {
        if (input.at(i, invalid) != '0')
            result += input.at(i, invalid);
        result += input.at(i + 1, invalid);
    }
    return result;
}
