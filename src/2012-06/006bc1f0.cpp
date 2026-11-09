// from server: 100% by atomic.potato
extern "C" bool __cdecl G1_func_006bbda0(void *);
extern "C" bool __cdecl G1_func_006bb1b0(void *);

bool G1_func_006bc1f0(void *value)
{
    if (G1_func_006bbda0(value))
        return true;
    return G1_func_006bb1b0(value) ? true : false;
}
