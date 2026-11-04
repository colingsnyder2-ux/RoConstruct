// from server: 31% by Intel
struct Assembly {
    int field_4;
    int field_14;
    int field_24;
    int field_30;
    short field_32;
    short field_34;
    int field_38;
    int func();
};

extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_7c2620(int, int*);
extern "C" int __stdcall sub_91b2b0(void*, int*, int);
extern "C" int __stdcall sub_91afb0(void*, int*);
extern "C" void __cdecl sub_982114(int);
extern "C" void __cdecl sub_62f170(int*);

int Assembly::func() {
    if (!*reinterpret_cast<char*>(0xE580B3))
        return 0;

    if (*reinterpret_cast<short*>(this + 0x32) == 1) {
        int v = *reinterpret_cast<int*>(0xE5809C);
        if (v) {
            int (__cdecl *fn)(int, int, int) = reinterpret_cast<int(__cdecl*)(int, int, int)>(v);
            if (fn(0x15, 0xBF5AD8, 0xBF610C))
                return 0;
        }
        sub_972290(*reinterpret_cast<char*>(0xE580B3), 0xBF6098);
    }

    if (!*reinterpret_cast<char*>(0xE580B3))
        return 0;

    short s34 = *reinterpret_cast<short*>(this + 0x34);
    if (s34 > 1 && s34 < 5)
        return 0;

    int v = *reinterpret_cast<int*>(0xE5809C);
    if (v) {
        int (__cdecl *fn)(int, int, int) = reinterpret_cast<int(__cdecl*)(int, int, int)>(v);
        if (fn(0x16, 0xBF5AD8, 0xBF6058))
            return 0;
    }
    sub_972290(*reinterpret_cast<char*>(0xE580B3), 0xBF5FB8);

    int i = 0;
    short s32 = *reinterpret_cast<short*>(this + 0x32);
    while (i < s32) {
        int eax;
        if (i > 0) {
            int ecx = *reinterpret_cast<int*>(this + 0x14);
            eax = i + ecx * 6 - 6;
        } else {
            int edx;
            sub_7c2620(*reinterpret_cast<int*>(this + 0x38), &edx);
            eax = edx;
        }

        int ecx_val = *reinterpret_cast<int*>(eax);
        short bp = *reinterpret_cast<short*>(eax + 4);
        int esi = s34;

        int eax_div = ecx_val;
        int edx_div = eax_div >> 31;
        int ebx = eax_div / esi;
        int edx_rem = eax_div % esi;
        int flag1 = edx_rem > 0 ? 1 : 0;

        int ecx_shr = ecx_val >> 16;
        eax_div = ecx_shr;
        edx_div = eax_div >> 31;
        int var18 = eax_div / esi;
        edx_rem = eax_div % esi;
        int flag2 = edx_rem > 0 ? 1 : 0;

        eax_div = bp;
        edx_div = eax_div >> 31;
        int var1c = eax_div / esi;
        edx_rem = eax_div % esi;
        int flag3 = edx_rem > 0 ? 1 : 0;

        ebx += var18;
        var18 += var1c;
        var1c += flag3;
        int ebp = var1c;
        int esi2 = i;
        int edx_z = var18;

        int eax_mul = esi2 * 3;
        int eax_ptr = *reinterpret_cast<int*>(this + 0x14) + eax_mul * 2;

        *reinterpret_cast<int*>(eax_ptr) = (ebp << 16) | (ebx & 0xFFFF);
        *reinterpret_cast<short*>(eax_ptr + 4) = static_cast<short>(edx_z);

        int ebx_pow = s34;
        int eax_inc = i + 1;
        int ebx_abs = eax_inc;
        if (eax_inc < 0) ebx_abs = -eax_inc;

        float xmm2 = *reinterpret_cast<float*>(0xB4C440);
        float xmm0 = xmm2;
        float xmm1 = static_cast<float>(ebx_pow);

        while (ebx_abs) {
            if (ebx_abs & 1)
                xmm0 *= xmm1;
            ebx_abs >>= 1;
            if (!ebx_abs) break;
            xmm1 *= xmm1;
        }

        if (eax_inc < 0)
            xmm1 = xmm2 / xmm0;
        else
            xmm1 = xmm0;

        int ebx_arr = *reinterpret_cast<int*>(this + 0x24);
        int ebp_mul = bp * edx_z;
        int eax_cvt = static_cast<int>(xmm1);
        *reinterpret_cast<short*>(ebx_arr + esi2 * 2) = static_cast<short>(eax_cvt);
        ebp_mul *= (ecx_val & 0xFFFF);
        int ebx_idx = ebp_mul + 31 >> 5;

        int var20 = 0;
        int var24 = ebx_idx;
        sub_91b2b0(this + 4, &var20, var24);

        if (ebp_mul != -1) {
            int ecx_v = var20;
            int edx_v = 0;
            int eax_v = ecx_v;
            eax_v -= edx_v;
            eax_v >>= 2;
            if (ebx_idx < eax_v) {
                int* ptr = reinterpret_cast<int*>(edx_v + ebx_idx * 4);
                if (ptr != reinterpret_cast<int*>(ecx_v)) {
                    var20 = reinterpret_cast<int>(ptr);
                }
            }
            int ecx_and = ebp_mul & 0x1F;
            if (ecx_and) {
                int mask = (1 << ecx_and) - 1;
                *reinterpret_cast<int*>(edx_v + ebx_idx * 4 - 4) &= mask;
            }

            int eax_f = *reinterpret_cast<int*>(this + 4);
            int ecx_lea = esi2 * 5;
            int eax_lea = eax_f + ecx_lea * 4;
            int* ecx_stack = reinterpret_cast<int*>(&var20);
            var24 = 1;
            if (eax_lea != reinterpret_cast<int>(ecx_stack)) {
                int ecx_val2 = *reinterpret_cast<int*>(eax_lea);
                int* edx_stack = reinterpret_cast<int*>(&var20 + 4);
                *reinterpret_cast<int*>(&var20) = ecx_val2;
                *reinterpret_cast<int*>(eax_lea) = ebp_mul;
                sub_91afb0(this + 4, edx_stack);
            }
        }

        if (var20)
            sub_982114(var20);

        ++i;
    }

    *reinterpret_cast<char*>(this + 0x30) = 1;
    return 0;
}
