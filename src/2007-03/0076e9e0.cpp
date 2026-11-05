// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" void* __cdecl sub_52D8E0(void*, int);

void* g_8B75FC;

void* sub_76E9E0()
{
    g_8B75FC = sub_52D8E0((void*)0x795564, -1);
    return g_8B75FC;
}
