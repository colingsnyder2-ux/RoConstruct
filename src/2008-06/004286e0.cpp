// from server: 100% by king_originala
struct Text {
    char storage[20];
    unsigned int length;
};

struct Buffer {
    void* data;
    __declspec(dllimport) Buffer();
    __declspec(dllimport) ~Buffer() throw();
    __declspec(dllimport) const char* c_str() const;
};

extern const char* (__thiscall* textData)(const Text*);
extern void (__cdecl* formatBuffer)(Buffer*, const char*, ...);

extern const char formatWithMessage[];
extern const char formatWithoutMessage[];
extern void __cdecl writeLog(int, const char*);

bool __cdecl reportAssertion(const char* expression, const Text* message,
                            const char* filename, int line)
{
    Buffer buffer;

    if (message->length > 0)
        formatBuffer(&buffer, formatWithMessage, expression,
                     textData(message), filename, line);
    else
        formatBuffer(&buffer, formatWithoutMessage, expression, filename, line);

    writeLog(2, buffer.c_str());
    return false;
}
