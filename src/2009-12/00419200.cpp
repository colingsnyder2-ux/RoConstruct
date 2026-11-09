// from server: 66% by atomic.potato
struct XDocHostUIHandler {
    int ShowContextMenu(unsigned int id, void* pcmdtReserved, void* pdispReserved);
};

int XDocHostUIHandler::ShowContextMenu(unsigned int id, void* pcmdtReserved, void* pdispReserved)
{
    char* base = (char*)pcmdtReserved;
    int* p = *(int**)(base - 0xcc);
    int* q = *(int**)((char*)p + 0x20);
    int* vtbl = *(int**)q;
    int (__stdcall *fn)(void*, unsigned int, void*, void*) = *(int (__stdcall **)(void*, unsigned int, void*, void*))((char*)vtbl + 0x1bc);
    return fn(q, id, pcmdtReserved, pdispReserved);
}
