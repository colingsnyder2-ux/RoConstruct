// from server: 40% by atomic.potato
extern "C" void __cdecl func_007a8ade(void *, unsigned int, unsigned int, const void *);

struct seg_009a0000
{
    void f();
};

void seg_009a0000::f()
{
    char local_buffer[0x1b4];
    func_007a8ade(local_buffer, 0x30, 2, (const void *)0x4545b0);
}
