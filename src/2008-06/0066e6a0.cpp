// from server: 100% by EspClaude
// from server: 99% by coldek
// roc 2008-06 0066e6a0  unit: RBX::HUMAN::GettingUp  size: 1003 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066e6a0
//
// 0066e6a0  81ec9c000000         sub esp, 0x9c
// 0066e6a6  53                   push ebx
// 0066e6a7  56                   push esi
// 0066e6a8  8bd9                 mov ebx, ecx
// 0066e6aa  e8a1561200           call 0x793d50
// 0066e6af  8bc8                 mov ecx, eax
// 0066e6b1  e8aaaaf6ff           call 0x5d9160
// 0066e6b6  8bf0                 mov esi, eax
// 0066e6b8  85f6                 test esi, esi
// 0066e6ba  0f84c0030000         je 0x66ea80
// 0066e6c0  57                   push edi
// 0066e6c1  8bcb                 mov ecx, ebx
// 0066e6c3  e888561200           call 0x793d50
// 0066e6c8  8bc8                 mov ecx, eax
// 0066e6ca  e8b1aaf6ff           call 0x5d9180
// 0066e6cf  8bf8                 mov edi, eax
// 0066e6d1  85ff                 test edi, edi
// 0066e6d3  0f84a6030000         je 0x66ea7f
// 0066e6d9  8bce                 mov ecx, esi
// 0066e6db  e880acf2ff           call 0x599360
// 0066e6e0  6a01                 push 1
// 0066e6e2  8d442458             lea eax, [esp + 0x58]
// 0066e6e6  50                   push eax
// 0066e6e7  8d8e94000000         lea ecx, [esi + 0x94]
// 0066e6ed  e84e4beaff           call 0x513240
// 0066e6f2  f605a428970001       test byte ptr [0x9728a4], 1
// 0066e6f9  7523                 jne 0x66e71e
// 0066e6fb  d9ee                 fldz 
// 0066e6fd  830da428970001       or dword ptr [0x9728a4], 1
// 0066e704  d9c0                 fld st(0)
// 0066e706  d91598289700         fst dword ptr [0x972898]
// 0066e70c  d9e8                 fld1 
// 0066e70e  d9159c289700         fst dword ptr [0x97289c]
// 0066e714  d9ca                 fxch st(2)
// 0066e716  d915a0289700         fst dword ptr [0x9728a0]
// 0066e71c  eb14                 jmp 0x66e732
// 0066e71e  d905a0289700         fld dword ptr [0x9728a0]
// 0066e724  d90598289700         fld dword ptr [0x972898]
// 0066e72a  d9059c289700         fld dword ptr [0x97289c]
// 0066e730  d9ca                 fxch st(2)
// 0066e732  d944245c             fld dword ptr [esp + 0x5c]
// 0066e736  8bce                 mov ecx, esi
// 0066e738  d9c0                 fld st(0)
// 0066e73a  d8cc                 fmul st(4)
// 0066e73c  d9442458             fld dword ptr [esp + 0x58]
// 0066e740  d9c0                 fld st(0)
// 0066e742  d8cc                 fmul st(4)
// 0066e744  deea                 fsubp st(2)
// 0066e746  d9c9                 fxch st(1)
// 0066e748  d95c240c             fstp dword ptr [esp + 0xc]
// 0066e74c  d9442454             fld dword ptr [esp + 0x54]
// 0066e750  dccb                 fmul st(3), st(0)
// 0066e752  d9ca                 fxch st(2)
// 0066e754  d8cc                 fmul st(4)
// 0066e756  deeb                 fsubp st(3)
// 0066e758  d9ca                 fxch st(2)
// 0066e75a  d95c2410             fstp dword ptr [esp + 0x10]
// 0066e75e  d9c9                 fxch st(1)
// 0066e760  deca                 fmulp st(2)
// 0066e762  deca                 fmulp st(2)
// 0066e764  dee1                 fsubrp st(1)
// 0066e766  d95c2414             fstp dword ptr [esp + 0x14]
// 0066e76a  e8f1abf2ff           call 0x599360
// 0066e76f  d986d0000000         fld dword ptr [esi + 0xd0]
// 0066e775  8bcf                 mov ecx, edi
// 0066e777  d95c2418             fstp dword ptr [esp + 0x18]
// 0066e77b  d986d4000000         fld dword ptr [esi + 0xd4]
// 0066e781  d95c241c             fstp dword ptr [esp + 0x1c]
// 0066e785  d986d8000000         fld dword ptr [esi + 0xd8]
// 0066e78b  d95c2420             fstp dword ptr [esp + 0x20]
// 0066e78f  e84cfbfbff           call 0x62e2e0
// 0066e794  d900                 fld dword ptr [eax]
// 0066e796  8bcf                 mov ecx, edi
// 0066e798  d95c2430             fstp dword ptr [esp + 0x30]
// 0066e79c  d94004               fld dword ptr [eax + 4]
// 0066e79f  d95c2434             fstp dword ptr [esp + 0x34]
// 0066e7a3  d94008               fld dword ptr [eax + 8]
// 0066e7a6  d95c2438             fstp dword ptr [esp + 0x38]
// 0066e7aa  e8b1abf2ff           call 0x599360
// 0066e7af  8d4c2460             lea ecx, [esp + 0x60]
// 0066e7b3  8db794000000         lea esi, [edi + 0x94]
// 0066e7b9  51                   push ecx
// 0066e7ba  8bce                 mov ecx, esi
// 0066e7bc  e84f4deaff           call 0x513510
// 0066e7c1  d94004               fld dword ptr [eax + 4]
// 0066e7c4  d9442410             fld dword ptr [esp + 0x10]
// 0066e7c8  8d542460             lea edx, [esp + 0x60]
// 0066e7cc  dcc9                 fmul st(1), st(0)
// 0066e7ce  52                   push edx
// 0066e7cf  d94008               fld dword ptr [eax + 8]
// 0066e7d2  8bce                 mov ecx, esi
// 0066e7d4  d9442418             fld dword ptr [esp + 0x18]
// 0066e7d8  dcc9                 fmul st(1), st(0)
// 0066e7da  d9cb                 fxch st(3)
// 0066e7dc  dec1                 faddp st(1)
// 0066e7de  d9442410             fld dword ptr [esp + 0x10]
// 0066e7e2  d9c0                 fld st(0)
// 0066e7e4  d808                 fmul dword ptr [eax]
// 0066e7e6  dec2                 faddp st(2)
// 0066e7e8  d9c9                 fxch st(1)
// 0066e7ea  d95c2410             fstp dword ptr [esp + 0x10]
// 0066e7ee  d94010               fld dword ptr [eax + 0x10]
// 0066e7f1  d8ca                 fmul st(2)
// 0066e7f3  d94014               fld dword ptr [eax + 0x14]
// 0066e7f6  d8cc                 fmul st(4)
// 0066e7f8  dec1                 faddp st(1)
// 0066e7fa  d9400c               fld dword ptr [eax + 0xc]
// 0066e7fd  d8ca                 fmul st(2)
// 0066e7ff  dec1                 faddp st(1)
// 0066e801  d95c2414             fstp dword ptr [esp + 0x14]
// 0066e805  d9401c               fld dword ptr [eax + 0x1c]
// 0066e808  deca                 fmulp st(2)
// 0066e80a  d94020               fld dword ptr [eax + 0x20]
// 0066e80d  decb                 fmulp st(3)
// 0066e80f  d9c9                 fxch st(1)
// 0066e811  dec2                 faddp st(2)
// 0066e813  d84818               fmul dword ptr [eax + 0x18]
// 0066e816  dec1                 faddp st(1)
// 0066e818  d95c2418             fstp dword ptr [esp + 0x18]
// 0066e81c  e8ef4ceaff           call 0x513510
// 0066e821  d94008               fld dword ptr [eax + 8]
// 0066e824  d9442420             fld dword ptr [esp + 0x20]
// 0066e828  8bce                 mov ecx, esi
// 0066e82a  dcc9                 fmul st(1), st(0)
// 0066e82c  d94004               fld dword ptr [eax + 4]
// 0066e82f  d944241c             fld dword ptr [esp + 0x1c]
// 0066e833  dcc9                 fmul st(1), st(0)
// 0066e835  d9cb                 fxch st(3)
// 0066e837  dec1                 faddp st(1)
// 0066e839  d900                 fld dword ptr [eax]
// 0066e83b  d9442418             fld dword ptr [esp + 0x18]
// 0066e83f  dcc9                 fmul st(1), st(0)
// 0066e841  d9ca                 fxch st(2)
// 0066e843  dec1                 faddp st(1)
// 0066e845  d95c2424             fstp dword ptr [esp + 0x24]
// 0066e849  d94014               fld dword ptr [eax + 0x14]
// 0066e84c  d8ca                 fmul st(2)
// 0066e84e  d94010               fld dword ptr [eax + 0x10]
// 0066e851  d8cc                 fmul st(4)
// 0066e853  dec1                 faddp st(1)
// 0066e855  d9400c               fld dword ptr [eax + 0xc]
// 0066e858  d8ca                 fmul st(2)
// 0066e85a  dec1                 faddp st(1)
// 0066e85c  d95c2428             fstp dword ptr [esp + 0x28]
// 0066e860  d94020               fld dword ptr [eax + 0x20]
// 0066e863  deca                 fmulp st(2)
// 0066e865  d9401c               fld dword ptr [eax + 0x1c]
// 0066e868  decb                 fmulp st(3)
// 0066e86a  d9c9                 fxch st(1)
// 0066e86c  dec2                 faddp st(2)
// 0066e86e  d84818               fmul dword ptr [eax + 0x18]
// 0066e871  8d442460             lea eax, [esp + 0x60]
// 0066e875  50                   push eax
// 0066e876  dec1                 faddp st(1)
// 0066e878  d95c2430             fstp dword ptr [esp + 0x30]
// 0066e87c  e88f4ceaff           call 0x513510
// 0066e881  d94008               fld dword ptr [eax + 8]
// 0066e884  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0066e887  d9442438             fld dword ptr [esp + 0x38]
// 0066e88b  dcc9                 fmul st(1), st(0)
// 0066e88d  d94004               fld dword ptr [eax + 4]
// 0066e890  d9442434             fld dword ptr [esp + 0x34]
// 0066e894  dcc9                 fmul st(1), st(0)
// 0066e896  d9cb                 fxch st(3)
// 0066e898  dec1                 faddp st(1)
// 0066e89a  d900                 fld dword ptr [eax]
// 0066e89c  d9442430             fld dword ptr [esp + 0x30]
// 0066e8a0  dcc9                 fmul st(1), st(0)
// 0066e8a2  d9ca                 fxch st(2)
// 0066e8a4  dec1                 faddp st(1)
// 0066e8a6  d95c2418             fstp dword ptr [esp + 0x18]
// 0066e8aa  d94014               fld dword ptr [eax + 0x14]
// 0066e8ad  d8ca                 fmul st(2)
// 0066e8af  d94010               fld dword ptr [eax + 0x10]
// 0066e8b2  d8cc                 fmul st(4)
// 0066e8b4  dec1                 faddp st(1)
// 0066e8b6  d9400c               fld dword ptr [eax + 0xc]
// 0066e8b9  d8ca                 fmul st(2)
// 0066e8bb  dec1                 faddp st(1)
// 0066e8bd  d95c241c             fstp dword ptr [esp + 0x1c]
// 0066e8c1  d94020               fld dword ptr [eax + 0x20]
// 0066e8c4  deca                 fmulp st(2)
// 0066e8c6  d9401c               fld dword ptr [eax + 0x1c]
// 0066e8c9  decb                 fmulp st(3)
// 0066e8cb  d9c9                 fxch st(1)
// 0066e8cd  dec2                 faddp st(2)
// 0066e8cf  d84818               fmul dword ptr [eax + 0x18]
// 0066e8d2  dec1                 faddp st(1)
// 0066e8d4  d95c2420             fstp dword ptr [esp + 0x20]
// 0066e8d8  85c9                 test ecx, ecx
// 0066e8da  7407                 je 0x66e8e3
// 0066e8dc  e88f18ffff           call 0x660170
// 0066e8e1  eb03                 jmp 0x66e8e6
// 0066e8e3  8d4768               lea eax, [edi + 0x68]
// 0066e8e6  50                   push eax
// 0066e8e7  8d4c2464             lea ecx, [esp + 0x64]
// 0066e8eb  e83049eaff           call 0x513220
// 0066e8f0  d983a0000000         fld dword ptr [ebx + 0xa0]
// 0066e8f6  8d4c240c             lea ecx, [esp + 0xc]
// 0066e8fa  d9e0                 fchs 
// 0066e8fc  51                   push ecx
// 0066e8fd  8d542440             lea edx, [esp + 0x40]
// 0066e901  52                   push edx
// 0066e902  8d442468             lea eax, [esp + 0x68]
// 0066e906  50                   push eax
// 0066e907  51                   push ecx
// 0066e908  8d8c2494000000       lea ecx, [esp + 0x94]
// 0066e90f  d91c24               fstp dword ptr [esp]
// 0066e912  51                   push ecx
// 0066e913  e8c84beaff           call 0x5134e0
// 0066e918  83c40c               add esp, 0xc
// 0066e91b  8bc8                 mov ecx, eax
// 0066e91d  e85e7ce0ff           call 0x476580
// 0066e922  d9442418             fld dword ptr [esp + 0x18]
// 0066e926  d844243c             fadd dword ptr [esp + 0x3c]
// 0066e92a  8b4f28               mov ecx, dword ptr [edi + 0x28]
// 0066e92d  d95c240c             fstp dword ptr [esp + 0xc]
// 0066e931  d9442440             fld dword ptr [esp + 0x40]
// 0066e935  d844241c             fadd dword ptr [esp + 0x1c]
// 0066e939  d95c2410             fstp dword ptr [esp + 0x10]
// 0066e93d  d9442444             fld dword ptr [esp + 0x44]
// 0066e941  d8442420             fadd dword ptr [esp + 0x20]
// 0066e945  d95c2414             fstp dword ptr [esp + 0x14]
// 0066e949  85c9                 test ecx, ecx
// 0066e94b  7407                 je 0x66e954
// 0066e94d  e81e18ffff           call 0x660170
// 0066e952  eb03                 jmp 0x66e957
// 0066e954  8d4768               lea eax, [edi + 0x68]
// 0066e957  50                   push eax
// 0066e958  8d4c2464             lea ecx, [esp + 0x64]
// 0066e95c  e8bf48eaff           call 0x513220
// 0066e961  8d542460             lea edx, [esp + 0x60]
// 0066e965  52                   push edx
// 0066e966  8d44244c             lea eax, [esp + 0x4c]
// 0066e96a  50                   push eax
// 0066e96b  e840f2f6ff           call 0x5ddbb0
// 0066e970  d9057c7b8400         fld dword ptr [0x847b7c]
// 0066e976  83c408               add esp, 8
// 0066e979  33c9                 xor ecx, ecx
// 0066e97b  d9440c3c             fld dword ptr [esp + ecx + 0x3c]
// 0066e97f  d8640c18             fsub dword ptr [esp + ecx + 0x18]
// 0066e983  d9e1                 fabs 
// 0066e985  d9440c48             fld dword ptr [esp + ecx + 0x48]
// 0066e989  d8ca                 fmul st(2)
// 0066e98b  ded9                 fcompp 
// 0066e98d  dfe0                 fnstsw ax
// 0066e98f  f6c441               test ah, 0x41
// 0066e992  7508                 jne 0x66e99c
// 0066e994  d9440c3c             fld dword ptr [esp + ecx + 0x3c]
// 0066e998  d95c0c0c             fstp dword ptr [esp + ecx + 0xc]
// 0066e99c  83c108               add ecx, 8
// 0066e99f  83f90c               cmp ecx, 0xc
// 0066e9a2  7cd7                 jl 0x66e97b
// 0066e9a4  ddd8                 fstp st(0)
// 0066e9a6  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0066e9a9  d983a4000000         fld dword ptr [ebx + 0xa4]
// 0066e9af  d9442448             fld dword ptr [esp + 0x48]
// 0066e9b3  d8c9                 fmul st(1)
// 0066e9b5  d944244c             fld dword ptr [esp + 0x4c]
// 0066e9b9  d8ca                 fmul st(2)
// 0066e9bb  d9442450             fld dword ptr [esp + 0x50]
// 0066e9bf  decb                 fmulp st(3)
// 0066e9c1  d9c9                 fxch st(1)
// 0066e9c3  d84c2424             fmul dword ptr [esp + 0x24]
// 0066e9c7  d9c9                 fxch st(1)
// 0066e9c9  d84c2428             fmul dword ptr [esp + 0x28]
// 0066e9cd  d9ca                 fxch st(2)
// 0066e9cf  d84c242c             fmul dword ptr [esp + 0x2c]
// 0066e9d3  d944240c             fld dword ptr [esp + 0xc]
// 0066e9d7  dee2                 fsubrp st(2)
// 0066e9d9  d9442410             fld dword ptr [esp + 0x10]
// 0066e9dd  dee3                 fsubrp st(3)
// 0066e9df  d86c2414             fsubr dword ptr [esp + 0x14]
// 0066e9e3  d94608               fld dword ptr [esi + 8]
// 0066e9e6  d8c9                 fmul st(1)
// 0066e9e8  d94604               fld dword ptr [esi + 4]
// 0066e9eb  d8cc                 fmul st(4)
// 0066e9ed  dec1                 faddp st(1)
// 0066e9ef  d9c2                 fld st(2)
// 0066e9f1  d80e                 fmul dword ptr [esi]
// 0066e9f3  dec1                 faddp st(1)
// 0066e9f5  d94614               fld dword ptr [esi + 0x14]
// 0066e9f8  d8ca                 fmul st(2)
// 0066e9fa  d94610               fld dword ptr [esi + 0x10]
// 0066e9fd  d8cd                 fmul st(5)
// 0066e9ff  dec1                 faddp st(1)
// 0066ea01  d9460c               fld dword ptr [esi + 0xc]
// 0066ea04  d8cc                 fmul st(4)
// 0066ea06  dec1                 faddp st(1)
// 0066ea08  d94620               fld dword ptr [esi + 0x20]
// 0066ea0b  decb                 fmulp st(3)
// 0066ea0d  d9461c               fld dword ptr [esi + 0x1c]
// 0066ea10  decd                 fmulp st(5)
// 0066ea12  d9ca                 fxch st(2)
// 0066ea14  dec4                 faddp st(4)
// 0066ea16  d94618               fld dword ptr [esi + 0x18]
// 0066ea19  8b712c               mov esi, dword ptr [ecx + 0x2c]
// 0066ea1c  decb                 fmulp st(3)
// 0066ea1e  d9cb                 fxch st(3)
// 0066ea20  dec2                 faddp st(2)
// 0066ea22  d9ca                 fxch st(2)
// 0066ea24  d8642430             fsub dword ptr [esp + 0x30]
// 0066ea28  d95c2424             fstp dword ptr [esp + 0x24]
// 0066ea2c  d9c9                 fxch st(1)
// 0066ea2e  d8642434             fsub dword ptr [esp + 0x34]
// 0066ea32  d95c2428             fstp dword ptr [esp + 0x28]
// 0066ea36  d8642438             fsub dword ptr [esp + 0x38]
// 0066ea3a  d95c242c             fstp dword ptr [esp + 0x2c]
// 0066ea3e  85f6                 test esi, esi
// 0066ea40  743d                 je 0x66ea7f
// 0066ea42  807e0800             cmp byte ptr [esi + 8], 0
// 0066ea46  7407                 je 0x66ea4f
// 0066ea48  8bce                 mov ecx, esi
// 0066ea4a  e8d1a2feff           call 0x658d20
// 0066ea4f  d9442424             fld dword ptr [esp + 0x24]
// 0066ea53  d88690000000         fadd dword ptr [esi + 0x90]
// 0066ea59  d99e90000000         fstp dword ptr [esi + 0x90]
// 0066ea5f  d9442428             fld dword ptr [esp + 0x28]
// 0066ea63  d88694000000         fadd dword ptr [esi + 0x94]
// 0066ea69  d99e94000000         fstp dword ptr [esi + 0x94]
// 0066ea6f  d944242c             fld dword ptr [esp + 0x2c]
// 0066ea73  d88698000000         fadd dword ptr [esi + 0x98]
// 0066ea79  d99e98000000         fstp dword ptr [esi + 0x98]
// 0066ea7f  5f                   pop edi
// 0066ea80  5e                   pop esi
// 0066ea81  5b                   pop ebx
// 0066ea82  81c49c000000         add esp, 0x9c
// 0066ea88  c20400               ret 4


