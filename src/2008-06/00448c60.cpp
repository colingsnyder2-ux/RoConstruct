// from server: 100% by king_originala
typedef unsigned long DWORD;

struct String;
extern void (__thiscall *string_default)(String *);
extern void (__thiscall *string_text)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);
extern unsigned long __cdecl availableMemory();

struct String {
    char storage[28];
    String();
    String(const char *);
    ~String();
};

inline String::String() { string_default(this); }
inline String::String(const char *s) { string_text(this, s); }
inline String::~String() { string_destroy(this); }

struct Base {
    char storage[0x130];
    Base();
    ~Base();
};

struct S : Base {
    DWORD mode;
    DWORD value134;
    DWORD quality;
    DWORD value13c;
    DWORD value140;
    float value144;
    float value148;
    float value14c;
    float value150;
    bool enabled;
    char padding[3];
    String text;
    unsigned short width;
    unsigned short height;
    DWORD value178;

    S();
    void setName(const String &);
};

S::S()
    : Base(),
      mode((
          value144 = *reinterpret_cast<const float *>(0x815bc0),
          value148 = *reinterpret_cast<const float *>(0x815bc0),
          value14c = *reinterpret_cast<const float *>(0x815bc8),
          *reinterpret_cast<volatile DWORD *>(reinterpret_cast<char *>(this) + 0x00) = 0x816364,
          value150 = *reinterpret_cast<const float *>(0x815bc8),
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x10) = 0x816354,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x14) = 0x81634c,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x20) = 0x816344,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x24) = 0x816334,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x44) = 0x816324,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x64) = 0x816314,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0x84) = 0x816304,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0xa4) = 0x8162f4,
          *reinterpret_cast<DWORD *>(reinterpret_cast<char *>(this) + 0xc4) = 0x8162e4,
          1)),
      value134(0),
      quality(2),
      value13c(0),
      value140(0),
      enabled(true),
      text()
{
    if (availableMemory() >= 16000000UL) {
        width = 1024;
        height = 768;
    } else {
        width = 800;
        height = 600;
    }

    value178 = *reinterpret_cast<const DWORD *>(0x93066c);

    {
        String name(reinterpret_cast<const char *>(0x8162d4));
        setName(name);
    }

    *reinterpret_cast<DWORD *>(0x942df8) = 1;
}
