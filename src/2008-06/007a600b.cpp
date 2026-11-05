// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /hotpatch /O1 /GS- /EHsc /MD
// from server: 73% by king_originala
extern "C" void __cdecl FreeThunkData(void*);
extern "C" int __cdecl InitializeThunkHeap();

extern unsigned long thunkHeap;
extern void* (__stdcall *allocateThunk)(unsigned long);
extern void (__stdcall *releaseThunk)(unsigned long, void*);

extern unsigned long (__stdcall *GetProcessHeap)();
extern void* (__stdcall *HeapAlloc)(unsigned long, unsigned long, unsigned long);
extern void* (__stdcall *VirtualAlloc)(void*, unsigned long, unsigned long, unsigned long);
extern int (__stdcall *VirtualFree)(void*, unsigned long, unsigned long);

#pragma optimize("y", off)
extern "C" void __stdcall FreeThunk(void* data)
{
    FreeThunkData(data);
}
#pragma optimize("y", on)
#pragma optimize("s", on)

extern "C" void* __cdecl AllocateThunk()
{
    unsigned char* page;
    unsigned char* result;

    if (thunkHeap == 0)
    {
        if (!InitializeThunkHeap())
            goto failure;
    }

    if (thunkHeap == 1)
    {
        result = (unsigned char*)HeapAlloc(GetProcessHeap(), 0, 13);
        if (!result)
            goto failure;
        return result;
    }

    result = (unsigned char*)allocateThunk(thunkHeap);
    if (result)
        return result;

    page = (unsigned char*)VirtualAlloc(0, 4096, 4096, 64);
    if (!page)
    {
failure:
        return 0;
    }

    (void)*(volatile unsigned long*)page;
    result = (unsigned char*)allocateThunk(thunkHeap);
    if (result)
    {
        VirtualFree(page, 0, 32768);
    }
    else
    {
        result = page;
        page += 4080;
        do
        {
            releaseThunk(thunkHeap, result);
            result += 16;
        } while (result < page);
    }
    return result;
}
