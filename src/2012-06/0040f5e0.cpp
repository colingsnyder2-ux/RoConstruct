// from server: 100% by Xemicl
// roc 2012-06 0040f5e0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040f5e0
//
// 0040f5e0  6aff                 push -1
// 0040f5e2  6811a8a900           push 0xa9a811
// 0040f5e7  64a100000000         mov eax, dword ptr fs:[0]
// 0040f5ed  50                   push eax
// 0040f5ee  64892500000000       mov dword ptr fs:[0], esp
// 0040f5f5  83ec4c               sub esp, 0x4c
// 0040f5f8  668b44245c           mov ax, word ptr [esp + 0x5c]
// 0040f5fd  56                   push esi
// 0040f5fe  57                   push edi
// 0040f5ff  668b7c246c           mov di, word ptr [esp + 0x6c]
// 0040f604  8bf1                 mov esi, ecx
// 0040f606  668b4c2468           mov cx, word ptr [esp + 0x68]
// 0040f60b  8d54240a             lea edx, [esp + 0xa]
// 0040f60f  52                   push edx
// 0040f610  668944240e           mov word ptr [esp + 0xe], ax
// 0040f615  66894c2410           mov word ptr [esp + 0x10], cx
// 0040f61a  66897c2412           mov word ptr [esp + 0x12], di
// 0040f61f  e89cc4ffff           call 0x40bac0
// 0040f624  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0040f628  8906                 mov dword ptr [esi], eax
// 0040f62a  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 0040f62e  50                   push eax
// 0040f62f  51                   push ecx
// 0040f630  e86bc5ffff           call 0x40bba0
// 0040f635  83c40c               add esp, 0xc
// 0040f638  663bc7               cmp ax, di
// 0040f63b  7338                 jae 0x40f675
// 0040f63d  685443b400           push 0xb44354
// 0040f642  8d4c2414             lea ecx, [esp + 0x14]
// 0040f646  ff154826b200         call dword ptr [0xb22648]
// 0040f64c  50                   push eax
// 0040f64d  8d4c2430             lea ecx, [esp + 0x30]
// 0040f651  c744246000000000     mov dword ptr [esp + 0x60], 0
// 0040f659  e8821dffff           call 0x4013e0
// 0040f65e  c744242c583cb400     mov dword ptr [esp + 0x2c], 0xb43c58
// 0040f666  8d54242c             lea edx, [esp + 0x2c]
// 0040f66a  52                   push edx
// 0040f66b  c644246001           mov byte ptr [esp + 0x60], 1
// 0040f670  e82bfdffff           call 0x40f3a0
// 0040f675  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0040f679  5f                   pop edi
// 0040f67a  8bc6                 mov eax, esi
// 0040f67c  5e                   pop esi
// 0040f67d  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f684  83c458               add esp, 0x58
// 0040f687  c20c00               ret 0xc
// copied from an identical function in another client (function ??0date@gregorian@boost@@QAE@Vgreg_year@12@Vgreg_month@12@Vgreg_day@12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
namespace boost {
template<class E> __declspec(noreturn) void throw_exception(E const& e);
namespace gregorian {
class greg_year { public: unsigned short value_; operator unsigned short() const { return value_; } };
class greg_month { public: unsigned short value_; operator unsigned short() const { return value_; } };
class greg_day { public: unsigned short value_; operator unsigned short() const { return value_; } };
struct ymd_type {
	ymd_type(unsigned short y, unsigned short m, unsigned short d) : year(y), month(m), day(d) {}
	unsigned short year, month, day;
};
struct gregorian_calendar {
	static unsigned long day_number(const ymd_type& ymd);
	static unsigned short end_of_month_day(greg_year y, greg_month m);
};
struct bad_day_of_month : public std::out_of_range {
	bad_day_of_month(const std::string& s) : std::out_of_range(s) {}
};
class date_base {
public:
	date_base(greg_year y, greg_month m, greg_day d)
		: days_(gregorian_calendar::day_number(ymd_type(y, m, d))) {}
	unsigned long days_;
};
class date : public date_base {
public:
	date(greg_year y, greg_month m, greg_day d);
};
date::date(greg_year y, greg_month m, greg_day d) : date_base(y, m, d)
{
	if (gregorian_calendar::end_of_month_day(y, m) < d) {
		boost::throw_exception(bad_day_of_month(std::string("Day of month is not valid for year")));
	}
}
}
}