// from server: 24% by colin
extern "C" void* __cdecl func_0062fef6(unsigned int);
extern "C" void __cdecl func_005800b0(void*, const char*, const char*);
extern "C" void __stdcall func_0077e6a8();
extern "C" void __stdcall func_0077e6ac();

struct LogManager {
    void* log;
    void* crashReporter;
    char pad[0xac - 8];
    void* getLogFileName();
};

struct ThreadLogManager : LogManager {
    void* getCurrent();
};

void* ThreadLogManager::getCurrent()
{
    if (*(char*)0x886374 == 0)
        return 0;
    if (this->crashReporter == 0) {
        void* p = func_0062fef6(0xac);
        if (p) {
            void* name = this->getLogFileName();
            func_0077e6a8();
            func_0077e6a8();
            func_005800b0(p, (const char*)name, (const char*)0);
        }
        this->crashReporter = p;
    }
    return this->crashReporter;
}
