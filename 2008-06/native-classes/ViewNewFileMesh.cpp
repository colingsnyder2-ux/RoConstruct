// 2008-06 native RBX::ViewNew::FileMesh (inactive): the unit 00500780..00500c98 (/fp:fast like the other ViewNew units).
// >>> native-status (generated) -- do not edit >>>
// ViewNewFileMesh | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-chat)
// <<< native-status | src 9f4df88c | roc native-status --write
#include "ViewNew/FileMesh.h"
#include <stdio.h>
#include <exception>
#include <string>
#include <vector>

namespace RBX
{
	namespace ViewNew
	{
#ifdef NATIVE_VIEWNEW_FILEMESH_PENDING
		// 00500780. Needs ContentProvider::requestContentFile(const ContentId&, Status*, std::string&) (00562670) and its
		// status enum (1 = succeeded: cmp [ebp+0x58], 1), which util/NativeContentProvider.h does not declare yet.
		bool FileMesh::loadFromMeshFile(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile)
		{
			try
			{
				std::string filename;
				if (provider->requestContentFile(meshFile, filename) != ContentProvider::Succeeded)
					return false;

				G3D::ReferenceCountedPointer<Level> level = new Level(G3D::RenderDevice::TRIANGLES);
				levels.append(level);

				std::vector<unsigned int> vertices;

				FILE* f = fopen(filename.c_str(), "r");
				fscanf(f, "version 1.00\n");
				int numFaces;
				fscanf(f, "%d\n", &numFaces);

				for (int i = 0; i < numFaces; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						float vx, vy, vz, nx, ny, nz, tu, tv, tw;
						fscanf(f, "[%f,%f,%f][%f,%f,%f][%f,%f,%f]", &vx, &vy, &vz, &nx, &ny, &nz, &tu, &tv, &tw);

						G3D::Vector3 vertex = G3D::Vector3(vx, vy, vz) * 0.5f;
						G3D::Vector2 tex(tu, 1.0f - tv);
						G3D::Vector3 normal = G3D::Vector3(nx, ny, nz).direction();
						vertices.push_back(allocVertex(vertex * scale, normal, tex, true));
					}

					level->indexArray.append(allocVertex(vertices[0], 1), allocVertex(vertices[1], 1), allocVertex(vertices[2], 1));

					for (int k = 0; k < 3; k++)
						freeVertex(vertices[k]);

					vertices.clear();
				}

				fclose(f);
			}
			catch (std::exception&)
			{
				return false;
			}
			return true;
		}
#endif

		// 00500b90
		G3D::ReferenceCountedPointer<RenderBase::Mesh> FileMesh::create(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile)
		{
			FileMesh* newMesh = new FileMesh;
			G3D::ReferenceCountedPointer<FileMesh> mesh = newMesh;

			if (!newMesh->loadFromMeshFile(provider, scale, meshFile))
				return NULL;
			else
				return mesh;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<RBX::ViewNew::FileMesh>;
