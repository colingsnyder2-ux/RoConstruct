// from server: 65% by Intel




extern "C" void __cdecl sub_982114(void*);

struct Replicator {
};

void __cdecl cleanupRange(void* start, void* end) {
    if (start == end)
        return;

    char* current = static_cast<char*>(start);
    char* limit = static_cast<char*>(end);

    do {
        void** ptr = reinterpret_cast<void**>(current + 0x1C);
        void* obj = *ptr;
        if (obj != 0) {
            sub_982114(obj);
            *ptr = 0;
        }
        ptr[1] = 0;
        ptr[2] = 0;
        current += 0x28;
    } while (current != limit);
}
