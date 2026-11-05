// from server: 100% by auto
// from server: 99% by EspClaude
// from server: 80% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_8ae1f5b421ed2a5b.cpp

// Candidate translation unit (score above; library headers required).
#include <stdio.h>
#include <exception>
#include <string>
#include <vector>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/Array.h>
#include <G3D/ReferenceCount.h>

namespace RBX
{
	class Name;
	class ContentId
	{
	private:
		std::string id;
		const Name* mimeTypePtr;
	};
	class MeshId : public ContentId
	{
	};

	class ContentProvider
	{
	public:
		enum Status { Failed, Succeeded, Pending };
		void requestContentFile(const ContentId& id, Status* status, std::string& filename);
		__forceinline Status requestContentFile(const ContentId& id, std::string& filename)
		{
			Status status;
			requestContentFile(id, &status, filename);
			return status;
		}
	};

	namespace Render
	{
		class Mesh : public G3D::ReferenceCountedObject
		{
		public:
			class Level : public G3D::ReferenceCountedObject
			{
			public:
				G3D::Array<unsigned> indexArray;
				int primitive;
				bool exeDirty;
				int exeFirst;
				int exeCount;
			public:
				Level(int primitive);
				virtual ~Level();
			};
		protected:
			G3D::Array<G3D::ReferenceCountedPointer<Level> > levels;
		protected:
			Mesh();
		public:
			virtual ~Mesh();
			static unsigned allocVertex(unsigned i, unsigned count);
			static unsigned allocVertex(const G3D::Vector3& vertex, const G3D::Vector3& normal, const G3D::Vector2& tex, bool share);
			static void freeVertex(unsigned index);
		};
	}

	namespace View
	{
		class FileMesh : public Render::Mesh
		{
		public:
			bool loadFromMeshFile(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile);
		};

		bool FileMesh::loadFromMeshFile(ContentProvider* provider, const G3D::Vector3& scale, MeshId meshFile)
		{
			try
			{
			std::string filename;
			if (provider->requestContentFile(meshFile, filename) != ContentProvider::Succeeded)
				return false;

			G3D::ReferenceCountedPointer<Level> level = new Level(2);
			levels.append(level);

			std::vector<unsigned> vertices;

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
	}
}
