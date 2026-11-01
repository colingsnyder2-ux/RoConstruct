// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String {
    char storage[28];
    String(const char*, String*&);
    const char* c_str() const;
    ~String();
};

extern String* __cdecl makeString(String*, const char*);
extern const char* (__thiscall *stringData)(const String*);
extern void (__thiscall *destroyString)(String*);

inline String::String(const char* text, String*& result) {
    result = makeString(this, text);
}

inline const char* String::c_str() const {
    return stringData(this);
}

inline String::~String() {
    destroyString(this);
}

struct Stream {
    Stream& write(int, const char*);
};

struct StreamProvider {
    virtual Stream* getStream() = 0;
};

extern StreamProvider* streamProvider;

struct ControlBlock {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long references;
    volatile long weakReferences;
    void release();
};

inline void ControlBlock::release() {
    if (_InterlockedDecrement(&references) == 0) {
        dispose();
        if (_InterlockedDecrement(&weakReferences) == 0)
            destroy();
    }
}

extern void __cdecl settingsCallback(const char*);

struct Settings {
    void enumerate(void (__cdecl *)(const char*));
};

struct SettingsHandle {
    Settings* object;
    ControlBlock* control;
    SettingsHandle(SettingsHandle*&);
    ~SettingsHandle();
};

extern SettingsHandle* __cdecl getSettings(SettingsHandle*);

inline SettingsHandle::SettingsHandle(SettingsHandle*& result) {
    result = getSettings(this);
}

inline SettingsHandle::~SettingsHandle() {
    if (control)
        control->release();
}

void __cdecl reportGlobalSettings() {
    {
        String* result;
        String text("GlobalSettings ---------------------------------------", result);
        Stream* stream = streamProvider ? streamProvider->getStream() : 0;
        stream->write(0, result->c_str());
    }
    {
        SettingsHandle* result;
        SettingsHandle settings(result);
        Settings* targetSettings = result->object;
        targetSettings->enumerate(settingsCallback);
    }
    {
        String* result;
        String text("End GlobalSettings -----------------------------------", result);
        Stream* stream = streamProvider ? streamProvider->getStream() : 0;
        stream->write(0, result->c_str());
    }
}
