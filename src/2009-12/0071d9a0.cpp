// from server: 63% by atomic.potato
struct RBX_Instance {
    char pad[0x4c];
    void* field_4c;
};

extern "C" void* __stdcall sub_7f4aaa(void*, int, void*, void*, int);

struct RBX_VDataModelMesh {
    char pad[0x4c];
    void* field_4c;
    float getValue();
};

float RBX_VDataModelMesh::getValue()
{
    void* p = field_4c;
    if (p) {
        void* r = sub_7f4aaa(p, 0, (void*)0xaffe40, (void*)0xb03a58, 0);
        if (r) {
            float one = 1.0f;
            return one - (one - *(float*)((char*)r + 0x178)) * *(float*)((char*)r + 0x1bc);
        }
    }
    return 0.0f;
}
