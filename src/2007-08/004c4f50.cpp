// from server: 100% by colin
struct RakPeer {
    unsigned int mUnknown0;
    unsigned int mStart;
    unsigned int mEnd;
    unsigned int mCapacity;
    unsigned int size() const;
};

unsigned int RakPeer::size() const {
    unsigned int start = mStart;
    unsigned int end = mEnd;
    if (start <= end) {
        return end - start;
    }
    return mCapacity - start + end;
}
