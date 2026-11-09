// from server: 100% by king_originala
extern const char G1[];
extern const char G2[];
extern const char G3[];

struct S
{
    char storage[16];
    S(const char*, const char*, const char*);
    ~S();
};

S* func_005eccf0()
{
    static S instance(G1, G2, G3);
    return &instance;
}
