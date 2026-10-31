// from server: 71% by Intel
struct CWrapperView;

extern "C" void __stdcall sub_4789b0(void* ecx, void* edx);

void __stdcall sub_436C70(CWrapperView* esi)
{
    void* eax = *reinterpret_cast<void**>(reinterpret_cast<char*>(esi) + 0x14);
    if (eax)
    {
        void* ecx = *reinterpret_cast<void**>(reinterpret_cast<char*>(eax) + 0xFC);
        int edx = *reinterpret_cast<int*>(reinterpret_cast<char*>(esi) + 8);
        if (edx >= 0)
        {
            int limit = *reinterpret_cast<int*>(reinterpret_cast<char*>(ecx) + 0x2C);
            if (edx < limit)
            {
                void** array = *reinterpret_cast<void***>(reinterpret_cast<char*>(ecx) + 0x28);
                eax = array[edx];
            }
            else
            {
                eax = 0;
            }
        }
        else
        {
            eax = 0;
        }
    }

    void* global = *reinterpret_cast<void**>(0xDB4930);
    sub_4789b0(eax, global);

    void** vtable = *reinterpret_cast<void***>(esi);
    void (*func)(CWrapperView*, int) = reinterpret_cast<void (*)(CWrapperView*, int)>(vtable[1]);
    func(esi, 1);
}
