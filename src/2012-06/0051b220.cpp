// from server: 100% by Intel
struct Ogre_istreamDataStream {
    bool isEOF();
};

bool Ogre_istreamDataStream::isEOF() {
    return *(char*)((char*)this + 0xc0) == 0;
}
