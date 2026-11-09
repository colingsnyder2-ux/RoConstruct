// from server: 100% by colin
struct CXTPImageManager {
    void* findImage(int);
    void* findImage2(int);
    void* addImage(int, int);
    void* getImage(int);
    void* setImage(int, int);
};

void* CXTPImageManager::setImage(int a, int b) {
    void* p = findImage(a);
    if (p) {
        return ((CXTPImageManager*)p)->addImage(b, 1);
    }
    void* q = findImage2(a);
    if (q) {
        return ((CXTPImageManager*)q)->getImage(a);
    }
    return 0;
}
