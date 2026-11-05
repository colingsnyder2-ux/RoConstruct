// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int __cdecl f(unsigned int value)
{
    switch (value)
    {
    case 0: return 21;
    case 1: return 70;
    case 2: return 80;
    case 3: return 443;
    case 7: return 1080;
    default: return 0;
    }
}