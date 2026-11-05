// from server: 100% by king_originala
struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *stringConstructor)(String*, const char*);

__forceinline String::String(const char* text) {
    stringConstructor(this, text);
}

struct ExceptionCode {};
struct Exception {
    char storage[160];
};

struct Texture {
    char storage[12];
};

Exception* __cdecl makeException(
    Exception*, ExceptionCode, const String&, const String&, const char*, int);

extern "C" {
    extern void (__stdcall *_invalid_parameter_noinfo)();
    __declspec(noreturn) void __stdcall throwException(void*, void*);
}
extern char exceptionType;

struct RbxSceneManager {
    Texture& getShadowTexture(unsigned int index);
};

Texture& RbxSceneManager::getShadowTexture(unsigned int index) {
    char* self = reinterpret_cast<char*>(this);

    if (index >= static_cast<unsigned int>(
            *reinterpret_cast<Texture**>(self + 0x8a68) -
            *reinterpret_cast<Texture**>(self + 0x8a64))) {
        String source("RbxSceneManager::getShadowTexture");
        String description("shadowIndex out of bounds");
        Exception exception;
        makeException(&exception, ExceptionCode(), description, source,
                      ".\\RbxSceneManager.cpp", 0x12b9);
        throwException(&exception, &exceptionType);
    }

    typedef void (__thiscall *UpdateFunction)(RbxSceneManager*);
    UpdateFunction* table = *reinterpret_cast<UpdateFunction**>(this);
    table[8](this);

    Texture* first = *reinterpret_cast<Texture**>(self + 0x8a80);
    Texture* last = *reinterpret_cast<Texture**>(self + 0x8a84);
    if (index >= static_cast<unsigned int>(last - first))
        _invalid_parameter_noinfo();

    return (*reinterpret_cast<Texture**>(self + 0x8a80))[index];
}