// claude-opus-5-5 opusC: codegen analog; unused float locals set the /fp:fast x87 frame-local count (not original declarations)
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
#include <stddef.h>
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(float a,float b,float c,int){x=a;z=0;y=b;z=c;}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 const float&operator[](int i)const{return ((float*)this)[i];}float&operator[](int i){return ((float*)this)[i];}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3 operator*(const Vector3&v)const{return Vector3(x*v.x,y*v.y,z*v.z);}Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 Vector3&operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 Vector3&operator-=(const Vector3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
 Vector3 cross(const Vector3&v)const{return Vector3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,0);}
 static const Vector3&unitY(){static Vector3 v(0,1,0);return v;}
};
inline Vector3 operator*(float f,const Vector3&v){return v*f;}
struct Matrix3 {
 float elt[3][3];Matrix3(){}Matrix3(const Matrix3&m){*this=m;}Matrix3&operator=(const Matrix3&);
 Vector3 getColumn(int)const;Matrix3 transpose()const;
 inline Vector3 operator*(const Vector3&v)const{Vector3 p;for(int r=0;r<3;++r)p[r]=elt[r][0]*v[0]+elt[r][1]*v[1]+elt[r][2]*v[2];return p;}
};
Matrix3 operator*(float,const Matrix3&);
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct Cofm {const G3D::Matrix3&getMoment()const;};
struct SimBody {char opaque[8];bool dirty;char padding[0x90-9];G3D::Vector3 torque;void update();void updateIfDirty(){if(dirty)update();}void accumulateTorque(const G3D::Vector3&t){updateIfDirty();torque.x=t.x+torque.x;torque.y+=t.y;torque.z+=t.z;}};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);};
struct Body {char opaque[0x10];Body*root;char opaque14[0x28-0x14];Cofm*cofm;SimBody*simBody;char opaque30[0x68-0x30];G3D::Matrix3 moment;char opaque8c[8];G3D::CoordinateFrame frame;Velocity velocity;
 void updatePV()const;const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return frame;}const Velocity&getVelocity()const{updatePV();return velocity;}
 const G3D::Vector3&getBranchTorque()const;G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&t){if(root->simBody)root->simBody->accumulateTorque(t);}
};
struct Humanoid {Body*getTorsoBody();Body*getRootBody();};
namespace HUMAN {
struct Balancing {char opaque[0xa0];float kP,kD;Humanoid*getHumanoid()const;void onComputeForce(float);};
void Balancing::onComputeForce(float){ float roc_dd0 = 0; float roc_dd1 = 0; float roc_dd2 = 0;
 Body*torso=getHumanoid()->getTorsoBody();if(!torso)return;
 Body*root=getHumanoid()->getRootBody();if(!root)return;
 G3D::Vector3 yAxis=torso->getCoordinateFrame().rotation.getColumn(1);
 G3D::Vector3 tilt=G3D::Vector3::unitY().cross(yAxis);
 G3D::Vector3 angularVelocity=torso->getVelocity().rotational;
 G3D::Vector3 torque=root->getBranchTorque();
 const G3D::CoordinateFrame&rootFrame=root->getCoordinateFrame();
 const G3D::Vector3 localTilt=rootFrame.vectorToObjectSpace(tilt);
 G3D::Vector3 localAngularVelocity=rootFrame.vectorToObjectSpace(angularVelocity);
 G3D::Vector3 localTorque=rootFrame.vectorToObjectSpace(torque);
 G3D::Vector3 desiredTorque=(-kP*root->getBranchIBody())*localTilt;
 G3D::Vector3 totalTorque=localTorque+desiredTorque;
 G3D::Vector3 inertia=RBX::Math::toDiagonal(root->getBranchIBody());
 for(int i=0;i<3;i+=2){if(fabs(desiredTorque[i]-localTorque[i])<inertia[i]*4000.0f)totalTorque[i]=desiredTorque[i];}
 totalTorque-=kD*inertia*localAngularVelocity;
 G3D::Vector3 torqueWorld=root->frame.vectorToWorldSpace(totalTorque);
 G3D::Vector3 addedTorque=torqueWorld-torque;
 root->accumulateTorque(addedTorque);
}
}
}
typedef char vector_size[sizeof(G3D::Vector3)==12?1:-1];
typedef char matrix_size[sizeof(G3D::Matrix3)==36?1:-1];
typedef char frame_size[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char body_root_offset[offsetof(RBX::Body,root)==0x10?1:-1];
typedef char body_cofm_offset[offsetof(RBX::Body,cofm)==0x28?1:-1];
typedef char body_sim_offset[offsetof(RBX::Body,simBody)==0x2c?1:-1];
typedef char body_moment_offset[offsetof(RBX::Body,moment)==0x68?1:-1];
typedef char body_frame_offset[offsetof(RBX::Body,frame)==0x94?1:-1];
typedef char body_angular_offset[offsetof(RBX::Body,velocity)+offsetof(RBX::Velocity,rotational)==0xd0?1:-1];
typedef char sim_torque_offset[offsetof(RBX::SimBody,torque)==0x90?1:-1];

typedef char balance_kp_offset[offsetof(RBX::HUMAN::Balancing,kP)==0xa0?1:-1];
typedef char balance_kd_offset[offsetof(RBX::HUMAN::Balancing,kD)==0xa4?1:-1];
