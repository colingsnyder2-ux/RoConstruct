// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_md5_native_length_family_7dc6dfbd72b7e96e.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "util/ContentProvider.h"
#include "util/standardout.h"
#include <windows.h>
#include <wincrypt.h>
#include <atlstr.h>
namespace RBX {

	class MD5HasherImpl : public MD5Hasher
	{
	private:
		HCRYPTPROV hProv;
		HCRYPTHASH hHash;
		std::string result;

	public:
		MD5HasherImpl()
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
		~MD5HasherImpl()
		{
		}

	public:
		virtual void addData(const char* data, size_t nBytes)
		{
			if (!CryptHashData(hHash, (const BYTE*)data, (DWORD)nBytes, 0))
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptHashData. GetLastError = %d", GetLastError());
			}
		}
		virtual void addData(const std::string& data)
		{
			if (!CryptHashData(hHash, (const BYTE*)data.c_str(), (DWORD)data.length(), 0))
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, "Error during CryptHashData. GetLastError = %d", GetLastError());
			}
		}
		virtual void addData(std::istream& data)
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
		virtual std::string toString()
		{
			c_str();
			return result;
		}
		virtual const char* c_str()
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
	};

	MD5Hasher* MD5Hasher::create()
	{
		return new MD5HasherImpl();
	}
}
