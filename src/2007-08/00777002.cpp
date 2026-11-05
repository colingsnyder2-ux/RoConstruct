// from server: 100% by colin
// roc 2007-08 00777002  unit: seg_00770000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00777002

extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap();

void __cdecl sub_630d23(void*);

void* g_8c9890;
unsigned char g_8c9894;
void* g_8c988c;

void __stdcall sub_777002()
{
    void* heap = GetProcessHeap();
    g_8c988c = (void*)0x7e50d0;
    g_8c9890 = heap;
    g_8c9894 = 0;
    sub_630d23((void*)0x77cd5e);
}
