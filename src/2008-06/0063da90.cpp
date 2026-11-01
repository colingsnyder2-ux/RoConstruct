// from server: 100% by colin
typedef unsigned long DWORD;

struct String {
    char storage[28];
    __declspec(dllimport) String(const char *);
    __declspec(dllimport) ~String();
};

struct Base {
    DWORD slots[77];
    Base();
    ~Base();
    void setName(const String &);
};

struct Parameters {
    int first;
    int second;
    int third;
    Parameters();
    ~Parameters();
};

inline Parameters::Parameters()
    : first(-1), second(-1), third(0)
{
}

struct Member {
    DWORD table;
    Member();
    ~Member();
};

struct S : Base {
    Parameters parameters;
    Member member;
    bool enabled;
    S();
};

S::S()
    : Base(), parameters(), member()
{
    slots[0] = 0x0084a234;
    slots[4] = 0x0084a228;
    slots[5] = 0x0084a220;
    slots[8] = 0x0084a218;
    slots[9] = 0x0084a208;
    slots[17] = 0x0084a1f8;
    slots[25] = 0x0084a1e8;
    slots[33] = 0x0084a1d8;
    slots[41] = 0x0084a1c8;
    slots[49] = 0x0084a1b8;
    slots[76] = 0x0084a1a0;
    member.table = 0x0084a198;
    enabled = true;

    String name(reinterpret_cast<const char *>(0x0084a274));
    setName(name);
}
