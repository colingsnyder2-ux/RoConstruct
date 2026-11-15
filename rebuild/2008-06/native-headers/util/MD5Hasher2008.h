#pragma once
// 2008-06 native RBX::MD5HasherImpl (inactive). Verified by tests/record_native_misc_leaves.py.
//
// The interface RBX::MD5Hasher is the donor declaration in util/ContentProvider.h (unchanged in 2008-06):
// MD5HasherImpl vtable 0082dc9c (RTTI .?AVMD5HasherImpl@RBX@@, bases MD5HasherImpl, MD5Hasher; no virtual base)
// has exactly 5 slots and no destructor slot:
//   0 addData(const char*, size_t) 0055c800   1 addData(const std::string&) 0055c740
//   2 addData(std::istream&) 0055c6a0         3 toString() 0055c710          4 c_str() 0055e320
// (MSVC places the three addData overloads in reverse declaration order.)
//
// Layout (sizeof 0x28: MD5Hasher::create 0055c8b0 calls operator new(0x28)):
//   +0x00 vfptr (constructor 0055c540 stores 0082dc9c)
//   +0x04 hProv  (constructor zeroes it, passes &+4 to CryptAcquireContextA)
//   +0x08 hHash  (constructor zeroes it, passes &+8 to CryptCreateHash; addData/c_str read +8)
//   +0x0c result std::string (msvcp90 basic_string ctor on +0xc; c_str tests size at +0x20, toString copies +0xc)
#include "util/ContentProvider.h"
#include <windows.h>
#include <wincrypt.h>
#include <string>
#include <istream>

namespace RBX
{
	class MD5HasherImpl : public MD5Hasher
	{
	private:
		HCRYPTPROV hProv;     // +0x04
		HCRYPTHASH hHash;     // +0x08
		std::string result;   // +0x0c

	public:
		MD5HasherImpl();      // 0055c540 (out of line in the original)

		virtual void addData(const char* data, size_t nBytes);  // 0055c800
		virtual void addData(const std::string& data);          // 0055c740
		virtual void addData(std::istream& data);               // 0055c6a0
		virtual std::string toString();                         // 0055c710
		virtual const char* c_str();                            // 0055e320
	};
}
