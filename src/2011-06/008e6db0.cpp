// from server: 100% by auto
// roc 2011-06 008e6db0  unit: CXTColorHex  size: 2261 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e6db0
//
// 008e6db0  83ec40               sub esp, 0x40
// 008e6db3  53                   push ebx
// 008e6db4  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 008e6db7  55                   push ebp
// 008e6db8  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 008e6dbb  56                   push esi
// 008e6dbc  8b350c01a400         mov esi, dword ptr [0xa4010c]
// 008e6dc2  57                   push edi
// 008e6dc3  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 008e6dc7  83eb02               sub ebx, 2
// 008e6dca  4d                   dec ebp
// 008e6dcb  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6dd3  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6dd7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6dda  6a00                 push 0
// 008e6ddc  03c5                 add eax, ebp
// 008e6dde  50                   push eax
// 008e6ddf  53                   push ebx
// 008e6de0  51                   push ecx
// 008e6de1  ffd6                 call esi
// 008e6de3  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6de7  40                   inc eax
// 008e6de8  83f80b               cmp eax, 0xb
// 008e6deb  89442410             mov dword ptr [esp + 0x10], eax
// 008e6def  7ce2                 jl 0x8e6dd3
// 008e6df1  8b5704               mov edx, dword ptr [edi + 4]
// 008e6df4  6a00                 push 0
// 008e6df6  8d450b               lea eax, [ebp + 0xb]
// 008e6df9  8d4b01               lea ecx, [ebx + 1]
// 008e6dfc  50                   push eax
// 008e6dfd  51                   push ecx
// 008e6dfe  52                   push edx
// 008e6dff  894c2434             mov dword ptr [esp + 0x34], ecx
// 008e6e03  ffd6                 call esi
// 008e6e05  6a00                 push 0
// 008e6e07  8d450b               lea eax, [ebp + 0xb]
// 008e6e0a  50                   push eax
// 008e6e0b  8b4704               mov eax, dword ptr [edi + 4]
// 008e6e0e  8d4b02               lea ecx, [ebx + 2]
// 008e6e11  51                   push ecx
// 008e6e12  50                   push eax
// 008e6e13  ffd6                 call esi
// 008e6e15  6a00                 push 0
// 008e6e17  8d450c               lea eax, [ebp + 0xc]
// 008e6e1a  50                   push eax
// 008e6e1b  8d4b03               lea ecx, [ebx + 3]
// 008e6e1e  51                   push ecx
// 008e6e1f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6e22  51                   push ecx
// 008e6e23  ffd6                 call esi
// 008e6e25  8b5704               mov edx, dword ptr [edi + 4]
// 008e6e28  6a00                 push 0
// 008e6e2a  8d450c               lea eax, [ebp + 0xc]
// 008e6e2d  8d4b04               lea ecx, [ebx + 4]
// 008e6e30  50                   push eax
// 008e6e31  51                   push ecx
// 008e6e32  52                   push edx
// 008e6e33  894c2430             mov dword ptr [esp + 0x30], ecx
// 008e6e37  ffd6                 call esi
// 008e6e39  6a00                 push 0
// 008e6e3b  8d450d               lea eax, [ebp + 0xd]
// 008e6e3e  50                   push eax
// 008e6e3f  8b4704               mov eax, dword ptr [edi + 4]
// 008e6e42  8d4b05               lea ecx, [ebx + 5]
// 008e6e45  51                   push ecx
// 008e6e46  50                   push eax
// 008e6e47  894c242c             mov dword ptr [esp + 0x2c], ecx
// 008e6e4b  ffd6                 call esi
// 008e6e4d  6a00                 push 0
// 008e6e4f  8d450d               lea eax, [ebp + 0xd]
// 008e6e52  8d4b06               lea ecx, [ebx + 6]
// 008e6e55  50                   push eax
// 008e6e56  51                   push ecx
// 008e6e57  894c2424             mov dword ptr [esp + 0x24], ecx
// 008e6e5b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6e5e  51                   push ecx
// 008e6e5f  ffd6                 call esi
// 008e6e61  8d5307               lea edx, [ebx + 7]
// 008e6e64  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6e6c  89542414             mov dword ptr [esp + 0x14], edx
// 008e6e70  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e6e74  8b5704               mov edx, dword ptr [edi + 4]
// 008e6e77  6a00                 push 0
// 008e6e79  8d450e               lea eax, [ebp + 0xe]
// 008e6e7c  50                   push eax
// 008e6e7d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6e81  03c1                 add eax, ecx
// 008e6e83  50                   push eax
// 008e6e84  52                   push edx
// 008e6e85  ffd6                 call esi
// 008e6e87  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6e8b  40                   inc eax
// 008e6e8c  83f805               cmp eax, 5
// 008e6e8f  89442410             mov dword ptr [esp + 0x10], eax
// 008e6e93  7cdb                 jl 0x8e6e70
// 008e6e95  6a00                 push 0
// 008e6e97  8d4d0d               lea ecx, [ebp + 0xd]
// 008e6e9a  51                   push ecx
// 008e6e9b  8d430c               lea eax, [ebx + 0xc]
// 008e6e9e  50                   push eax
// 008e6e9f  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ea2  50                   push eax
// 008e6ea3  ffd6                 call esi
// 008e6ea5  6a00                 push 0
// 008e6ea7  8d4d0d               lea ecx, [ebp + 0xd]
// 008e6eaa  51                   push ecx
// 008e6eab  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6eae  8d430d               lea eax, [ebx + 0xd]
// 008e6eb1  50                   push eax
// 008e6eb2  51                   push ecx
// 008e6eb3  ffd6                 call esi
// 008e6eb5  8b5704               mov edx, dword ptr [edi + 4]
// 008e6eb8  6a00                 push 0
// 008e6eba  8d4d0c               lea ecx, [ebp + 0xc]
// 008e6ebd  51                   push ecx
// 008e6ebe  8d430e               lea eax, [ebx + 0xe]
// 008e6ec1  50                   push eax
// 008e6ec2  52                   push edx
// 008e6ec3  ffd6                 call esi
// 008e6ec5  6a00                 push 0
// 008e6ec7  8d4d0c               lea ecx, [ebp + 0xc]
// 008e6eca  51                   push ecx
// 008e6ecb  8d430f               lea eax, [ebx + 0xf]
// 008e6ece  50                   push eax
// 008e6ecf  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ed2  50                   push eax
// 008e6ed3  ffd6                 call esi
// 008e6ed5  6a00                 push 0
// 008e6ed7  8d4d0b               lea ecx, [ebp + 0xb]
// 008e6eda  51                   push ecx
// 008e6edb  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6ede  8d4310               lea eax, [ebx + 0x10]
// 008e6ee1  50                   push eax
// 008e6ee2  51                   push ecx
// 008e6ee3  ffd6                 call esi
// 008e6ee5  8b5704               mov edx, dword ptr [edi + 4]
// 008e6ee8  6a00                 push 0
// 008e6eea  8d4d0b               lea ecx, [ebp + 0xb]
// 008e6eed  51                   push ecx
// 008e6eee  8d4311               lea eax, [ebx + 0x11]
// 008e6ef1  50                   push eax
// 008e6ef2  52                   push edx
// 008e6ef3  ffd6                 call esi
// 008e6ef5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6efd  8d4900               lea ecx, [ecx]
// 008e6f00  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6f04  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6f07  6a00                 push 0
// 008e6f09  03c5                 add eax, ebp
// 008e6f0b  50                   push eax
// 008e6f0c  8d4312               lea eax, [ebx + 0x12]
// 008e6f0f  50                   push eax
// 008e6f10  51                   push ecx
// 008e6f11  ffd6                 call esi
// 008e6f13  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6f17  40                   inc eax
// 008e6f18  83f80b               cmp eax, 0xb
// 008e6f1b  89442410             mov dword ptr [esp + 0x10], eax
// 008e6f1f  7cdf                 jl 0x8e6f00
// 008e6f21  8b5704               mov edx, dword ptr [edi + 4]
// 008e6f24  6a00                 push 0
// 008e6f26  8d45ff               lea eax, [ebp - 1]
// 008e6f29  50                   push eax
// 008e6f2a  8944245c             mov dword ptr [esp + 0x5c], eax
// 008e6f2e  8d4310               lea eax, [ebx + 0x10]
// 008e6f31  50                   push eax
// 008e6f32  52                   push edx
// 008e6f33  ffd6                 call esi
// 008e6f35  8b442454             mov eax, dword ptr [esp + 0x54]
// 008e6f39  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6f3c  6a00                 push 0
// 008e6f3e  50                   push eax
// 008e6f3f  8d4311               lea eax, [ebx + 0x11]
// 008e6f42  50                   push eax
// 008e6f43  51                   push ecx
// 008e6f44  ffd6                 call esi
// 008e6f46  8b5704               mov edx, dword ptr [edi + 4]
// 008e6f49  6a00                 push 0
// 008e6f4b  8d45fe               lea eax, [ebp - 2]
// 008e6f4e  50                   push eax
// 008e6f4f  8d430e               lea eax, [ebx + 0xe]
// 008e6f52  50                   push eax
// 008e6f53  52                   push edx
// 008e6f54  ffd6                 call esi
// 008e6f56  6a00                 push 0
// 008e6f58  8d45fe               lea eax, [ebp - 2]
// 008e6f5b  50                   push eax
// 008e6f5c  8d430f               lea eax, [ebx + 0xf]
// 008e6f5f  50                   push eax
// 008e6f60  8b4704               mov eax, dword ptr [edi + 4]
// 008e6f63  50                   push eax
// 008e6f64  ffd6                 call esi
// 008e6f66  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6f69  6a00                 push 0
// 008e6f6b  8d45fd               lea eax, [ebp - 3]
// 008e6f6e  50                   push eax
// 008e6f6f  8d430c               lea eax, [ebx + 0xc]
// 008e6f72  50                   push eax
// 008e6f73  51                   push ecx
// 008e6f74  ffd6                 call esi
// 008e6f76  8b5704               mov edx, dword ptr [edi + 4]
// 008e6f79  6a00                 push 0
// 008e6f7b  8d45fd               lea eax, [ebp - 3]
// 008e6f7e  50                   push eax
// 008e6f7f  8d430d               lea eax, [ebx + 0xd]
// 008e6f82  50                   push eax
// 008e6f83  52                   push edx
// 008e6f84  ffd6                 call esi
// 008e6f86  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6f8e  8bff                 mov edi, edi
// 008e6f90  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e6f94  8b5704               mov edx, dword ptr [edi + 4]
// 008e6f97  6a00                 push 0
// 008e6f99  8d45fc               lea eax, [ebp - 4]
// 008e6f9c  50                   push eax
// 008e6f9d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6fa1  03c1                 add eax, ecx
// 008e6fa3  50                   push eax
// 008e6fa4  52                   push edx
// 008e6fa5  ffd6                 call esi
// 008e6fa7  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6fab  40                   inc eax
// 008e6fac  83f805               cmp eax, 5
// 008e6faf  89442410             mov dword ptr [esp + 0x10], eax
// 008e6fb3  7cdb                 jl 0x8e6f90
// 008e6fb5  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6fb8  6a00                 push 0
// 008e6fba  8d45fd               lea eax, [ebp - 3]
// 008e6fbd  50                   push eax
// 008e6fbe  8b442424             mov eax, dword ptr [esp + 0x24]
// 008e6fc2  50                   push eax
// 008e6fc3  51                   push ecx
// 008e6fc4  ffd6                 call esi
// 008e6fc6  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e6fca  6a00                 push 0
// 008e6fcc  8d45fd               lea eax, [ebp - 3]
// 008e6fcf  50                   push eax
// 008e6fd0  8b4704               mov eax, dword ptr [edi + 4]
// 008e6fd3  52                   push edx
// 008e6fd4  50                   push eax
// 008e6fd5  ffd6                 call esi
// 008e6fd7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6fda  6a00                 push 0
// 008e6fdc  8d45fe               lea eax, [ebp - 2]
// 008e6fdf  50                   push eax
// 008e6fe0  8d4303               lea eax, [ebx + 3]
// 008e6fe3  50                   push eax
// 008e6fe4  51                   push ecx
// 008e6fe5  ffd6                 call esi
// 008e6fe7  8b542420             mov edx, dword ptr [esp + 0x20]
// 008e6feb  6a00                 push 0
// 008e6fed  8d45fe               lea eax, [ebp - 2]
// 008e6ff0  50                   push eax
// 008e6ff1  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ff4  52                   push edx
// 008e6ff5  50                   push eax
// 008e6ff6  ffd6                 call esi
// 008e6ff8  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e6ffc  8b542424             mov edx, dword ptr [esp + 0x24]
// 008e7000  8b4704               mov eax, dword ptr [edi + 4]
// 008e7003  6a00                 push 0
// 008e7005  51                   push ecx
// 008e7006  52                   push edx
// 008e7007  50                   push eax
// 008e7008  ffd6                 call esi
// 008e700a  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e700e  8b5704               mov edx, dword ptr [edi + 4]
// 008e7011  6a00                 push 0
// 008e7013  51                   push ecx
// 008e7014  8d4302               lea eax, [ebx + 2]
// 008e7017  50                   push eax
// 008e7018  52                   push edx
// 008e7019  ffd6                 call esi
// 008e701b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e7023  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7027  8b5704               mov edx, dword ptr [edi + 4]
// 008e702a  6a00                 push 0
// 008e702c  8d4c2802             lea ecx, [eax + ebp + 2]
// 008e7030  51                   push ecx
// 008e7031  8d4303               lea eax, [ebx + 3]
// 008e7034  50                   push eax
// 008e7035  52                   push edx
// 008e7036  ffd6                 call esi
// 008e7038  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e703c  40                   inc eax
// 008e703d  83f807               cmp eax, 7
// 008e7040  89442410             mov dword ptr [esp + 0x10], eax
// 008e7044  7cdd                 jl 0x8e7023
// 008e7046  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7049  6a00                 push 0
// 008e704b  8d4509               lea eax, [ebp + 9]
// 008e704e  50                   push eax
// 008e704f  8b442428             mov eax, dword ptr [esp + 0x28]
// 008e7053  50                   push eax
// 008e7054  51                   push ecx
// 008e7055  ffd6                 call esi
// 008e7057  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008e705b  6a00                 push 0
// 008e705d  8d4509               lea eax, [ebp + 9]
// 008e7060  50                   push eax
// 008e7061  8b4704               mov eax, dword ptr [edi + 4]
// 008e7064  52                   push edx
// 008e7065  50                   push eax
// 008e7066  ffd6                 call esi
// 008e7068  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008e706c  8b5704               mov edx, dword ptr [edi + 4]
// 008e706f  6a00                 push 0
// 008e7071  8d450a               lea eax, [ebp + 0xa]
// 008e7074  50                   push eax
// 008e7075  51                   push ecx
// 008e7076  52                   push edx
// 008e7077  ffd6                 call esi
// 008e7079  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e707c  6a00                 push 0
// 008e707e  8d450a               lea eax, [ebp + 0xa]
// 008e7081  50                   push eax
// 008e7082  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e7086  50                   push eax
// 008e7087  51                   push ecx
// 008e7088  ffd6                 call esi
// 008e708a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e7092  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e7096  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7099  6a00                 push 0
// 008e709b  8d450b               lea eax, [ebp + 0xb]
// 008e709e  50                   push eax
// 008e709f  8d441308             lea eax, [ebx + edx + 8]
// 008e70a3  50                   push eax
// 008e70a4  51                   push ecx
// 008e70a5  ffd6                 call esi
// 008e70a7  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e70ab  40                   inc eax
// 008e70ac  83f803               cmp eax, 3
// 008e70af  89442410             mov dword ptr [esp + 0x10], eax
// 008e70b3  7cdd                 jl 0x8e7092
// 008e70b5  8b5704               mov edx, dword ptr [edi + 4]
// 008e70b8  6a00                 push 0
// 008e70ba  8d4d0a               lea ecx, [ebp + 0xa]
// 008e70bd  51                   push ecx
// 008e70be  8d430b               lea eax, [ebx + 0xb]
// 008e70c1  50                   push eax
// 008e70c2  52                   push edx
// 008e70c3  ffd6                 call esi
// 008e70c5  6a00                 push 0
// 008e70c7  8d450a               lea eax, [ebp + 0xa]
// 008e70ca  50                   push eax
// 008e70cb  8d430c               lea eax, [ebx + 0xc]
// 008e70ce  50                   push eax
// 008e70cf  8b4704               mov eax, dword ptr [edi + 4]
// 008e70d2  50                   push eax
// 008e70d3  ffd6                 call esi
// 008e70d5  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e70d8  6a00                 push 0
// 008e70da  8d4509               lea eax, [ebp + 9]
// 008e70dd  50                   push eax
// 008e70de  8d430d               lea eax, [ebx + 0xd]
// 008e70e1  50                   push eax
// 008e70e2  51                   push ecx
// 008e70e3  ffd6                 call esi
// 008e70e5  8b5704               mov edx, dword ptr [edi + 4]
// 008e70e8  6a00                 push 0
// 008e70ea  8d4509               lea eax, [ebp + 9]
// 008e70ed  50                   push eax
// 008e70ee  8d430e               lea eax, [ebx + 0xe]
// 008e70f1  50                   push eax
// 008e70f2  52                   push edx
// 008e70f3  ffd6                 call esi
// 008e70f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e70fd  8d4900               lea ecx, [ecx]
// 008e7100  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7104  8b5704               mov edx, dword ptr [edi + 4]
// 008e7107  6a00                 push 0
// 008e7109  8d4c2802             lea ecx, [eax + ebp + 2]
// 008e710d  51                   push ecx
// 008e710e  8d430f               lea eax, [ebx + 0xf]
// 008e7111  50                   push eax
// 008e7112  52                   push edx
// 008e7113  ffd6                 call esi
// 008e7115  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7119  40                   inc eax
// 008e711a  83f807               cmp eax, 7
// 008e711d  89442410             mov dword ptr [esp + 0x10], eax
// 008e7121  7cdd                 jl 0x8e7100
// 008e7123  6a00                 push 0
// 008e7125  8d4501               lea eax, [ebp + 1]
// 008e7128  50                   push eax
// 008e7129  8d430d               lea eax, [ebx + 0xd]
// 008e712c  50                   push eax
// 008e712d  8b4704               mov eax, dword ptr [edi + 4]
// 008e7130  50                   push eax
// 008e7131  ffd6                 call esi
// 008e7133  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7136  6a00                 push 0
// 008e7138  8d4501               lea eax, [ebp + 1]
// 008e713b  50                   push eax
// 008e713c  8d430e               lea eax, [ebx + 0xe]
// 008e713f  50                   push eax
// 008e7140  51                   push ecx
// 008e7141  ffd6                 call esi
// 008e7143  8b5704               mov edx, dword ptr [edi + 4]
// 008e7146  6a00                 push 0
// 008e7148  55                   push ebp
// 008e7149  8d430b               lea eax, [ebx + 0xb]
// 008e714c  50                   push eax
// 008e714d  52                   push edx
// 008e714e  ffd6                 call esi
// 008e7150  6a00                 push 0
// 008e7152  55                   push ebp
// 008e7153  8d430c               lea eax, [ebx + 0xc]
// 008e7156  50                   push eax
// 008e7157  8b4704               mov eax, dword ptr [edi + 4]
// 008e715a  50                   push eax
// 008e715b  ffd6                 call esi
// 008e715d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e7165  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e7169  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e716d  6a00                 push 0
// 008e716f  51                   push ecx
// 008e7170  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7173  8d441308             lea eax, [ebx + edx + 8]
// 008e7177  50                   push eax
// 008e7178  51                   push ecx
// 008e7179  ffd6                 call esi
// 008e717b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e717f  40                   inc eax
// 008e7180  83f803               cmp eax, 3
// 008e7183  89442410             mov dword ptr [esp + 0x10], eax
// 008e7187  7cdc                 jl 0x8e7165
// 008e7189  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e718d  8b4704               mov eax, dword ptr [edi + 4]
// 008e7190  6a00                 push 0
// 008e7192  55                   push ebp
// 008e7193  52                   push edx
// 008e7194  50                   push eax
// 008e7195  ffd6                 call esi
// 008e7197  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e719b  8b5704               mov edx, dword ptr [edi + 4]
// 008e719e  6a00                 push 0
// 008e71a0  55                   push ebp
// 008e71a1  51                   push ecx
// 008e71a2  52                   push edx
// 008e71a3  ffd6                 call esi
// 008e71a5  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e71a9  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e71ac  6a00                 push 0
// 008e71ae  8d5d01               lea ebx, [ebp + 1]
// 008e71b1  53                   push ebx
// 008e71b2  50                   push eax
// 008e71b3  51                   push ecx
// 008e71b4  ffd6                 call esi
// 008e71b6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008e71ba  8b4704               mov eax, dword ptr [edi + 4]
// 008e71bd  6a00                 push 0
// 008e71bf  53                   push ebx
// 008e71c0  52                   push edx
// 008e71c1  50                   push eax
// 008e71c2  ffd6                 call esi
// 008e71c4  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008e71c8  896c2420             mov dword ptr [esp + 0x20], ebp
// 008e71cc  c74424240b000000     mov dword ptr [esp + 0x24], 0xb
// 008e71d4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e71d8  8b5704               mov edx, dword ptr [edi + 4]
// 008e71db  68ffffff00           push 0xffffff
// 008e71e0  51                   push ecx
// 008e71e1  53                   push ebx
// 008e71e2  52                   push edx
// 008e71e3  ffd6                 call esi
// 008e71e5  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e71e9  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e71ec  68ffffff00           push 0xffffff
// 008e71f1  50                   push eax
// 008e71f2  8d4301               lea eax, [ebx + 1]
// 008e71f5  50                   push eax
// 008e71f6  51                   push ecx
// 008e71f7  ffd6                 call esi
// 008e71f9  b801000000           mov eax, 1
// 008e71fe  01442420             add dword ptr [esp + 0x20], eax
// 008e7202  29442424             sub dword ptr [esp + 0x24], eax
// 008e7206  75cc                 jne 0x8e71d4
// 008e7208  8d5302               lea edx, [ebx + 2]
// 008e720b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e7213  89542444             mov dword ptr [esp + 0x44], edx
// 008e7217  eb07                 jmp 0x8e7220
// 008e7219  8da42400000000       lea esp, [esp]
// 008e7220  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e7224  8b542444             mov edx, dword ptr [esp + 0x44]
// 008e7228  68ffffff00           push 0xffffff
// 008e722d  8d4c2809             lea ecx, [eax + ebp + 9]
// 008e7231  8b4704               mov eax, dword ptr [edi + 4]
// 008e7234  51                   push ecx
// 008e7235  52                   push edx
// 008e7236  50                   push eax
// 008e7237  ffd6                 call esi
// 008e7239  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e723d  40                   inc eax
// 008e723e  83f803               cmp eax, 3
// 008e7241  89442410             mov dword ptr [esp + 0x10], eax
// 008e7245  7cd9                 jl 0x8e7220
// 008e7247  68ffffff00           push 0xffffff
// 008e724c  8d4d0a               lea ecx, [ebp + 0xa]
// 008e724f  51                   push ecx
// 008e7250  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7253  8d4303               lea eax, [ebx + 3]
// 008e7256  50                   push eax
// 008e7257  51                   push ecx
// 008e7258  89442450             mov dword ptr [esp + 0x50], eax
// 008e725c  ffd6                 call esi
// 008e725e  8b542440             mov edx, dword ptr [esp + 0x40]
// 008e7262  68ffffff00           push 0xffffff
// 008e7267  8d450b               lea eax, [ebp + 0xb]
// 008e726a  50                   push eax
// 008e726b  8b4704               mov eax, dword ptr [edi + 4]
// 008e726e  52                   push edx
// 008e726f  50                   push eax
// 008e7270  ffd6                 call esi
// 008e7272  8d4b04               lea ecx, [ebx + 4]
// 008e7275  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e727d  894c2420             mov dword ptr [esp + 0x20], ecx
// 008e7281  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e7285  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e7289  68ffffff00           push 0xffffff
// 008e728e  8d442a0a             lea eax, [edx + ebp + 0xa]
// 008e7292  8b5704               mov edx, dword ptr [edi + 4]
// 008e7295  50                   push eax
// 008e7296  51                   push ecx
// 008e7297  52                   push edx
// 008e7298  ffd6                 call esi
// 008e729a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e729e  40                   inc eax
// 008e729f  83f803               cmp eax, 3
// 008e72a2  89442410             mov dword ptr [esp + 0x10], eax
// 008e72a6  7cd9                 jl 0x8e7281
// 008e72a8  68ffffff00           push 0xffffff
// 008e72ad  8d4d0b               lea ecx, [ebp + 0xb]
// 008e72b0  8d4305               lea eax, [ebx + 5]
// 008e72b3  51                   push ecx
// 008e72b4  50                   push eax
// 008e72b5  89442428             mov dword ptr [esp + 0x28], eax
// 008e72b9  8b4704               mov eax, dword ptr [edi + 4]
// 008e72bc  50                   push eax
// 008e72bd  ffd6                 call esi
// 008e72bf  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008e72c3  8b5704               mov edx, dword ptr [edi + 4]
// 008e72c6  68ffffff00           push 0xffffff
// 008e72cb  8d450c               lea eax, [ebp + 0xc]
// 008e72ce  50                   push eax
// 008e72cf  51                   push ecx
// 008e72d0  52                   push edx
// 008e72d1  ffd6                 call esi
// 008e72d3  8d4306               lea eax, [ebx + 6]
// 008e72d6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e72de  89442418             mov dword ptr [esp + 0x18], eax
// 008e72e2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e72e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e72ea  68ffffff00           push 0xffffff
// 008e72ef  8d54290b             lea edx, [ecx + ebp + 0xb]
// 008e72f3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e72f6  52                   push edx
// 008e72f7  50                   push eax
// 008e72f8  51                   push ecx
// 008e72f9  ffd6                 call esi
// 008e72fb  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e72ff  40                   inc eax
// 008e7300  83f803               cmp eax, 3
// 008e7303  89442410             mov dword ptr [esp + 0x10], eax
// 008e7307  7cd9                 jl 0x8e72e2
// 008e7309  8b5704               mov edx, dword ptr [edi + 4]
// 008e730c  68ffffff00           push 0xffffff
// 008e7311  8d4d0c               lea ecx, [ebp + 0xc]
// 008e7314  8d4307               lea eax, [ebx + 7]
// 008e7317  51                   push ecx
// 008e7318  50                   push eax
// 008e7319  52                   push edx
// 008e731a  89442424             mov dword ptr [esp + 0x24], eax
// 008e731e  ffd6                 call esi
// 008e7320  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7323  68ffffff00           push 0xffffff
// 008e7328  8d450d               lea eax, [ebp + 0xd]
// 008e732b  50                   push eax
// 008e732c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e7330  50                   push eax
// 008e7331  51                   push ecx
// 008e7332  ffd6                 call esi
// 008e7334  8b5704               mov edx, dword ptr [edi + 4]
// 008e7337  68ffffff00           push 0xffffff
// 008e733c  8d4d0c               lea ecx, [ebp + 0xc]
// 008e733f  8d4308               lea eax, [ebx + 8]
// 008e7342  51                   push ecx
// 008e7343  50                   push eax
// 008e7344  52                   push edx
// 008e7345  89442434             mov dword ptr [esp + 0x34], eax
// 008e7349  ffd6                 call esi
// 008e734b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e734e  68ffffff00           push 0xffffff
// 008e7353  8d450d               lea eax, [ebp + 0xd]
// 008e7356  50                   push eax
// 008e7357  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008e735b  50                   push eax
// 008e735c  51                   push ecx
// 008e735d  ffd6                 call esi
// 008e735f  8b5704               mov edx, dword ptr [edi + 4]
// 008e7362  68ffffff00           push 0xffffff
// 008e7367  8d4d0c               lea ecx, [ebp + 0xc]
// 008e736a  8d4309               lea eax, [ebx + 9]
// 008e736d  51                   push ecx
// 008e736e  50                   push eax
// 008e736f  52                   push edx
// 008e7370  8944244c             mov dword ptr [esp + 0x4c], eax
// 008e7374  ffd6                 call esi
// 008e7376  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7379  68ffffff00           push 0xffffff
// 008e737e  8d450d               lea eax, [ebp + 0xd]
// 008e7381  50                   push eax
// 008e7382  8b442444             mov eax, dword ptr [esp + 0x44]
// 008e7386  50                   push eax
// 008e7387  51                   push ecx
// 008e7388  ffd6                 call esi
// 008e738a  8d530a               lea edx, [ebx + 0xa]
// 008e738d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e7395  89542438             mov dword ptr [esp + 0x38], edx
// 008e7399  8da42400000000       lea esp, [esp]
// 008e73a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e73a4  8b542438             mov edx, dword ptr [esp + 0x38]
// 008e73a8  68ffffff00           push 0xffffff
// 008e73ad  8d4c280b             lea ecx, [eax + ebp + 0xb]
// 008e73b1  8b4704               mov eax, dword ptr [edi + 4]
// 008e73b4  51                   push ecx
// 008e73b5  52                   push edx
// 008e73b6  50                   push eax
// 008e73b7  ffd6                 call esi
// 008e73b9  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e73bd  40                   inc eax
// 008e73be  83f803               cmp eax, 3
// 008e73c1  89442410             mov dword ptr [esp + 0x10], eax
// 008e73c5  7cd9                 jl 0x8e73a0
// 008e73c7  68ffffff00           push 0xffffff
// 008e73cc  8d4d0b               lea ecx, [ebp + 0xb]
// 008e73cf  51                   push ecx
// 008e73d0  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e73d3  8d430b               lea eax, [ebx + 0xb]
// 008e73d6  50                   push eax
// 008e73d7  51                   push ecx
// 008e73d8  89442444             mov dword ptr [esp + 0x44], eax
// 008e73dc  ffd6                 call esi
// 008e73de  8b542434             mov edx, dword ptr [esp + 0x34]
// 008e73e2  68ffffff00           push 0xffffff
// 008e73e7  8d450c               lea eax, [ebp + 0xc]
// 008e73ea  50                   push eax
// 008e73eb  8b4704               mov eax, dword ptr [edi + 4]
// 008e73ee  52                   push edx
// 008e73ef  50                   push eax
// 008e73f0  ffd6                 call esi
// 008e73f2  8d4b0c               lea ecx, [ebx + 0xc]
// 008e73f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e73fd  894c2430             mov dword ptr [esp + 0x30], ecx
// 008e7401  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e7405  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008e7409  68ffffff00           push 0xffffff
// 008e740e  8d442a0a             lea eax, [edx + ebp + 0xa]
// 008e7412  8b5704               mov edx, dword ptr [edi + 4]
// 008e7415  50                   push eax
// 008e7416  51                   push ecx
// 008e7417  52                   push edx
// 008e7418  ffd6                 call esi
// 008e741a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e741e  40                   inc eax
// 008e741f  83f803               cmp eax, 3
// 008e7422  89442410             mov dword ptr [esp + 0x10], eax
// 008e7426  7cd9                 jl 0x8e7401
// 008e7428  68ffffff00           push 0xffffff
// 008e742d  8d4d0a               lea ecx, [ebp + 0xa]
// 008e7430  8d430d               lea eax, [ebx + 0xd]
// 008e7433  51                   push ecx
// 008e7434  50                   push eax
// 008e7435  89442438             mov dword ptr [esp + 0x38], eax
// 008e7439  8b4704               mov eax, dword ptr [edi + 4]
// 008e743c  50                   push eax
// 008e743d  ffd6                 call esi
// 008e743f  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008e7443  8b5704               mov edx, dword ptr [edi + 4]
// 008e7446  68ffffff00           push 0xffffff
// 008e744b  8d450b               lea eax, [ebp + 0xb]
// 008e744e  50                   push eax
// 008e744f  51                   push ecx
// 008e7450  52                   push edx
// 008e7451  ffd6                 call esi
// 008e7453  8d430e               lea eax, [ebx + 0xe]
// 008e7456  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e745e  89442428             mov dword ptr [esp + 0x28], eax
// 008e7462  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e7466  8b442428             mov eax, dword ptr [esp + 0x28]
// 008e746a  68ffffff00           push 0xffffff
// 008e746f  8d542909             lea edx, [ecx + ebp + 9]
// 008e7473  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7476  52                   push edx
// 008e7477  50                   push eax
// 008e7478  51                   push ecx
// 008e7479  ffd6                 call esi
// 008e747b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e747f  40                   inc eax
// 008e7480  83f803               cmp eax, 3
// 008e7483  89442410             mov dword ptr [esp + 0x10], eax
// 008e7487  7cd9                 jl 0x8e7462
// 008e7489  8d530f               lea edx, [ebx + 0xf]
// 008e748c  83c310               add ebx, 0x10
// 008e748f  895c244c             mov dword ptr [esp + 0x4c], ebx
// 008e7493  89542448             mov dword ptr [esp + 0x48], edx
// 008e7497  8bdd                 mov ebx, ebp
// 008e7499  c74424100b000000     mov dword ptr [esp + 0x10], 0xb
// 008e74a1  8b442448             mov eax, dword ptr [esp + 0x48]
// 008e74a5  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e74a8  68ffffff00           push 0xffffff
// 008e74ad  53                   push ebx
// 008e74ae  50                   push eax
// 008e74af  51                   push ecx
// 008e74b0  ffd6                 call esi
// 008e74b2  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 008e74b6  8b4704               mov eax, dword ptr [edi + 4]
// 008e74b9  68ffffff00           push 0xffffff
// 008e74be  53                   push ebx
// 008e74bf  52                   push edx
// 008e74c0  50                   push eax
// 008e74c1  ffd6                 call esi
// 008e74c3  43                   inc ebx
// 008e74c4  836c241001           sub dword ptr [esp + 0x10], 1
// 008e74c9  75d6                 jne 0x8e74a1
// 008e74cb  33db                 xor ebx, ebx
// 008e74cd  8d4900               lea ecx, [ecx]
// 008e74d0  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e74d4  8b542428             mov edx, dword ptr [esp + 0x28]
// 008e74d8  8b4704               mov eax, dword ptr [edi + 4]
// 008e74db  68ffffff00           push 0xffffff
// 008e74e0  03cb                 add ecx, ebx
// 008e74e2  51                   push ecx
// 008e74e3  52                   push edx
// 008e74e4  50                   push eax
// 008e74e5  ffd6                 call esi
// 008e74e7  43                   inc ebx
// 008e74e8  83fb03               cmp ebx, 3
// 008e74eb  7ce3                 jl 0x8e74d0
// 008e74ed  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 008e74f1  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e74f4  68ffffff00           push 0xffffff
// 008e74f9  55                   push ebp
// 008e74fa  53                   push ebx
// 008e74fb  51                   push ecx
// 008e74fc  ffd6                 call esi
// 008e74fe  8b542454             mov edx, dword ptr [esp + 0x54]
// 008e7502  8b4704               mov eax, dword ptr [edi + 4]
// 008e7505  68ffffff00           push 0xffffff
// 008e750a  52                   push edx
// 008e750b  53                   push ebx
// 008e750c  50                   push eax
// 008e750d  ffd6                 call esi
// 008e750f  33db                 xor ebx, ebx
// 008e7511  8b542430             mov edx, dword ptr [esp + 0x30]
// 008e7515  8b4704               mov eax, dword ptr [edi + 4]
// 008e7518  68ffffff00           push 0xffffff
// 008e751d  8d4c2bfe             lea ecx, [ebx + ebp - 2]
// 008e7521  51                   push ecx
// 008e7522  52                   push edx
// 008e7523  50                   push eax
// 008e7524  ffd6                 call esi
// 008e7526  43                   inc ebx
// 008e7527  83fb03               cmp ebx, 3
// 008e752a  7ce5                 jl 0x8e7511
// 008e752c  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e7530  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 008e7534  8b5704               mov edx, dword ptr [edi + 4]
// 008e7537  68ffffff00           push 0xffffff
// 008e753c  51                   push ecx
// 008e753d  53                   push ebx
// 008e753e  52                   push edx
// 008e753f  ffd6                 call esi
// 008e7541  68ffffff00           push 0xffffff
// 008e7546  8d45fe               lea eax, [ebp - 2]
// 008e7549  50                   push eax
// 008e754a  8b4704               mov eax, dword ptr [edi + 4]
// 008e754d  53                   push ebx
// 008e754e  50                   push eax
// 008e754f  ffd6                 call esi
// 008e7551  33db                 xor ebx, ebx
// 008e7553  8b542438             mov edx, dword ptr [esp + 0x38]
// 008e7557  8b4704               mov eax, dword ptr [edi + 4]
// 008e755a  68ffffff00           push 0xffffff
// 008e755f  8d4c2bfd             lea ecx, [ebx + ebp - 3]
// 008e7563  51                   push ecx
// 008e7564  52                   push edx
// 008e7565  50                   push eax
// 008e7566  ffd6                 call esi
// 008e7568  43                   inc ebx
// 008e7569  83fb03               cmp ebx, 3
// 008e756c  7ce5                 jl 0x8e7553
// 008e756e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e7572  8b5704               mov edx, dword ptr [edi + 4]
// 008e7575  68ffffff00           push 0xffffff
// 008e757a  8d5dfe               lea ebx, [ebp - 2]
// 008e757d  53                   push ebx
// 008e757e  51                   push ecx
// 008e757f  52                   push edx
// 008e7580  ffd6                 call esi
// 008e7582  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7585  68ffffff00           push 0xffffff
// 008e758a  8d45fd               lea eax, [ebp - 3]
// 008e758d  50                   push eax
// 008e758e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e7592  50                   push eax
// 008e7593  51                   push ecx
// 008e7594  ffd6                 call esi
// 008e7596  8b542424             mov edx, dword ptr [esp + 0x24]
// 008e759a  8b4704               mov eax, dword ptr [edi + 4]
// 008e759d  68ffffff00           push 0xffffff
// 008e75a2  53                   push ebx
// 008e75a3  52                   push edx
// 008e75a4  50                   push eax
// 008e75a5  ffd6                 call esi
// 008e75a7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e75ab  8b5704               mov edx, dword ptr [edi + 4]
// 008e75ae  68ffffff00           push 0xffffff
// 008e75b3  8d45fd               lea eax, [ebp - 3]
// 008e75b6  50                   push eax
// 008e75b7  51                   push ecx
// 008e75b8  52                   push edx
// 008e75b9  ffd6                 call esi
// 008e75bb  8b4704               mov eax, dword ptr [edi + 4]
// 008e75be  68ffffff00           push 0xffffff
// 008e75c3  53                   push ebx
// 008e75c4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 008e75c8  53                   push ebx
// 008e75c9  50                   push eax
// 008e75ca  ffd6                 call esi
// 008e75cc  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e75cf  68ffffff00           push 0xffffff
// 008e75d4  8d45fd               lea eax, [ebp - 3]
// 008e75d7  50                   push eax
// 008e75d8  53                   push ebx
// 008e75d9  51                   push ecx
// 008e75da  ffd6                 call esi
// 008e75dc  33db                 xor ebx, ebx
// 008e75de  8bff                 mov edi, edi
// 008e75e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e75e4  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e75e7  68ffffff00           push 0xffffff
// 008e75ec  8d542bfd             lea edx, [ebx + ebp - 3]
// 008e75f0  52                   push edx
// 008e75f1  50                   push eax
// 008e75f2  51                   push ecx
// 008e75f3  ffd6                 call esi
// 008e75f5  43                   inc ebx
// 008e75f6  83fb03               cmp ebx, 3
// 008e75f9  7ce5                 jl 0x8e75e0
// 008e75fb  8b542454             mov edx, dword ptr [esp + 0x54]
// 008e75ff  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 008e7603  8b4704               mov eax, dword ptr [edi + 4]
// 008e7606  68ffffff00           push 0xffffff
// 008e760b  52                   push edx
// 008e760c  53                   push ebx
// 008e760d  50                   push eax
// 008e760e  ffd6                 call esi
// 008e7610  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7613  68ffffff00           push 0xffffff
// 008e7618  8d45fe               lea eax, [ebp - 2]
// 008e761b  50                   push eax
// 008e761c  53                   push ebx
// 008e761d  51                   push ecx
// 008e761e  ffd6                 call esi
// 008e7620  33db                 xor ebx, ebx
// 008e7622  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e7626  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e7629  68ffffff00           push 0xffffff
// 008e762e  8d542bfe             lea edx, [ebx + ebp - 2]
// 008e7632  52                   push edx
// 008e7633  50                   push eax
// 008e7634  51                   push ecx
// 008e7635  ffd6                 call esi
// 008e7637  43                   inc ebx
// 008e7638  83fb03               cmp ebx, 3
// 008e763b  7ce5                 jl 0x8e7622
// 008e763d  8b5704               mov edx, dword ptr [edi + 4]
// 008e7640  68ffffff00           push 0xffffff
// 008e7645  55                   push ebp
// 008e7646  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 008e764a  55                   push ebp
// 008e764b  52                   push edx
// 008e764c  ffd6                 call esi
// 008e764e  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 008e7652  8b4704               mov eax, dword ptr [edi + 4]
// 008e7655  68ffffff00           push 0xffffff
// 008e765a  53                   push ebx
// 008e765b  55                   push ebp
// 008e765c  50                   push eax
// 008e765d  ffd6                 call esi
// 008e765f  33ed                 xor ebp, ebp
// 008e7661  8b542444             mov edx, dword ptr [esp + 0x44]
// 008e7665  8b4704               mov eax, dword ptr [edi + 4]
// 008e7668  68ffffff00           push 0xffffff
// 008e766d  8d0c2b               lea ecx, [ebx + ebp]
// 008e7670  51                   push ecx
// 008e7671  52                   push edx
// 008e7672  50                   push eax
// 008e7673  ffd6                 call esi
// 008e7675  45                   inc ebp
// 008e7676  83fd03               cmp ebp, 3
// 008e7679  7ce6                 jl 0x8e7661
// 008e767b  5f                   pop edi
// 008e767c  5e                   pop esi
// 008e767d  5d                   pop ebp
// 008e767e  5b                   pop ebx
// 008e767f  83c440               add esp, 0x40
// 008e7682  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
