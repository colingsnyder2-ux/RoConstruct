// from server: 100% by king_originala
struct Root;
extern Root* root;
extern void (__thiscall *destroyRoot)(Root*);
void __cdecl operator delete(void*);

struct Root
{
    ~Root();
};

__forceinline Root::~Root()
{
    destroyRoot(this);
}

void cleanupRoot()
{
    if (root)
    {
        delete root;
        root = 0;
    }
}
