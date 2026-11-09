// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 005c3fd0  unit: RBX::Profiling::Profiler  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c3fd0
//
// 005c3fd0  56                   push esi
// 005c3fd1  8bf1                 mov esi, ecx
// 005c3fd3  e8f843f4ff           call 0x5083d0
// 005c3fd8  d9c0                 fld st(0)
// 005c3fda  dca618c00000         fsub qword ptr [esi + 0xc018]
// 005c3fe0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c3fe4  8bd1                 mov edx, ecx
// 005c3fe6  2b9640c00000         sub edx, dword ptr [esi + 0xc040]
// 005c3fec  dc5608               fcom qword ptr [esi + 8]
// 005c3fef  dfe0                 fnstsw ax
// 005c3ff1  f6c401               test ah, 1
// 005c3ff4  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c3ff7  753c                 jne 0x5c4035
// 005c3ff9  40                   inc eax
// 005c3ffa  25ff070000           and eax, 0x7ff
// 005c3fff  89542408             mov dword ptr [esp + 8], edx
// 005c4003  db442408             fild dword ptr [esp + 8]
// 005c4007  894610               mov dword ptr [esi + 0x10], eax
// 005c400a  85d2                 test edx, edx
// 005c400c  7d06                 jge 0x5c4014
// 005c400e  dc0540128100         fadd qword ptr [0x811240]
// 005c4014  8d0440               lea eax, [eax + eax*2]
// 005c4017  dd5cc620             fstp qword ptr [esi + eax*8 + 0x20]
// 005c401b  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c401e  40                   inc eax
// 005c401f  8d1440               lea edx, [eax + eax*2]
// 005c4022  dd1cd6               fstp qword ptr [esi + edx*8]
// 005c4025  898e40c00000         mov dword ptr [esi + 0xc040], ecx
// 005c402b  dd9e18c00000         fstp qword ptr [esi + 0xc018]
// 005c4031  5e                   pop esi
// 005c4032  c20400               ret 4
// 005c4035  8d0440               lea eax, [eax + eax*2]
// 005c4038  89542408             mov dword ptr [esp + 8], edx
// 005c403c  db442408             fild dword ptr [esp + 8]
// 005c4040  8d44c620             lea eax, [esi + eax*8 + 0x20]
// 005c4044  85d2                 test edx, edx
// 005c4046  7d06                 jge 0x5c404e
// 005c4048  dc0540128100         fadd qword ptr [0x811240]
// 005c404e  dc00                 fadd qword ptr [eax]
// 005c4050  dd18                 fstp qword ptr [eax]
// 005c4052  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c4055  40                   inc eax
// 005c4056  8d0440               lea eax, [eax + eax*2]
// 005c4059  dc04c6               fadd qword ptr [esi + eax*8]
// 005c405c  8d04c6               lea eax, [esi + eax*8]
// 005c405f  dd18                 fstp qword ptr [eax]
// 005c4061  898e40c00000         mov dword ptr [esi + 0xc040], ecx
// 005c4067  dd9e18c00000         fstp qword ptr [esi + 0xc018]
// 005c406d  5e                   pop esi
// 005c406e  c20400               ret 4

extern double __cdecl sampleTime();

struct Profiler
{
    char reserved0[8];
    double interval;
    unsigned int index;
    char reserved1[4];

    struct Entry
    {
        double elapsed;
        double count;
        double reserved;
    };

    Entry entries[2048];
    double lastTime;
    char reserved2[32];
    unsigned int lastCount;

    void update(unsigned int count);
};

void Profiler::update(unsigned int count)
{
    double now = sampleTime();
    double elapsed = now - lastTime;

    if (elapsed >= interval)
    {
        index = (index + 1) & 0x7ff;
        entries[index].count = count - lastCount;
        entries[index].elapsed = elapsed;
    }
    else
    {
        entries[index].count += count - lastCount;
        entries[index].elapsed += elapsed;
    }

    lastCount = count;
    lastTime = now;
}
