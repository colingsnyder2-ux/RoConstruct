// from server: 66% by Intel
struct EventReplicator {
    int method(int* a1, int a2, int a3);
};

int EventReplicator::method(int* a1, int a2, int a3) {
    int* v4 = 0;
    if (a1) {
        int v5 = a3;
        int v6 = *(int*)((char*)this + 0x2C);
        int v7 = a2;
        int v8 = (int)a1 - 0x1C;
        v6 += v8;
        int v9 = ((int(__thiscall*)(int, int, int))0x8D5D70)(v6, v7, v5);
        return v7;
    }
    *a1 = 0;
    return 0;
}
