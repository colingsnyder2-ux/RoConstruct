// from server: 11% by atomic.potato
struct Sub {
    char pad[4];
    void init(int);
};

struct AnimationTrack {
    char pad0[4];
    Sub sub;
    void* func(int, int);
};

void Sub::init(int) {}

void* AnimationTrack::func(int a, int b) {
    sub.init(1);
    return (void*)0;
}
