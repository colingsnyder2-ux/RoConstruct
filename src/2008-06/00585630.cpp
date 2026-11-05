// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <vector>

struct __declspec(novtable) IPrimaryPart { virtual void a0(); };
struct __declspec(novtable) ICameraSubject { virtual void c0(); ~ICameraSubject() {} };
struct __declspec(novtable) ISelectable3d : virtual IPrimaryPart { virtual void s0(); };

struct P00 { virtual void m00(); unsigned long pad[3]; };
struct P10 { virtual void m10(); };
struct P14 { virtual void m14(); unsigned long pad[2]; };
struct P20 { virtual void m20(); };
struct P24 { virtual void m24(); unsigned long pad[7]; };
struct P44 { virtual void m44(); unsigned long pad[7]; };
struct P64 { virtual void m64(); unsigned long pad[7]; };
struct P84 { virtual void m84(); unsigned long pad[7]; };
struct PA4 { virtual void mA4(); unsigned long pad[7]; };
struct PC4 { virtual void mC4(); unsigned long pad[26]; };
struct P130 { virtual void m130(); };

struct __declspec(novtable) IRenderable
{
    virtual void r0();
    int a, b, c;
    IRenderable() : a(-1), b(-1), c(0) {}
    ~IRenderable();
};

struct Base : P00, P10, P14, P20, P24, P44, P64, P84, PA4, PC4, P130, virtual ICameraSubject, virtual IPrimaryPart
{
    Base(const char*);
    ~Base();
    unsigned long pad[(0x1a0 - 0x138) / 4];
};

struct Frame { char data[0x30]; Frame(); ~Frame() {} };

struct Extents { float v[6]; };

void releaseCount(void*);
struct SP { void* px; void* pn; SP() : px(0), pn(0) {} ~SP() { if (pn) releaseCount(pn); } };

struct ModelInstance;
struct Delegate { void* fn; int a; int b; Delegate() {} Delegate(void* f) : fn(f), a(0), b(0) {} };

struct FlagProp
{
    bool dirty;
    ModelInstance* object;
    float val;
    Delegate d;
    FlagProp(ModelInstance* o, Delegate f) : dirty(true), object(o), d(f) {}
    ~FlagProp() {}
};

struct ExtProp
{
    Extents val;
    bool dirty;
    ModelInstance* object;
    Delegate d;
    int tail;
    ExtProp(ModelInstance* o, Delegate f);
};

struct Name;
struct Creator;
struct CreatorMap { Creator*& operator[](const Name* const&); };
CreatorMap& getCreators();
const Name& declareName(const char*, int);
extern Creator creatorObject;
extern bool physicalCharacterHacked;

float computeFlagHeightThunk();
Extents computeLocalThunk();
Extents computeWorldThunk();

struct ModelInstance : Base, IRenderable, virtual ISelectable3d
{
    ModelInstance();
    virtual void a0();
    virtual void c0();
    virtual void s0();
    Frame frame;
    void* primaryPart;
    SP candidate;
    std::vector<int> v;
    char gap2[8];
    FlagProp flag;
    int gap3;
    ExtProp local;
    ExtProp world;
};

ModelInstance::ModelInstance()
    : Base("Model"),
      frame(),
      primaryPart(0),
      candidate(),
      flag(this, Delegate((void*)computeFlagHeightThunk)),
      local(this, Delegate((void*)computeLocalThunk)),
      world(this, Delegate((void*)computeWorldThunk))
{
    if (!physicalCharacterHacked)
    {
        const Name& name = declareName("PhysicalCharacter", -1);
        getCreators()[&name] = &creatorObject;
        physicalCharacterHacked = true;
    }
}
