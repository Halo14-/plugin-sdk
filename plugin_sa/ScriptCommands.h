#pragma once
#include <game_sa\CPed.h>
#include <game_sa\ePadButtons.h>

class CSpawnInfo {
public:
	int model;
	CVector coord;

	CSpawnInfo() {}
};

class ScriptCommand
{
public:
	
	// Vehicle and ped tasks
	static void SetTaskEnterVehicleAsPassenger(CPed* ped, CVehicle* targetVeh, int seat, int time);
	static void SetTaskKillPedOnFoot(CPed* ped, CPed* targetPed);
	static void SetTaskKillPedOnFoot(CPed* ped, CPed* targetPed, int time);
	static void SetTaskGoToPedOnFoot(CPed* ped, CPed* targetPed);
	static void SetTaskGoToCoord(CPed* ped, CVector &coord, CVehicle* veh);
	static void SetTaskEnterVehicleAsDriver(CPed* ped, CVehicle* targetVeh, int time);
	static void SetTaskFollowPed(CPed* ped, CPed* targetPed);
	static void SetTaskShootAtPed(CPed* ped, CPed* targetPed);
	static void SetTaskLeaveCurrentCar(CPed* ped);
	static void SetTaskCarTempAction(CPed* ped, CVehicle* pedVeh, char action, int time);
	static void SetTaskCarDriveToCoord(CVehicle* veh, CVector &coord);
	static void SetTaskWander(CPed* ped);
	static void SetTaskWanderInCar(CPed* ped, CVehicle* targetVeh, float speed, char drivingStyle);
	static void SetTaskFollowCar(CVehicle* veh, CVehicle* targetVeh, float radius);
	static void SetCarGoToCoordAccurate(CVehicle* veh, CVector coord);
	static void SetHeliKeepEntityInView(CVehicle* veh, CPed* targetPed, float minAlt, float maxAlt);
	static void SetHeliGoToCoord(CVehicle* veh, CVector const &coord, float minAlt, float maxAlt);
	static void SetNextMoveState(eMoveState state);
	static void SetTaskDriveBy(CPed* ped, CPed* targetPed, CVehicle* targetVeh, CVector coord, float radius, int style, bool bRHS, int fireRate);
	static void SetTaskLookAbout(CPed* ped, int time);
	static void SetTaskScratchHead(CPed* ped);
	static void SetTaskGoToCoordOnFoot(CPed* ped, CVector coord, eMoveState state, int time);
	static void SetTaskFleePedAnyMeans(CPed* ped, CPed* targetPed, float runDistanceRadius, int time, bool bChangeCourse, int timeUnk1, int timeUnk2, float radius);
	static void SetTaskSmartFleePoint(CPed* ped, CVector point, float radius, int time);
	static void SetTaskSmartFleePed(CPed* ped, CPed* targetPed, float radius, int time);
	static void SetTaskGoToPedWhileAiming(CPed* ped, CPed* targetPed, float radiusMin, float radiusMax);
	static void SetTaskLeaveCarAndFleeToCoord(CPed* ped, CVehicle* veh, CVector coord);
	static void SetTaskTurnToFacePed(CPed* ped, CPed* targetPed);
	static void SetTaskArrestPed(CPed* ped, CPed* targetPed);
	static void SetTaskSay(CPed* ped, int audioTable);
	static void SetTaskGoToPedOnFoot(CPed* ped, CPed* targetPed, int time, float radius);
	static void SetTaskTurnToFaceCoord(CPed* ped, CVector coord);
	static void SetTaskPause(CPed* ped, int time);
	static void SetTaskPlayAnimSecondary(CPed* ped, char* animName, char* animFile, float framedelta, bool loop, bool lockX, bool lockY, bool lockF, int time);

	// Ped attributes
	static void SetClearPedTasks(CPed* ped);
	static void SetClearPedTasksImmediately(CPed* ped);
	static void SetPedNeverLeaveGroup(CPed* ped, bool bDontLeaveGroup);
	static void SetPedDecisionMaker(CPed* ped, int decision);
	static void SetPedShootRate(CPed* ped, int rate);
	static void SetPedRelationshipToPedtype(CPed* ped, char relationType, ePedType type);
	static bool IsPedMale(CPed* ped);
	static void SetPedCoordinates(CPed* ped, CVector coord);
	static void SetAnimGroupForPed(CPed* ped, char* animName);


	// Player attributes
	static void SetPlayerModel(int model);
	static void BuildPlayerModel();
	static void SetPlayerControl(bool enable);
	static void SetMaxWantedLevel(int level);
	static void WarpPedInCarAsPassenger(CPed* ped, CVehicle* veh, int seat);
	static bool IsPlayerDead();


	// Vehicle attributes
	static float GetCarSpeed(CVehicle* veh);
	static void SetCarForwardSpeed(CVehicle* veh, float speed);
	static void SetCarMaxSpeed(CVehicle* veh, float speed);
	static void PlaceCarAtCoordinates(CVehicle* veh, CVector &coord);
	static void PlacePedAtCoordinates(CPed* ped, CVector &coord);
	static void TurnCarToFaceCoord(CVehicle* veh, float x, float y);
	static void SetCarMission(CVehicle* veh, char mission);
	static void SetCarTempAction(CVehicle* veh, char action, int time);
	static void SetHeliBladesFullSpeed(CVehicle* veh);
	static void ControlCarDoor(CVehicle* veh, int door, int latchValue, float angle);
	static void FireWeaponOfCar(CVehicle* veh);
	static int GetNumberOfAvailablePaintjobs(CVehicle* veh);
	static void GiveVehiclePaintjob(CVehicle* veh, unsigned int jobNum);
	static void AttachTrailerToCab(CVehicle* veh, CVehicle* trailer);
	static void PlaneStartsInAir(CVehicle* veh);
	static void ForceHeliOrientation(CVehicle* veh, float angle);

