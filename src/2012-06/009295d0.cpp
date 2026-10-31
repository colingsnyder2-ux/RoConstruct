// from server: 56% by Intel
typedef void __stdcall InitializeCriticalSection_t(void* lpCriticalSection);
extern "C" InitializeCriticalSection_t InitializeCriticalSection;

extern "C" void __cdecl sub_9831f5(int);

int* dword_E56CFC = (int*)0xE56CFC;
int* dword_E56D00 = (int*)0xE56D00;
int* dword_E56D04 = (int*)0xE56D04;
int* dword_E56D08 = (int*)0xE56D08;
int* dword_E56D0C = (int*)0xE56D0C;
int* dword_E56D10 = (int*)0xE56D10;
unsigned char* byte_E56D14 = (unsigned char*)0xE56D14;
void* criticalSection_E56CE4 = (void*)0xE56CE4;
int* dword_B21340 = (int*)0xB21340;

int __cdecl sub_9295D0()
{
    if (*byte_E56D14)
    {
        return 0xE56CE4;
    }

    *byte_E56D14 = 1;
    InitializeCriticalSection(criticalSection_E56CE4);

    *dword_E56CFC = 0;
    *dword_E56D00 = 0;
    *dword_E56D04 = 0;

    *dword_E56D08 = 0x84;
    *dword_E56D0C = 0x20;
    *dword_E56D10 = 0x20;

    sub_9831f5(*dword_B21340);

    return 0xE56CE4;
}
