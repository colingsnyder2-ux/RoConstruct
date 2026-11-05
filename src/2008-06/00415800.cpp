// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_clipboarddirectrange9f920a6de726796c.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
// from server: 91% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" void* (__stdcall* GlobalAlloc)(unsigned int, unsigned long);
extern "C" void* (__stdcall* GlobalLock)(void*);
extern "C" int (__stdcall* GlobalUnlock)(void*);
extern "C" int (__stdcall* OpenClipboard)(void*);
extern "C" int (__stdcall* EmptyClipboard)();
extern "C" int (__stdcall* CloseClipboard)();
extern "C" unsigned int (__stdcall* RegisterClipboardFormatA)(const char*);
extern "C" void* (__stdcall* SetClipboardData)(unsigned int, void*);
extern "C" char* __cdecl strcpy(char*, const char*);
#pragma intrinsic(strcpy)

struct Text
{
    unsigned char storage[20];
    unsigned int length;
    unsigned int capacity;
    ~Text();
    const char* c_str() const;
};

struct Stream
{
    unsigned char storage[128];
    Stream(int, int = 1);
    ~Stream();
    __declspec(dllimport) Text str() const;
};

extern void (__thiscall* constructStream)(Stream*, int, int);
extern void (__thiscall* destroyStream)(Stream*);
extern void (__thiscall* extractText)(const Stream*, Text*);
extern void (__thiscall* destroyText)(Text*);
extern const char* (__thiscall* textData)(const Text*);

inline Stream::Stream(int mode, int initialize)
{
    constructStream(this, mode, initialize);
}

inline Stream::~Stream()
{
    destroyStream(this);
}

inline Text::~Text()
{
    destroyText(this);
}

inline const char* Text::c_str() const
{
    return textData(this);
}

struct Resource
{
    unsigned char storage[36];
    ~Resource();
};

struct SerializerBase {
 virtual void slot();
 Resource resource;
 SerializerBase(Stream*);
};
struct Serializer:SerializerBase {
 Serializer(Stream* s):SerializerBase(s) {}
 virtual void slot();
 void write(void*);
};

typedef std::vector<boost::shared_ptr<void> > Selection;
typedef Selection::iterator Iterator;

struct Document
{
    unsigned char reserved[0x154];
    Selection* selection;
};

struct Owner
{
    Document* document();
};

struct Window
{
    unsigned char reserved[0x20];
    void* handle;
};

struct Application
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual Window* window();
};

struct Context
{
    void release();
};

extern Context* __cdecl getContext();
extern Application* __cdecl getApplication();
extern void __cdecl freeContext(void*);
extern void __cdecl copyItem(Context*,boost::shared_ptr<void>);
extern void* serializerTable;
extern unsigned long clipboardInitialized;
extern unsigned int clipboardFormat;
extern const char clipboardFormatName[];

struct CopyVerb
{
    unsigned char reserved[0x20];
    Owner* owner;
    void execute(void*);
};

void CopyVerb::execute(void*)
{
    Context* context = getContext();
    Document* document = owner ? owner->document() : 0;
    std::for_each(document->selection->begin(),document->selection->end(),boost::bind(copyItem,context,_1));

    Stream stream(2);
    Serializer serializer(&stream);
    serializer.write(context);

    if (context)
    {
        context->release();
        freeContext(context);
    }

    Application* application = getApplication();
    Window* window = application ? application->window() : 0;
    if (OpenClipboard(window->handle))
    {
        EmptyClipboard();
        Text text = stream.str();
        void* memory = GlobalAlloc(2, text.length + 1);
        char* destination = static_cast<char*>(GlobalLock(memory));
        strcpy(destination, text.c_str());
        GlobalUnlock(memory);
        if (!(clipboardInitialized & 1))
        {
            clipboardInitialized |= 1;
            clipboardFormat = RegisterClipboardFormatA(clipboardFormatName);
        }
        SetClipboardData(clipboardFormat, memory);
        CloseClipboard();
    }
}
