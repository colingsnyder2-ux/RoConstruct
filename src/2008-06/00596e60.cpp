// from server: 100% by king_originala
struct StringData {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

struct Log {
    StringData* get();
};

extern Log* globalLog;
extern int initializationFlag;
extern char* fallbackText;

void __cdecl initializeLog();
void __cdecl initializeOnce(void (__cdecl* initializer)(), int* flag);

char* getText()
{
    initializeOnce(initializeLog, &initializationFlag);
    StringData* text = globalLog->get();
    if (text) {
        if (text->capacity >= 16)
            return text->pointer;
        return text->buffer;
    }
    return fallbackText;
}
