// from server: 100% by king_originala
extern "C" void* (__stdcall *LoadLibraryA)(const char*);
extern void* moduleHandle;
extern int referenceCount;

struct CObjectBrowser
{
    int func_00462c60(void* argument);
    int func_00463930(void* argument);
};

int CObjectBrowser::func_00463930(void* argument)
{
    if (referenceCount == 0)
    {
        moduleHandle = LoadLibraryA("SciLexer.dll");
        if (moduleHandle == 0)
            return -1;
    }

    ++referenceCount;
    return func_00462c60(argument) == -1 ? -1 : 0;
}
