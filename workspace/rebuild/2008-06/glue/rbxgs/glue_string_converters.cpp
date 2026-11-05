// Rebuild glue: rbxgs defines its StringConverter<T> specializations as inline class bodies in
// util/Utilities.cpp and v8tree/Property.cpp, so no object file ever emits them for other files to call.
// This unit compiles both files unchanged and takes each member's address so the compiler emits them.
// (The module excludes the two files from its main layer.)
#include "../../../../tools/rbxgs/Client/App/util/Utilities.cpp"
#include "../../../../tools/rbxgs/Client/App/v8tree/Property.cpp"

namespace
{
#define RBX_REBUILD_EMIT(T) \
	(void*)static_cast<std::string (*)(const T&)>(&RBX::StringConverter<T>::convertToString), \
	(void*)static_cast<bool (*)(const std::string&, T&)>(&RBX::StringConverter<T>::convertToValue)

	void* const emitted[] = {
		RBX_REBUILD_EMIT(bool), RBX_REBUILD_EMIT(int), RBX_REBUILD_EMIT(unsigned), RBX_REBUILD_EMIT(double),
		RBX_REBUILD_EMIT(float), RBX_REBUILD_EMIT(RBX::ContentId), RBX_REBUILD_EMIT(RBX::MeshId),
		RBX_REBUILD_EMIT(RBX::TextureId), RBX_REBUILD_EMIT(G3D::Vector3), RBX_REBUILD_EMIT(G3D::Color3),
	};
#undef RBX_REBUILD_EMIT
}

// referenced so the table (and through it the emitted members) is kept
void* rbxRebuildStringConverters() { return (void*)emitted; }
