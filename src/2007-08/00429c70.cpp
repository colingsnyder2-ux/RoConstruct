// from server: 24% by colin
struct LogManager {
    void* log;
    unsigned long threadID;
    char name[4];
    void* vtable;
    LogManager(const char* n);
    virtual ~LogManager();
    virtual void getLogFileName();
};

struct ThreadLogManager : LogManager {
    ThreadLogManager(const char* n);
    virtual ~ThreadLogManager();
    virtual void getLogFileName();
};

extern "C" unsigned long __stdcall GetCurrentThreadId();
extern "C" void __stdcall SetUnhandledExceptionFilter(void*);
extern "C" void __stdcall _set_purecall_handler(void*);

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

ThreadLogManager::ThreadLogManager(const char* n) : LogManager(n) {
    this->vtable = (void*)0x78a170;
    *(void**)((char*)this + 4) = (void*)0x78a164;
    *(void**)((char*)this + 0x2c) = 0;
    *(unsigned long*)((char*)this + 0x30) = GetCurrentThreadId();
    *(void**)0x8bb8e8 = this;
    SetUnhandledExceptionFilter((void*)0x428510);
    _set_purecall_handler((void*)0x4285d0);
    (*(void(__stdcall*)(void*))0x77e974)((void*)0x428080);
}

ThreadLogManager::~ThreadLogManager() {
    this->vtable = (void*)0x78a01c;
    *(void**)((char*)this + 4) = (void*)0x789fa4;
    *(void**)((char*)this + 8) = 0;
    (*(void(__stdcall*)(void))0x77d2c4)();
    (*(void(__stdcall*)(void*))0x77e698)((void*)0);
    this->vtable = (void*)0x78a170;
    *(void**)((char*)this + 4) = (void*)0x78a164;
    (*(void(__stdcall*)(void))0x77e6a4)();
    (*(void(__stdcall*)(void))0x77e6ac)();
}

void ThreadLogManager::getLogFileName() {
    (*(void(__stdcall*)(void))0x77e63c)();
    (*(void(__stdcall*)(void))0x77e640)();
    (*(void(__stdcall*)(void))0x77e64c)();
    (*(void(__stdcall*)(void))0x77e660)();
}
