// from server: 72% by Intel
struct NodeVisitor {
    short level;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct SpatialHash {
    int getSpatialNodeLevel();
};

extern "C" int __stdcall sub_972290(const char*, int);
extern "C" int __stdcall sub_50C4B0(SpatialHash*);

int __stdcall sub_50C8C0(NodeVisitor* node, int a2, SpatialHash* p, int a4, int a5) {
    static int flag = 0;
    static int global_ptr = 0;
    static const char* str1 = (const char*)0xB6C338;
    static const char* str2 = (const char*)0xB6C360;
    static const char* str3 = (const char*)0xB6C2A0;

    if (flag) {
        int level = sub_50C4B0(p);
        if (node->level != level) {
            if (global_ptr) {
                if (sub_972290(str1, 0xC5)) {
                    goto LABEL_RETURN;
                }
            }
            sub_972290(str3, flag);
        }
    }

LABEL_RETURN:
    node->field_14 = a4;
    int* src = (int*)a5;
    node->field_8 = src[0];
    node->field_C = src[1];
    node->field_10 = src[2];
    node->field_4 = a2;
    return 0;
}
