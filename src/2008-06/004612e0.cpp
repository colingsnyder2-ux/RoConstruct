// from server: 100% by king_originala
struct Text;

extern "C" void* __cdecl allocate(unsigned int);
extern "C" void __cdecl release(void*);
extern void (__thiscall *constructText)(Text*, const char*);

struct S {
    char padding[0x54];
    int (__cdecl *direct)(int, unsigned int, unsigned int, int);
    int context;

    Text* getSelectedText(Text* result);
};

Text* S::getSelectedText(Text* result)
{
    volatile int state = 0;
    int start = direct(context, 0x85F, 0, 0);
    int end = direct(context, 0x861, 0, 0);
    char* buffer = static_cast<char*>(allocate(end - start + 1));
    direct(context, 0x871, 0, reinterpret_cast<int>(buffer));
    constructText(result, buffer);
    release(buffer);
    return result;
}
