// from server: 100% by king_originala
struct Kernel {
    void removeJoint();
    void release();
};

struct Joint {
    virtual ~Joint();
};

struct Pair {
    void* first;
    void* second;
};

struct MultiJoint {
    unsigned char padding[0x88];
    int count;
    Pair pairs[4];
    Joint* joints[4];

    Kernel* lookup(void*);
    void finish();
    void clear();
};

void MultiJoint::clear()
{
    for (int i = 0; i < count; ++i) {
        lookup(joints[i])->removeJoint();
        delete joints[i];
        lookup(pairs[i].first)->release();
        lookup(pairs[i].second)->release();
        pairs[i].first = 0;
        pairs[i].second = 0;
        joints[i] = 0;
    }
    count = 0;
    finish();
}
