// from server: 100% by king_originala
struct String;

extern void (__thiscall* constructString)(String*, const char*);
extern void (__thiscall* destroyString)(String*);

struct String {
    char reserved[4];
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;

    String(const char* text) { constructString(this, text); }
    ~String() { destroyString(this); }
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Input;

extern const char* (__thiscall* getText)(Input*);
extern bool __cdecl parseVector(const String&, Vector3&);

int __stdcall readVector(Input* input)
{
    Vector3 value = { 0.0f, 0.0f, 0.0f };
    String text(getText(input));
    return parseVector(text, value);
}
