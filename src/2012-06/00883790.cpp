// from server: 100% by tajop
struct type_info {
    __declspec(dllimport) bool operator==(const type_info&) const;
};

extern type_info type_info_00de83d8;

void* __cdecl operator new(unsigned int);
inline void* operator new(unsigned int, void* p) { return p; }

struct Functor {
    char storage[0x20];
    Functor(const Functor&);
    void* scalar_deleting_dtor(unsigned int);
};

union function_buffer {
    void* obj_ptr;
    struct {
        const type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
};

void __cdecl functor_manager_manage(const function_buffer& in_buffer,
                                    function_buffer& out_buffer, int op)
{
    if (op == 0) {
        const Functor* f = (const Functor*)in_buffer.obj_ptr;
        void* mem = operator new(0x20);
        out_buffer.obj_ptr = mem ? new (mem) Functor(*f) : 0;
    } else if (op == 1) {
        out_buffer.obj_ptr = in_buffer.obj_ptr;
        const_cast<function_buffer&>(in_buffer).obj_ptr = 0;
    } else if (op == 2) {
        Functor* f = (Functor*)out_buffer.obj_ptr;
        if (f)
            f->scalar_deleting_dtor(1);
        out_buffer.obj_ptr = 0;
    } else if (op == 3) {
        if (*out_buffer.type.type == type_info_00de83d8)
            out_buffer.obj_ptr = in_buffer.obj_ptr;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_info_00de83d8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
