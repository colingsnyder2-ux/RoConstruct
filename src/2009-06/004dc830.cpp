// from server: 100% by EspClaude
// roc 2009-06 004dc830  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dc830
//
// 004dc830  d90578658c00         fld dword ptr [0x8c6578]
// 004dc836  83ec08               sub esp, 8
// 004dc839  d816                 fcom dword ptr [esi]
// 004dc83b  dfe0                 fnstsw ax
// 004dc83d  f6c441               test ah, 0x41
// 004dc840  7b11                 jnp 0x4dc853
// 004dc842  d90574658c00         fld dword ptr [0x8c6574]
// 004dc848  d816                 fcom dword ptr [esi]
// 004dc84a  dfe0                 fnstsw ax
// 004dc84c  f6c401               test ah, 1
// 004dc84f  750a                 jne 0x4dc85b
// 004dc851  ddd8                 fstp st(0)
// 004dc853  ddd8                 fstp st(0)
// 004dc855  32c0                 xor al, al
// 004dc857  83c408               add esp, 8
// 004dc85a  c3                   ret 
// 004dc85b  d9c9                 fxch st(1)
// 004dc85d  d85e08               fcomp dword ptr [esi + 8]
// 004dc860  dfe0                 fnstsw ax
// 004dc862  f6c441               test ah, 0x41
// 004dc865  7bec                 jnp 0x4dc853
// 004dc867  d85e08               fcomp dword ptr [esi + 8]
// 004dc86a  dfe0                 fnstsw ax
// 004dc86c  f6c401               test ah, 1
// 004dc86f  74e4                 je 0x4dc855
// 004dc871  d90570658c00         fld dword ptr [0x8c6570]
// 004dc877  d85e04               fcomp dword ptr [esi + 4]
// 004dc87a  dfe0                 fnstsw ax
// 004dc87c  f6c441               test ah, 0x41
// 004dc87f  7bd4                 jnp 0x4dc855
// 004dc881  d9ee                 fldz 
// 004dc883  d85e04               fcomp dword ptr [esi + 4]
// 004dc886  dfe0                 fnstsw ax
// 004dc888  f6c441               test ah, 0x41
// 004dc88b  74c8                 je 0x4dc855
// 004dc88d  d906                 fld dword ptr [esi]
// 004dc88f  d90544d08b00         fld dword ptr [0x8bd044]
// 004dc895  dcc9                 fmul st(1), st(0)
// 004dc897  d9c1                 fld st(1)
// 004dc899  e822d62300           call 0x719ec0
// 004dc89e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004dc8a2  0fbfd0               movsx edx, ax
// 004dc8a5  891424               mov dword ptr [esp], edx
// 004dc8a8  668901               mov word ptr [ecx], ax
// 004dc8ab  db0424               fild dword ptr [esp]
// 004dc8ae  ddea                 fucomp st(2)
// 004dc8b0  dfe0                 fnstsw ax
// 004dc8b2  ddd9                 fstp st(1)
// 004dc8b4  f6c444               test ah, 0x44
// 004dc8b7  7a9a                 jp 0x4dc853
// 004dc8b9  d84e08               fmul dword ptr [esi + 8]
// 004dc8bc  d9c0                 fld st(0)
// 004dc8be  e8fdd52300           call 0x719ec0
// 004dc8c3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004dc8c7  0fbfd0               movsx edx, ax
// 004dc8ca  891424               mov dword ptr [esp], edx
// 004dc8cd  668901               mov word ptr [ecx], ax
// 004dc8d0  db0424               fild dword ptr [esp]
// 004dc8d3  dae9                 fucompp 
// 004dc8d5  dfe0                 fnstsw ax
// 004dc8d7  f6c444               test ah, 0x44
// 004dc8da  0f8a75ffffff         jp 0x4dc855
// 004dc8e0  d94604               fld dword ptr [esi + 4]
// 004dc8e3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dc8e7  d80d38e88b00         fmul dword ptr [0x8be838]
// 004dc8ed  83ec08               sub esp, 8
// 004dc8f0  d97c2408             fnstcw word ptr [esp + 8]
// 004dc8f4  0fb7442408           movzx eax, word ptr [esp + 8]
// 004dc8f9  d9c0                 fld st(0)
// 004dc8fb  0d000c0000           or eax, 0xc00
// 004dc900  8944240c             mov dword ptr [esp + 0xc], eax
// 004dc904  d96c240c             fldcw word ptr [esp + 0xc]
// 004dc908  db5c240c             fistp dword ptr [esp + 0xc]
// 004dc90c  668b44240c           mov ax, word ptr [esp + 0xc]
// 004dc911  0fb7d0               movzx edx, ax
// 004dc914  8954240c             mov dword ptr [esp + 0xc], edx
// 004dc918  d96c2408             fldcw word ptr [esp + 8]
// 004dc91c  668901               mov word ptr [ecx], ax
// 004dc91f  d95c2404             fstp dword ptr [esp + 4]
// 004dc923  db44240c             fild dword ptr [esp + 0xc]
// 004dc927  d91c24               fstp dword ptr [esp]
// 004dc92a  e8c1feffff           call 0x4dc7f0
// 004dc92f  83c408               add esp, 8
// 004dc932  84c0                 test al, al
// 004dc934  0f95c0               setne al
// 004dc937  83c408               add esp, 8
// 004dc93a  c3                   ret 
// copied from an identical function in another client (function ?isBrickLocation@@YA_NABUVector3@@AAFAAG1@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>

// RBX::Network::isBrickLocation (2008-06 Networking/Streaming.cpp), self-contained:
// only the G3D::Vector3 field layout (x,y,z at +0,+4,+8) matters for the codegen.
// The 2008-06 build compares v.y against a float literal: the double 204.8 is
// folded to a float compare, and x87 keeps the products in extended precision.
struct Vector3
{
	float x;
	float y;
	float z;
};

static __declspec(noinline) bool brickEq(float a, float b)
{
	return a == b || fabs(a - b) <= 0.0005f;
}

static bool isBrickLocation(const Vector3& v, short& x, unsigned short& y, short& z)
{
	if (v.x >= 512.0f)
		return false;

	if (v.x <= -512.0f)
		return false;

	if (v.z >= 512.0f)
		return false;

	if (v.z <= -512.0f)
		return false;

	if (v.y >= 204.8f)
		return false;

	if (v.y < 0.0f)
		return false;

	float dx = v.x * 2.0f;
	x = (short)dx;

	if ((float)x != dx)
		return false;

	float dz = v.z * 2.0f;
	z = (short)dz;

	if ((float)z != dz)
		return false;

	float dy = v.y * 10.0f;
	y = (unsigned short)dy;

	if (!brickEq((float)y, dy))
		return false;

	return true;
}

// Keeps the internal-linkage definition above alive without changing its body.
bool isBrickLocationEntry(const Vector3& v, short& x, unsigned short& y, short& z)
{
	return isBrickLocation(v, x, y, z);
}