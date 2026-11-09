// from server: 39% by colin
extern "C" void __cdecl _invalid_parameter_noinfo(void);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl construct_range(void*, void*, void*, void*, void*, void*);

struct SlotVector {
    void* begin;
    void* end;
    void* capacity;
    void assign(unsigned int count, void* value);
};

void SlotVector::assign(unsigned int count, void* value) {
    if (count == 0) {
        begin = 0;
        end = 0;
        capacity = 0;
        return;
    }
    if (count > 0x3fffffff) {
        _invalid_parameter_noinfo();
    }
    void* mem = operator_new(count * 4);
    begin = mem;
    end = mem;
    capacity = (char*)mem + count * 4;
    construct_range(mem, mem, value, value, (void*)this, (void*)count);
    end = (char*)mem + count * 4;
}
