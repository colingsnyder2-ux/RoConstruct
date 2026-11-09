// from server: 100% by colin
struct VCApp_CComObject {
    int method(int unused, short* out);
};

extern VCApp_CComObject* g_ptr_8bbe8c;

int VCApp_CComObject::method(int unused, short* out)
{
    int v = *(int*)(*(char**)g_ptr_8bbe8c + 0x10);
    *out = (short)(v != 0 ? 0xFFFF : 0);
    return 0;
}
