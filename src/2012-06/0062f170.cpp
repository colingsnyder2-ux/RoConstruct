// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Contact.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Contact.h"

#include "decomp.h"
#include "util/Math.h"
#include "util/StlExtra.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Kernel.h"
#include "v8world/Block.h"
#include "v8world/Primitive.h"

#include <algorithm>

namespace RBX {

int Contact::contactPairMatches;
int Contact::contactPairMisses;

// FUNCTION: WEBSERVICE 0x100d1fb0
Contact::Contact(Primitive* p0, Primitive* p1)
	: Edge(p0, p1), lastContactStep(-1), steppingIndex(-1), jointK(0), elasticJointK(0), kFriction(0)
{
}

// FUNCTION: WEBSERVICE 0x100d1fe0
bool Contact::step(int uiStepId)
{
	bool touching = stepContact();

	if (touching) {
		if (lastContactStep == -1) {
			Primitive::onNewTouch(getPrimitive(0), getPrimitive(1));
		}

		lastContactStep = uiStepId;
	}
	else {
		if (lastContactStep < uiStepId) {
			lastContactStep = -1;
		}
	}

	return touching;
}

// FUNCTION: WEBSERVICE 0x100d2030
bool Contact::computeIsAdjacent(float spaceAllowed)
{
	if (computeIsColliding(spaceAllowed)) {
		return false;
	}

	return computeIsColliding(-spaceAllowed);
}

// FUNCTION: WEBSERVICE 0x100d2070
void Contact::deleteConnector(ContactConnector*& c)
{
	if (c != NULL) {
		getKernel()->removeConnector(c);

		delete c;

		c = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x100d22b0
ContactConnector* Contact::createConnector()
{
	ContactConnector* connector = new ContactConnector(jointK, elasticJointK, kFriction);

	getKernel()->insertConnector(connector);

	return connector;
}

// FUNCTION: WEBSERVICE 0x100d2330
bool BallBallContact::computeIsColliding(float overlapIgnored)
{
	float r0 = getPrimitive(0)->getGeometry()->getRadius();
	float r1 = getPrimitive(1)->getGeometry()->getRadius();

	const Vector3& p0 = getPrimitive(0)->getBody()->getPV().position.translation;
	const Vector3& p1 = getPrimitive(1)->getBody()->getPV().position.translation;

	float dx = p1.x - p0.x;
	float dy = p1.y - p0.y;
	float dz = p1.z - p0.z;

	float radiusSum = r0 + r1;

	if (radiusSum > std::max(fabsf(dx), std::max(fabsf(dy), fabsf(dz)))) {
		return sqrtf(dx * dx + dy * dy + dz * dz) < radiusSum - overlapIgnored;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d2430
bool BallBallContact::stepContact()
{
	if (BallBallContact::computeIsColliding(0.0f)) {

		if (inKernel()) {

			if (ballBallConnector == NULL) {
				ballBallConnector = createConnector();
			}

			Ball* ball1 = ball(1);
			Ball* ball0 = ball(0);

			ContactConnector* connector = ballBallConnector;

			Body* body1 = getBody(1);
			Body* body0 = getBody(0);

			float radius0 = ball0->getRadius();
			float radius1 = ball1->getRadius();

			connector->setBallBall(body0, body1, radius0, radius0 + radius1);
		}

		return true;
	}

	deleteAllConnectors();

	return false;
}

// FUNCTION: WEBSERVICE 0x100d24c0
bool BallBlockContact::computeIsColliding(
	int& onBorder,
	G3D::Vector3int16& clip,
	Vector3& projectionInBlock,
	float overlapIgnored
)
{
	if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1))) {

		Body* ballBody = getPrimitive(0)->getBody();
		Body* blockBody = getPrimitive(1)->getBody();

		const PV& ballPV = ballBody->getPV();
		const PV& blockPV = blockBody->getPV();

		Vector3 blockToBall = ballPV.position.translation - blockPV.position.translation;

		projectionInBlock = blockPV.position.rotation.transpose() * blockToBall;

		((Block*) getPrimitive(1)->getGeometry())->projectToFace(projectionInBlock, clip, onBorder);

		Vector3 blockPtWorld = blockPV.position.pointToWorldSpace(projectionInBlock);

		return (blockPtWorld - ballPV.position.translation).magnitude() <
			   getPrimitive(0)->getGeometry()->getRadius() - overlapIgnored;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d25f0
bool BallBlockContact::stepContact()
{
	int onBorder;
	Vector3int16 clip;
	Vector3 projectionInBlock(0, 0, 0);

	if (computeIsColliding(onBorder, clip, projectionInBlock, 0.0f)) {

		if (inKernel()) {

			if (ballBlockConnector == NULL) {
				ballBlockConnector = createConnector();
			}

			const Vector3* offset;
			NormalId normalID;

			GeoPairType pairType = onBorder != 0 ? block()->getBallBlockInfo(onBorder, clip, offset, normalID)
												 : block()->getBallInsideInfo(projectionInBlock, offset, normalID);

			ballBlockConnector->setBallBlock(getBody(0), getBody(1), ball()->getRadius(), offset, normalID, pairType);
		}

		return true;
	}

	deleteAllConnectors();

	return false;
}

// STUB: WEBSERVICE 0x100d2710
bool BlockBlockContact::getBestPlaneEdge(bool& planeContact, float overlapIgnored)
{
	float bestPlaneLength = Math::inf();
	float bestEdgeLength = Math::inf();
	float lastPlaneLength = Math::inf();

	int lastFeature[2] = {feature[0], feature[1]};

	bool checkLastFeature = (lastFeature[0] >= 0 && lastFeature[0] < 6) || (lastFeature[1] >= 0 && lastFeature[1] < 6);

	for (int i = separatingBodyId; i < separatingBodyId + 2; i++) {

		int baseId = i % 2;
		int i1 = (i + 1) % 2;

		const CoordinateFrame& cBase = getBody(baseId)->getCoordinateFrame();
		const CoordinateFrame& cTest = getBody(i1)->getCoordinateFrame();

		const Vector3& eBase = block(baseId)->getExtent();
		const Vector3& eTest = block(i1)->getExtent();

		Vector3 pTestInBase = cBase.pointToObjectSpace(cTest.translation);

		for (int testId = separatingAxisId; testId < separatingAxisId + 3; testId++) {

			int j = testId % 3;

			Vector3 eBaseInTest = cBase.rotation.getColumn(j) * cTest.rotation;

			float length = fabsf(eBaseInTest.y * eTest.y) + fabsf(eBaseInTest.x * eTest.x) +
						   fabsf(eBaseInTest.z * eTest.z) + eBase[j] - fabsf(pTestInBase[j]);

			if (!(length > overlapIgnored)) {
				separatingBodyId = baseId;
				separatingAxisId = j;

				return false;
			}

			if (checkLastFeature) {
				if (lastFeature[baseId] % 3 == j) {
					lastPlaneLength = length;
				}
			}

			if (length < bestPlaneLength) {
				bestPlaneLength = length;

				feature[baseId] = pTestInBase[j] > 0 ? j : j + 3;
				feature[i1] = -1;

				separatingBodyId = baseId;
				separatingAxisId = j;

				planeContact = true;
			}
		}
	}

	if (checkLastFeature && (feature[0] != lastFeature[0] || feature[1] != lastFeature[1]) &&
		!(bestPlaneLength * 1.01f < lastPlaneLength)) {

		bestPlaneLength = lastPlaneLength;

		feature[0] = lastFeature[0];
		feature[1] = lastFeature[1];
	}

	const CoordinateFrame& c0 = getBody(0)->getCoordinateFrame();
	const CoordinateFrame& c1 = getBody(1)->getCoordinateFrame();

	const Vector3& extent0 = block(0)->getExtent();
	const Vector3& extent1 = block(1)->getExtent();

	Vector3 p0p1 = c1.translation - c0.translation;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			Vector3 crossAxis = c0.rotation.getColumn(i).cross(c1.rotation.getColumn(j));

			if (crossAxis.unitize() <= 0.001f) {
				return planeContact;
			}

			float p0p1inCrossAxis = p0p1.dot(crossAxis);

			Vector3 crossInBase = crossAxis * c0.rotation;
			Vector3 crossInTest = crossAxis * c1.rotation;

			float length = fabsf(crossInBase.x * extent0.x) + fabsf(crossInBase.y * extent0.y) +
						   fabsf(crossInBase.z * extent0.z) + fabsf(crossInTest.x * extent1.x) +
						   fabsf(crossInTest.y * extent1.y) + fabsf(crossInTest.z * extent1.z) - fabsf(p0p1inCrossAxis);

			if (!(length > overlapIgnored)) {
				return false;
			}

			if (length < bestEdgeLength) {
				bestEdgeLength = length;

				if (length * 10.0f < bestPlaneLength) {

					if (p0p1inCrossAxis > 0) {
						feature[0] = block(0)->getClosestEdge(c0.rotation, (NormalId) i, crossAxis) + 6;
						feature[1] = block(1)->getClosestEdge(c1.rotation, (NormalId) j, -crossAxis) + 6;
					}
					else {
						Vector3 negCrossAxis = -crossAxis;

						feature[0] = block(0)->getClosestEdge(c0.rotation, (NormalId) i, negCrossAxis) + 6;
						feature[1] = block(1)->getClosestEdge(c1.rotation, (NormalId) j, crossAxis) + 6;
					}

					planeContact = false;
				}
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100d2da0
void Contact::onPrimitiveContactParametersChanged()
{
	Primitive* prim0 = getPrimitive(0);
	Primitive* prim1 = getPrimitive(1);

	kFriction = std::min(prim0->getFriction(), prim1->getFriction());

	float elasticity = std::min(prim0->getElasticity(), prim1->getElasticity());

	jointK = std::min(prim0->getJointK(), prim1->getJointK());

	elasticJointK = Constants::getElasticMultiplier(elasticity) * jointK;
}

// FUNCTION: WEBSERVICE 0x100d2ea0
bool BallBlockContact::computeIsColliding(float overlapIgnored)
{
	int onBorder;
	Vector3int16 clip(0, 0, 0);
	Vector3 projectionInBlock(0, 0, 0);

	return computeIsColliding(onBorder, clip, projectionInBlock, overlapIgnored);
}

// FUNCTION: WEBSERVICE 0x100d2ef0
bool BlockBlockContact::computeIsColliding(float overlapIgnored)
{
	if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1))) {

		bool temp;

		return getBestPlaneEdge(temp, overlapIgnored);
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d4150
void BlockBlockContact::deleteAllConnectors()
{
	for (unsigned int i = 0; i < connectors.size(); i++) {
		deleteConnector(connectors[i]);
	}

	connectors.resize(0);
	matched.resize(0);
}

// FUNCTION: WEBSERVICE 0x100d41e0
void BlockBlockContact::deleteUnmatchedConnectors()
{
	for (int i = connectors.size() - 1; i >= 0; i--) {

		if (!matched[i]) {

			ContactConnector* c = connectors[i];

			fastRemoveIndex(connectors, i);
			fastRemoveIndex(matched, i);

			deleteConnector(c);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d42f0
ContactConnector* BlockBlockContact::matchContactConnector(
	Body* b0,
	Body* b1,
	GeoPairType _pairType,
	int param0,
	int param1
)
{
	for (unsigned int i = 0; i < matched.size(); i++) {

		if (!matched[i]) {

			if (connectors[i]->match(b0, b1, _pairType, param0, param1)) {

				matched[i] = true;

				contactPairMatches++;

				return connectors[i];
			}
		}
	}

	contactPairMisses++;

	ContactConnector* c = createConnector();

	connectors.push_back(c);
	matched.push_back(true);

	return c;
}

// FUNCTION: WEBSERVICE 0x100d44e0
void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
{
	NormalId normalID0 = block(b0)->getEdgeNormal(edge0);
	NormalId normalID1 = block(b1)->getEdgeNormal(edge1);

	ContactConnector* c = matchContactConnector(getBody(b0), getBody(b1), EDGE_EDGE_PAIR, normalID0, normalID1);

	c->setEdgeEdge(
		getBody(b0),
		getBody(b1),
		block(b0)->getEdgeVertex(edge0),
		block(b1)->getEdgeVertex(edge1),
		normalID0,
		normalID1
	);
}

// FUNCTION: WEBSERVICE 0x100d45e0
void BlockBlockContact::loadGeoPairPointPlane(
	int pointBody,
	int planeBody,
	int pointID,
	NormalId pointFaceID,
	NormalId planeFaceID
)
{
	ContactConnector* c =
		matchContactConnector(getBody(pointBody), getBody(planeBody), POINT_PLANE_PAIR, pointID, planeFaceID);

	c->setPointPlane(
		getBody(pointBody),
		getBody(planeBody),
		block(pointBody)->getFaceVertex(pointFaceID, pointID),
		block(planeBody)->getFaceVertex(planeFaceID, 0),
		pointID,
		planeFaceID
	);
}

// FUNCTION: WEBSERVICE 0x100d4680
void BlockBlockContact::loadGeoPairEdgeEdgePlane(int edgeBody, int planeBody, int edge0, int edge1)
{
	NormalId normalID0 = block(edgeBody)->getEdgeNormal(edge0);
	NormalId normalID1 = block(planeBody)->getEdgeNormal(edge1);

	ContactConnector* c =
		matchContactConnector(getBody(edgeBody), getBody(planeBody), EDGE_EDGE_PLANE_PAIR, normalID0, normalID1);

	c->setEdgeEdgePlane(
		getBody(edgeBody),
		getBody(planeBody),
		block(edgeBody)->getEdgeVertex(edge0),
		block(planeBody)->getEdgeVertex(edge1),
		normalID0,
		normalID1,
		planeID,
		block(edgeBody)->getGridSize()[normalID0 % 3]
	);
}

// FUNCTION: WEBSERVICE 0x100d47b0
int BlockBlockContact::intersectRectQuad(Vector2& planeRect, Vector2 (&otherQuad)[4])
{
	bool rectCrossQuad[4][4];

	int found;

	bool quadIn[4] = {true, true, true, true};

	found = 0;

	for (int i = 3; i >= 0; i--) {

		if (otherQuad[i].y <= planeRect.y) {
			rectCrossQuad[0][i] = true;
		}
		else {
			rectCrossQuad[0][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].x >= -planeRect.x) {
			rectCrossQuad[1][i] = true;
		}
		else {
			rectCrossQuad[1][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].y >= -planeRect.y) {
			rectCrossQuad[2][i] = true;
		}
		else {
			rectCrossQuad[2][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].x <= planeRect.x) {
			rectCrossQuad[3][i] = true;
		}
		else {
			rectCrossQuad[3][i] = false;
			quadIn[i] = false;
		}
	}

	for (int i = 3; i >= 0; i--) {
		if (quadIn[i]) {
			loadGeoPairPointPlane(bOther, bPlane, i, otherPlaneID, planeID);

			found++;
		}
	}

	if (found == 4) {
		return 4;
	}

	bool quadCrossRect[4][4];
	bool rectIn[4] = {true, true, true, true};

	Vector2 rect[4];

	rect[0] = Vector2(planeRect.x, planeRect.y);
	rect[1] = Vector2(-planeRect.x, planeRect.y);
	rect[2] = Vector2(-planeRect.x, -planeRect.y);
	rect[3] = Vector2(planeRect.x, -planeRect.y);

	for (int i = 3; i >= 0; i--) {

		Vector2 quadEdge = otherQuad[(i + 3) % 4] - otherQuad[i];

		for (int j = 0; j < 4; j++) {

			Vector2 rectToQuad = rect[j] - otherQuad[i];

			if (rectToQuad.y * quadEdge.x - quadEdge.y * rectToQuad.x >= 0.0f) {
				quadCrossRect[i][j] = true;
			}
			else {
				quadCrossRect[i][j] = false;
				rectIn[j] = false;
			}
		}
	}

	int noneFound = found == 0;

	for (int j = 0; j < 4; j++) {
		if (rectIn[j]) {
			loadGeoPairPointPlane(bPlane, bOther, j, planeID, otherPlaneID);

			found++;
		}
	}

	if (noneFound && found == 4) {
		return found;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 0; j--) {

			if (rectCrossQuad[i][j] != rectCrossQuad[i][(j + 3) % 4]) {

				if (quadCrossRect[j][i] != quadCrossRect[j][(i + 1) % 4]) {

					loadGeoPairEdgeEdgePlane(
						bOther,
						bPlane,
						block(bOther)->faceVertexToEdge(otherPlaneID, (j + 3) % 4),
						block(bPlane)->faceVertexToEdge(planeID, i)
					);

					found++;
				}
			}
		}
	}

	return found;
}

// STUB: WEBSERVICE 0x100d4be0
int BlockBlockContact::computePlaneContact()
{
	if (feature[0] >= 0) {
		planeID = (NormalId) feature[0];
		bPlane = 0;
		bOther = 1;
	}
	else {
		planeID = (NormalId) feature[1];
		bPlane = 1;
		bOther = 0;
	}

	const CoordinateFrame& otherCoord = getBody(bOther)->getCoordinateFrame();
	const CoordinateFrame& planeCoord = getBody(bPlane)->getCoordinateFrame();

	CoordinateFrame otherToPlane = planeCoord.inverse() * otherCoord;

	Block& otherBlock = *block(bOther);
	Block& planeBlock = *block(bPlane);

	int planeFlip = planeID / 3;
	int planeAxis = planeID - 3 * planeFlip;

	otherPlaneID = Math::getClosestObjectNormalId(
		-(Vector3(
			  planeCoord.rotation[0][planeAxis],
			  planeCoord.rotation[1][planeAxis],
			  planeCoord.rotation[2][planeAxis]
		  ) *
		  (float) (1 - 2 * planeFlip)),
		otherCoord.rotation
	);

	Vector2 planeRect = planeBlock.getProjectedVertex(*planeBlock.getFaceVertex(planeID, 0), planeID);

	Vector2 otherQuad[4];

	for (int i = 0; i < 4; i++) {
		const Vector3& otherVertex = *otherBlock.getFaceVertex(otherPlaneID, i);

		Vector3 otherVertexPlaneCoords = otherToPlane.pointToWorldSpace(otherVertex);

		otherQuad[i] = otherBlock.getProjectedVertex(otherVertexPlaneCoords, planeID);
	}

	return intersectRectQuad(planeRect, otherQuad);
}

// FUNCTION: WEBSERVICE 0x100d4df0
bool BlockBlockContact::stepContact()
{
	bool planeContact;

	if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(planeContact, 0.0f)) {

		if (inKernel()) {

			matched.resize(0);
			matched.resize(connectors.size());

			if (planeContact) {
				computePlaneContact();
			}
			else {
				loadGeoPairEdgeEdge(0, 1, feature[0] - 6, feature[1] - 6);
			}

			deleteUnmatchedConnectors();
		}

		return true;
	}

	deleteAllConnectors();

	feature[0] = -1;
	feature[1] = -1;

	return false;
}

} // namespace RBX
