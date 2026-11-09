// from server: 49% by colin
struct AggregateChunk {
    void* field0;
    void* field4;
    void* field8;
    void clear();
};

extern "C" int __stdcall InterlockedDecrement(int*);
extern "C" void __stdcall sub_457DD0(void*);

void AggregateChunk::clear()
{
    if (field8) {
        if (InterlockedDecrement((int*)field8 + 1) == 0) {
            sub_457DD0(field8);
            if (field8) {
                void** v = *(void***)field8;
                void (*fn)(void*, int) = (void (*)(void*, int))v[0];
                fn(field8, 1);
            }
        }
        field8 = 0;
    }
    if (field4) {
        if (InterlockedDecrement((int*)field4 + 1) == 0) {
            sub_457DD0(field4);
            if (field4) {
                void** v = *(void***)field4;
                void (*fn)(void*, int) = (void (*)(void*, int))v[0];
                fn(field4, 1);
            }
        }
        field4 = 0;
    }
    if (field0) {
        if (InterlockedDecrement((int*)field0 + 1) == 0) {
            sub_457DD0(field0);
            if (field0) {
                void** v = *(void***)field0;
                void (*fn)(void*, int) = (void (*)(void*, int))v[0];
                fn(field0, 1);
            }
        }
        field0 = 0;
    }
}
