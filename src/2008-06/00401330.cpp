// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CAboutRobloxDialog
{
    char storage[0x130];
    CAboutRobloxDialog(int);
};

CAboutRobloxDialog* createDialog()
{
    return new CAboutRobloxDialog(0);
}
