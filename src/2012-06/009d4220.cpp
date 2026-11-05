// roc 2012-06 009d4220  unit: CXTPControlSelector  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d4220
//
// 009d4220  8b442404             mov eax, dword ptr [esp + 4]
// 009d4224  85c0                 test eax, eax
// 009d4226  7425                 je 0x9d424d
// 009d4228  83f8ff               cmp eax, -1
// 009d422b  7420                 je 0x9d424d
// 009d422d  8a08                 mov cl, byte ptr [eax]
// 009d422f  8bd0                 mov edx, eax
// 009d4231  84c9                 test cl, cl
// 009d4233  7415                 je 0x9d424a
// 009d4235  80f926               cmp cl, 0x26
// 009d4238  7505                 jne 0x9d423f
// 009d423a  384801               cmp byte ptr [eax + 1], cl
// 009d423d  7503                 jne 0x9d4242
// 009d423f  880a                 mov byte ptr [edx], cl
// 009d4241  42                   inc edx
// 009d4242  8a4801               mov cl, byte ptr [eax + 1]
// 009d4245  40                   inc eax
// 009d4246  84c9                 test cl, cl
// 009d4248  75eb                 jne 0x9d4235
// 009d424a  c60200               mov byte ptr [edx], 0
// 009d424d  c3                   ret 
// copied from an identical function in another client (function ?strip_ampersands@ns_ROCX000050@@YAPADPAD@Z)

namespace ns_ROCX000050 {
char* __cdecl strip_ampersands(char* p)
{
    if (p != 0 && p != (char*)-1)
    {
        char* d = p;
        char c = *p;
        if (c != 0)
        {
            do
            {
                if (c != '&' || p[1] == c)
                {
                    *d = c;
                    d++;
                }
                c = p[1];
                p++;
            } while (c != 0);
        }
        *d = 0;
    }
    return p;
}
}
