// from server: 100% by king_originala
extern void (__thiscall *destroyStream)(void *);

struct Stream
{
    ~Stream() { destroyStream(this); }
};

struct Module
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

extern Module *module;

struct S
{
    virtual ~S();

    unsigned long references;
    unsigned char reserved[12];
    Stream stream;
};

S::~S()
{
    references = 0xC0000001UL;
    module->release();
}
