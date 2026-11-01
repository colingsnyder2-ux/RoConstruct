// from server: 100% by king_originala
typedef void (__thiscall *StringConstruct)(void *, const char *);
typedef void (__thiscall *StringDestroy)(void *);

extern StringConstruct stringConstruct;
extern StringDestroy stringDestroy;

struct String {
    unsigned char storage[28];

    String(const char *text);
    ~String();
};

inline String::String(const char *text) {
    stringConstruct(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    unsigned char storage[0x130];

    Base();
    ~Base();
    void setName(const String &name);
};

struct Matrix {
    float elements[9];

    Matrix &operator=(const Matrix &other);
};

struct Frame {
    Matrix rotation;
    float translation[3];
};

struct S : Base {
    Frame frame;

    S();
};

S::S()
    : Base()
{
    Frame *f = &frame;

    *reinterpret_cast<unsigned long *>(storage + 0x00) = 0x8496cc;
    *reinterpret_cast<unsigned long *>(storage + 0x10) = 0x8496c0;
    *reinterpret_cast<unsigned long *>(storage + 0x14) = 0x8496b8;
    *reinterpret_cast<unsigned long *>(storage + 0x20) = 0x8496b0;
    *reinterpret_cast<unsigned long *>(storage + 0x24) = 0x8496a0;
    *reinterpret_cast<unsigned long *>(storage + 0x44) = 0x849690;
    *reinterpret_cast<unsigned long *>(storage + 0x64) = 0x849680;
    *reinterpret_cast<unsigned long *>(storage + 0x84) = 0x849670;
    *reinterpret_cast<unsigned long *>(storage + 0xa4) = 0x849660;
    *reinterpret_cast<unsigned long *>(storage + 0xc4) = 0x849650;

    f->rotation = *reinterpret_cast<const Matrix *>(0x97d3a0);
    f->translation[0] = *reinterpret_cast<const float *>(0x97d3c4);
    f->translation[1] = *reinterpret_cast<const float *>(0x97d3c8);
    f->translation[2] = *reinterpret_cast<const float *>(0x97d3cc);

    String name(reinterpret_cast<const char *>(0x818478));
    setName(name);
}
