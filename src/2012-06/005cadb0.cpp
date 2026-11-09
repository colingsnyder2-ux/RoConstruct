// from server: 100% by Intel
struct Ogre_istreamDataStream {
    char pad[104];
    int field_68;
    void Release(int);
};

void Ogre_istreamDataStream::Release(int) {
    --field_68;
}
