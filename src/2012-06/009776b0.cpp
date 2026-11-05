// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/Guid.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Guid.h"

#include "decomp.h"
#include "util/Name.h"

#define NOMINMAX

#include <algorithm>
#include <boost/thread/once.hpp>
#include <objbase.h>
#include <stdio.h>
#include <windows.h>

namespace RBX {

static const Name* localScope;
static long nextIndex;

// FUNCTION: WEBSERVICE 0x1003d410
void Guid::generateGUID(std::string& result)
{
	GUID guid;

	result = "RBX";

	CoCreateGuid(&guid);

	WCHAR wszGUID[64] = L"";
	char ansiClsid[64];

	StringFromGUID2(guid, wszGUID, 64);
	WideCharToMultiByte(CP_ACP, 0, wszGUID, 64, ansiClsid, 64, NULL, NULL);

	result += ansiClsid;

	result.erase(0x28, 1);
	result.erase(0x1b, 1);
	result.erase(0x16, 1);
	result.erase(0x11, 1);
	result.erase(0x0c, 1);
	result.erase(0x03, 1);
}

// FUNCTION: WEBSERVICE 0x1003d4e0
void Guid::assign(Data data)
{
	this->data = data;
}

// FUNCTION: WEBSERVICE 0x1003d4f0
bool Guid::Data::operator<(const Data& other) const
{
	const Name* otherScope = other.scope;
	const Name* thisScope = scope;
	int order = 0;

	if (thisScope != otherScope) {
		order = thisScope->name.compare(otherScope->name);

		if (order != -1 && order != 0) {
			return false;
		}
	}

	if (order == 0) {
		return index < other.index;
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x1003d540
int Guid::compare(const Guid* a, const Guid* b)
{
	const Name* scopeA = a != NULL ? a->data.scope : NULL;
	const Name* scopeB = b != NULL ? b->data.scope : NULL;
	int order;

	if (scopeA == NULL) {
		order = scopeB != NULL ? -1 : 0;
	}
	else if (scopeB == NULL) {
		order = 1;
	}
	else if (scopeA == scopeB) {
		order = 0;
	}
	else {
		order = scopeA->name.compare(scopeB->name);
	}

	if (order != -1) {
		if (order != 0 && order != 1) {
			return 0;
		}

		if (order == 0) {
			int indexA = a != NULL ? a->data.index : 0;
			int indexB = b != NULL ? b->data.index : 0;

			if (indexA > indexB) {
				return 1;
			}

			return indexA >= indexB ? 0 : -1;
		}

		return 1;
	}

	return -1;
}

// FUNCTION: WEBSERVICE 0x1003d5d0
int Guid::compare(const Guid* a0, const Guid* a1, const Guid* b0, const Guid* b1)
{
	int a = compare(a0, a1);
	int b = compare(b0, b1);
	const Guid* worseA = a == 1 ? a0 : a1;
	int order = compare(worseA, b == 1 ? b0 : b1);

	if (order != -1) {
		if (order != 0) {
			return order == 1;
		}

		const Guid* betterA = a == 1 ? a1 : a0;

		return compare(betterA, b == 1 ? b1 : b0);
	}

	return -1;
}

// FUNCTION: WEBSERVICE 0x1003d660
static void initLocalScope()
{
	std::string guid;

	Guid::generateGUID(guid);
	localScope = &Name::declare(guid.c_str(), -1);
}

// FUNCTION: WEBSERVICE 0x1003d6e0
const Name& Guid::getLocalScope()
{
	static boost::once_flag flag = BOOST_ONCE_INIT;

	boost::call_once(initLocalScope, flag);

	return *localScope;
}

// FUNCTION: WEBSERVICE 0x1003d700
Guid::Guid()
{
	data.scope = &getLocalScope();
	data.index = InterlockedIncrement(&nextIndex);
}

// FUNCTION: WEBSERVICE 0x1003d730
std::string Guid::Data::readableString(int scopeLength) const
{
	char buffer[64];

	if (scopeLength > 0) {
		std::string s = scope->name;

		s = s.substr(std::min<size_t>(3, s.size()), std::min(scopeLength, 32));

		sprintf(buffer, "%s_%d", s.c_str(), index);
	}
	else {
		sprintf(buffer, "%d", index);
	}

	return std::string(buffer);
}

} // namespace RBX
