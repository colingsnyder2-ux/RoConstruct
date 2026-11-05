// from server: 33% by atomic.potato
struct Sub {
    char pad[4];
    void init(int);
};

struct AnimationTrack {
    char pad0[4];
    Sub sub;
    void* f(int, int);
};

void* AnimationTrack::f(int a, int b) {
    sub.init(1);
    return (void*)a;
}
