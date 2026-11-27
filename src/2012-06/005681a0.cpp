// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
bool swapNeeded();
struct BS {
    unsigned bits; int pad[2]; unsigned char* buf;
    void reserve(int n);
    void write16(const unsigned char* p);
};
void BS::write16(const unsigned char* p) {
    reserve(16);
    if (swapNeeded()) {
        buf[bits >> 3] = p[1];
        buf[(bits >> 3) + 1] = p[0];
    } else {
        buf[bits >> 3] = p[0];
        buf[(bits >> 3) + 1] = p[1];
    }
    bits += 16;
}