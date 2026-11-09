// from server: 100% by king_originala
extern const char* (__thiscall *getText)(void*);
extern void (__thiscall *constructText)(void*, const char*);

struct NameItem {
    char padding[0x7c];
    char* instance;
    void* getName(void* result, int unused);
};

void* NameItem::getName(void* result, int unused)
{
    volatile int temporary = 0;
    const char* text = getText(instance + 0x110);
    constructText(result, text);
    return result;
}
