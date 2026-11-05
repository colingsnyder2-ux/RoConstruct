// from server: 67% by atomic.potato
extern "C" int __cdecl RBX_Descriptor_create();
extern "C" void __cdecl RBX_sp_counted_impl_p_init(void*);

struct S_func_00618850 {
    char pad0[4];
    int m_value;
    S_func_00618850();
};

int g_0xc18314;

S_func_00618850::S_func_00618850()
{
    ++g_0xc18314;
    m_value = RBX_Descriptor_create();
    RBX_sp_counted_impl_p_init((char*)this + 4);
}
