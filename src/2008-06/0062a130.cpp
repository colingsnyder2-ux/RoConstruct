// from server: 100% by king_originala
struct S {
    int reserved[2];
    int offset;
    float get(void* object);
};

float S::get(void* object) {
    char* base = object ? (char*)object - 20 : 0;
    return *(float*)(base + offset);
}
