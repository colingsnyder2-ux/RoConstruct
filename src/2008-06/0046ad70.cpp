// from server: 100% by colin
extern void * __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void *);

extern char logName[];

extern void __stdcall writeLog(int, const char *, int, int, const char *, int);

struct Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void read(char*, unsigned int, int);
    unsigned int reserved;
    Base();
};

struct Object : Base
{
    unsigned int status;
    Object() { status = 0; }
    virtual void v0();
};

void func_0046ad70(int first, int second)
{
    char buffer[1024];
    Object *object = new Object;
    object->status = 0x80004001U;
    object->read(buffer, 1024, 0);
    writeLog(second, buffer, 0, 0, logName, first);
    throw object;
}
