// from server: 100% by tajop


struct Module {
    long Invoke(void *a, void *b, void *c, void *d, void *e);
};

extern Module g_module;

long __stdcall ForwardToModule(void *self, void *a, void *b, void *c, void *d, void *e)
{
    return g_module.Invoke(a, b, c, d, e);
}
