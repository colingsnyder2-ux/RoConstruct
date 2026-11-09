// from server: 100% by atomic.potato
extern "C" int __cdecl UniversalTool(void *, void *, void *);

int function(int a, int b)
{
    extern int global;
    return UniversalTool((void *)a, (void *)b, (void *)global);
}
