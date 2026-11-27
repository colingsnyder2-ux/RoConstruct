// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
int convert(int a)
{
    switch (a)
    {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 0;
    case 4: return 1;
    case 5: return 2;
    default: return -1;
    }
}