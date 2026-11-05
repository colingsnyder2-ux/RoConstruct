// from server: 71% by atomic.potato
extern "C" void __cdecl std_exception_ctor(void *, const char *);
extern "C" void __cdecl rbx_throw(void *, const char *);

void getEdgeList(void *, void *)
{
    char exception_object[16];
    std_exception_ctor(exception_object,
        "RBX RbxSubEntity::getEdgeList(): should not be called");
    rbx_throw(exception_object, "RBX RbxSubEntity::getEdgeList(): should not be called");
}
