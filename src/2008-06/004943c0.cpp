// from server: 68% by king_originala
struct Callback
{
    typedef void (__cdecl *Manager)(void*, void*, int);

    Manager* manager;
    unsigned int reserved;
    unsigned char storage[72];

    Callback(const Callback&);
    ~Callback();
};

inline Callback::~Callback()
{
    if (manager)
    {
        Manager operation = *manager;
        if (operation)
            operation(storage, storage, 1);
        manager = 0;
    }
}

struct Player
{
    void forward(unsigned int, unsigned int, Callback, Callback, bool);
    void invoke(unsigned int, unsigned int, Callback, Callback);
};

void Player::invoke(unsigned int first, unsigned int second,
                    Callback callback1, Callback callback2)
{
    forward(first, second, callback1, callback2, false);
}
