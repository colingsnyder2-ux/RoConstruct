// from server: 100% by atomic.potato
struct VCContent {
    int CompareContent(const void* unused, const void* other);
};

extern const unsigned int g_content0;
extern const unsigned int g_content1;
extern const unsigned int g_content2;
extern const unsigned int g_content3;

int VCContent::CompareContent(const void* unused, const void* other) {
    const unsigned int* p = (const unsigned int*)other;
    int result;
    if (p[0] == g_content0 &&
        p[1] == g_content1 &&
        p[2] == g_content2 &&
        p[3] == g_content3) {
        result = 1;
    } else {
        result = 0;
    }
    return !result;
}
