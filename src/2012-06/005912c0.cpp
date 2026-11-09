// from server: 100% by intel
struct VServerReplicator {
    void* field0;
    char pad[4];
    int field8;
    int fieldC;
    void Setter(int a, int b);
};

extern "C" bool __cdecl func_00880f30(void* out);

void VServerReplicator::Setter(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!func_00880f30(local)) {
        int* p = (int*)((char*)this + 8);
        if (p) {
            p[0] = local[0];
            p[1] = local[1];
        }
        field0 = (void*)0xd8dc30;
    } else {
        field0 = 0;
    }
}
