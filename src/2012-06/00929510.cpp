// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00401910  unit: CAboutRobloxDialog  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401910
//
// 00401910  b801000000           mov eax, 1
// 00401915  84053c63e100         test byte ptr [0xe1633c], al
// 0040191b  7548                 jne 0x401965
// 0040191d  09053c63e100         or dword ptr [0xe1633c], eax
// 00401923  680c63e100           push 0xe1630c
// 00401928  ff15dc21b200         call dword ptr [0xb221dc]
// 0040192e  33c0                 xor eax, eax
// 00401930  a32463e100           mov dword ptr [0xe16324], eax
// 00401935  a32863e100           mov dword ptr [0xe16328], eax
// 0040193a  a32c63e100           mov dword ptr [0xe1632c], eax
// 0040193f  b820000000           mov eax, 0x20
// 00401944  689013b100           push 0xb11390
// 00401949  c7053063e10018000000 mov dword ptr [0xe16330], 0x18
// 00401953  a33463e100           mov dword ptr [0xe16334], eax
// 00401958  a33863e100           mov dword ptr [0xe16338], eax
// 0040195d  e893185800           call 0x9831f5
// 00401962  83c404               add esp, 4
// 00401965  b80c63e100           mov eax, 0xe1630c
// 0040196a  c3                   ret 

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
extern "C" void __cdecl func_009831f5(void*);

struct CAboutRobloxDialog
{
    static CAboutRobloxDialog* GetInstance();
};

CAboutRobloxDialog* CAboutRobloxDialog::GetInstance()
{
    static int initFlag;
    static char section[24];
    static int field24;
    static int field28;
    static int field2c;
    static int field30;
    static int field34;
    static int field38;

    if ((initFlag & 1) == 0)
    {
        initFlag |= 1;
        InitializeCriticalSection(section);
        field24 = 0;
        field28 = 0;
        field2c = 0;
        field30 = 0xa0;
        field34 = 0x20;
        field38 = 0x20;
        func_009831f5((void*)0xb11390);
    }
    return (CAboutRobloxDialog*)section;
}
