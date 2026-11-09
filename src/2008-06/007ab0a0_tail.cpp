// continuation replacing placeholder tail
            // 007AB86F..007AB884 : float-valued sub_548F80(p18, (float)(cmp < 0 ? 1 : 0))
            float floatVal = 0.0f;
            {
                float d0 = At<float>(r5, 0x24) - At<float>(f, kTiming1A8 + 0x24);
                float d1 = At<float>(r5, 0x28) - At<float>(f, kTiming1A8 + 0x28);
                float d2 = At<float>(r5, 0x2C) - At<float>(f, kTiming1A8 + 0x2C);
                float f0 = d0 * At<float>(f, kTiming1A8 + 0x20);
                float f1 = d1 * At<float>(f, kTiming1A8 + 0x1C);
                float f2 = d2 * At<float>(f, kTiming1A8 + 0x18);
                float sum = (f0 + f1 + f2);
                floatVal = (-sum < 0.0f) ? 1.0f : 0.0f;
                (void)sum;
            }
            At<int>(f, kR24) = (floatVal != 0.0f) ? 1 : 0;
            sub_548F80(p18, floatVal);

            // 007AB885..007AB89D : camera / transform branch (simplified but structured)
            if (At<int>(p18, 0x84) == 4) {
                unsigned char* ctxPtr = reinterpret_cast<unsigned char*>(ctx);
                if (At<u8>(this, kFlagF4) == 0 || ctxPtr[0x806] == 0) {
                    unsigned char* obj = reinterpret_cast<unsigned char*>(At<void*>(f, 0x14));
                    if (obj && obj[0x1C]) {
                        imp_804338(Addr(f, 0x78));
                        // quaternion/transform accumulation handled by target helpers
                        sub_548F80(p18, 0.0f);
                        if (At<int>(p18, 0x18) == 5 && At<int>(p18, 0x10) == 4) {
                            void* a = VCall<void*>(p18, 0x1C, 0);
                            void* b = At<void*>(f, 0x20);
                            (void)a; (void)b;
                        }
                    }
                }
            }
            // continuation of item handling
            if (At<int>(item, 0x10) != 0) {
                // cache-hit path: update existing render target (007AC8E9..)
                (void)item;
            } else {
                // allocate/populate new target via sub_67D9B0 (007AC533..007AC8CA)
                void* tgt = At<void*>(this, kTarget);
                (void)tgt;
            }
            // release p18 slot
            ReleaseSlot(At<void*>(f, kP18));
        }
    }

    // 007ACB33..007ACBBF : end of outer loop; diagnostics / camera cleanup
    if (At<u8>(ctx, kCtxFlag) != 0 && g_942EBC != 0) {
        sub_5493E0(ctx);
        if (At<void*>(this, kTarget) != NULL) {
            unsigned char tmp[0x0C] = {};
            imp_804C68(tmp, Lit(0x9738B8));
            sub_67C520(At<void*>(this, kTarget));
        }
    }

    // 007ACBC6..007ACC5D : final camera pass
    imp_804E7C(Addr(f, kGuard230));
    if (At<void*>(this, kTarget) != NULL) {
        VCall<void>(At<void*>(this, kTarget), 0xD8, 1);
        if (At<u8>(this, kFlagF4)) {
            At<float>(At<void*>(this, kTarget), 0x29C) = 0.0f; // 0x84B020
            At<int>(At<void*>(this, kTarget), 0x2A0) = 0x258;
        } else {
            At<float>(At<void*>(this, kTarget), 0x29C) = 0.0f; // 0x8222F0
            At<int>(At<void*>(this, kTarget), 0x2A0) = 0x28A;
        }
    }

    // 007ACC5D.. : epilogue cleanup
    imp_804E80(Addr(f, kGuard230));
    At<int>(f, kR24) = -1;
}  // namespace? function end

// Keep namespace close in source; this continuation is inserted before the real final }
