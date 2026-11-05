// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary
{
    virtual ~Primary();
    char padding[0x374];
};

struct Secondary
{
    virtual ~Secondary();
    char padding[0x20];
};

struct Tertiary
{
    virtual ~Tertiary();
    char padding[0x2c];
};

struct Base : Primary, Secondary, Tertiary
{
    Base();
};

struct CSettingsExplorer : Base
{
    virtual ~CSettingsExplorer();
};

CSettingsExplorer* createSettingsExplorer()
{
    return new CSettingsExplorer;
}
