// from server: 30% by atomic.potato
struct ManualJointSurfacePair {
    int compare(void* other);
};

int ManualJointSurfacePair::compare(void* other) {
    if (*(int*)((char*)this + 4) == 0)
        return 0;
    if (other == 0)
        return 0;
    int* a = *(int**)((char*)this + 4);
    int va = (*(int (**)(void))((*(int**)a) + 4))();
    int vb = (*(int (**)(void))((*(int**)other) + 4))();
    if (va > vb)
        return 1;
    return 0;
}
