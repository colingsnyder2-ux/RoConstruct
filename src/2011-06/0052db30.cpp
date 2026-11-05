// from server: 93% by atomic.potato
// roc 2007-03 0052db30  unit: seg_00520000  size: 97 bytes
// library raknet-4.081/RPCMap.cpp

extern "C" void __cdecl sub_80A058(void*);
extern "C" void __cdecl sub_80A304(void*);
extern "C" void __cdecl sub_C2EE8C(int, const char*, int);

struct ProfiledRakPeer {
    void** data;
    unsigned int count;
    unsigned int capacity;
    void clear();
};

void ProfiledRakPeer::clear() {
    unsigned int i = 0;
    if (count > 0) {
        do {
            void* p = data[i];
            if (p) {
                sub_C2EE8C(*(int*)p, ".\\raknet\\Source\\RPCMap.cpp", 0x1b);
                sub_80A058(p);
            }
            i++;
        } while (i < count);
    }
    if (capacity) {
        sub_80A304(data);
        capacity = 0;
        data = 0;
        count = 0;
    }
}
