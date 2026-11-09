// from server: 35% by Intel
struct ThreadData {
    char data[0x28];
};

extern "C" void __cdecl construct_thread_data(ThreadData* dst, const ThreadData* src);

struct UPoolData {
};

void __cdecl copy_range(ThreadData* first, ThreadData* last, ThreadData* dest) {
    while (first != last) {
        construct_thread_data(dest, first);
        first = reinterpret_cast<ThreadData*>(reinterpret_cast<char*>(first) + 0x28);
        dest = reinterpret_cast<ThreadData*>(reinterpret_cast<char*>(dest) + 0x28);
    }
}
