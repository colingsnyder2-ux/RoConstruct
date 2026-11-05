// from server: 100% by colin
// roc 2008-06 0040e4b0  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e4b0
//
// 0040e4b0  83790400             cmp dword ptr [ecx + 4], 0
// 0040e4b4  7e0a                 jle 0x40e4c0
// 0040e4b6  8b01                 mov eax, dword ptr [ecx]
// 0040e4b8  50                   push eax
// 0040e4b9  ff15c0288000         call dword ptr [0x8028c0]
// 0040e4bf  59                   pop ecx
// 0040e4c0  c3                   ret 

extern "C" void (__cdecl *free)(void *);

struct Buffer {
    void *data;
    int count;
    void release();
};

void Buffer::release()
{
    if (count > 0)
        free(data);
}
