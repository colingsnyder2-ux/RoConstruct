// from server: 75% by atomic.potato
struct RakPeer {
    void* field0;
    int* field4;
    void Clear();
};

extern "C" void __stdcall sub_5C93E0(void*);
extern "C" void __stdcall sub_982114(void*);

void RakPeer::Clear()
{
    int* p = field4;
    if (p != 0) {
        if (--*p == 0) {
            void* q = field0;
            if (q != 0) {
                sub_5C93E0(q);
                sub_982114(q);
            }
            p = field4;
            if (p != 0) {
                sub_982114(p);
            }
        }
    }
    field4 = 0;
    field0 = 0;
}
