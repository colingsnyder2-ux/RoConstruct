// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern const int ballTable[];

struct Ball;

struct State {
    char storage[0x50];
    State(Ball*, int);
};

struct Ball {
    const int* table;
    int first;
    State* state;
    int second;

    Ball* initialize(int, int);
};

Ball* Ball::initialize(int a, int b)
{
    State* p = new State(this, b);
    first = a;
    second = b;
    state = p;
    table = ballTable;
    return this;
}
