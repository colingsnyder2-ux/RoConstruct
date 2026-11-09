// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct SceneManager
{
    char storage[0x8c04];
    SceneManager(unsigned int);
};

struct Factory
{
    SceneManager* create(unsigned int);
};

SceneManager* Factory::create(unsigned int value)
{
    return new SceneManager(value);
}
