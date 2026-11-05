// from server: 100% by king_originala
struct String;
extern String* (__thiscall *constructString)(String*);
extern String* (__thiscall *constructStringText)(String*, const char*);
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    String();
    String(const char*);
    ~String();
};

inline String::String() { constructString(this); }
inline String::String(const char* text) { constructStringText(this, text); }
inline String::~String() { destroyString(this); }

struct Name;
extern const Name& __cdecl getLocalScope();
extern const float initialVolume;
extern const char soundName[];

extern char table00[], table10[], table14[], table20[];
extern char table24[], table44[], table64[], table84[];
extern char tableA4[], tableC4[], table130[];

struct Base {
    char storage[0x130];
    Base();
    ~Base();
    void setValue(const String&);
};

struct Shared {
    void* count;
    Shared();
    ~Shared();
};

inline Shared::Shared() : count(0) {}

struct Guid {
    String value;
    const Name* scope;
    Guid();
};

inline Guid::Guid() : scope(&getLocalScope()) {}

struct SoundService : Base {
    void* table;
    void* object;
    Shared shared;
    void* system;
    Guid guid;
    float volume;
    unsigned char enabled;
    unsigned char flags;
    unsigned short padding;
    int identifier;
    void* context;

    SoundService();
};

SoundService::SoundService()
    : table((
          *reinterpret_cast<void**>(storage) = table00,
          *reinterpret_cast<void**>(storage + 0x10) = table10,
          *reinterpret_cast<void**>(storage + 0x14) = table14,
          *reinterpret_cast<void**>(storage + 0x20) = table20,
          *reinterpret_cast<void**>(storage + 0x24) = table24,
          *reinterpret_cast<void**>(storage + 0x44) = table44,
          *reinterpret_cast<void**>(storage + 0x64) = table64,
          *reinterpret_cast<void**>(storage + 0x84) = table84,
          *reinterpret_cast<void**>(storage + 0xA4) = tableA4,
          *reinterpret_cast<void**>(storage + 0xC4) = tableC4,
          table130)),
      object(0),
      system(0),
      volume(initialVolume),
      enabled(0),
      identifier(-1),
      context(0)
{
    flags &= 0xF8;
    setValue(String(soundName));
}
