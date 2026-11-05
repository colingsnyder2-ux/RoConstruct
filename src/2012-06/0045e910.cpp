// from server: 100% by atomic.potato
struct FaceComparable {
    bool equals(void* p);
};

struct FacesComponentItem {
    char pad[0x128];
    void* field_128;
    bool compare(void* a, void* b);
};

bool FacesComponentItem::compare(void* a, void* b) {
    FaceComparable* lhs = (FaceComparable*)a;
    FaceComparable* rhs = (FaceComparable*)b;
    bool r1 = lhs->equals(field_128);
    bool r2 = rhs->equals(field_128);
    return r1 == r2;
}
