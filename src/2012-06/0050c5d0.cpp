// from server: 100% by Intel
struct OgreRbxImage {
    void set();
};

void OgreRbxImage::set() {
    *(short*)this = -2;
    *(int*)(this + 4) = -2;
}
