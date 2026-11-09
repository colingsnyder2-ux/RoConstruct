// from server: 47% by Intel
struct Vector3 {
    float x, y, z;
};

extern "C" void* __cdecl sub_833810(void* a1, int a2, void* a3);
extern "C" void __cdecl sub_8322a0(int a1, void* a2);

int* g_global_ptr = (int*)0xDE13B0;

int sub_843F10(void* a1) {
    void* v1 = sub_833810(g_global_ptr, 2, a1);
    void* v2 = sub_833810(g_global_ptr, 1, a1);
    Vector3* vec1 = (Vector3*)v2;
    Vector3* vec2 = (Vector3*)v1;

    int result = 0;
    if (!(*(unsigned int*)&vec1->x & 0x7F800000) && !(*(unsigned int*)&vec2->x & 0x7F800000)) {
        if (vec1->x == vec2->x) {
            if (!(*(unsigned int*)&vec1->y & 0x7F800000) && !(*(unsigned int*)&vec2->y & 0x7F800000)) {
                if (vec1->y == vec2->y) {
                    if (!(*(unsigned int*)&vec1->z & 0x7F800000) && !(*(unsigned int*)&vec2->z & 0x7F800000)) {
                        if (vec1->z == vec2->z) {
                            result = 1;
                        }
                    }
                }
            }
        }
    }

    sub_8322a0(result, a1);
    return 1;
}
