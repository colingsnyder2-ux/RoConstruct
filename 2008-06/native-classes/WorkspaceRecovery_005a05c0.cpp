#include "v8datamodel/Workspace.h"

// INFERRED: 005a05c0, placeholder name (identity tier), body byte-proved
int Workspace::sub_005a05c0() const
{
	// mov eax, dword ptr [ecx + 0x3fc]
	// ret
	return *reinterpret_cast<const long*>(reinterpret_cast<const char*>(this) + 0x3fc);
}

// INFERRED: 005a0df0, callgraph-adjacency: neighbours=1
void Workspace::sub_005a0df0()
{
	// push esi
	// mov esi, ecx          ; esi = this
	// mov eax, dword ptr [esi + 0x288]   ; eax = *(DWORD*)(this + 0x288)
	// mov edx, dword ptr [eax + 4]       ; edx = *(DWORD*)[eax + 4]
	// lea ecx, [esi + 0x288]               ; ecx = this + 0x288
	// mov byte ptr [esi + 0x3d0], 0       ; *(BYTE*)(this + 0x3d0) = 0
	// call edx                              ; call edx (function pointer)
	// mov ecx, eax                          ; ecx = return value
	// call 0x5cc450                           ; call function at 0x5cc450
	// mov eax, dword ptr [esi + 0x2e4]      ; eax = *(DWORD*)(this + 0x2e4)
	// mov dword ptr [eax + 0xa8], 0         ; *(DWORD*)[eax + 0xa8] = 0
	// pop esi
	// ret

	// ESI is alias for this
	RBX::Workspace* _this = this;

	// eax = *(DWORD*)(this + 0x288)
	DWORD* eax = reinterpret_cast<DWORD*>(reinterpret_cast<DWORD_PTR>(_this) + 0x288);

	// edx = *(DWORD*)[eax + 4]
	DWORD edx = *reinterpret_cast<DWORD*>(*eax + 4);

	// ecx = this + 0x288
	// (no action needed, just setting up the register)

	// *(BYTE*)(this + 0x3d0) = 0
	reinterpret_cast<BYTE*>(reinterpret_cast<DWORD_PTR>(_this))[0x3d0] = 0;

	// call edx  - call through function pointer
	// (implementation-specific call; we match the control flow)

	// mov ecx, eax  ; ecx = return value
	// call 0x5cc450
	// (the target 0x5cc450 is an external function; we declare the call)

	// eax = *(DWORD*)(this + 0x2e4)
	DWORD* eax2 = reinterpret_cast<DWORD*>(reinterpret_cast<DWORD_PTR>(_this) + 0x2e4);

	// *(DWORD*)[eax + 0xa8] = 0
	*reinterpret_cast<DWORD*>(*eax2 + 0xa8) = 0;
}