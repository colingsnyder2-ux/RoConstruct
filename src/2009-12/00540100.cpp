// from server: 90% by atomic.potato
extern "C" void** __cdecl function_004fd680(void*);

void f(void** out, void* param)
{
    void** v = function_004fd680(param);
    *out = *v;
}
