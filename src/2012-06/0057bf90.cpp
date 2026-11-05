// from server: 46% by Intel
struct Vector3 {
    float x, y, z;
};

struct InstanceItem {
    char pad[4];
    Vector3 position;
};

extern "C" InstanceItem* __cdecl GetInstanceItem(int);
extern "C" void __cdecl ProcessItem(Vector3*, int, Vector3*);

void __cdecl NewInstanceItem(int a1, int a2, Vector3* a3) {
    InstanceItem* item = GetInstanceItem(a1);
    Vector3 pos = item->position;
    ProcessItem(&pos, a2, a3);
}
