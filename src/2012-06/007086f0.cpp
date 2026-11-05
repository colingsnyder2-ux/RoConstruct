// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_serializer_load_native_bdce1b0b0dd41fcf.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/SerializerV2.h"
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"

namespace RBX
{
	template<> ContentProvider* ServiceProvider::create<ContentProvider>() const;
}

void SerializerV2::load(std::istream& stream, RBX::DataModel* dataModel)
{
	char header[5];
	header[4] = 0;
	if (!stream.read(header, 4).good())
		throw std::runtime_error("SerializerV2::load can't read header");

	if (strcmp(header, "RBX_") != 0)
	{
		stream.clear();
		stream.seekg(0, std::ios::beg);
		loadXML(stream, dataModel);
	}
	else
	{
	int fileFormatVersion;
	if (!stream.read(reinterpret_cast<char*>(&fileFormatVersion), sizeof(fileFormatVersion)).good())
		throw std::runtime_error("SerializerV2::load can't read old fileFormatVersion");
	if (fileFormatVersion != 1)
		throw std::runtime_error("SerializerV2::load canfileFormatVersion!=1");

	int contentPos = 0;
	if (!stream.read(reinterpret_cast<char*>(&contentPos), sizeof(contentPos)).good())
		throw std::runtime_error("SerializerV2::load can't read contentPos");

	if (contentPos != 0)
	{
		std::streamoff oldPos = stream.tellg();
		stream.clear();
		stream.seekg(contentPos, std::ios::beg);

		while (stream.peek())
		{
			char id[33];
			unsigned long dataLength;
			bool compressed;
			id[32] = 0;
			if (!stream.read(id, 32).good())
				throw std::runtime_error("SerializerV2::load error reading compound file (1)");
			if (!stream.read(reinterpret_cast<char*>(&dataLength), sizeof(dataLength)).good())
				throw std::runtime_error("SerializerV2::load error reading compound file (2)");
			if (!stream.read(reinterpret_cast<char*>(&compressed), sizeof(compressed)).good())
				throw std::runtime_error("SerializerV2::load error reading compound file (3)");
			if (compressed)
				throw std::runtime_error("SerializerV2::load error reading compound file (4)");

			RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel)->readContent(id, stream, dataLength);
		}

		stream.clear();
		stream.seekg(oldPos, std::ios::beg);
	}

	bool compressed;
	if (!stream.read(reinterpret_cast<char*>(&compressed), sizeof(compressed)).good())
		throw std::runtime_error("SerializerV2::load error reading compound file (5)");
	if (compressed)
		throw std::runtime_error("SerializerV2::load error reading compound file (6)");

	loadXML(stream, dataModel);
	}
}
