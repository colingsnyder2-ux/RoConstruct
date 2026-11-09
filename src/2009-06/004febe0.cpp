// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 004bbd90  unit: ProfiledRakPeer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbd90
//
// 004bbd90  51                   push ecx
// 004bbd91  8b81d4060000         mov eax, dword ptr [ecx + 0x6d4]
// 004bbd97  85c0                 test eax, eax
// 004bbd99  762a                 jbe 0x4bbdc5
// 004bbd9b  8b89dc060000         mov ecx, dword ptr [ecx + 0x6dc]
// 004bbda1  890c24               mov dword ptr [esp], ecx
// 004bbda4  db0424               fild dword ptr [esp]
// 004bbda7  85c9                 test ecx, ecx
// 004bbda9  7d06                 jge 0x4bbdb1
// 004bbdab  d80578978100         fadd dword ptr [0x819778]
// 004bbdb1  890424               mov dword ptr [esp], eax
// 004bbdb4  db0424               fild dword ptr [esp]
// 004bbdb7  85c0                 test eax, eax
// 004bbdb9  7d06                 jge 0x4bbdc1
// 004bbdbb  d80578978100         fadd dword ptr [0x819778]
// 004bbdc1  def9                 fdivp st(1)
// 004bbdc3  59                   pop ecx
// 004bbdc4  c3                   ret 
// 004bbdc5  d9ee                 fldz 
// 004bbdc7  59                   pop ecx
// 004bbdc8  c3                   ret 

struct ProfiledRakPeer
{
    char padding[0x9fc];
    unsigned int denominator;
    unsigned int unused;
    unsigned int numerator;
    double getAverage();
};
double ProfiledRakPeer::getAverage()
{
    if (denominator > 0) return (float)numerator / (float)denominator; return 0.0;
}
