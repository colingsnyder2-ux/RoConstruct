// from server: 89% by atomic.potato
extern "C" int __cdecl sub_7F4CE6(int, int, int);

struct MeshPartKey {
    int compare(const char* other, unsigned int len) const;
};

int MeshPartKey::compare(const char* other, unsigned int len) const {
    int result = 0x35;
    if (len > 0) {
        unsigned int n = len;
        const char* p;
        if (n > 0x35) {
            p = (const char*)&result;
        } else {
            p = (const char*)&n;
        }
        int v = *(const int*)p;
        sub_7F4CE6((int)this, (int)other, v);
        return v;
    }
    return result;
}
