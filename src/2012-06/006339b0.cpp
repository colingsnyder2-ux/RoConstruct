// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int uint32;
namespace G3D {
class Random {
protected:
    enum { N = 624, M = 397, R = 31, U = 11, S = 7, T = 15, L = 18,
        A = 0x9908B0DF, B = 0x9D2C5680, C = 0xEFC60000 };
    volatile long lock;
    uint32* state;
    int index;
    virtual void generate();
public:
    virtual ~Random();
    virtual uint32 bits();
};
Random::~Random() {
    delete[] state;
    state = 0;
}
uint32 Random::bits() {
    int localIndex = index;
    if ((unsigned int)localIndex >= (unsigned int)N) {
        generate();
        localIndex = 0;
    }
    ++index;
    uint32 r = state[localIndex];
    r ^=  r >> U;
    r ^= (r << S) & B;
    r ^= (r << T) & C;
    r ^=  r >> L;
    return r;
}
}