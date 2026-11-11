// 2008-06 native RBX::MD5HasherImpl / MD5Hasher::create (inactive); evidence in native-headers/util/MD5Hasher2008.h.
// Verified by tests/record_native_misc_leaves.py. Rows 0055c540..0055c905 and c_str 0055e320.
// >>> native-status (generated) -- do not edit >>>
// MD5Hasher | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src acaad615 | roc native-status --write
#include "util/MD5Hasher2008.h"
#include "util/standardout.h"
#include <atlstr.h>

namespace RBX
{
	// 0055c540
	MD5HasherImpl::MD5HasherImpl()
		: hProv(NULL),
		  hHash(NULL),
		  result()
	{
		if (!CryptAcquireContextA(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptAcquireContext. GetLastError = %d", GetLastError());
		}

		if (!CryptCreateHash(hProv, CALG_MD5, NULL, NULL, &hHash))
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptCreateHash. GetLastError = %d", GetLastError());
		}
	}

	// 0055c800
	void MD5HasherImpl::addData(const char* data, size_t nBytes)
	{
		if (!CryptHashData(hHash, (const BYTE*)data, (DWORD)nBytes, 0))
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptHashData. GetLastError = %d", GetLastError());
		}
	}

	// 0055c740
	void MD5HasherImpl::addData(const std::string& data)
	{
		if (!CryptHashData(hHash, (const BYTE*)data.c_str(), (DWORD)data.length(), 0))
		{
			StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptHashData. GetLastError = %d", GetLastError());
		}
	}

	// 0055c6a0
	void MD5HasherImpl::addData(std::istream& data)
	{
		data.clear();
		data.seekg(0, std::ios_base::beg);

		char buffer[1024];
		do
		{
			data.read(buffer, sizeof(buffer));
			addData(buffer, data.gcount());
		}
		while (data.gcount() > 0);
	}

	// 0055c710
	std::string MD5HasherImpl::toString()
	{
		c_str();
		return result;
	}

	// 0055e320
	const char* MD5HasherImpl::c_str()
	{
		if (result.size() == 0)
		{
			DWORD hashSize;
			DWORD hashSizeLen = sizeof(DWORD);
			if (!CryptGetHashParam(hHash, HP_HASHSIZE, (BYTE*)&hashSize, &hashSizeLen, 0))
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptGetHashParam. GetLastError = %d", GetLastError());
			}

			char* hashValue = new char[hashSize];
			if (!CryptGetHashParam(hHash, HP_HASHVAL, (BYTE*)hashValue, &hashSize, 0))
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptGetHashParam. GetLastError = %d", GetLastError());
			}

			for (DWORD i = 0; i < hashSize; ++i)
			{
				ATL::CString temp;
				temp.Format("%02x", (unsigned char)hashValue[i]);
				result += temp.GetString();
			}

			delete[] hashValue;
		}

		return result.c_str();
	}

	// 0055c8b0
	MD5Hasher* MD5Hasher::create()
	{
		return new MD5HasherImpl();
	}
}
