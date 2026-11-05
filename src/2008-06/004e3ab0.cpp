// roc 2008-06 004e3ab0  unit: seg_004e0000  size: 6223 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e3ab0
//
// 004e3ab0  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3ab4  d9c9                 fxch st(1)
// 004e3ab6  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3aba  d9442418             fld dword ptr [esp + 0x18]
// 004e3abe  d944241c             fld dword ptr [esp + 0x1c]
// 004e3ac2  d9cb                 fxch st(3)
// 004e3ac4  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3ac8  d9ce                 fxch st(6)
// 004e3aca  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3ace  d9442418             fld dword ptr [esp + 0x18]
// 004e3ad2  d944241c             fld dword ptr [esp + 0x1c]
// 004e3ad6  d9cd                 fxch st(5)
// 004e3ad8  d9cf                 fxch st(7)
// 004e3ada  d9c9                 fxch st(1)
// 004e3adc  d9ce                 fxch st(6)
// 004e3ade  d9ca                 fxch st(2)
// 004e3ae0  d9cc                 fxch st(4)
// 004e3ae2  d9ca                 fxch st(2)
// 004e3ae4  d9cb                 fxch st(3)
// 004e3ae6  a804                 test al, 4
// 004e3ae8  7426                 je 0x4e3b10
// 004e3aea  d9cc                 fxch st(4)
// 004e3aec  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3af0  d9c9                 fxch st(1)
// 004e3af2  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3af6  d9442418             fld dword ptr [esp + 0x18]
// 004e3afa  d944241c             fld dword ptr [esp + 0x1c]
// 004e3afe  d9cd                 fxch st(5)
// 004e3b00  d9cf                 fxch st(7)
// 004e3b02  d9ca                 fxch st(2)
// 004e3b04  d9ce                 fxch st(6)
// 004e3b06  d9cc                 fxch st(4)
// 004e3b08  d9cd                 fxch st(5)
// 004e3b0a  d9cb                 fxch st(3)
// 004e3b0c  d9cc                 fxch st(4)
// 004e3b0e  d9cb                 fxch st(3)
// 004e3b10  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e3b16  d9cc                 fxch st(4)
// 004e3b18  8b9424c0000000       mov edx, dword ptr [esp + 0xc0]
// 004e3b1f  d91cd1               fstp dword ptr [ecx + edx*8]
// 004e3b22  8d04d1               lea eax, [ecx + edx*8]
// 004e3b25  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 004e3b2c  d9c9                 fxch st(1)
// 004e3b2e  d95804               fstp dword ptr [eax + 4]
// 004e3b31  a134399700           mov eax, dword ptr [0x973934]
// 004e3b36  8d04c8               lea eax, [eax + ecx*8]
// 004e3b39  d9c9                 fxch st(1)
// 004e3b3b  d918                 fstp dword ptr [eax]
// 004e3b3d  d9cc                 fxch st(4)
// 004e3b3f  d95804               fstp dword ptr [eax + 4]
// 004e3b42  8b1534399700         mov edx, dword ptr [0x973934]
// 004e3b48  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 004e3b4f  d9ca                 fxch st(2)
// 004e3b51  d91cc2               fstp dword ptr [edx + eax*8]
// 004e3b54  8d04c2               lea eax, [edx + eax*8]
// 004e3b57  8b9424cc000000       mov edx, dword ptr [esp + 0xcc]
// 004e3b5e  d95804               fstp dword ptr [eax + 4]
// 004e3b61  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e3b67  8d04d1               lea eax, [ecx + edx*8]
// 004e3b6a  d9c9                 fxch st(1)
// 004e3b6c  d918                 fstp dword ptr [eax]
// 004e3b6e  8d4c2428             lea ecx, [esp + 0x28]
// 004e3b72  d95804               fstp dword ptr [eax + 4]
// 004e3b75  8b942464010000       mov edx, dword ptr [esp + 0x164]
// 004e3b7c  d9442420             fld dword ptr [esp + 0x20]
// 004e3b80  8d8424d0000000       lea eax, [esp + 0xd0]
// 004e3b87  50                   push eax
// 004e3b88  51                   push ecx
// 004e3b89  51                   push ecx
// 004e3b8a  d91c24               fstp dword ptr [esp]
// 004e3b8d  52                   push edx
// 004e3b8e  d90558279700         fld dword ptr [0x972758]
// 004e3b94  51                   push ecx
// 004e3b95  8d8424b8000000       lea eax, [esp + 0xb8]
// 004e3b9c  d91c24               fstp dword ptr [esp]
// 004e3b9f  50                   push eax
// 004e3ba0  e80bc0ffff           call 0x4dfbb0
// 004e3ba5  8b0e                 mov ecx, dword ptr [esi]
// 004e3ba7  c1e104               shl ecx, 4
// 004e3baa  d9443908             fld dword ptr [ecx + edi + 8]
// 004e3bae  8d0439               lea eax, [ecx + edi]
// 004e3bb1  d905746e8200         fld dword ptr [0x826e74]
// 004e3bb7  83c418               add esp, 0x18
// 004e3bba  dcc9                 fmul st(1), st(0)
// 004e3bbc  d8480c               fmul dword ptr [eax + 0xc]
// 004e3bbf  d9842478010000       fld dword ptr [esp + 0x178]
// 004e3bc6  dcca                 fmul st(2), st(0)
// 004e3bc8  dec9                 fmulp st(1)
// 004e3bca  d900                 fld dword ptr [eax]
// 004e3bcc  d8c2                 fadd st(2)
// 004e3bce  d9c0                 fld st(0)
// 004e3bd0  d954242c             fst dword ptr [esp + 0x2c]
// 004e3bd4  d9c2                 fld st(2)
// 004e3bd6  d84004               fadd dword ptr [eax + 4]
// 004e3bd9  d9c0                 fld st(0)
// 004e3bdb  d9542410             fst dword ptr [esp + 0x10]
// 004e3bdf  d900                 fld dword ptr [eax]
// 004e3be1  d84008               fadd dword ptr [eax + 8]
// 004e3be4  dee6                 fsubrp st(6)
// 004e3be6  d9c5                 fld st(5)
// 004e3be8  d9542418             fst dword ptr [esp + 0x18]
// 004e3bec  d9ca                 fxch st(2)
// 004e3bee  d9542430             fst dword ptr [esp + 0x30]
// 004e3bf2  d9ce                 fxch st(6)
// 004e3bf4  d954243c             fst dword ptr [esp + 0x3c]
// 004e3bf8  d94004               fld dword ptr [eax + 4]
// 004e3bfb  d8400c               fadd dword ptr [eax + 0xc]
// 004e3bfe  8b4500               mov eax, dword ptr [ebp]
// 004e3c01  a801                 test al, 1
// 004e3c03  dee6                 fsubrp st(6)
// 004e3c05  d9cd                 fxch st(5)
// 004e3c07  d9542424             fst dword ptr [esp + 0x24]
// 004e3c0b  d9442424             fld dword ptr [esp + 0x24]
// 004e3c0f  d9cd                 fxch st(5)
// 004e3c11  d9542438             fst dword ptr [esp + 0x38]
// 004e3c15  d9c9                 fxch st(1)
// 004e3c17  d9542434             fst dword ptr [esp + 0x34]
// 004e3c1b  7440                 je 0x4e3c5d
// 004e3c1d  dddc                 fstp st(4)
// 004e3c1f  ddd9                 fstp st(1)
// 004e3c21  ddd9                 fstp st(1)
// 004e3c23  dddc                 fstp st(4)
// 004e3c25  ddda                 fstp st(2)
// 004e3c27  ddd8                 fstp st(0)
// 004e3c29  ddd9                 fstp st(1)
// 004e3c2b  ddd8                 fstp st(0)
// 004e3c2d  d9442418             fld dword ptr [esp + 0x18]
// 004e3c31  d9442430             fld dword ptr [esp + 0x30]
// 004e3c35  d944242c             fld dword ptr [esp + 0x2c]
// 004e3c39  d9442410             fld dword ptr [esp + 0x10]
// 004e3c3d  d9442438             fld dword ptr [esp + 0x38]
// 004e3c41  d9442434             fld dword ptr [esp + 0x34]
// 004e3c45  d944243c             fld dword ptr [esp + 0x3c]
// 004e3c49  d9442424             fld dword ptr [esp + 0x24]
// 004e3c4d  d9cc                 fxch st(4)
// 004e3c4f  d9cf                 fxch st(7)
// 004e3c51  d9cb                 fxch st(3)
// 004e3c53  d9ce                 fxch st(6)
// 004e3c55  d9ca                 fxch st(2)
// 004e3c57  d9cd                 fxch st(5)
// 004e3c59  d9cb                 fxch st(3)
// 004e3c5b  d9cc                 fxch st(4)
// 004e3c5d  a802                 test al, 2
// 004e3c5f  7438                 je 0x4e3c99
// 004e3c61  d9cc                 fxch st(4)
// 004e3c63  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3c67  d9c9                 fxch st(1)
// 004e3c69  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3c6d  d9442418             fld dword ptr [esp + 0x18]
// 004e3c71  d944241c             fld dword ptr [esp + 0x1c]
// 004e3c75  d9cb                 fxch st(3)
// 004e3c77  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3c7b  d9ce                 fxch st(6)
// 004e3c7d  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3c81  d9442418             fld dword ptr [esp + 0x18]
// 004e3c85  d944241c             fld dword ptr [esp + 0x1c]
// 004e3c89  d9cd                 fxch st(5)
// 004e3c8b  d9cf                 fxch st(7)
// 004e3c8d  d9c9                 fxch st(1)
// 004e3c8f  d9ce                 fxch st(6)
// 004e3c91  d9ca                 fxch st(2)
// 004e3c93  d9cc                 fxch st(4)
// 004e3c95  d9ca                 fxch st(2)
// 004e3c97  d9cb                 fxch st(3)
// 004e3c99  a804                 test al, 4
// 004e3c9b  7426                 je 0x4e3cc3
// 004e3c9d  d9cc                 fxch st(4)
// 004e3c9f  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3ca3  d9c9                 fxch st(1)
// 004e3ca5  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3ca9  d9442418             fld dword ptr [esp + 0x18]
// 004e3cad  d944241c             fld dword ptr [esp + 0x1c]
// 004e3cb1  d9cd                 fxch st(5)
// 004e3cb3  d9cf                 fxch st(7)
// 004e3cb5  d9ca                 fxch st(2)
// 004e3cb7  d9ce                 fxch st(6)
// 004e3cb9  d9cc                 fxch st(4)
// 004e3cbb  d9cd                 fxch st(5)
// 004e3cbd  d9cb                 fxch st(3)
// 004e3cbf  d9cc                 fxch st(4)
// 004e3cc1  d9cb                 fxch st(3)
// 004e3cc3  8b1534399700         mov edx, dword ptr [0x973934]
// 004e3cc9  d9cc                 fxch st(4)
// 004e3ccb  8b8424d0000000       mov eax, dword ptr [esp + 0xd0]
// 004e3cd2  d91cc2               fstp dword ptr [edx + eax*8]
// 004e3cd5  8d04c2               lea eax, [edx + eax*8]
// 004e3cd8  8b9424d4000000       mov edx, dword ptr [esp + 0xd4]
// 004e3cdf  d9c9                 fxch st(1)
// 004e3ce1  d95804               fstp dword ptr [eax + 4]
// 004e3ce4  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e3cea  8d04d1               lea eax, [ecx + edx*8]
// 004e3ced  d9c9                 fxch st(1)
// 004e3cef  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 004e3cf6  d918                 fstp dword ptr [eax]
// 004e3cf8  d9cc                 fxch st(4)
// 004e3cfa  d95804               fstp dword ptr [eax + 4]
// 004e3cfd  a134399700           mov eax, dword ptr [0x973934]
// 004e3d02  8d04c8               lea eax, [eax + ecx*8]
// 004e3d05  d9ca                 fxch st(2)
// 004e3d07  d918                 fstp dword ptr [eax]
// 004e3d09  8d8c24e0000000       lea ecx, [esp + 0xe0]
// 004e3d10  51                   push ecx
// 004e3d11  d95804               fstp dword ptr [eax + 4]
// 004e3d14  8b1534399700         mov edx, dword ptr [0x973934]
// 004e3d1a  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 004e3d21  d9c9                 fxch st(1)
// 004e3d23  d91cc2               fstp dword ptr [edx + eax*8]
// 004e3d26  8d04c2               lea eax, [edx + eax*8]
// 004e3d29  8d54242c             lea edx, [esp + 0x2c]
// 004e3d2d  d95804               fstp dword ptr [eax + 4]
// 004e3d30  8b842468010000       mov eax, dword ptr [esp + 0x168]
// 004e3d37  d9442424             fld dword ptr [esp + 0x24]
// 004e3d3b  52                   push edx
// 004e3d3c  51                   push ecx
// 004e3d3d  d91c24               fstp dword ptr [esp]
// 004e3d40  50                   push eax
// 004e3d41  d90558279700         fld dword ptr [0x972758]
// 004e3d47  51                   push ecx
// 004e3d48  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 004e3d4f  d91c24               fstp dword ptr [esp]
// 004e3d52  51                   push ecx
// 004e3d53  e888caffff           call 0x4e07e0
// 004e3d58  8b5608               mov edx, dword ptr [esi + 8]
// 004e3d5b  c1e204               shl edx, 4
// 004e3d5e  d9443a08             fld dword ptr [edx + edi + 8]
// 004e3d62  8d043a               lea eax, [edx + edi]
// 004e3d65  d905746e8200         fld dword ptr [0x826e74]
// 004e3d6b  83c418               add esp, 0x18
// 004e3d6e  dcc9                 fmul st(1), st(0)
// 004e3d70  d8480c               fmul dword ptr [eax + 0xc]
// 004e3d73  d9842478010000       fld dword ptr [esp + 0x178]
// 004e3d7a  dcca                 fmul st(2), st(0)
// 004e3d7c  dec9                 fmulp st(1)
// 004e3d7e  d9c1                 fld st(1)
// 004e3d80  d800                 fadd dword ptr [eax]
// 004e3d82  d9c0                 fld st(0)
// 004e3d84  d954242c             fst dword ptr [esp + 0x2c]
// 004e3d88  d9c2                 fld st(2)
// 004e3d8a  d84004               fadd dword ptr [eax + 4]
// 004e3d8d  d9c0                 fld st(0)
// 004e3d8f  d9542410             fst dword ptr [esp + 0x10]
// 004e3d93  d94008               fld dword ptr [eax + 8]
// 004e3d96  d800                 fadd dword ptr [eax]
// 004e3d98  dee6                 fsubrp st(6)
// 004e3d9a  d9c5                 fld st(5)
// 004e3d9c  d9542418             fst dword ptr [esp + 0x18]
// 004e3da0  d9ca                 fxch st(2)
// 004e3da2  d9542430             fst dword ptr [esp + 0x30]
// 004e3da6  d9ce                 fxch st(6)
// 004e3da8  d954243c             fst dword ptr [esp + 0x3c]
// 004e3dac  d94004               fld dword ptr [eax + 4]
// 004e3daf  d8400c               fadd dword ptr [eax + 0xc]
// 004e3db2  8b4508               mov eax, dword ptr [ebp + 8]
// 004e3db5  a801                 test al, 1
// 004e3db7  dee6                 fsubrp st(6)
// 004e3db9  d9cd                 fxch st(5)
// 004e3dbb  d9542424             fst dword ptr [esp + 0x24]
// 004e3dbf  d9442424             fld dword ptr [esp + 0x24]
// 004e3dc3  d9cd                 fxch st(5)
// 004e3dc5  d9542438             fst dword ptr [esp + 0x38]
// 004e3dc9  d9c9                 fxch st(1)
// 004e3dcb  d9542434             fst dword ptr [esp + 0x34]
// 004e3dcf  7440                 je 0x4e3e11
// 004e3dd1  dddc                 fstp st(4)
// 004e3dd3  ddd9                 fstp st(1)
// 004e3dd5  ddd9                 fstp st(1)
// 004e3dd7  dddc                 fstp st(4)
// 004e3dd9  ddda                 fstp st(2)
// 004e3ddb  ddd8                 fstp st(0)
// 004e3ddd  ddd9                 fstp st(1)
// 004e3ddf  ddd8                 fstp st(0)
// 004e3de1  d9442418             fld dword ptr [esp + 0x18]
// 004e3de5  d9442430             fld dword ptr [esp + 0x30]
// 004e3de9  d944242c             fld dword ptr [esp + 0x2c]
// 004e3ded  d9442410             fld dword ptr [esp + 0x10]
// 004e3df1  d9442438             fld dword ptr [esp + 0x38]
// 004e3df5  d9442434             fld dword ptr [esp + 0x34]
// 004e3df9  d944243c             fld dword ptr [esp + 0x3c]
// 004e3dfd  d9442424             fld dword ptr [esp + 0x24]
// 004e3e01  d9cc                 fxch st(4)
// 004e3e03  d9cf                 fxch st(7)
// 004e3e05  d9cb                 fxch st(3)
// 004e3e07  d9ce                 fxch st(6)
// 004e3e09  d9ca                 fxch st(2)
// 004e3e0b  d9cd                 fxch st(5)
// 004e3e0d  d9cb                 fxch st(3)
// 004e3e0f  d9cc                 fxch st(4)
// 004e3e11  a802                 test al, 2
// 004e3e13  7438                 je 0x4e3e4d
// 004e3e15  d9cc                 fxch st(4)
// 004e3e17  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3e1b  d9c9                 fxch st(1)
// 004e3e1d  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3e21  d9442418             fld dword ptr [esp + 0x18]
// 004e3e25  d944241c             fld dword ptr [esp + 0x1c]
// 004e3e29  d9cb                 fxch st(3)
// 004e3e2b  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3e2f  d9ce                 fxch st(6)
// 004e3e31  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3e35  d9442418             fld dword ptr [esp + 0x18]
// 004e3e39  d944241c             fld dword ptr [esp + 0x1c]
// 004e3e3d  d9cd                 fxch st(5)
// 004e3e3f  d9cf                 fxch st(7)
// 004e3e41  d9c9                 fxch st(1)
// 004e3e43  d9ce                 fxch st(6)
// 004e3e45  d9ca                 fxch st(2)
// 004e3e47  d9cc                 fxch st(4)
// 004e3e49  d9ca                 fxch st(2)
// 004e3e4b  d9cb                 fxch st(3)
// 004e3e4d  a804                 test al, 4
// 004e3e4f  7426                 je 0x4e3e77
// 004e3e51  d9cc                 fxch st(4)
// 004e3e53  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3e57  d9c9                 fxch st(1)
// 004e3e59  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3e5d  d9442418             fld dword ptr [esp + 0x18]
// 004e3e61  d944241c             fld dword ptr [esp + 0x1c]
// 004e3e65  d9cd                 fxch st(5)
// 004e3e67  d9cf                 fxch st(7)
// 004e3e69  d9ca                 fxch st(2)
// 004e3e6b  d9ce                 fxch st(6)
// 004e3e6d  d9cc                 fxch st(4)
// 004e3e6f  d9cd                 fxch st(5)
// 004e3e71  d9cb                 fxch st(3)
// 004e3e73  d9cc                 fxch st(4)
// 004e3e75  d9cb                 fxch st(3)
// 004e3e77  a134399700           mov eax, dword ptr [0x973934]
// 004e3e7c  d9cc                 fxch st(4)
// 004e3e7e  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 004e3e85  d91cc8               fstp dword ptr [eax + ecx*8]
// 004e3e88  8d04c8               lea eax, [eax + ecx*8]
// 004e3e8b  d9c9                 fxch st(1)
// 004e3e8d  d95804               fstp dword ptr [eax + 4]
// 004e3e90  8b1534399700         mov edx, dword ptr [0x973934]
// 004e3e96  8b8424e4000000       mov eax, dword ptr [esp + 0xe4]
// 004e3e9d  d9c9                 fxch st(1)
// 004e3e9f  d91cc2               fstp dword ptr [edx + eax*8]
// 004e3ea2  8d04c2               lea eax, [edx + eax*8]
// 004e3ea5  8b9424e8000000       mov edx, dword ptr [esp + 0xe8]
// 004e3eac  d9cc                 fxch st(4)
// 004e3eae  d95804               fstp dword ptr [eax + 4]
// 004e3eb1  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e3eb7  8d04d1               lea eax, [ecx + edx*8]
// 004e3eba  d9ca                 fxch st(2)
// 004e3ebc  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 004e3ec3  d918                 fstp dword ptr [eax]
// 004e3ec5  8d9424f0000000       lea edx, [esp + 0xf0]
// 004e3ecc  d95804               fstp dword ptr [eax + 4]
// 004e3ecf  a134399700           mov eax, dword ptr [0x973934]
// 004e3ed4  8d04c8               lea eax, [eax + ecx*8]
// 004e3ed7  d9c9                 fxch st(1)
// 004e3ed9  d918                 fstp dword ptr [eax]
// 004e3edb  52                   push edx
// 004e3edc  8d9424a8000000       lea edx, [esp + 0xa8]
// 004e3ee3  d95804               fstp dword ptr [eax + 4]
// 004e3ee6  8d44242c             lea eax, [esp + 0x2c]
// 004e3eea  d9442424             fld dword ptr [esp + 0x24]
// 004e3eee  50                   push eax
// 004e3eef  51                   push ecx
// 004e3ef0  8b8c2470010000       mov ecx, dword ptr [esp + 0x170]
// 004e3ef7  d91c24               fstp dword ptr [esp]
// 004e3efa  d90558279700         fld dword ptr [0x972758]
// 004e3f00  51                   push ecx
// 004e3f01  51                   push ecx
// 004e3f02  d91c24               fstp dword ptr [esp]
// 004e3f05  52                   push edx
// 004e3f06  e805d5ffff           call 0x4e1410
// 004e3f0b  8b4614               mov eax, dword ptr [esi + 0x14]
// 004e3f0e  c1e004               shl eax, 4
// 004e3f11  d9443808             fld dword ptr [eax + edi + 8]
// 004e3f15  03c7                 add eax, edi
// 004e3f17  d905746e8200         fld dword ptr [0x826e74]
// 004e3f1d  83c418               add esp, 0x18
// 004e3f20  dcc9                 fmul st(1), st(0)
// 004e3f22  d8480c               fmul dword ptr [eax + 0xc]
// 004e3f25  d9842478010000       fld dword ptr [esp + 0x178]
// 004e3f2c  dcca                 fmul st(2), st(0)
// 004e3f2e  dec9                 fmulp st(1)
// 004e3f30  d9c1                 fld st(1)
// 004e3f32  d800                 fadd dword ptr [eax]
// 004e3f34  d9c0                 fld st(0)
// 004e3f36  d954242c             fst dword ptr [esp + 0x2c]
// 004e3f3a  d9c2                 fld st(2)
// 004e3f3c  d84004               fadd dword ptr [eax + 4]
// 004e3f3f  d9c0                 fld st(0)
// 004e3f41  d9542410             fst dword ptr [esp + 0x10]
// 004e3f45  d94008               fld dword ptr [eax + 8]
// 004e3f48  d800                 fadd dword ptr [eax]
// 004e3f4a  dee6                 fsubrp st(6)
// 004e3f4c  d9c5                 fld st(5)
// 004e3f4e  d9542418             fst dword ptr [esp + 0x18]
// 004e3f52  d9ca                 fxch st(2)
// 004e3f54  d9542430             fst dword ptr [esp + 0x30]
// 004e3f58  d9ce                 fxch st(6)
// 004e3f5a  d954243c             fst dword ptr [esp + 0x3c]
// 004e3f5e  d9400c               fld dword ptr [eax + 0xc]
// 004e3f61  d84004               fadd dword ptr [eax + 4]
// 004e3f64  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004e3f67  a801                 test al, 1
// 004e3f69  dee6                 fsubrp st(6)
// 004e3f6b  d9cd                 fxch st(5)
// 004e3f6d  d9542424             fst dword ptr [esp + 0x24]
// 004e3f71  d9442424             fld dword ptr [esp + 0x24]
// 004e3f75  d9cd                 fxch st(5)
// 004e3f77  d9542438             fst dword ptr [esp + 0x38]
// 004e3f7b  d9c9                 fxch st(1)
// 004e3f7d  d9542434             fst dword ptr [esp + 0x34]
// 004e3f81  7440                 je 0x4e3fc3
// 004e3f83  dddc                 fstp st(4)
// 004e3f85  ddd9                 fstp st(1)
// 004e3f87  ddd9                 fstp st(1)
// 004e3f89  dddc                 fstp st(4)
// 004e3f8b  ddda                 fstp st(2)
// 004e3f8d  ddd8                 fstp st(0)
// 004e3f8f  ddd9                 fstp st(1)
// 004e3f91  ddd8                 fstp st(0)
// 004e3f93  d9442418             fld dword ptr [esp + 0x18]
// 004e3f97  d9442430             fld dword ptr [esp + 0x30]
// 004e3f9b  d944242c             fld dword ptr [esp + 0x2c]
// 004e3f9f  d9442410             fld dword ptr [esp + 0x10]
// 004e3fa3  d9442438             fld dword ptr [esp + 0x38]
// 004e3fa7  d9442434             fld dword ptr [esp + 0x34]
// 004e3fab  d944243c             fld dword ptr [esp + 0x3c]
// 004e3faf  d9442424             fld dword ptr [esp + 0x24]
// 004e3fb3  d9cc                 fxch st(4)
// 004e3fb5  d9cf                 fxch st(7)
// 004e3fb7  d9cb                 fxch st(3)
// 004e3fb9  d9ce                 fxch st(6)
// 004e3fbb  d9ca                 fxch st(2)
// 004e3fbd  d9cd                 fxch st(5)
// 004e3fbf  d9cb                 fxch st(3)
// 004e3fc1  d9cc                 fxch st(4)
// 004e3fc3  a802                 test al, 2
// 004e3fc5  7438                 je 0x4e3fff
// 004e3fc7  d9cc                 fxch st(4)
// 004e3fc9  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3fcd  d9c9                 fxch st(1)
// 004e3fcf  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3fd3  d9442418             fld dword ptr [esp + 0x18]
// 004e3fd7  d944241c             fld dword ptr [esp + 0x1c]
// 004e3fdb  d9cb                 fxch st(3)
// 004e3fdd  d95c2418             fstp dword ptr [esp + 0x18]
// 004e3fe1  d9ce                 fxch st(6)
// 004e3fe3  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e3fe7  d9442418             fld dword ptr [esp + 0x18]
// 004e3feb  d944241c             fld dword ptr [esp + 0x1c]
// 004e3fef  d9cd                 fxch st(5)
// 004e3ff1  d9cf                 fxch st(7)
// 004e3ff3  d9c9                 fxch st(1)
// 004e3ff5  d9ce                 fxch st(6)
// 004e3ff7  d9ca                 fxch st(2)
// 004e3ff9  d9cc                 fxch st(4)
// 004e3ffb  d9ca                 fxch st(2)
// 004e3ffd  d9cb                 fxch st(3)
// 004e3fff  a804                 test al, 4
// 004e4001  7426                 je 0x4e4029
// 004e4003  d9cc                 fxch st(4)
// 004e4005  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4009  d9c9                 fxch st(1)
// 004e400b  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e400f  d9442418             fld dword ptr [esp + 0x18]
// 004e4013  d944241c             fld dword ptr [esp + 0x1c]
// 004e4017  d9cd                 fxch st(5)
// 004e4019  d9cf                 fxch st(7)
// 004e401b  d9ca                 fxch st(2)
// 004e401d  d9ce                 fxch st(6)
// 004e401f  d9cc                 fxch st(4)
// 004e4021  d9cd                 fxch st(5)
// 004e4023  d9cb                 fxch st(3)
// 004e4025  d9cc                 fxch st(4)
// 004e4027  d9cb                 fxch st(3)
// 004e4029  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e402f  d9cc                 fxch st(4)
// 004e4031  8b9424f0000000       mov edx, dword ptr [esp + 0xf0]
// 004e4038  d91cd1               fstp dword ptr [ecx + edx*8]
// 004e403b  8d04d1               lea eax, [ecx + edx*8]
// 004e403e  8b8c24f4000000       mov ecx, dword ptr [esp + 0xf4]
// 004e4045  d9c9                 fxch st(1)
// 004e4047  d95804               fstp dword ptr [eax + 4]
// 004e404a  a134399700           mov eax, dword ptr [0x973934]
// 004e404f  8d04c8               lea eax, [eax + ecx*8]
// 004e4052  d9c9                 fxch st(1)
// 004e4054  d918                 fstp dword ptr [eax]
// 004e4056  d9cc                 fxch st(4)
// 004e4058  d95804               fstp dword ptr [eax + 4]
// 004e405b  8b1534399700         mov edx, dword ptr [0x973934]
// 004e4061  8b8424f8000000       mov eax, dword ptr [esp + 0xf8]
// 004e4068  d9ca                 fxch st(2)
// 004e406a  d91cc2               fstp dword ptr [edx + eax*8]
// 004e406d  8d04c2               lea eax, [edx + eax*8]
// 004e4070  8b9424fc000000       mov edx, dword ptr [esp + 0xfc]
// 004e4077  d95804               fstp dword ptr [eax + 4]
// 004e407a  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e4080  8d04d1               lea eax, [ecx + edx*8]
// 004e4083  d9c9                 fxch st(1)
// 004e4085  d918                 fstp dword ptr [eax]
// 004e4087  8d4c2428             lea ecx, [esp + 0x28]
// 004e408b  d95804               fstp dword ptr [eax + 4]
// 004e408e  8b942464010000       mov edx, dword ptr [esp + 0x164]
// 004e4095  d9442420             fld dword ptr [esp + 0x20]
// 004e4099  8d842400010000       lea eax, [esp + 0x100]
// 004e40a0  50                   push eax
// 004e40a1  51                   push ecx
// 004e40a2  51                   push ecx
// 004e40a3  d91c24               fstp dword ptr [esp]
// 004e40a6  52                   push edx
// 004e40a7  d90558279700         fld dword ptr [0x972758]
// 004e40ad  51                   push ecx
// 004e40ae  8d8424b8000000       lea eax, [esp + 0xb8]
// 004e40b5  d91c24               fstp dword ptr [esp]
// 004e40b8  50                   push eax
// 004e40b9  e882dfffff           call 0x4e2040
// 004e40be  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e40c1  83c418               add esp, 0x18
// 004e40c4  c1e104               shl ecx, 4
// 004e40c7  d9443908             fld dword ptr [ecx + edi + 8]
// 004e40cb  8d0439               lea eax, [ecx + edi]
// 004e40ce  d905746e8200         fld dword ptr [0x826e74]
// 004e40d4  dcc9                 fmul st(1), st(0)
// 004e40d6  d8480c               fmul dword ptr [eax + 0xc]
// 004e40d9  d9842478010000       fld dword ptr [esp + 0x178]
// 004e40e0  dcca                 fmul st(2), st(0)
// 004e40e2  dec9                 fmulp st(1)
// 004e40e4  d9c1                 fld st(1)
// 004e40e6  d800                 fadd dword ptr [eax]
// 004e40e8  d9c0                 fld st(0)
// 004e40ea  d954242c             fst dword ptr [esp + 0x2c]
// 004e40ee  d9c2                 fld st(2)
// 004e40f0  d84004               fadd dword ptr [eax + 4]
// 004e40f3  d9c0                 fld st(0)
// 004e40f5  d9542410             fst dword ptr [esp + 0x10]
// 004e40f9  d94008               fld dword ptr [eax + 8]
// 004e40fc  d800                 fadd dword ptr [eax]
// 004e40fe  dee6                 fsubrp st(6)
// 004e4100  d9c5                 fld st(5)
// 004e4102  d9542418             fst dword ptr [esp + 0x18]
// 004e4106  d9ca                 fxch st(2)
// 004e4108  d9542430             fst dword ptr [esp + 0x30]
// 004e410c  d9ce                 fxch st(6)
// 004e410e  d9542434             fst dword ptr [esp + 0x34]
// 004e4112  d94004               fld dword ptr [eax + 4]
// 004e4115  d8400c               fadd dword ptr [eax + 0xc]
// 004e4118  8b4504               mov eax, dword ptr [ebp + 4]
// 004e411b  dee6                 fsubrp st(6)
// 004e411d  d9cd                 fxch st(5)
// 004e411f  d9542420             fst dword ptr [esp + 0x20]
// 004e4123  d9442420             fld dword ptr [esp + 0x20]
// 004e4127  d9cd                 fxch st(5)
// 004e4129  d9542438             fst dword ptr [esp + 0x38]
// 004e412d  d9c9                 fxch st(1)
// 004e412f  d95c2424             fstp dword ptr [esp + 0x24]
// 004e4133  d9442424             fld dword ptr [esp + 0x24]
// 004e4137  a801                 test al, 1
// 004e4139  7440                 je 0x4e417b
// 004e413b  ddd9                 fstp st(1)
// 004e413d  dddd                 fstp st(5)
// 004e413f  dddc                 fstp st(4)
// 004e4141  ddd8                 fstp st(0)
// 004e4143  ddd8                 fstp st(0)
// 004e4145  ddd9                 fstp st(1)
// 004e4147  ddd9                 fstp st(1)
// 004e4149  ddd8                 fstp st(0)
// 004e414b  d9442418             fld dword ptr [esp + 0x18]
// 004e414f  d9442430             fld dword ptr [esp + 0x30]
// 004e4153  d944242c             fld dword ptr [esp + 0x2c]
// 004e4157  d9442410             fld dword ptr [esp + 0x10]
// 004e415b  d9442438             fld dword ptr [esp + 0x38]
// 004e415f  d9442424             fld dword ptr [esp + 0x24]
// 004e4163  d9442434             fld dword ptr [esp + 0x34]
// 004e4167  d9442420             fld dword ptr [esp + 0x20]
// 004e416b  d9cc                 fxch st(4)
// 004e416d  d9cf                 fxch st(7)
// 004e416f  d9cb                 fxch st(3)
// 004e4171  d9ce                 fxch st(6)
// 004e4173  d9ca                 fxch st(2)
// 004e4175  d9cd                 fxch st(5)
// 004e4177  d9cb                 fxch st(3)
// 004e4179  d9cc                 fxch st(4)
// 004e417b  a802                 test al, 2
// 004e417d  7438                 je 0x4e41b7
// 004e417f  d9cc                 fxch st(4)
// 004e4181  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4185  d9c9                 fxch st(1)
// 004e4187  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e418b  d9442418             fld dword ptr [esp + 0x18]
// 004e418f  d944241c             fld dword ptr [esp + 0x1c]
// 004e4193  d9cb                 fxch st(3)
// 004e4195  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4199  d9ce                 fxch st(6)
// 004e419b  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e419f  d9442418             fld dword ptr [esp + 0x18]
// 004e41a3  d944241c             fld dword ptr [esp + 0x1c]
// 004e41a7  d9cd                 fxch st(5)
// 004e41a9  d9cf                 fxch st(7)
// 004e41ab  d9c9                 fxch st(1)
// 004e41ad  d9ce                 fxch st(6)
// 004e41af  d9ca                 fxch st(2)
// 004e41b1  d9cc                 fxch st(4)
// 004e41b3  d9ca                 fxch st(2)
// 004e41b5  d9cb                 fxch st(3)
// 004e41b7  a804                 test al, 4
// 004e41b9  7426                 je 0x4e41e1
// 004e41bb  d9cc                 fxch st(4)
// 004e41bd  d95c2418             fstp dword ptr [esp + 0x18]
// 004e41c1  d9c9                 fxch st(1)
// 004e41c3  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e41c7  d9442418             fld dword ptr [esp + 0x18]
// 004e41cb  d944241c             fld dword ptr [esp + 0x1c]
// 004e41cf  d9cd                 fxch st(5)
// 004e41d1  d9cf                 fxch st(7)
// 004e41d3  d9ca                 fxch st(2)
// 004e41d5  d9ce                 fxch st(6)
// 004e41d7  d9cc                 fxch st(4)
// 004e41d9  d9cd                 fxch st(5)
// 004e41db  d9cb                 fxch st(3)
// 004e41dd  d9cc                 fxch st(4)
// 004e41df  d9cb                 fxch st(3)
// 004e41e1  8b1534399700         mov edx, dword ptr [0x973934]
// 004e41e7  d9cc                 fxch st(4)
// 004e41e9  8b842400010000       mov eax, dword ptr [esp + 0x100]
// 004e41f0  8bac2404010000       mov ebp, dword ptr [esp + 0x104]
// 004e41f7  03c0                 add eax, eax
// 004e41f9  03c0                 add eax, eax
// 004e41fb  03c0                 add eax, eax
// 004e41fd  d91c10               fstp dword ptr [eax + edx]
// 004e4200  8944242c             mov dword ptr [esp + 0x2c], eax
// 004e4204  03c2                 add eax, edx
// 004e4206  d9c9                 fxch st(1)
// 004e4208  d95804               fstp dword ptr [eax + 4]
// 004e420b  a134399700           mov eax, dword ptr [0x973934]
// 004e4210  03ed                 add ebp, ebp
// 004e4212  d9c9                 fxch st(1)
// 004e4214  03ed                 add ebp, ebp
// 004e4216  03ed                 add ebp, ebp
// 004e4218  d91c28               fstp dword ptr [eax + ebp]
// 004e421b  03c5                 add eax, ebp
// 004e421d  d9cc                 fxch st(4)
// 004e421f  d95804               fstp dword ptr [eax + 4]
// 004e4222  8b842408010000       mov eax, dword ptr [esp + 0x108]
// 004e4229  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e422f  d9ca                 fxch st(2)
// 004e4231  03c0                 add eax, eax
// 004e4233  03c0                 add eax, eax
// 004e4235  03c0                 add eax, eax
// 004e4237  d91c08               fstp dword ptr [eax + ecx]
// 004e423a  89442418             mov dword ptr [esp + 0x18], eax
// 004e423e  03c1                 add eax, ecx
// 004e4240  d95804               fstp dword ptr [eax + 4]
// 004e4243  8b84240c010000       mov eax, dword ptr [esp + 0x10c]
// 004e424a  8b1534399700         mov edx, dword ptr [0x973934]
// 004e4250  d9c9                 fxch st(1)
// 004e4252  03c0                 add eax, eax
// 004e4254  03c0                 add eax, eax
// 004e4256  03c0                 add eax, eax
// 004e4258  89442430             mov dword ptr [esp + 0x30], eax
// 004e425c  d91c10               fstp dword ptr [eax + edx]
// 004e425f  03c2                 add eax, edx
// 004e4261  d95804               fstp dword ptr [eax + 4]
// 004e4264  d9ee                 fldz 
// 004e4266  d81d58279700         fcomp dword ptr [0x972758]
// 004e426c  dfe0                 fnstsw ax
// 004e426e  f6c405               test ah, 5
// 004e4271  0f8a24100000         jp 0x4e529b
// 004e4277  33f6                 xor esi, esi
// 004e4279  8da42400000000       lea esp, [esp]
// 004e4280  8b8434b0000000       mov eax, dword ptr [esp + esi + 0xb0]
// 004e4287  8b0d34399700         mov ecx, dword ptr [0x973934]
// 004e428d  8b15fc389700         mov edx, dword ptr [0x9738fc]
// 004e4293  8b3df0389700         mov edi, dword ptr [0x9738f0]
// 004e4299  8d0cc1               lea ecx, [ecx + eax*8]
// 004e429c  8d0440               lea eax, [eax + eax*2]
// 004e429f  03c0                 add eax, eax
// 004e42a1  03c0                 add eax, eax
// 004e42a3  6a01                 push 1
// 004e42a5  03d0                 add edx, eax
// 004e42a7  51                   push ecx
// 004e42a8  03c7                 add eax, edi
// 004e42aa  52                   push edx
// 004e42ab  50                   push eax
// 004e42ac  e84f3d0600           call 0x548000
// 004e42b1  89443450             mov dword ptr [esp + esi + 0x50], eax
// 004e42b5  83c604               add esi, 4
// 004e42b8  83c410               add esp, 0x10
// 004e42bb  83fe60               cmp esi, 0x60
// 004e42be  7cc0                 jl 0x4e4280
// 004e42c0  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 004e42c4  8b7c2458             mov edi, dword ptr [esp + 0x58]
// 004e42c8  a134399700           mov eax, dword ptr [0x973934]
// 004e42cd  03f6                 add esi, esi
// 004e42cf  03ff                 add edi, edi
// 004e42d1  03f6                 add esi, esi
// 004e42d3  03f6                 add esi, esi
// 004e42d5  d90406               fld dword ptr [esi + eax]
// 004e42d8  03ff                 add edi, edi
// 004e42da  03ff                 add edi, edi
// 004e42dc  d82407               fsub dword ptr [edi + eax]
// 004e42df  51                   push ecx
// 004e42e0  d9440604             fld dword ptr [esi + eax + 4]
// 004e42e4  8d4c2414             lea ecx, [esp + 0x14]
// 004e42e8  d8640704             fsub dword ptr [edi + eax + 4]
// 004e42ec  d9c9                 fxch st(1)
// 004e42ee  d95c2414             fstp dword ptr [esp + 0x14]
// 004e42f2  d95c2418             fstp dword ptr [esp + 0x18]
// 004e42f6  d905706e8200         fld dword ptr [0x826e70]
// 004e42fc  d91c24               fstp dword ptr [esp]
// 004e42ff  e87c590200           call 0x509c80
// 004e4304  a134399700           mov eax, dword ptr [0x973934]
// 004e4309  ddd8                 fstp st(0)
// 004e430b  d9842478010000       fld dword ptr [esp + 0x178]
// 004e4312  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e4316  d80d646e8200         fmul dword ptr [0x826e64]
// 004e431c  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 004e4320  03db                 add ebx, ebx
// 004e4322  03db                 add ebx, ebx
// 004e4324  d9542420             fst dword ptr [esp + 0x20]
// 004e4328  03db                 add ebx, ebx
// 004e432a  d9442410             fld dword ptr [esp + 0x10]
// 004e432e  d8c9                 fmul st(1)
// 004e4330  d9442414             fld dword ptr [esp + 0x14]
// 004e4334  deca                 fmulp st(2)
// 004e4336  d80406               fadd dword ptr [esi + eax]
// 004e4339  d9440604             fld dword ptr [esi + eax + 4]
// 004e433d  8d04c8               lea eax, [eax + ecx*8]
// 004e4340  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004e4344  dec2                 faddp st(2)
// 004e4346  03c9                 add ecx, ecx
// 004e4348  03c9                 add ecx, ecx
// 004e434a  d918                 fstp dword ptr [eax]
// 004e434c  03c9                 add ecx, ecx
// 004e434e  51                   push ecx
// 004e434f  d95804               fstp dword ptr [eax + 4]
// 004e4352  a134399700           mov eax, dword ptr [0x973934]
// 004e4357  d90401               fld dword ptr [ecx + eax]
// 004e435a  894c2428             mov dword ptr [esp + 0x28], ecx
// 004e435e  d82403               fsub dword ptr [ebx + eax]
// 004e4361  d9440104             fld dword ptr [ecx + eax + 4]
// 004e4365  8d4c2414             lea ecx, [esp + 0x14]
// 004e4369  d8640304             fsub dword ptr [ebx + eax + 4]
// 004e436d  d9c9                 fxch st(1)
// 004e436f  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4373  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4377  d905706e8200         fld dword ptr [0x826e70]
// 004e437d  d91c24               fstp dword ptr [esp]
// 004e4380  e8fb580200           call 0x509c80
// 004e4385  a134399700           mov eax, dword ptr [0x973934]
// 004e438a  ddd8                 fstp st(0)
// 004e438c  d9442420             fld dword ptr [esp + 0x20]
// 004e4390  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e4394  d9442410             fld dword ptr [esp + 0x10]
// 004e4398  8b542448             mov edx, dword ptr [esp + 0x48]
// 004e439c  d8c9                 fmul st(1)
// 004e439e  d9442414             fld dword ptr [esp + 0x14]
// 004e43a2  deca                 fmulp st(2)
// 004e43a4  d80401               fadd dword ptr [ecx + eax]
// 004e43a7  d9440104             fld dword ptr [ecx + eax + 4]
// 004e43ab  8d04d0               lea eax, [eax + edx*8]
// 004e43ae  dec2                 faddp st(2)
// 004e43b0  d918                 fstp dword ptr [eax]
// 004e43b2  d95804               fstp dword ptr [eax + 4]
// 004e43b5  a134399700           mov eax, dword ptr [0x973934]
// 004e43ba  d90401               fld dword ptr [ecx + eax]
// 004e43bd  d82406               fsub dword ptr [esi + eax]
// 004e43c0  d9440104             fld dword ptr [ecx + eax + 4]
// 004e43c4  d8640604             fsub dword ptr [esi + eax + 4]
// 004e43c8  d9c9                 fxch st(1)
// 004e43ca  d95c2410             fstp dword ptr [esp + 0x10]
// 004e43ce  d95c2414             fstp dword ptr [esp + 0x14]
// 004e43d2  51                   push ecx
// 004e43d3  d905706e8200         fld dword ptr [0x826e70]
// 004e43d9  8d4c2414             lea ecx, [esp + 0x14]
// 004e43dd  d91c24               fstp dword ptr [esp]
// 004e43e0  e89b580200           call 0x509c80
// 004e43e5  a134399700           mov eax, dword ptr [0x973934]
// 004e43ea  ddd8                 fstp st(0)
// 004e43ec  d9442420             fld dword ptr [esp + 0x20]
// 004e43f0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e43f4  d9442410             fld dword ptr [esp + 0x10]
// 004e43f8  d8c9                 fmul st(1)
// 004e43fa  d9442414             fld dword ptr [esp + 0x14]
// 004e43fe  deca                 fmulp st(2)
// 004e4400  d80401               fadd dword ptr [ecx + eax]
// 004e4403  d9440104             fld dword ptr [ecx + eax + 4]
// 004e4407  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 004e440e  dec2                 faddp st(2)
// 004e4410  8d04c8               lea eax, [eax + ecx*8]
// 004e4413  51                   push ecx
// 004e4414  8d4c2414             lea ecx, [esp + 0x14]
// 004e4418  d918                 fstp dword ptr [eax]
// 004e441a  d95804               fstp dword ptr [eax + 4]
// 004e441d  a134399700           mov eax, dword ptr [0x973934]
// 004e4422  d90403               fld dword ptr [ebx + eax]
// 004e4425  d82407               fsub dword ptr [edi + eax]
// 004e4428  d9440304             fld dword ptr [ebx + eax + 4]
// 004e442c  d8640704             fsub dword ptr [edi + eax + 4]
// 004e4430  d9c9                 fxch st(1)
// 004e4432  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4436  d95c2418             fstp dword ptr [esp + 0x18]
// 004e443a  d905706e8200         fld dword ptr [0x826e70]
// 004e4440  d91c24               fstp dword ptr [esp]
// 004e4443  e838580200           call 0x509c80
// 004e4448  a134399700           mov eax, dword ptr [0x973934]
// 004e444d  ddd8                 fstp st(0)
// 004e444f  d9442420             fld dword ptr [esp + 0x20]
// 004e4453  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 004e445a  d9442410             fld dword ptr [esp + 0x10]
// 004e445e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e4462  d8c9                 fmul st(1)
// 004e4464  51                   push ecx
// 004e4465  d9442418             fld dword ptr [esp + 0x18]
// 004e4469  deca                 fmulp st(2)
// 004e446b  d80403               fadd dword ptr [ebx + eax]
// 004e446e  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4472  8d04d0               lea eax, [eax + edx*8]
// 004e4475  dec2                 faddp st(2)
// 004e4477  d918                 fstp dword ptr [eax]
// 004e4479  d95804               fstp dword ptr [eax + 4]
// 004e447c  a134399700           mov eax, dword ptr [0x973934]
// 004e4481  d90403               fld dword ptr [ebx + eax]
// 004e4484  d82401               fsub dword ptr [ecx + eax]
// 004e4487  d9440304             fld dword ptr [ebx + eax + 4]
// 004e448b  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e448f  8d4c2414             lea ecx, [esp + 0x14]
// 004e4493  d9c9                 fxch st(1)
// 004e4495  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4499  d95c2418             fstp dword ptr [esp + 0x18]
// 004e449d  d905706e8200         fld dword ptr [0x826e70]
// 004e44a3  d91c24               fstp dword ptr [esp]
// 004e44a6  e8d5570200           call 0x509c80
// 004e44ab  a134399700           mov eax, dword ptr [0x973934]
// 004e44b0  ddd8                 fstp st(0)
// 004e44b2  d9442420             fld dword ptr [esp + 0x20]
// 004e44b6  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 004e44ba  d9442410             fld dword ptr [esp + 0x10]
// 004e44be  d8c9                 fmul st(1)
// 004e44c0  d9442414             fld dword ptr [esp + 0x14]
// 004e44c4  deca                 fmulp st(2)
// 004e44c6  d80403               fadd dword ptr [ebx + eax]
// 004e44c9  d9440304             fld dword ptr [ebx + eax + 4]
// 004e44cd  8d04c8               lea eax, [eax + ecx*8]
// 004e44d0  dec2                 faddp st(2)
// 004e44d2  d918                 fstp dword ptr [eax]
// 004e44d4  d95804               fstp dword ptr [eax + 4]
// 004e44d7  a134399700           mov eax, dword ptr [0x973934]
// 004e44dc  d90407               fld dword ptr [edi + eax]
// 004e44df  d82406               fsub dword ptr [esi + eax]
// 004e44e2  d9440704             fld dword ptr [edi + eax + 4]
// 004e44e6  d8640604             fsub dword ptr [esi + eax + 4]
// 004e44ea  d9c9                 fxch st(1)
// 004e44ec  51                   push ecx
// 004e44ed  d95c2414             fstp dword ptr [esp + 0x14]
// 004e44f1  8d4c2414             lea ecx, [esp + 0x14]
// 004e44f5  d95c2418             fstp dword ptr [esp + 0x18]
// 004e44f9  d905706e8200         fld dword ptr [0x826e70]
// 004e44ff  d91c24               fstp dword ptr [esp]
// 004e4502  e879570200           call 0x509c80
// 004e4507  a134399700           mov eax, dword ptr [0x973934]
// 004e450c  ddd8                 fstp st(0)
// 004e450e  d9442420             fld dword ptr [esp + 0x20]
// 004e4512  8b542478             mov edx, dword ptr [esp + 0x78]
// 004e4516  d9442410             fld dword ptr [esp + 0x10]
// 004e451a  51                   push ecx
// 004e451b  d8c9                 fmul st(1)
// 004e451d  8d4c2414             lea ecx, [esp + 0x14]
// 004e4521  d9442418             fld dword ptr [esp + 0x18]
// 004e4525  deca                 fmulp st(2)
// 004e4527  d80407               fadd dword ptr [edi + eax]
// 004e452a  d9440704             fld dword ptr [edi + eax + 4]
// 004e452e  8d04d0               lea eax, [eax + edx*8]
// 004e4531  dec2                 faddp st(2)
// 004e4533  d918                 fstp dword ptr [eax]
// 004e4535  d95804               fstp dword ptr [eax + 4]
// 004e4538  a134399700           mov eax, dword ptr [0x973934]
// 004e453d  d90407               fld dword ptr [edi + eax]
// 004e4540  d82403               fsub dword ptr [ebx + eax]
// 004e4543  d9440704             fld dword ptr [edi + eax + 4]
// 004e4547  d8640304             fsub dword ptr [ebx + eax + 4]
// 004e454b  d9c9                 fxch st(1)
// 004e454d  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4551  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4555  d905706e8200         fld dword ptr [0x826e70]
// 004e455b  d91c24               fstp dword ptr [esp]
// 004e455e  e81d570200           call 0x509c80
// 004e4563  a134399700           mov eax, dword ptr [0x973934]
// 004e4568  ddd8                 fstp st(0)
// 004e456a  d9442420             fld dword ptr [esp + 0x20]
// 004e456e  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004e4572  d9442410             fld dword ptr [esp + 0x10]
// 004e4576  d8c9                 fmul st(1)
// 004e4578  d9442414             fld dword ptr [esp + 0x14]
// 004e457c  deca                 fmulp st(2)
// 004e457e  d80407               fadd dword ptr [edi + eax]
// 004e4581  d9440704             fld dword ptr [edi + eax + 4]
// 004e4585  8d04c8               lea eax, [eax + ecx*8]
// 004e4588  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e458c  dec2                 faddp st(2)
// 004e458e  51                   push ecx
// 004e458f  d918                 fstp dword ptr [eax]
// 004e4591  d95804               fstp dword ptr [eax + 4]
// 004e4594  a134399700           mov eax, dword ptr [0x973934]
// 004e4599  d90406               fld dword ptr [esi + eax]
// 004e459c  d82401               fsub dword ptr [ecx + eax]
// 004e459f  d9440604             fld dword ptr [esi + eax + 4]
// 004e45a3  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e45a7  8d4c2414             lea ecx, [esp + 0x14]
// 004e45ab  d9c9                 fxch st(1)
// 004e45ad  d95c2414             fstp dword ptr [esp + 0x14]
// 004e45b1  d95c2418             fstp dword ptr [esp + 0x18]
// 004e45b5  d905706e8200         fld dword ptr [0x826e70]
// 004e45bb  d91c24               fstp dword ptr [esp]
// 004e45be  e8bd560200           call 0x509c80
// 004e45c3  a134399700           mov eax, dword ptr [0x973934]
// 004e45c8  ddd8                 fstp st(0)
// 004e45ca  d9442420             fld dword ptr [esp + 0x20]
// 004e45ce  8b542468             mov edx, dword ptr [esp + 0x68]
// 004e45d2  d9442410             fld dword ptr [esp + 0x10]
// 004e45d6  d8c9                 fmul st(1)
// 004e45d8  d9442414             fld dword ptr [esp + 0x14]
// 004e45dc  deca                 fmulp st(2)
// 004e45de  d80406               fadd dword ptr [esi + eax]
// 004e45e1  d9440604             fld dword ptr [esi + eax + 4]
// 004e45e5  8bb42480000000       mov esi, dword ptr [esp + 0x80]
// 004e45ec  dec2                 faddp st(2)
// 004e45ee  8d04d0               lea eax, [eax + edx*8]
// 004e45f1  03f6                 add esi, esi
// 004e45f3  03f6                 add esi, esi
// 004e45f5  d918                 fstp dword ptr [eax]
// 004e45f7  03f6                 add esi, esi
// 004e45f9  d95804               fstp dword ptr [eax + 4]
// 004e45fc  8b9c2484000000       mov ebx, dword ptr [esp + 0x84]
// 004e4603  a134399700           mov eax, dword ptr [0x973934]
// 004e4608  03db                 add ebx, ebx
// 004e460a  03db                 add ebx, ebx
// 004e460c  03db                 add ebx, ebx
// 004e460e  d90403               fld dword ptr [ebx + eax]
// 004e4611  51                   push ecx
// 004e4612  d82406               fsub dword ptr [esi + eax]
// 004e4615  8d4c2414             lea ecx, [esp + 0x14]
// 004e4619  d9440304             fld dword ptr [ebx + eax + 4]
// 004e461d  d8640604             fsub dword ptr [esi + eax + 4]
// 004e4621  d9c9                 fxch st(1)
// 004e4623  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4627  d95c2418             fstp dword ptr [esp + 0x18]
// 004e462b  d905706e8200         fld dword ptr [0x826e70]
// 004e4631  d91c24               fstp dword ptr [esp]
// 004e4634  e847560200           call 0x509c80
// 004e4639  a134399700           mov eax, dword ptr [0x973934]
// 004e463e  ddd8                 fstp st(0)
// 004e4640  d9442420             fld dword ptr [esp + 0x20]
// 004e4644  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004e4648  d9442410             fld dword ptr [esp + 0x10]
// 004e464c  8bbc2488000000       mov edi, dword ptr [esp + 0x88]
// 004e4653  d8c9                 fmul st(1)
// 004e4655  d9442414             fld dword ptr [esp + 0x14]
// 004e4659  deca                 fmulp st(2)
// 004e465b  d80403               fadd dword ptr [ebx + eax]
// 004e465e  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4662  8d04c8               lea eax, [eax + ecx*8]
// 004e4665  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 004e466c  dec2                 faddp st(2)
// 004e466e  03c9                 add ecx, ecx
// 004e4670  03c9                 add ecx, ecx
// 004e4672  d918                 fstp dword ptr [eax]
// 004e4674  03c9                 add ecx, ecx
// 004e4676  51                   push ecx
// 004e4677  d95804               fstp dword ptr [eax + 4]
// 004e467a  a134399700           mov eax, dword ptr [0x973934]
// 004e467f  d904f8               fld dword ptr [eax + edi*8]
// 004e4682  894c2428             mov dword ptr [esp + 0x28], ecx
// 004e4686  d82401               fsub dword ptr [ecx + eax]
// 004e4689  d944f804             fld dword ptr [eax + edi*8 + 4]
// 004e468d  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e4691  8d4c2414             lea ecx, [esp + 0x14]
// 004e4695  d9c9                 fxch st(1)
// 004e4697  d95c2414             fstp dword ptr [esp + 0x14]
// 004e469b  d95c2418             fstp dword ptr [esp + 0x18]
// 004e469f  d905706e8200         fld dword ptr [0x826e70]
// 004e46a5  d91c24               fstp dword ptr [esp]
// 004e46a8  e8d3550200           call 0x509c80
// 004e46ad  a134399700           mov eax, dword ptr [0x973934]
// 004e46b2  ddd8                 fstp st(0)
// 004e46b4  d9442420             fld dword ptr [esp + 0x20]
// 004e46b8  8b542440             mov edx, dword ptr [esp + 0x40]
// 004e46bc  d9442410             fld dword ptr [esp + 0x10]
// 004e46c0  51                   push ecx
// 004e46c1  d8c9                 fmul st(1)
// 004e46c3  8d4c2414             lea ecx, [esp + 0x14]
// 004e46c7  d9442418             fld dword ptr [esp + 0x18]
// 004e46cb  deca                 fmulp st(2)
// 004e46cd  d804f8               fadd dword ptr [eax + edi*8]
// 004e46d0  d944f804             fld dword ptr [eax + edi*8 + 4]
// 004e46d4  8d04d0               lea eax, [eax + edx*8]
// 004e46d7  dec2                 faddp st(2)
// 004e46d9  d918                 fstp dword ptr [eax]
// 004e46db  d95804               fstp dword ptr [eax + 4]
// 004e46de  a134399700           mov eax, dword ptr [0x973934]
// 004e46e3  d904f8               fld dword ptr [eax + edi*8]
// 004e46e6  d82403               fsub dword ptr [ebx + eax]
// 004e46e9  d944f804             fld dword ptr [eax + edi*8 + 4]
// 004e46ed  d8640304             fsub dword ptr [ebx + eax + 4]
// 004e46f1  d9c9                 fxch st(1)
// 004e46f3  d95c2414             fstp dword ptr [esp + 0x14]
// 004e46f7  d95c2418             fstp dword ptr [esp + 0x18]
// 004e46fb  d905706e8200         fld dword ptr [0x826e70]
// 004e4701  d91c24               fstp dword ptr [esp]
// 004e4704  e877550200           call 0x509c80
// 004e4709  ddd8                 fstp st(0)
// 004e470b  d9442420             fld dword ptr [esp + 0x20]
// 004e470f  d9442410             fld dword ptr [esp + 0x10]
// 004e4713  d8c9                 fmul st(1)
// 004e4715  d9442414             fld dword ptr [esp + 0x14]
// 004e4719  a134399700           mov eax, dword ptr [0x973934]
// 004e471e  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004e4722  deca                 fmulp st(2)
// 004e4724  d804f8               fadd dword ptr [eax + edi*8]
// 004e4727  d944f804             fld dword ptr [eax + edi*8 + 4]
// 004e472b  8d04c8               lea eax, [eax + ecx*8]
// 004e472e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e4732  dec2                 faddp st(2)
// 004e4734  51                   push ecx
// 004e4735  d918                 fstp dword ptr [eax]
// 004e4737  d95804               fstp dword ptr [eax + 4]
// 004e473a  a134399700           mov eax, dword ptr [0x973934]
// 004e473f  d90401               fld dword ptr [ecx + eax]
// 004e4742  d82406               fsub dword ptr [esi + eax]
// 004e4745  d9440104             fld dword ptr [ecx + eax + 4]
// 004e4749  8d4c2414             lea ecx, [esp + 0x14]
// 004e474d  d8640604             fsub dword ptr [esi + eax + 4]
// 004e4751  d9c9                 fxch st(1)
// 004e4753  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4757  d95c2418             fstp dword ptr [esp + 0x18]
// 004e475b  d905706e8200         fld dword ptr [0x826e70]
// 004e4761  d91c24               fstp dword ptr [esp]
// 004e4764  e817550200           call 0x509c80
// 004e4769  a134399700           mov eax, dword ptr [0x973934]
// 004e476e  ddd8                 fstp st(0)
// 004e4770  d9442420             fld dword ptr [esp + 0x20]
// 004e4774  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e4778  d9442410             fld dword ptr [esp + 0x10]
// 004e477c  8b542460             mov edx, dword ptr [esp + 0x60]
// 004e4780  d8c9                 fmul st(1)
// 004e4782  51                   push ecx
// 004e4783  d9442418             fld dword ptr [esp + 0x18]
// 004e4787  deca                 fmulp st(2)
// 004e4789  d80401               fadd dword ptr [ecx + eax]
// 004e478c  d9440104             fld dword ptr [ecx + eax + 4]
// 004e4790  8d04d0               lea eax, [eax + edx*8]
// 004e4793  dec2                 faddp st(2)
// 004e4795  d918                 fstp dword ptr [eax]
// 004e4797  d95804               fstp dword ptr [eax + 4]
// 004e479a  a134399700           mov eax, dword ptr [0x973934]
// 004e479f  d90401               fld dword ptr [ecx + eax]
// 004e47a2  d824f8               fsub dword ptr [eax + edi*8]
// 004e47a5  d9440104             fld dword ptr [ecx + eax + 4]
// 004e47a9  8d4c2414             lea ecx, [esp + 0x14]
// 004e47ad  d864f804             fsub dword ptr [eax + edi*8 + 4]
// 004e47b1  d9c9                 fxch st(1)
// 004e47b3  d95c2414             fstp dword ptr [esp + 0x14]
// 004e47b7  d95c2418             fstp dword ptr [esp + 0x18]
// 004e47bb  d905706e8200         fld dword ptr [0x826e70]
// 004e47c1  d91c24               fstp dword ptr [esp]
// 004e47c4  e8b7540200           call 0x509c80
// 004e47c9  a134399700           mov eax, dword ptr [0x973934]
// 004e47ce  ddd8                 fstp st(0)
// 004e47d0  d9442420             fld dword ptr [esp + 0x20]
// 004e47d4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e47d8  d9442410             fld dword ptr [esp + 0x10]
// 004e47dc  d8c9                 fmul st(1)
// 004e47de  d9442414             fld dword ptr [esp + 0x14]
// 004e47e2  deca                 fmulp st(2)
// 004e47e4  d80401               fadd dword ptr [ecx + eax]
// 004e47e7  d9440104             fld dword ptr [ecx + eax + 4]
// 004e47eb  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 004e47ef  dec2                 faddp st(2)
// 004e47f1  8d04c8               lea eax, [eax + ecx*8]
// 004e47f4  51                   push ecx
// 004e47f5  8d4c2414             lea ecx, [esp + 0x14]
// 004e47f9  d918                 fstp dword ptr [eax]
// 004e47fb  d95804               fstp dword ptr [eax + 4]
// 004e47fe  a134399700           mov eax, dword ptr [0x973934]
// 004e4803  d90406               fld dword ptr [esi + eax]
// 004e4806  d82403               fsub dword ptr [ebx + eax]
// 004e4809  d9440604             fld dword ptr [esi + eax + 4]
// 004e480d  d8640304             fsub dword ptr [ebx + eax + 4]
// 004e4811  d9c9                 fxch st(1)
// 004e4813  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4817  d95c2418             fstp dword ptr [esp + 0x18]
// 004e481b  d905706e8200         fld dword ptr [0x826e70]
// 004e4821  d91c24               fstp dword ptr [esp]
// 004e4824  e857540200           call 0x509c80
// 004e4829  ddd8                 fstp st(0)
// 004e482b  d9442420             fld dword ptr [esp + 0x20]
// 004e482f  a134399700           mov eax, dword ptr [0x973934]
// 004e4834  d9442410             fld dword ptr [esp + 0x10]
// 004e4838  8b542470             mov edx, dword ptr [esp + 0x70]
// 004e483c  d8c9                 fmul st(1)
// 004e483e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004e4842  d9442414             fld dword ptr [esp + 0x14]
// 004e4846  51                   push ecx
// 004e4847  deca                 fmulp st(2)
// 004e4849  d80406               fadd dword ptr [esi + eax]
// 004e484c  d9440604             fld dword ptr [esi + eax + 4]
// 004e4850  8d04d0               lea eax, [eax + edx*8]
// 004e4853  dec2                 faddp st(2)
// 004e4855  d918                 fstp dword ptr [eax]
// 004e4857  d95804               fstp dword ptr [eax + 4]
// 004e485a  a134399700           mov eax, dword ptr [0x973934]
// 004e485f  d90406               fld dword ptr [esi + eax]
// 004e4862  d82401               fsub dword ptr [ecx + eax]
// 004e4865  d9440604             fld dword ptr [esi + eax + 4]
// 004e4869  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e486d  8d4c2414             lea ecx, [esp + 0x14]
// 004e4871  d9c9                 fxch st(1)
// 004e4873  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4877  d95c2418             fstp dword ptr [esp + 0x18]
// 004e487b  d905706e8200         fld dword ptr [0x826e70]
// 004e4881  d91c24               fstp dword ptr [esp]
// 004e4884  e8f7530200           call 0x509c80
// 004e4889  a134399700           mov eax, dword ptr [0x973934]
// 004e488e  ddd8                 fstp st(0)
// 004e4890  d9442420             fld dword ptr [esp + 0x20]
// 004e4894  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 004e489b  d9442410             fld dword ptr [esp + 0x10]
// 004e489f  51                   push ecx
// 004e48a0  d8c9                 fmul st(1)
// 004e48a2  d9442418             fld dword ptr [esp + 0x18]
// 004e48a6  deca                 fmulp st(2)
// 004e48a8  d80406               fadd dword ptr [esi + eax]
// 004e48ab  d9440604             fld dword ptr [esi + eax + 4]
// 004e48af  8d04c8               lea eax, [eax + ecx*8]
// 004e48b2  dec2                 faddp st(2)
// 004e48b4  8d4c2414             lea ecx, [esp + 0x14]
// 004e48b8  d918                 fstp dword ptr [eax]
// 004e48ba  d95804               fstp dword ptr [eax + 4]
// 004e48bd  a134399700           mov eax, dword ptr [0x973934]
// 004e48c2  d90403               fld dword ptr [ebx + eax]
// 004e48c5  d824f8               fsub dword ptr [eax + edi*8]
// 004e48c8  d9440304             fld dword ptr [ebx + eax + 4]
// 004e48cc  d864f804             fsub dword ptr [eax + edi*8 + 4]
// 004e48d0  d9c9                 fxch st(1)
// 004e48d2  d95c2414             fstp dword ptr [esp + 0x14]
// 004e48d6  d95c2418             fstp dword ptr [esp + 0x18]
// 004e48da  d905706e8200         fld dword ptr [0x826e70]
// 004e48e0  d91c24               fstp dword ptr [esp]
// 004e48e3  e898530200           call 0x509c80
// 004e48e8  a134399700           mov eax, dword ptr [0x973934]
// 004e48ed  ddd8                 fstp st(0)
// 004e48ef  d9442420             fld dword ptr [esp + 0x20]
// 004e48f3  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 004e48fa  d9442410             fld dword ptr [esp + 0x10]
// 004e48fe  8b742428             mov esi, dword ptr [esp + 0x28]
// 004e4902  d8c9                 fmul st(1)
// 004e4904  8d4c2450             lea ecx, [esp + 0x50]
// 004e4908  d9442414             fld dword ptr [esp + 0x14]
// 004e490c  83c60c               add esi, 0xc
// 004e490f  deca                 fmulp st(2)
// 004e4911  d80403               fadd dword ptr [ebx + eax]
// 004e4914  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4918  8d04d0               lea eax, [eax + edx*8]
// 004e491b  dec2                 faddp st(2)
// 004e491d  8d542448             lea edx, [esp + 0x48]
// 004e4921  d918                 fstp dword ptr [eax]
// 004e4923  d95804               fstp dword ptr [eax + 4]
// 004e4926  8d44245c             lea eax, [esp + 0x5c]
// 004e492a  50                   push eax
// 004e492b  51                   push ecx
// 004e492c  52                   push edx
// 004e492d  8d442458             lea eax, [esp + 0x58]
// 004e4931  50                   push eax
// 004e4932  8bce                 mov ecx, esi
// 004e4934  e8677dffff           call 0x4dc6a0
// 004e4939  8d4c2458             lea ecx, [esp + 0x58]
// 004e493d  51                   push ecx
// 004e493e  8d542460             lea edx, [esp + 0x60]
// 004e4942  52                   push edx
// 004e4943  8d442470             lea eax, [esp + 0x70]
// 004e4947  50                   push eax
// 004e4948  8d4c2478             lea ecx, [esp + 0x78]
// 004e494c  51                   push ecx
// 004e494d  8bce                 mov ecx, esi
// 004e494f  e84c7dffff           call 0x4dc6a0
// 004e4954  8d542478             lea edx, [esp + 0x78]
// 004e4958  52                   push edx
// 004e4959  8d842480000000       lea eax, [esp + 0x80]
// 004e4960  50                   push eax
// 004e4961  8d4c245c             lea ecx, [esp + 0x5c]
// 004e4965  51                   push ecx
// 004e4966  8d542464             lea edx, [esp + 0x64]
// 004e496a  52                   push edx
// 004e496b  8bce                 mov ecx, esi
// 004e496d  e82e7dffff           call 0x4dc6a0
// 004e4972  8d842498000000       lea eax, [esp + 0x98]
// 004e4979  50                   push eax
// 004e497a  8d8c24a0000000       lea ecx, [esp + 0xa0]
// 004e4981  51                   push ecx
// 004e4982  8d542458             lea edx, [esp + 0x58]
// 004e4986  52                   push edx
// 004e4987  8d442460             lea eax, [esp + 0x60]
// 004e498b  50                   push eax
// 004e498c  8bce                 mov ecx, esi
// 004e498e  e80d7dffff           call 0x4dc6a0
// 004e4993  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 004e499a  8b8424b0000000       mov eax, dword ptr [esp + 0xb0]
// 004e49a1  8b9c24d8000000       mov ebx, dword ptr [esp + 0xd8]
// 004e49a8  8d8c2410010000       lea ecx, [esp + 0x110]
// 004e49af  51                   push ecx
// 004e49b0  8b8c24d8000000       mov ecx, dword ptr [esp + 0xd8]
// 004e49b7  52                   push edx
// 004e49b8  50                   push eax
// 004e49b9  51                   push ecx
// 004e49ba  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 004e49c1  53                   push ebx
// 004e49c2  8d54243c             lea edx, [esp + 0x3c]
// 004e49c6  52                   push edx
// 004e49c7  e8d480ffff           call 0x4dcaa0
// 004e49cc  a134399700           mov eax, dword ptr [0x973934]
// 004e49d1  8b8c24dc000000       mov ecx, dword ptr [esp + 0xdc]
// 004e49d8  03db                 add ebx, ebx
// 004e49da  03db                 add ebx, ebx
// 004e49dc  03db                 add ebx, ebx
// 004e49de  d90403               fld dword ptr [ebx + eax]
// 004e49e1  51                   push ecx
// 004e49e2  d824c8               fsub dword ptr [eax + ecx*8]
// 004e49e5  d9440304             fld dword ptr [ebx + eax + 4]
// 004e49e9  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e49ed  8d4c2414             lea ecx, [esp + 0x14]
// 004e49f1  d9c9                 fxch st(1)
// 004e49f3  d95c2414             fstp dword ptr [esp + 0x14]
// 004e49f7  d95c2418             fstp dword ptr [esp + 0x18]
// 004e49fb  d905706e8200         fld dword ptr [0x826e70]
// 004e4a01  d91c24               fstp dword ptr [esp]
// 004e4a04  e877520200           call 0x509c80
// 004e4a09  a134399700           mov eax, dword ptr [0x973934]
// 004e4a0e  ddd8                 fstp st(0)
// 004e4a10  d9442420             fld dword ptr [esp + 0x20]
// 004e4a14  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 004e4a1b  d9442410             fld dword ptr [esp + 0x10]
// 004e4a1f  d8c9                 fmul st(1)
// 004e4a21  d9442414             fld dword ptr [esp + 0x14]
// 004e4a25  deca                 fmulp st(2)
// 004e4a27  d80403               fadd dword ptr [ebx + eax]
// 004e4a2a  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4a2e  8b9c24d4000000       mov ebx, dword ptr [esp + 0xd4]
// 004e4a35  dec2                 faddp st(2)
// 004e4a37  8d04c8               lea eax, [eax + ecx*8]
// 004e4a3a  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 004e4a41  03db                 add ebx, ebx
// 004e4a43  d918                 fstp dword ptr [eax]
// 004e4a45  03db                 add ebx, ebx
// 004e4a47  03db                 add ebx, ebx
// 004e4a49  d95804               fstp dword ptr [eax + 4]
// 004e4a4c  a134399700           mov eax, dword ptr [0x973934]
// 004e4a51  d90403               fld dword ptr [ebx + eax]
// 004e4a54  d824c8               fsub dword ptr [eax + ecx*8]
// 004e4a57  51                   push ecx
// 004e4a58  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4a5c  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e4a60  8d4c2414             lea ecx, [esp + 0x14]
// 004e4a64  d9c9                 fxch st(1)
// 004e4a66  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4a6a  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4a6e  d905706e8200         fld dword ptr [0x826e70]
// 004e4a74  d91c24               fstp dword ptr [esp]
// 004e4a77  e804520200           call 0x509c80
// 004e4a7c  a134399700           mov eax, dword ptr [0x973934]
// 004e4a81  ddd8                 fstp st(0)
// 004e4a83  d9442420             fld dword ptr [esp + 0x20]
// 004e4a87  8b942418010000       mov edx, dword ptr [esp + 0x118]
// 004e4a8e  d9442410             fld dword ptr [esp + 0x10]
// 004e4a92  8b8c240c010000       mov ecx, dword ptr [esp + 0x10c]
// 004e4a99  d8c9                 fmul st(1)
// 004e4a9b  d9442414             fld dword ptr [esp + 0x14]
// 004e4a9f  deca                 fmulp st(2)
// 004e4aa1  d80403               fadd dword ptr [ebx + eax]
// 004e4aa4  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4aa8  8b9c24b8000000       mov ebx, dword ptr [esp + 0xb8]
// 004e4aaf  8d04d0               lea eax, [eax + edx*8]
// 004e4ab2  dec2                 faddp st(2)
// 004e4ab4  8b942400010000       mov edx, dword ptr [esp + 0x100]
// 004e4abb  d918                 fstp dword ptr [eax]
// 004e4abd  d95804               fstp dword ptr [eax + 4]
// 004e4ac0  8d842420010000       lea eax, [esp + 0x120]
// 004e4ac7  50                   push eax
// 004e4ac8  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 004e4acf  51                   push ecx
// 004e4ad0  52                   push edx
// 004e4ad1  50                   push eax
// 004e4ad2  53                   push ebx
// 004e4ad3  8d4c243c             lea ecx, [esp + 0x3c]
// 004e4ad7  51                   push ecx
// 004e4ad8  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 004e4adf  e8bc7fffff           call 0x4dcaa0
// 004e4ae4  a134399700           mov eax, dword ptr [0x973934]
// 004e4ae9  8b8c24bc000000       mov ecx, dword ptr [esp + 0xbc]
// 004e4af0  03db                 add ebx, ebx
// 004e4af2  03db                 add ebx, ebx
// 004e4af4  03db                 add ebx, ebx
// 004e4af6  d90403               fld dword ptr [ebx + eax]
// 004e4af9  51                   push ecx
// 004e4afa  d824c8               fsub dword ptr [eax + ecx*8]
// 004e4afd  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4b01  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e4b05  8d4c2414             lea ecx, [esp + 0x14]
// 004e4b09  d9c9                 fxch st(1)
// 004e4b0b  d95c2414             fstp dword ptr [esp + 0x14]
// 004e4b0f  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4b13  d905706e8200         fld dword ptr [0x826e70]
// 004e4b19  d91c24               fstp dword ptr [esp]
// 004e4b1c  e85f510200           call 0x509c80
// 004e4b21  a134399700           mov eax, dword ptr [0x973934]
// 004e4b26  ddd8                 fstp st(0)
// 004e4b28  d9442420             fld dword ptr [esp + 0x20]
// 004e4b2c  8b94242c010000       mov edx, dword ptr [esp + 0x12c]
// 004e4b33  d9442410             fld dword ptr [esp + 0x10]
// 004e4b37  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 004e4b3e  d8c9                 fmul st(1)
// 004e4b40  d9442414             fld dword ptr [esp + 0x14]
// 004e4b44  deca                 fmulp st(2)
// 004e4b46  d80403               fadd dword ptr [ebx + eax]
// 004e4b49  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4b4d  8b9c24b4000000       mov ebx, dword ptr [esp + 0xb4]
// 004e4b54  dec2                 faddp st(2)
// 004e4b56  8d04d0               lea eax, [eax + edx*8]
// 004e4b59  03db                 add ebx, ebx
// 004e4b5b  03db                 add ebx, ebx
// 004e4b5d  d918                 fstp dword ptr [eax]
// 004e4b5f  03db                 add ebx, ebx
// 004e4b61  d95804               fstp dword ptr [eax + 4]
// 004e4b64  a134399700           mov eax, dword ptr [0x973934]
// 004e4b69  d90403               fld dword ptr [ebx + eax]
// 004e4b6c  d824c8               fsub dword ptr [eax + ecx*8]
// 004e4b6f  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4b73  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e4b77  d9c9                 fxch st(1)
// 004e4b79  d95c2410             fstp dword ptr [esp + 0x10]
// 004e4b7d  51                   push ecx
// 004e4b7e  8d4c2414             lea ecx, [esp + 0x14]
// 004e4b82  d95c2418             fstp dword ptr [esp + 0x18]
// 004e4b86  d905706e8200         fld dword ptr [0x826e70]
// 004e4b8c  d91c24               fstp dword ptr [esp]
// 004e4b8f  e8ec500200           call 0x509c80
// 004e4b94  a134399700           mov eax, dword ptr [0x973934]
// 004e4b99  ddd8                 fstp st(0)
// 004e4b9b  d9442420             fld dword ptr [esp + 0x20]
// 004e4b9f  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 004e4ba6  d9442410             fld dword ptr [esp + 0x10]
// 004e4baa  8d942430010000       lea edx, [esp + 0x130]
// 004e4bb1  d8c9                 fmul st(1)
// 004e4bb3  52                   push edx
// 004e4bb4  d9442418             fld dword ptr [esp + 0x18]
// 004e4bb8  8b942408010000       mov edx, dword ptr [esp + 0x108]
// 004e4bbf  deca                 fmulp st(2)
// 004e4bc1  d80403               fadd dword ptr [ebx + eax]
// 004e4bc4  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4bc8  8d04c8               lea eax, [eax + ecx*8]
// 004e4bcb  8b8c24e4000000       mov ecx, dword ptr [esp + 0xe4]
// 004e4bd2  dec2                 faddp st(2)
// 004e4bd4  d918                 fstp dword ptr [eax]
// 004e4bd6  d95804               fstp dword ptr [eax + 4]
// 004e4bd9  8b8424f0000000       mov eax, dword ptr [esp + 0xf0]
// 004e4be0  50                   push eax
// 004e4be1  8b842410010000       mov eax, dword ptr [esp + 0x110]
// 004e4be8  51                   push ecx
// 004e4be9  52                   push edx
// 004e4bea  50                   push eax
// 004e4beb  8d4c243c             lea ecx, [esp + 0x3c]
// 004e4bef  51                   push ecx
// 004e4bf0  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 004e4bf7  e8a47effff           call 0x4dcaa0
// 004e4bfc  a134399700           mov eax, dword ptr [0x973934]
// 004e4c01  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004e4c05  d90403               fld dword ptr [ebx + eax]
// 004e4c08  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004e4c0c  d82401               fsub dword ptr [ecx + eax]
// 004e4c0f  51                   push ecx
// 004e4c10  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4c14  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e4c18  8d4c241c             lea ecx, [esp + 0x1c]
// 004e4c1c  d9c9                 fxch st(1)
// 004e4c1e  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e4c22  d95c2420             fstp dword ptr [esp + 0x20]
// 004e4c26  d905706e8200         fld dword ptr [0x826e70]
// 004e4c2c  d91c24               fstp dword ptr [esp]
// 004e4c2f  e84c500200           call 0x509c80
// 004e4c34  a134399700           mov eax, dword ptr [0x973934]
// 004e4c39  ddd8                 fstp st(0)
// 004e4c3b  d9442420             fld dword ptr [esp + 0x20]
// 004e4c3f  8b94243c010000       mov edx, dword ptr [esp + 0x13c]
// 004e4c46  d9442418             fld dword ptr [esp + 0x18]
// 004e4c4a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004e4c4e  d8c9                 fmul st(1)
// 004e4c50  51                   push ecx
// 004e4c51  d9442420             fld dword ptr [esp + 0x20]
// 004e4c55  deca                 fmulp st(2)
// 004e4c57  d80403               fadd dword ptr [ebx + eax]
// 004e4c5a  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4c5e  8d04d0               lea eax, [eax + edx*8]
// 004e4c61  dec2                 faddp st(2)
// 004e4c63  d918                 fstp dword ptr [eax]
// 004e4c65  d95804               fstp dword ptr [eax + 4]
// 004e4c68  a134399700           mov eax, dword ptr [0x973934]
// 004e4c6d  d90428               fld dword ptr [eax + ebp]
// 004e4c70  d82401               fsub dword ptr [ecx + eax]
// 004e4c73  d9442804             fld dword ptr [eax + ebp + 4]
// 004e4c77  d8640104             fsub dword ptr [ecx + eax + 4]
// 004e4c7b  8d4c241c             lea ecx, [esp + 0x1c]
// 004e4c7f  d9c9                 fxch st(1)
// 004e4c81  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e4c85  d95c2420             fstp dword ptr [esp + 0x20]
// 004e4c89  d905706e8200         fld dword ptr [0x826e70]
// 004e4c8f  d91c24               fstp dword ptr [esp]
// 004e4c92  e8e94f0200           call 0x509c80
// 004e4c97  ddd8                 fstp st(0)
// 004e4c99  d9442420             fld dword ptr [esp + 0x20]
// 004e4c9d  d9442418             fld dword ptr [esp + 0x18]
// 004e4ca1  a134399700           mov eax, dword ptr [0x973934]
// 004e4ca6  d8c9                 fmul st(1)
// 004e4ca8  d944241c             fld dword ptr [esp + 0x1c]
// 004e4cac  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004e4cb3  8b9c24e8000000       mov ebx, dword ptr [esp + 0xe8]
// 004e4cba  deca                 fmulp st(2)
// 004e4cbc  8d942440010000       lea edx, [esp + 0x140]
// 004e4cc3  52                   push edx
// 004e4cc4  d80428               fadd dword ptr [eax + ebp]
// 004e4cc7  8d54242c             lea edx, [esp + 0x2c]
// 004e4ccb  d9442804             fld dword ptr [eax + ebp + 4]
// 004e4ccf  8bac24e8000000       mov ebp, dword ptr [esp + 0xe8]
// 004e4cd6  8d04c8               lea eax, [eax + ecx*8]
// 004e4cd9  dec2                 faddp st(2)
// 004e4cdb  8b8c24d4000000       mov ecx, dword ptr [esp + 0xd4]
// 004e4ce2  d918                 fstp dword ptr [eax]
// 004e4ce4  d95804               fstp dword ptr [eax + 4]
// 004e4ce7  8b8424e0000000       mov eax, dword ptr [esp + 0xe0]
// 004e4cee  50                   push eax
// 004e4cef  51                   push ecx
// 004e4cf0  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 004e4cf7  55                   push ebp
// 004e4cf8  53                   push ebx
// 004e4cf9  52                   push edx
// 004e4cfa  e8a17dffff           call 0x4dcaa0
// 004e4cff  a134399700           mov eax, dword ptr [0x973934]
// 004e4d04  8b8c24ec000000       mov ecx, dword ptr [esp + 0xec]
// 004e4d0b  03db                 add ebx, ebx
// 004e4d0d  03db                 add ebx, ebx
// 004e4d0f  03db                 add ebx, ebx
// 004e4d11  d90403               fld dword ptr [ebx + eax]
// 004e4d14  51                   push ecx
// 004e4d15  d824c8               fsub dword ptr [eax + ecx*8]
// 004e4d18  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4d1c  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e4d20  8d4c241c             lea ecx, [esp + 0x1c]
// 004e4d24  d9c9                 fxch st(1)
// 004e4d26  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e4d2a  d95c2420             fstp dword ptr [esp + 0x20]
// 004e4d2e  d905706e8200         fld dword ptr [0x826e70]
// 004e4d34  d91c24               fstp dword ptr [esp]
// 004e4d37  e8444f0200           call 0x509c80
// 004e4d3c  a134399700           mov eax, dword ptr [0x973934]
// 004e4d41  ddd8                 fstp st(0)
// 004e4d43  d9442420             fld dword ptr [esp + 0x20]
// 004e4d47  8b8c244c010000       mov ecx, dword ptr [esp + 0x14c]
// 004e4d4e  d9442418             fld dword ptr [esp + 0x18]
// 004e4d52  d8c9                 fmul st(1)
// 004e4d54  d944241c             fld dword ptr [esp + 0x1c]
// 004e4d58  deca                 fmulp st(2)
// 004e4d5a  d80403               fadd dword ptr [ebx + eax]
// 004e4d5d  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4d61  8d04c8               lea eax, [eax + ecx*8]
// 004e4d64  8b8c24e0000000       mov ecx, dword ptr [esp + 0xe0]
// 004e4d6b  dec2                 faddp st(2)
// 004e4d6d  8d1ced00000000       lea ebx, [ebp*8]
// 004e4d74  51                   push ecx
// 004e4d75  d918                 fstp dword ptr [eax]
// 004e4d77  d95804               fstp dword ptr [eax + 4]
// 004e4d7a  a134399700           mov eax, dword ptr [0x973934]
// 004e4d7f  d90403               fld dword ptr [ebx + eax]
// 004e4d82  d824c8               fsub dword ptr [eax + ecx*8]
// 004e4d85  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4d89  d864c804             fsub dword ptr [eax + ecx*8 + 4]
// 004e4d8d  8d4c241c             lea ecx, [esp + 0x1c]
// 004e4d91  d9c9                 fxch st(1)
// 004e4d93  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e4d97  d95c2420             fstp dword ptr [esp + 0x20]
// 004e4d9b  d905706e8200         fld dword ptr [0x826e70]
// 004e4da1  d91c24               fstp dword ptr [esp]
// 004e4da4  e8d74e0200           call 0x509c80
// 004e4da9  a134399700           mov eax, dword ptr [0x973934]
// 004e4dae  ddd8                 fstp st(0)
// 004e4db0  d9442420             fld dword ptr [esp + 0x20]
// 004e4db4  d9442418             fld dword ptr [esp + 0x18]
// 004e4db8  d8c9                 fmul st(1)
// 004e4dba  d944241c             fld dword ptr [esp + 0x1c]
// 004e4dbe  deca                 fmulp st(2)
// 004e4dc0  d80403               fadd dword ptr [ebx + eax]
// 004e4dc3  d9440304             fld dword ptr [ebx + eax + 4]
// 004e4dc7  dec2                 faddp st(2)
// 004e4dc9  8b942448010000       mov edx, dword ptr [esp + 0x148]
// 004e4dd0  8d04d0               lea eax, [eax + edx*8]
// 004e4dd3  d918                 fstp dword ptr [eax]
// 004e4dd5  8d8c2494000000       lea ecx, [esp + 0x94]
// 004e4ddc  8d942480000000       lea edx, [esp + 0x80]
// 004e4de3  d95804               fstp dword ptr [eax + 4]
// 004e4de6  8d842490000000       lea eax, [esp + 0x90]
// 004e4ded  50                   push eax
// 004e4dee  51                   push ecx
// 004e4def  52                   push edx
// 004e4df0  8d842490000000       lea eax, [esp + 0x90]
// 004e4df7  50                   push eax
// 004e4df8  8bce                 mov ecx, esi
// 004e4dfa  e8a178ffff           call 0x4dc6a0
// 004e4dff  8d8c248c000000       lea ecx, [esp + 0x8c]
// 004e4e06  51                   push ecx
// 004e4e07  8d942484000000       lea edx, [esp + 0x84]
// 004e4e0e  52                   push edx
// 004e4e0f  8d442478             lea eax, [esp + 0x78]
// 004e4e13  50                   push eax
// 004e4e14  8d8c2480000000       lea ecx, [esp + 0x80]
// 004e4e1b  51                   push ecx
// 004e4e1c  8bce                 mov ecx, esi
// 004e4e1e  e87d78ffff           call 0x4dc6a0
// 004e4e23  8d942488000000       lea edx, [esp + 0x88]
// 004e4e2a  52                   push edx
// 004e4e2b  8d842490000000       lea eax, [esp + 0x90]
// 004e4e32  50                   push eax
// 004e4e33  8d4c2468             lea ecx, [esp + 0x68]
// 004e4e37  51                   push ecx
// 004e4e38  8d542470             lea edx, [esp + 0x70]
// 004e4e3c  52                   push edx
// 004e4e3d  8bce                 mov ecx, esi
// 004e4e3f  e85c78ffff           call 0x4dc6a0
// 004e4e44  8d842484000000       lea eax, [esp + 0x84]
// 004e4e4b  50                   push eax
// 004e4e4c  8d8c248c000000       lea ecx, [esp + 0x8c]
// 004e4e53  51                   push ecx
// 004e4e54  8d542448             lea edx, [esp + 0x48]
// 004e4e58  52                   push edx
// 004e4e59  8d442450             lea eax, [esp + 0x50]
// 004e4e5d  50                   push eax
// 004e4e5e  8bce                 mov ecx, esi
// 004e4e60  e83b78ffff           call 0x4dc6a0
// 004e4e65  8d4c244c             lea ecx, [esp + 0x4c]
// 004e4e69  51                   push ecx
// 004e4e6a  8bd1                 mov edx, ecx
// 004e4e6c  52                   push edx
// 004e4e6d  8d442470             lea eax, [esp + 0x70]
// 004e4e71  50                   push eax
// 004e4e72  8d4c2468             lea ecx, [esp + 0x68]
// 004e4e76  51                   push ecx
// 004e4e77  8bce                 mov ecx, esi
// 004e4e79  e82278ffff           call 0x4dc6a0
// 004e4e7e  8d94249c000000       lea edx, [esp + 0x9c]
// 004e4e85  52                   push edx
// 004e4e86  8bc2                 mov eax, edx
// 004e4e88  50                   push eax
// 004e4e89  8d4c2450             lea ecx, [esp + 0x50]
// 004e4e8d  51                   push ecx
// 004e4e8e  8d54245c             lea edx, [esp + 0x5c]
// 004e4e92  52                   push edx
// 004e4e93  8bce                 mov ecx, esi
// 004e4e95  e80678ffff           call 0x4dc6a0
// 004e4e9a  8d44247c             lea eax, [esp + 0x7c]
// 004e4e9e  50                   push eax
// 004e4e9f  8bc8                 mov ecx, eax
// 004e4ea1  51                   push ecx
// 004e4ea2  8d9424a0000000       lea edx, [esp + 0xa0]
// 004e4ea9  52                   push edx
// 004e4eaa  8d442460             lea eax, [esp + 0x60]
// 004e4eae  50                   push eax
// 004e4eaf  8bce                 mov ecx, esi
// 004e4eb1  e8ea77ffff           call 0x4dc6a0
// 004e4eb6  8d4c2478             lea ecx, [esp + 0x78]
// 004e4eba  51                   push ecx
// 004e4ebb  8bd1                 mov edx, ecx
// 004e4ebd  52                   push edx
// 004e4ebe  8d442460             lea eax, [esp + 0x60]
// 004e4ec2  50                   push eax
// 004e4ec3  8d4c2478             lea ecx, [esp + 0x78]
// 004e4ec7  51                   push ecx
// 004e4ec8  8bce                 mov ecx, esi
// 004e4eca  e8d177ffff           call 0x4dc6a0
// 004e4ecf  8d942494000000       lea edx, [esp + 0x94]
// 004e4ed6  52                   push edx
// 004e4ed7  8bc2                 mov eax, edx
// 004e4ed9  50                   push eax
// 004e4eda  8d4c2478             lea ecx, [esp + 0x78]
// 004e4ede  51                   push ecx
// 004e4edf  8d94248c000000       lea edx, [esp + 0x8c]
// 004e4ee6  52                   push edx
// 004e4ee7  8bce                 mov ecx, esi
// 004e4ee9  e8b277ffff           call 0x4dc6a0
// 004e4eee  8d442460             lea eax, [esp + 0x60]
// 004e4ef2  50                   push eax
// 004e4ef3  8bc8                 mov ecx, eax
// 004e4ef5  51                   push ecx
// 004e4ef6  8d942494000000       lea edx, [esp + 0x94]
// 004e4efd  52                   push edx
// 004e4efe  8d842480000000       lea eax, [esp + 0x80]
// 004e4f05  50                   push eax
// 004e4f06  8bce                 mov ecx, esi
// 004e4f08  e89377ffff           call 0x4dc6a0
// 004e4f0d  8d8c2488000000       lea ecx, [esp + 0x88]
// 004e4f14  51                   push ecx
// 004e4f15  8bd1                 mov edx, ecx
// 004e4f17  52                   push edx
// 004e4f18  8d44246c             lea eax, [esp + 0x6c]
// 004e4f1c  50                   push eax
// 004e4f1d  8d4c244c             lea ecx, [esp + 0x4c]
// 004e4f21  51                   push ecx
// 004e4f22  8bce                 mov ecx, esi
// 004e4f24  e87777ffff           call 0x4dc6a0
// 004e4f29  8d542444             lea edx, [esp + 0x44]
// 004e4f2d  52                   push edx
// 004e4f2e  8bc2                 mov eax, edx
// 004e4f30  50                   push eax
// 004e4f31  8d8c2498000000       lea ecx, [esp + 0x98]
// 004e4f38  51                   push ecx
// 004e4f39  8d942490000000       lea edx, [esp + 0x90]
// 004e4f40  52                   push edx
// 004e4f41  8bce                 mov ecx, esi
// 004e4f43  e85877ffff           call 0x4dc6a0
// 004e4f48  8b6c244c             mov ebp, dword ptr [esp + 0x4c]
// 004e4f4c  6a01                 push 1
// 004e4f4e  55                   push ebp
// 004e4f4f  e86c300600           call 0x547fc0
// 004e4f54  8b442450             mov eax, dword ptr [esp + 0x50]
// 004e4f58  6a01                 push 1
// 004e4f5a  50                   push eax
// 004e4f5b  e860300600           call 0x547fc0
// 004e4f60  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 004e4f64  6a01                 push 1
// 004e4f66  51                   push ecx
// 004e4f67  e854300600           call 0x547fc0
// 004e4f6c  8b5c2474             mov ebx, dword ptr [esp + 0x74]
// 004e4f70  6a01                 push 1
// 004e4f72  53                   push ebx
// 004e4f73  e848300600           call 0x547fc0
// 004e4f78  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 004e4f7f  6a01                 push 1
// 004e4f81  52                   push edx
// 004e4f82  e839300600           call 0x547fc0
// 004e4f87  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 004e4f8e  6a01                 push 1
// 004e4f90  50                   push eax
// 004e4f91  e82a300600           call 0x547fc0
// 004e4f96  6a01                 push 1
// 004e4f98  53                   push ebx
// 004e4f99  e822300600           call 0x547fc0
// 004e4f9e  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 004e4fa5  6a01                 push 1
// 004e4fa7  56                   push esi
// 004e4fa8  e813300600           call 0x547fc0
// 004e4fad  83c440               add esp, 0x40
// 004e4fb0  6a01                 push 1
// 004e4fb2  56                   push esi
// 004e4fb3  e808300600           call 0x547fc0
// 004e4fb8  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004e4fbc  6a01                 push 1
// 004e4fbe  51                   push ecx
// 004e4fbf  e8fc2f0600           call 0x547fc0
// 004e4fc4  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 004e4fcb  6a01                 push 1
// 004e4fcd  52                   push edx
// 004e4fce  e8ed2f0600           call 0x547fc0
// 004e4fd3  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 004e4fda  6a01                 push 1
// 004e4fdc  50                   push eax
// 004e4fdd  e8de2f0600           call 0x547fc0
// 004e4fe2  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 004e4fe6  6a01                 push 1
// 004e4fe8  51                   push ecx
// 004e4fe9  e8d22f0600           call 0x547fc0
// 004e4fee  8b542478             mov edx, dword ptr [esp + 0x78]
// 004e4ff2  6a01                 push 1
// 004e4ff4  52                   push edx
// 004e4ff5  e8c62f0600           call 0x547fc0
// 004e4ffa  8b8424cc000000       mov eax, dword ptr [esp + 0xcc]
// 004e5001  6a01                 push 1
// 004e5003  50                   push eax
// 004e5004  e8b72f0600           call 0x547fc0
// 004e5009  8b8c24d0000000       mov ecx, dword ptr [esp + 0xd0]
// 004e5010  6a01                 push 1
// 004e5012  51                   push ecx
// 004e5013  e8a82f0600           call 0x547fc0
// 004e5018  8b9424c4000000       mov edx, dword ptr [esp + 0xc4]
// 004e501f  83c440               add esp, 0x40
// 004e5022  6a01                 push 1
// 004e5024  52                   push edx
// 004e5025  e8962f0600           call 0x547fc0
// 004e502a  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 004e5031  6a01                 push 1
// 004e5033  50                   push eax
// 004e5034  e8872f0600           call 0x547fc0
// 004e5039  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 004e5040  6a01                 push 1
// 004e5042  51                   push ecx
// 004e5043  e8782f0600           call 0x547fc0
// 004e5048  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 004e504f  6a01                 push 1
// 004e5051  52                   push edx
// 004e5052  e8692f0600           call 0x547fc0
// 004e5057  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 004e505e  6a01                 push 1
// 004e5060  50                   push eax
// 004e5061  e85a2f0600           call 0x547fc0
// 004e5066  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 004e506d  6a01                 push 1
// 004e506f  51                   push ecx
// 004e5070  e84b2f0600           call 0x547fc0
// 004e5075  8b9424b0000000       mov edx, dword ptr [esp + 0xb0]
// 004e507c  6a01                 push 1
// 004e507e  52                   push edx
// 004e507f  e83c2f0600           call 0x547fc0
// 004e5084  8b8424c4000000       mov eax, dword ptr [esp + 0xc4]
// 004e508b  6a01                 push 1
// 004e508d  50                   push eax
// 004e508e  e82d2f0600           call 0x547fc0
// 004e5093  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 004e509a  83c440               add esp, 0x40
// 004e509d  6a01                 push 1
// 004e509f  51                   push ecx
// 004e50a0  e81b2f0600           call 0x547fc0
// 004e50a5  8b542468             mov edx, dword ptr [esp + 0x68]
// 004e50a9  6a01                 push 1
// 004e50ab  52                   push edx
// 004e50ac  e80f2f0600           call 0x547fc0
// 004e50b1  8b84249c000000       mov eax, dword ptr [esp + 0x9c]
// 004e50b8  6a01                 push 1
// 004e50ba  50                   push eax
// 004e50bb  e8002f0600           call 0x547fc0
// 004e50c0  6a01                 push 1
// 004e50c2  57                   push edi
// 004e50c3  e8f82e0600           call 0x547fc0
// 004e50c8  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004e50cc  6a01                 push 1
// 004e50ce  51                   push ecx
// 004e50cf  e8ec2e0600           call 0x547fc0
// 004e50d4  8b542468             mov edx, dword ptr [esp + 0x68]
// 004e50d8  6a01                 push 1
// 004e50da  52                   push edx
// 004e50db  e8e02e0600           call 0x547fc0
// 004e50e0  6a01                 push 1
// 004e50e2  57                   push edi
// 004e50e3  e8d82e0600           call 0x547fc0
// 004e50e8  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 004e50ef  6a01                 push 1
// 004e50f1  50                   push eax
// 004e50f2  e8c92e0600           call 0x547fc0
// 004e50f7  83c440               add esp, 0x40
// 004e50fa  6a01                 push 1
// 004e50fc  53                   push ebx
// 004e50fd  e8be2e0600           call 0x547fc0
// 004e5102  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 004e5106  6a01                 push 1
// 004e5108  51                   push ecx
// 004e5109  e8b22e0600           call 0x547fc0
// 004e510e  6a01                 push 1
// 004e5110  55                   push ebp
// 004e5111  e8aa2e0600           call 0x547fc0
// 004e5116  6a01                 push 1
// 004e5118  55                   push ebp
// 004e5119  e8a22e0600           call 0x547fc0
// 004e511e  8b542470             mov edx, dword ptr [esp + 0x70]
// 004e5122  6a01                 push 1
// 004e5124  52                   push edx
// 004e5125  e8962e0600           call 0x547fc0
// 004e512a  8b442470             mov eax, dword ptr [esp + 0x70]
// 004e512e  6a01                 push 1
// 004e5130  50                   push eax
// 004e5131  e88a2e0600           call 0x547fc0
// 004e5136  8b9c24cc000000       mov ebx, dword ptr [esp + 0xcc]
// 004e513d  6a01                 push 1
// 004e513f  53                   push ebx
// 004e5140  e87b2e0600           call 0x547fc0
// 004e5145  6a01                 push 1
// 004e5147  53                   push ebx
// 004e5148  e8732e0600           call 0x547fc0
// 004e514d  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 004e5154  83c440               add esp, 0x40
// 004e5157  6a01                 push 1
// 004e5159  51                   push ecx
// 004e515a  e8612e0600           call 0x547fc0
// 004e515f  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 004e5166  6a01                 push 1
// 004e5168  52                   push edx
// 004e5169  e8522e0600           call 0x547fc0
// 004e516e  8b9c248c000000       mov ebx, dword ptr [esp + 0x8c]
// 004e5175  6a01                 push 1
// 004e5177  53                   push ebx
// 004e5178  e8432e0600           call 0x547fc0
// 004e517d  6a01                 push 1
// 004e517f  53                   push ebx
// 004e5180  e83b2e0600           call 0x547fc0
// 004e5185  8b84248c000000       mov eax, dword ptr [esp + 0x8c]
// 004e518c  6a01                 push 1
// 004e518e  50                   push eax
// 004e518f  e82c2e0600           call 0x547fc0
// 004e5194  6a01                 push 1
// 004e5196  56                   push esi
// 004e5197  e8242e0600           call 0x547fc0
// 004e519c  8bb424a8000000       mov esi, dword ptr [esp + 0xa8]
// 004e51a3  6a01                 push 1
// 004e51a5  56                   push esi
// 004e51a6  e8152e0600           call 0x547fc0
// 004e51ab  6a01                 push 1
// 004e51ad  56                   push esi
// 004e51ae  e80d2e0600           call 0x547fc0
// 004e51b3  8b8c24c0000000       mov ecx, dword ptr [esp + 0xc0]
// 004e51ba  83c440               add esp, 0x40
// 004e51bd  6a01                 push 1
// 004e51bf  51                   push ecx
// 004e51c0  e8fb2d0600           call 0x547fc0
// 004e51c5  8b542478             mov edx, dword ptr [esp + 0x78]
// 004e51c9  6a01                 push 1
// 004e51cb  52                   push edx
// 004e51cc  e8ef2d0600           call 0x547fc0
// 004e51d1  8bb424a4000000       mov esi, dword ptr [esp + 0xa4]
// 004e51d8  6a01                 push 1
// 004e51da  56                   push esi
// 004e51db  e8e02d0600           call 0x547fc0
// 004e51e0  6a01                 push 1
// 004e51e2  56                   push esi
// 004e51e3  e8d82d0600           call 0x547fc0
// 004e51e8  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 004e51ef  6a01                 push 1
// 004e51f1  50                   push eax
// 004e51f2  e8c92d0600           call 0x547fc0
// 004e51f7  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 004e51fe  6a01                 push 1
// 004e5200  51                   push ecx
// 004e5201  e8ba2d0600           call 0x547fc0
// 004e5206  8bb42490000000       mov esi, dword ptr [esp + 0x90]
// 004e520d  6a01                 push 1
// 004e520f  56                   push esi
// 004e5210  e8ab2d0600           call 0x547fc0
// 004e5215  6a01                 push 1
// 004e5217  56                   push esi
// 004e5218  e8a32d0600           call 0x547fc0
// 004e521d  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 004e5224  83c440               add esp, 0x40
// 004e5227  6a01                 push 1
// 004e5229  52                   push edx
// 004e522a  e8912d0600           call 0x547fc0
// 004e522f  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004e5233  6a01                 push 1
// 004e5235  50                   push eax
// 004e5236  e8852d0600           call 0x547fc0
// 004e523b  6a01                 push 1
// 004e523d  57                   push edi
// 004e523e  e87d2d0600           call 0x547fc0
// 004e5243  6a01                 push 1
// 004e5245  57                   push edi
// 004e5246  e8752d0600           call 0x547fc0
// 004e524b  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 004e5252  6a01                 push 1
// 004e5254  51                   push ecx
// 004e5255  e8662d0600           call 0x547fc0
// 004e525a  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 004e5261  6a01                 push 1
// 004e5263  52                   push edx
// 004e5264  e8572d0600           call 0x547fc0
// 004e5269  8b742474             mov esi, dword ptr [esp + 0x74]
// 004e526d  6a01                 push 1
// 004e526f  56                   push esi
// 004e5270  e84b2d0600           call 0x547fc0
// 004e5275  6a01                 push 1
// 004e5277  56                   push esi
// 004e5278  e8432d0600           call 0x547fc0
// 004e527d  83c440               add esp, 0x40
// 004e5280  33f6                 xor esi, esi
// 004e5282  8b44b440             mov eax, dword ptr [esp + esi*4 + 0x40]
// 004e5286  6aff                 push -1
// 004e5288  50                   push eax
// 004e5289  e8322d0600           call 0x547fc0
// 004e528e  46                   inc esi
// 004e528f  83c408               add esp, 8
// 004e5292  83fe18               cmp esi, 0x18
// 004e5295  7ceb                 jl 0x4e5282
// 004e5297  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004e529b  5f                   pop edi
// 004e529c  c7842454010000ffffffff mov dword ptr [esp + 0x154], 0xffffffff
// 004e52a7  5d                   pop ebp
// 004e52a8  85db                 test ebx, ebx
// 004e52aa  743a                 je 0x4e52e6
// 004e52ac  8d4b04               lea ecx, [ebx + 4]
// 004e52af  51                   push ecx
// 004e52b0  ff15ac218000         call dword ptr [0x8021ac]
// 004e52b6  85c0                 test eax, eax
// 004e52b8  752c                 jne 0x4e52e6
// 004e52ba  8b7308               mov esi, dword ptr [ebx + 8]
// 004e52bd  85f6                 test esi, esi
// 004e52bf  741b                 je 0x4e52dc
// 004e52c1  8b0e                 mov ecx, dword ptr [esi]
// 004e52c3  8b11                 mov edx, dword ptr [ecx]
// 004e52c5  8b4204               mov eax, dword ptr [edx + 4]
// 004e52c8  ffd0                 call eax
// 004e52ca  8bc6                 mov eax, esi
// 004e52cc  8b7604               mov esi, dword ptr [esi + 4]
// 004e52cf  50                   push eax
// 004e52d0  e8a5b31b00           call 0x6a067a
// 004e52d5  83c404               add esp, 4
// 004e52d8  85f6                 test esi, esi
// 004e52da  75e5                 jne 0x4e52c1
// 004e52dc  8b13                 mov edx, dword ptr [ebx]
// 004e52de  8b02                 mov eax, dword ptr [edx]
// 004e52e0  6a01                 push 1
// 004e52e2  8bcb                 mov ecx, ebx
// 004e52e4  ffd0                 call eax
// 004e52e6  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 004e52ed  5e                   pop esi
// 004e52ee  5b                   pop ebx
// 004e52ef  64890d00000000       mov dword ptr fs:[0], ecx
// 004e52f6  81c44c010000         add esp, 0x14c
// 004e52fc  c21c00               ret 0x1c

void func_004e3ab0()
{
}
