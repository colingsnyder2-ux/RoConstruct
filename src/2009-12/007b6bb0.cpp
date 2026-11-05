// from server: 28% by atomic.potato
struct GlueJoint {
    int compare(void* other);
    int field0;
    void* field4;
};

int GlueJoint::compare(void* other) {
    if (field4 == 0)
        return 0;
    if (other == 0)
        return 0;
    void* a = field4;
    int (*fp1)(void*) = *(int (**)(void*))a;
    int v1 = fp1(a);
    int (*fp2)(void*) = *(int (**)(void*))other;
    int v2 = fp2(other);
    if (v1 > v2)
        return 1;
    return 0;
}
