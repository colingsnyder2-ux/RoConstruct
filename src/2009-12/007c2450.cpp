// from server: 25% by atomic.potato
struct VChatLine_sp_counted_impl_p {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    int field18;
    int field1C;
    void sort(void* a, void* b);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void VChatLine_sp_counted_impl_p::sort(void* a, void* b) {
    int start = field18;
    int end = field1C + start;
    if (start > end)
        _invalid_parameter_noinfo();
    void* first = a;
    void* last = b;
    void* base = field0;
    if (first != last) {
        int i = start + (int)first;
        int j = start + (int)last;
        while (1) {
            last = (void*)((int)last - 1);
            first = (void*)((int)first - 1);
            if (first == last)
                break;
            void* p = base;
            if (p == 0) {
                _invalid_parameter_noinfo();
                p = 0;
            }
            if ((int)last > (int)p + field1C)
                _invalid_parameter_noinfo();
            void* tmp1[2];
            tmp1[0] = p;
            tmp1[1] = last;
            void* r1 = (void*)0x740bf0;
            void* q = base;
            if (q == 0) {
                _invalid_parameter_noinfo();
                q = 0;
            }
            if (i > (int)q + field1C)
                _invalid_parameter_noinfo();
            void* tmp2[2];
            tmp2[0] = q;
            tmp2[1] = (void*)i;
            void* r2 = (void*)0x740bf0;
            if (r1 != r2) {
                void* t = *(void**)r1;
                *(void**)r1 = *(void**)r2;
                *(void**)r2 = t;
            }
            *(void**)((int)r1 + 4) = *(void**)((int)r2 + 4);
            *(void**)((int)r2 + 4) = *(void**)((int)r1 + 4);
            i++;
            j++;
            if (i == end)
                break;
        }
    }
}
