// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct Base
{
    char storage[0x158];
    ~Base();
};

struct S : Base
{
    Manager *manager;
    unsigned int padding;
    char buffer[16];

    ~S();
};

S::~S()
{
    if (manager)
    {
        Manager destroy = *manager;
        void *data = buffer;
        if (destroy)
            destroy(data, data, 1);
        manager = 0;
    }
}
