// from server: 100% by king_originala
struct Mutex {
    void lock();
};

struct Key {
    unsigned int first;
    unsigned int second;
};

struct Ball {
    void update(const Key &key);
};

struct S {
    Mutex mutex;
    unsigned char padding[7];
    Key key;
    unsigned char reserved[0x218];
    Ball ball;
    void f();
};

void S::f()
{
    mutex.lock();
    ball.update(key);
}
