// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_renderdeviceautoptreefad870f7e7913d.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
// from server: 93% by king_originala
typedef unsigned int size_t;

struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text)
{
    stringConstruct(this, text);
}

extern bool (__cdecl *stringEqual)(const String&, const char*);
extern const String& __cdecl getRendererName();
extern void* __cdecl getConfiguration();
extern unsigned int (__stdcall *getGLError)();
extern void* __cdecl operator new(size_t);
extern void __cdecl operator delete(void*);

struct GraphicsError {
    char storage[40];
    GraphicsError(const String&);
    GraphicsError(const GraphicsError&);
    ~GraphicsError();
};

struct Context {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void activate();
};

struct RenderDevice {
    char storage[0x8b0];
    RenderDevice();
    ~RenderDevice();
    bool init(Context*, void*);
    void setOption(bool);
    void begin();
};

extern Context* currentContext;
extern bool deviceCreated;
extern const char driverWarning[];

struct CRobloxWnd {
    char padding0[0x88];
    bool beginImmediately;
    char padding1[0x1b];
    Context* context;
    char padding2[4];
    std::auto_ptr<RenderDevice> renderDevice;

    void createRenderDevice(Context*);
};

void CRobloxWnd::createRenderDevice(Context* value)
{
    context = value;
    if (currentContext != value) {
        value->activate();
        currentContext = value;
    }

    if (stringEqual(getRendererName(), "GDI Generic"))
        throw GraphicsError(String(driverWarning));

    renderDevice.reset(new RenderDevice);
    if (!renderDevice->init(context, getConfiguration())) {
        renderDevice.reset();
        throw GraphicsError(String("renderDevice->init failed"));
    }

    deviceCreated = true;
    renderDevice->setOption(false);
    if (beginImmediately)
        renderDevice->begin();

    if (getGLError() != 0)
        throw GraphicsError(String("GL error creating RenderDevice"));
}
