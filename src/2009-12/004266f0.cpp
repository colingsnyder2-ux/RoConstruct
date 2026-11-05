// from server: 33% by atomic.potato
extern "C" void destroy_string(void*);

void __stdcall Function004266f0(void* a0, void* a1)
{
    char local[1];
    local[0] = 2;
    destroy_string(&local[0]);
}
