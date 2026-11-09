// from server: 32% by atomic.potato
struct RBX_BallBallContact {
    char pad0[0x30];
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    bool overlaps(const RBX_BallBallContact* other) const;
};

bool RBX_BallBallContact::overlaps(const RBX_BallBallContact* other) const {
    if (f48 != other->f48) {
        if (f30 > other->f3c) return false;
        if (f34 > other->f40) return false;
        if (f38 > other->f44) return false;
        if (f40 < other->f34) return false;
        if (f3c < other->f30) return false;
        if (f44 < other->f38) return false;
        return true;
    }
    const RBX_BallBallContact* a;
    const RBX_BallBallContact* b;
    if (f48 > other->f48) {
        a = this;
        b = other;
    } else {
        a = other;
        b = this;
    }
    int shift = a->f48 - b->f48;
    int a30 = a->f30 >> shift;
    int a34 = a->f34 >> shift;
    int a38 = a->f38 >> shift;
    int a3c = a->f3c >> shift;
    int a40 = a->f40 >> shift;
    int a44 = a->f44 >> shift;
    if (b->f30 > a3c) return false;
    if (b->f34 > a40) return false;
    if (b->f38 > a44) return false;
    if (b->f40 < a34) return false;
    if (b->f3c < a30) return false;
    if (b->f44 < a38) return false;
    return true;
}
