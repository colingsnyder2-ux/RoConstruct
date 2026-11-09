// from server: 100% by EspClaude
// roc 2009-06 00448a50  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 310 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00448a50
//
// 00448a50  6aff                 push -1
// 00448a52  683a098500           push 0x85093a
// 00448a57  64a100000000         mov eax, dword ptr fs:[0]
// 00448a5d  50                   push eax
// 00448a5e  64892500000000       mov dword ptr fs:[0], esp
// 00448a65  83ec40               sub esp, 0x40
// 00448a68  56                   push esi
// 00448a69  57                   push edi
// 00448a6a  8d442410             lea eax, [esp + 0x10]
// 00448a6e  68cc728b00           push 0x8b72cc
// 00448a73  50                   push eax
// 00448a74  e817cb2b00           call 0x705590
// 00448a79  83c408               add esp, 8
// 00448a7c  8bf8                 mov edi, eax
// 00448a7e  8b0de404a500         mov ecx, dword ptr [0xa504e4]
// 00448a84  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00448a8c  85c9                 test ecx, ecx
// 00448a8e  740a                 je 0x448a9a
// 00448a90  8b11                 mov edx, dword ptr [ecx]
// 00448a92  8b02                 mov eax, dword ptr [edx]
// 00448a94  ffd0                 call eax
// 00448a96  8bf0                 mov esi, eax
// 00448a98  eb02                 jmp 0x448a9c
// 00448a9a  33f6                 xor esi, esi
// 00448a9c  8bcf                 mov ecx, edi
// 00448a9e  ff15bce48900         call dword ptr [0x89e4bc]
// 00448aa4  50                   push eax
// 00448aa5  6a00                 push 0
// 00448aa7  8bce                 mov ecx, esi
// 00448aa9  e842fe2b00           call 0x7088f0
// 00448aae  8d4c2410             lea ecx, [esp + 0x10]
// 00448ab2  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 00448aba  ff15c4e48900         call dword ptr [0x89e4c4]
// 00448ac0  8d4c2408             lea ecx, [esp + 8]
// 00448ac4  51                   push ecx
// 00448ac5  e8b60e1c00           call 0x609980
// 00448aca  83c404               add esp, 4
// 00448acd  8b00                 mov eax, dword ptr [eax]
// 00448acf  6810894400           push 0x448910
// 00448ad4  8bc8                 mov ecx, eax
// 00448ad6  c744245401000000     mov dword ptr [esp + 0x54], 1
// 00448ade  e88df6ffff           call 0x448170
// 00448ae3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00448ae7  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 00448aef  85c0                 test eax, eax
// 00448af1  742c                 je 0x448b1f
// 00448af3  8bf0                 mov esi, eax
// 00448af5  83c004               add eax, 4
// 00448af8  83caff               or edx, 0xffffffff
// 00448afb  f00fc110             lock xadd dword ptr [eax], edx
// 00448aff  751e                 jne 0x448b1f
// 00448b01  8b06                 mov eax, dword ptr [esi]
// 00448b03  8b5004               mov edx, dword ptr [eax + 4]
// 00448b06  8bce                 mov ecx, esi
// 00448b08  ffd2                 call edx
// 00448b0a  8d4608               lea eax, [esi + 8]
// 00448b0d  83c9ff               or ecx, 0xffffffff
// 00448b10  f00fc108             lock xadd dword ptr [eax], ecx
// 00448b14  7509                 jne 0x448b1f
// 00448b16  8b16                 mov edx, dword ptr [esi]
// 00448b18  8b4208               mov eax, dword ptr [edx + 8]
// 00448b1b  8bce                 mov ecx, esi
// 00448b1d  ffd0                 call eax
// 00448b1f  8d4c242c             lea ecx, [esp + 0x2c]
// 00448b23  6894728b00           push 0x8b7294
// 00448b28  51                   push ecx
// 00448b29  e862ca2b00           call 0x705590
// 00448b2e  83c408               add esp, 8
// 00448b31  8bf8                 mov edi, eax
// 00448b33  8b0de404a500         mov ecx, dword ptr [0xa504e4]
// 00448b39  c744245002000000     mov dword ptr [esp + 0x50], 2
// 00448b41  85c9                 test ecx, ecx
// 00448b43  740a                 je 0x448b4f
// 00448b45  8b11                 mov edx, dword ptr [ecx]
// 00448b47  8b02                 mov eax, dword ptr [edx]
// 00448b49  ffd0                 call eax
// 00448b4b  8bf0                 mov esi, eax
// 00448b4d  eb02                 jmp 0x448b51
// 00448b4f  33f6                 xor esi, esi
// 00448b51  8bcf                 mov ecx, edi
// 00448b53  ff15bce48900         call dword ptr [0x89e4bc]
// 00448b59  50                   push eax
// 00448b5a  6a00                 push 0
// 00448b5c  8bce                 mov ecx, esi
// 00448b5e  e88dfd2b00           call 0x7088f0
// 00448b63  8d4c242c             lea ecx, [esp + 0x2c]
// 00448b67  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 00448b6f  ff15c4e48900         call dword ptr [0x89e4c4]
// 00448b75  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00448b79  5f                   pop edi
// 00448b7a  5e                   pop esi
// 00448b7b  64890d00000000       mov dword ptr fs:[0], ecx
// 00448b82  83c44c               add esp, 0x4c
// 00448b85  c3                   ret 
// copied from an identical function in another client (function ?reportGlobalSettings@ns_ROCX000006@@YAXXZ)

namespace ns_ROCX000006 {
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
}
