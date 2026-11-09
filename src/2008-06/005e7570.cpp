// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct Ball {
    void* bulletSphereShape;
    int getBulletSphereShape() const;
};

int Ball::getBulletSphereShape() const {
    void* p = *(void**)((char*)this + 0x5c);
    if (p) {
        return *(int*)((char*)p + 0x24);
    }
    return 0;
}
