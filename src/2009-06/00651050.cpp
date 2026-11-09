// from server: 97% by EspClaude
// from server: 83% by EspClaude
// roc 2009-06 00651050  unit: RBX::VExplosion::?$EventDesc  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00651050
//
// 00651050  56                   push esi
// 00651051  8bf1                 mov esi, ecx
// 00651053  c7064cf98d00         mov dword ptr [esi], 0x8df94c
// 00651059  dd05d8ffa000         fld qword ptr [0xa0ffd8]
// 0065105f  dd5e08               fstp qword ptr [esi + 8]
// 00651062  33d2                 xor edx, edx
// 00651064  d9ee                 fldz 
// 00651066  895610               mov dword ptr [esi + 0x10], edx
// 00651069  8d4618               lea eax, [esi + 0x18]
// 0065106c  b9ff070000           mov ecx, 0x7ff
// 00651071  dd10                 fst qword ptr [eax]
// 00651073  895010               mov dword ptr [eax + 0x10], edx
// 00651076  dd5008               fst qword ptr [eax + 8]
// 00651079  83c018               add eax, 0x18
// 0065107c  83e901               sub ecx, 1
// 0065107f  79f0                 jns 0x651071
// 00651081  8b442408             mov eax, dword ptr [esp + 8]
// 00651085  dd9e18c00000         fstp qword ptr [esi + 0xc018]
// 0065108b  50                   push eax
// 0065108c  8d8e20c00000         lea ecx, [esi + 0xc020]
// 00651092  ff15b4e48900         call dword ptr [0x89e4b4]
// 00651098  8bc6                 mov eax, esi
// 0065109a  5e                   pop esi
// 0065109b  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 005c4340  unit: RBX::Profiling::Profiler  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c4340
//
// 005c4340  56                   push esi
// 005c4341  8bf1                 mov esi, ecx
// 005c4343  c706548c8300         mov dword ptr [esi], 0x838c54
// 005c4349  dd0538f69400         fld qword ptr [0x94f638]
// 005c434f  33d2                 xor edx, edx
// 005c4351  dd5e08               fstp qword ptr [esi + 8]
// 005c4354  d9ee                 fldz 
// 005c4356  895610               mov dword ptr [esi + 0x10], edx
// 005c4359  8d4618               lea eax, [esi + 0x18]
// 005c435c  b9ff070000           mov ecx, 0x7ff
// 005c4361  dd10                 fst qword ptr [eax]
// 005c4363  895010               mov dword ptr [eax + 0x10], edx
// 005c4366  dd5008               fst qword ptr [eax + 8]
// 005c4369  83c018               add eax, 0x18
// 005c436c  83e901               sub ecx, 1
// 005c436f  79f0                 jns 0x5c4361
// 005c4371  ddd8                 fstp st(0)
// 005c4373  e85840f4ff           call 0x5083d0
// 005c4378  8b442408             mov eax, dword ptr [esp + 8]
// 005c437c  dd9e18c00000         fstp qword ptr [esi + 0xc018]
// 005c4382  50                   push eax
// 005c4383  8d8e20c00000         lea ecx, [esi + 0xc020]
// 005c4389  ff1558248000         call dword ptr [0x802458]
// 005c438f  8bc6                 mov eax, esi
// 005c4391  5e                   pop esi
// 005c4392  c20400               ret 4

extern const double initialValue;
extern double __cdecl currentTime();

typedef void* (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

struct Sample {
    double first;
    double second;
    int count;
};

struct Profiler {
    virtual void virtualFunction();
    double value;
    int count;
    Sample samples[2048];
    double startTime;
    char name[28];

    Profiler(const char*);
};

Profiler::Profiler(const char* text)
{
    value = initialValue;
    count = 0;

    Sample* sample = samples;
    int remaining = 2047;
    do {
        sample->first = 0.0;
        sample->count = 0;
        sample->second = 0.0;
        ++sample;
    } while (--remaining >= 0);

    startTime = 0.0;
    constructString(name, text);
}
