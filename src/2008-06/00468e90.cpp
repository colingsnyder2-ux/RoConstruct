// from server: 100% by king_originala
#include <intrin.h>
// from server: 89% by king_originala
typedef unsigned long DWORD;

struct Accelerator;
extern "C" __declspec(dllimport) int __stdcall copyAccelerators(void*, Accelerator*, int);
extern long (__stdcall *createInput)(void*, DWORD, const void*, void**, void*);
extern const unsigned char inputIdentifier[];
extern "C" long __stdcall normalizeResult(long);
extern "C" void* __cdecl clearMemory(void*, int, unsigned int);
extern "C" __declspec(noreturn) void __stdcall AtlThrowImpl(long);

void* __cdecl operator new[](unsigned int);

struct Primary {
    virtual void primaryMethod();
    unsigned char reserved[0x24];
};

struct Interface1 {
    virtual void firstMethod();
};

struct Interface2 {
    virtual void secondMethod();
};

struct Base : Primary, Interface1, Interface2 {
    DWORD reserved30;
    Base();
    ~Base();
};

struct Member {
    unsigned char reserved[0x18];
    Member();
    ~Member();
};

struct Listener {
    void connect(void*);
    void disconnect(void*);
};

struct Object {
    unsigned char reserved0[0x130];
    Listener first;
    unsigned char reserved1[0x170 - 0x130 - sizeof(Listener)];
    Listener second;
    Object* related();
};

void __cdecl initializeReference(void*, Object*);

struct Reference {
    Object* object;
    void* control;
    Reference(Object*);
    ~Reference();
};

inline Reference::Reference(Object* p)
{
    initializeReference(this, p);
}

struct COMInterface {
 virtual long __stdcall query(void*,void**)=0;
 virtual unsigned long __stdcall addRef()=0;
 virtual unsigned long __stdcall releaseRef()=0;
 virtual void __stdcall slot3();virtual void __stdcall slot4();virtual void __stdcall slot5();virtual void __stdcall slot6();virtual void __stdcall slot7();
 virtual long __stdcall unacquire()=0;
};
struct Resource {
    COMInterface* value;
    Resource();
    ~Resource(){if(value)value->releaseRef();}
    void release(){if(value){value->releaseRef();value=0;}}
};

inline Resource::Resource() : value(0)
{
}

struct Window;

struct WindowTable {
    void* reserved[98];
    void* (__thiscall *accelerators)(Window*);
};

struct Window {
    WindowTable* table;
    unsigned char reserved[0x1c];
    void* handle;
    Window* owner();
    Window* parent();
};

struct Accelerator {
    unsigned short flags;
    unsigned short key;
    unsigned short command;
};

inline void* ownerHandle(Window* w)
{
    Window* p = w->owner();
    if (!p)
        return 0;
    return p->handle;
}

struct S : Base {
    Member member;
    Window* current;
    Accelerator* acceleratorData;
    volatile unsigned int acceleratorCount;
    unsigned char flag58;
    unsigned char flag59;
    unsigned short reserved5a;
    DWORD value5c;
    volatile float value60;
    volatile float value64;
    unsigned char keys[0x100];
    DWORD value168;
    Window* window;
    void* handle;
    Resource input;
    Resource device;
    Resource extraDevice;
    Reference reference;
    Reference relatedReference;
    unsigned char flag190;
    unsigned char flag191;
    unsigned char flag192;
    unsigned char flag193;

    virtual void primaryMethod();
    virtual void firstMethod();
    virtual void secondMethod();

    S(Window*, Object*);
    ~S();
    void initializeFirst();
    void initializeSecond();
};


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
inline Member::~Member(){DeleteCriticalSection(this);}
struct RefCount {virtual ~RefCount(){}virtual void dispose()=0;virtual void destroy()=0;long strong,weak;};
inline Reference::~Reference(){RefCount*p=static_cast<RefCount*>(control);if(p){if(_InterlockedDecrement(&p->strong)==0){p->dispose();if(_InterlockedDecrement(&p->weak)==0)p->destroy();}}}
S::~S(){
 if(relatedReference.object)relatedReference.object->first.disconnect(static_cast<Interface2*>(this));
 if(relatedReference.object)relatedReference.object->second.disconnect(static_cast<Interface1*>(this));
 if(device.value){device.value->unacquire();device.release();}
 if(extraDevice.value){extraDevice.value->unacquire();extraDevice.release();}
 if(input.value)input.release();
 delete[] acceleratorData;
}