	// Animation
	static void RequestionAnimationFile(char* animFile);
	static bool HasAnimationFileLoaded(char* animFile);
	static void ReleaseAnimationFile(char* animFile);

	// Existence
	static bool IsCarDead(CVehicle* veh);
	static bool IsPedDead(CPed* ped);

	// Coordinates
	static CVector FindNearestPedNodeToCoord(CVector coord);
	static CVector FindNearestCarNodeToCoord(CVector coord);
	static float GetHeadingForClosestCarNode(CVector coord);
	static CVector GetOffsetCoordFromPed(CPed* ped, float x, float y, float z);
	static float GetGroundZForCoord(CVector coord);
	static bool IsPointOnScreen(CVector point, float radius);
	static bool IsPedInCarNearPed(CPed* ped, CPed* targetPed, float radiusX, float radiusY, float radiusZ);


	// Group 
	static int CreateGroupOfType(int type);
	static void SetAsGroupLeader(int groupHandle, CPed* ped);
	// use groupHandle = -1 for player group
	static void SetAsGroupMember(int groupHandle, CPed* ped);
	static void ReleaseGroup(int groupHandle);
	static void SetGroupFollowStatus(int groupHandle, bool bStatus);
	// use groupHandle = -1 for player group
	static bool IsGroupMember(CPed* ped, int groupHandle);
	// use groupHandle = -1 for player group
	static int GetNumberOfGroupMembers(int groupHandle);
	static void RemoveFromGroup(CPed* ped);
	//static void SetPedNeverLeaveGroup(CPed* ped, bool bTrue);

	// Creation
	static CVehicle* CreateCarAtPosition(int model, CVector const &coord);
	static CPed* CreatePedInCarAsDriver(CVehicle* veh, ePedType type, int model);
	static CPed* CreatePedInCarAsPassenger(CVehicle* veh, ePedType type, int model, int seat);
	static CPed* CreateRandomPedInCarAsDriver(CVehicle* veh);
	static CPed* CreateRandomPedInCarAsPassenger(CVehicle* veh, int seat);
	static CPed* CreatePedAtPosition(ePedType pedType, int model, CVector coord);
	static CPed* CreateRandomPedAtCoord(CVector coord);
	static void CreateEmergencyServiceVehicleAtCoord(int model, CVector coord);

	// Camera
	static void SetFixedCameraPosition(CVector pos, float xAngle, float yAngle, float zAngle);
	static void PointCameraAtPosition(CVector pos, int switchstyle);
	static void RestoreCamera();
	static void AttachCameraToVehicleLookAtVehicle(CVehicle* veh, CVector offset, CVehicle* targetveh, float tilt, int switchstyle);
	static void AttachCameraToVehicleLookAtPed(CVehicle* veh, CVector offset, CPed* targetped, float tilt, int switchstyle);

	// Area, interior
	static void SetAreaVisible(int area);
	static void SetPedAreaVisible(CPed* ped, int area);

	// Removal
	static void MarkPedAsNoLongerNeeded(CPed* ped);
	static void MarkCarAsNoLongerNeeded(CVehicle* veh);
	// Removes ped with fade
	static void RemovePedElegantly(CPed* ped);

	// Searchlight
	static int CreateSearchlightOnVehicle(CVehicle* veh, CVector offset, CVector target, float dstRadius, float srcRadius);
	static void DeleteSearchlight(int searchlightHandle);
	static void PointSearchlightAtCoord(int searchlightHandle, CVector coord, float speed);
	static void PointSearchlightAtPed(int searchlightHandle, CPed* ped, float speed);
	static void MoveSearchlightBetweenPoints(int searchlightHandle, CVector coord1, CVector coord2, float speed);
	static void SetSearchlightClipIfColliding(int searchlightHandle, bool bSet);
	static bool DoesSearchlightExist(int searchlightHandle);

	// Particle
	static void FireSingleBullet(CVector src, CVector dest, int energy);
	static void CreateExplosionWithCameraShake(CVector coord, int type, float camShake);
	static void CreateExplosion(CVector coord, int type);
	static void DrawSphere(CVector coord, float radius);

	// Controller
	static bool IsButtonPressed(ePadButton button);
	static bool IsButtonPressed(int button);

	// Weapon
	static int GetModelFromWeaponType(eWeaponType weapon);
	static int GetModelFromWeaponType(int weaponID);

	// Model
	static bool HasModelLoaded(int model);
	static bool IsModelInCD(int model);
	static int GetRandomVehicleModelInMemory(bool bArg = true);

	// Renderer
	static void RequestCollision(CVector2D coord);

	// Retrieval
	static CVehicle* GetRandomCarInSphereNoSave(CVector coord, float radius);

	// Condition
	static bool HasPedBeenArrested(CPed* ped);

	// Blip/Marker
	static bool DoesBlipExist(int blipIndex);

	// Other
	static int LoadPedDecisionMaker(int id);
	static float GetAngleBetween2dVectors(float x1, float y1, float x2, float y2);
};