// from server: 100% by king_originala
struct TypeDescriptor
{
    unsigned long vtable;
    unsigned long spare;
    char name[sizeof(".?AV?$bind_t@XV?$mf1@XVSeat@RBX@@_N@_mfi@boost@@V?$list2@V?$value@PAVSeat@RBX@@@_bi@boost@@V?$arg@$00@3@@_bi@3@@_bi@boost@@")];
};

static const TypeDescriptor functor_type = {
    0x00850180UL,
    0,
    ".?AV?$bind_t@XV?$mf1@XVSeat@RBX@@_N@_mfi@boost@@V?$list2@V?$value@PAVSeat@RBX@@@_bi@boost@@V?$arg@$00@3@@_bi@3@@_bi@boost@@"
};

typedef bool (__thiscall *TypeEqual)(const void*, const void*);
extern TypeEqual type_equal;

struct Functor
{
    unsigned long words[6];
};

union FunctionBuffer
{
    void* obj_ptr;
    const void* const_obj_ptr;
    mutable char data;
};

void __cdecl manager(const FunctionBuffer& in_buffer,
                     FunctionBuffer& out_buffer, int op)
{
    if (op == 0) {
        if (&out_buffer != 0)
            *reinterpret_cast<Functor*>(&out_buffer.data) =
                *reinterpret_cast<const Functor*>(&in_buffer.data);
    } else if (op != 1) {
        if (type_equal(out_buffer.const_obj_ptr, &functor_type))
            out_buffer.obj_ptr = &in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    }
}
