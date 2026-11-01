// from server: 100% by atomic.potato
typedef struct tagSAFEARRAY SAFEARRAY;

extern "C" long __declspec(dllimport) __stdcall SafeArrayUnlock(SAFEARRAY *);
extern "C" long __declspec(dllimport) __stdcall SafeArrayDestroy(SAFEARRAY *);

struct PasteVerb
{
    SAFEARRAY *array;
    void f();
};

void PasteVerb::f()
{
    if (array != 0)
    {
        if (SafeArrayUnlock(array) >= 0)
        {
            if (SafeArrayDestroy(array) >= 0)
                array = 0;
        }
    }
}
