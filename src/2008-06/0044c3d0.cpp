// from server: 100% by king_originala
struct Base
{
    unsigned char storage[160];
    Base(int);
    virtual ~Base();
};

struct String
{
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *constructString)(void*);

struct CRobloxModule : Base
{
    String name;
    unsigned char padding[48];
    unsigned char text[28];
    unsigned value;

    CRobloxModule();
    virtual ~CRobloxModule();
};

CRobloxModule::CRobloxModule()
    : Base(0), name("Roblox")
{
    constructString(text);
    value = 0;
}
