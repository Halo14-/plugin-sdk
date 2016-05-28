#include "ScriptCommands.h"

#include <game_sa\CRunningScriptWrapper.h>
#include <game_sa\CPools.h>
#include <game_sa\RenderWare.h>


// 05CA: task_enter_car_as_passenger $ACTOR_SMOKE car 41@ seat 0 time 10000
void ScriptCommand::SetTaskEnterVehicleAsPassenger(CPed* ped, CVehicle* targetveh, int seat, int time)
{
	if (!ped || !targetveh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(targetveh);

	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(seat, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x5CA);

	return;
}
// 05E2: task_kill_char_on_foot 65@ char 50@
void ScriptCommand::SetTaskKillPedOnFoot(CPed* ped, CPed* targetped)
{
	if (!ped || !targetped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);

	// 0x05E2
	TheSCMWrapper.CallCommand(0x5E2);

	return;
}
// 07A5: task_kill_char_on_foot_timed - 1 char $PLAYER_ACTOR time 1500
void ScriptCommand::SetTaskKillPedOnFoot(CPed* ped, CPed* targetped, int time)
{
	if (!ped || !targetped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushInt(time, false);

	// 0x05E2
	TheSCMWrapper.CallCommand(0x7A5);

	return;
}
// 0603: task_go_to_coord_any_means 65@(48@,3i) coord 2493.82 -1669.91 12.8 walk_speed 7 car -1
void ScriptCommand::SetTaskGoToCoord(CPed* ped, CVector& coord, CVehicle* targetveh)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	float x = coord.x;
	float y = coord.y;
	float z = coord.z;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(x, false);
	TheSCMWrapper.PushFloat(y, false);
	TheSCMWrapper.PushFloat(z, false);
	TheSCMWrapper.PushInt(7, false);
	int vehHandle;
	if (targetveh)
		vehHandle = CPools::ms_pVehiclePool->GetIndex(targetveh);
	else
		vehHandle = -1;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x603);

	return;
}
// 0850: task_follow_footsteps 95@ char $PLAYER_ACTOR
void ScriptCommand::SetTaskFollowPed(CPed* ped, CPed* targetped)
{
	if (!ped || !targetped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);

	TheSCMWrapper.CallCommand(0x850);

	return;
}
// 05CB: task_enter_car_as_driver $PLAYER_ACTOR car 41@ time 10000
void ScriptCommand::SetTaskEnterVehicleAsDriver(CPed* ped, CVehicle* targetveh, int time)
{
	if (!ped || !targetveh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pVehiclePool->GetIndex(targetveh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x5CB);

	return;
}
// 074D: task_shoot_at_char -1 char 37@ time -2
void ScriptCommand::SetTaskShootAtPed(CPed* ped, CPed* targetped)
{
	if (!ped || !targetped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushInt(1000, false);

	TheSCMWrapper.CallCommand(0x74D);

	return;
}
// 0633: task_leave_any_car 50@
void ScriptCommand::SetTaskLeaveCurrentCar(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x633);

	return;
}
// 00A7: car_goto_coordinates 99@ coords 252@ 253@ 254@
void ScriptCommand::SetTaskCarDriveToCoord(CVehicle* veh, CVector& coord)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	float x = coord.x;
	float y = coord.y;
	float z = coord.z;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(x, false);
	TheSCMWrapper.PushFloat(y, false);
	TheSCMWrapper.PushFloat(z, false);

	TheSCMWrapper.CallCommand(0x0A7);

	return;
}
// 05DE: task_wander_standard 54@
void ScriptCommand::SetTaskWander(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x5DE);

	return;
}
// 05D2: task_car_drive_wander 50@ car 51@ speed 20.0 driving_style 2
void ScriptCommand::SetTaskWanderInCar(CPed* ped, CVehicle* veh, float speed, char drivingStyle)
{
	if (!ped || !veh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(speed, false);
	TheSCMWrapper.PushInt(drivingStyle, false);

	TheSCMWrapper.CallCommand(0x5D2);

	return;
}
// 07F8: set_car_follow_car 74@ car 72@ radius 27.0
void ScriptCommand::SetTaskFollowCar(CVehicle* veh, CVehicle* targetveh, float radius)
{
	if (!veh || !targetveh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	int targetvehHandle = CPools::ms_pVehiclePool->GetIndex(targetveh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(targetvehHandle, false);
	TheSCMWrapper.PushFloat(radius, false);

	TheSCMWrapper.CallCommand(0x7F8);

	return;
}

// 0687: clear_char_tasks $PLAYER_ACTOR 
void ScriptCommand::SetClearPedTasks(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x687);

	return;
}

// 02E3: get_car_speed 59@ store_to 188@
float ScriptCommand::GetCarSpeed(CVehicle* veh)
{
	if (!veh)
		return NULL;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_FLOAT);

	TheSCMWrapper.CallCommand(0x2E3);

	tRunningScriptWrapper_SavedReturnedValuesArray speed;
	TheSCMWrapper.SaveReturnedValues(speed);

	return speed.returnedValues[0].Float;
}
// 00AD: set_car_cruise_speed 36@ to 10.0
void ScriptCommand::SetCarMaxSpeed(CVehicle* veh, float speed)
{
	if (!veh)
		return;
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.PushFloat(speed);

	TheSCMWrapper.CallCommand(0x0AD);

	return;
}

// 02C0: get_closest_char_node 141@ 142@ 143@ store_to 137@ 138@ 139@
CVector ScriptCommand::FindNearestPedNodeToCoord(CVector coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArguments(RUNNING_SCRIPT_VALUE_TYPE_FLOAT, 3);

	TheSCMWrapper.CallCommand(0x2C0);

	tRunningScriptWrapper_SavedReturnedValuesArray nodeVal;
	TheSCMWrapper.SaveReturnedValues(nodeVal);
	CVector nodeCoord;
	nodeCoord.x = nodeVal.returnedValues[0].Float;
	nodeCoord.y = nodeVal.returnedValues[1].Float;
	nodeCoord.z = nodeVal.returnedValues[2].Float;

	return nodeCoord;
}

// 02C1: get_closest_car_node 116@ 117@ 118@ store_to 119@ 120@ 121@
CVector ScriptCommand::FindNearestCarNodeToCoord(CVector coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArguments(RUNNING_SCRIPT_VALUE_TYPE_FLOAT, 3);

	TheSCMWrapper.CallCommand(0x2C1);

	tRunningScriptWrapper_SavedReturnedValuesArray nodeVal;
	TheSCMWrapper.SaveReturnedValues(nodeVal);
	CVector nodeCoord;
	nodeCoord.x = nodeVal.returnedValues[0].Float;
	nodeCoord.y = nodeVal.returnedValues[1].Float;
	nodeCoord.z = nodeVal.returnedValues[2].Float;

	return nodeCoord;
}

// 04C4: get_offset_from_char_in_world_coords 215@ offset 1.0 3.0 1.0 store_to $TEMPVAR_FLOAT_1 $TEMPVAR_FLOAT_2 $TEMPVAR_FLOAT_3
CVector ScriptCommand::GetOffsetCoordFromPed(CPed* ped, float x, float y, float z)
{
	CVector nodeCoord;

	if (!ped)
		return nodeCoord;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(x, false);
	TheSCMWrapper.PushFloat(y, false);
	TheSCMWrapper.PushFloat(z, false);

	TheSCMWrapper.PushReturnArguments(RUNNING_SCRIPT_VALUE_TYPE_FLOAT, 3);

	TheSCMWrapper.CallCommand(0x4C4);

	tRunningScriptWrapper_SavedReturnedValuesArray nodeVal;
	TheSCMWrapper.SaveReturnedValues(nodeVal);
	nodeCoord.x = nodeVal.returnedValues[0].Float;
	nodeCoord.y = nodeVal.returnedValues[1].Float;
	nodeCoord.z = nodeVal.returnedValues[2].Float;

	return nodeCoord;
}

// 0780: heli_keep_entity_in_view 75@ char $PLAYER_ACTOR car -1 min_altitude 15.0 max_altitude 170.0
void ScriptCommand::SetHeliKeepEntityInView(CVehicle* veh, CPed* targetPed, float minAlt, float maxAlt)
{
	if (!veh || !targetPed)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	int pedHandle = CPools::ms_pPedPool->GetIndex(targetPed);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(-1, false);

	TheSCMWrapper.PushFloat(minAlt, false);
	TheSCMWrapper.PushFloat(maxAlt, false);

	TheSCMWrapper.CallCommand(0x788);

	return;
}

// 04A2: heli_goto_coords 379@(253@,16i) coords 331@(253@,16f) 347@(253@,16f) 363@(253@,16f) min_altitude 0.0 max_altitude 363@(253@,16f)
void ScriptCommand::SetHeliGoToCoord(CVehicle* veh, CVector const& coord, float minAlt, float maxAlt)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushFloat(minAlt, false);
	TheSCMWrapper.PushFloat(maxAlt, false);

	TheSCMWrapper.CallCommand(0x4A2);

	return;
}

// 062F: create_group 0 store_to 192@
int ScriptCommand::CreateGroupOfType(int type)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(type, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x62F);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 00A5: create_car #PONY at 0.0 0.0 0.0 store_to 0@
CVehicle* ScriptCommand::CreateCarAtPosition(int model, CVector const& coord)
{
	return ((CVehicle* (__cdecl *)(int, RwV3d, bool))0x431F80)(model, *(RwV3d*)&coord, false);
}

// 00AB: set_car_coordinates 22@ to -1577.942 52.6333 40.0
void ScriptCommand::PlaceCarAtCoordinates(CVehicle* veh, CVector& coord)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x0AB);

	return;
}

// 00A1: set_char_coordinates $PLAYER_ACTOR to 345.5621 306.2212 998.4484
void ScriptCommand::PlacePedAtCoordinates(CPed* ped, CVector& coord)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x0A1);

	return;
}

// 0560: create_random_char_as_driver 148@ store_to 149@ 
CPed* ScriptCommand::CreateRandomPedInCarAsDriver(CVehicle* veh)
{
	if (!veh)
		return nullptr;

	CPed* ped = nullptr;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x560);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 0561: create_random_char_as_passenger 46@(129@,5i) seat 0 store_to 51@(129@,5i)
CPed* ScriptCommand::CreateRandomPedInCarAsPassenger(CVehicle* veh, int seat)
{
	if (!veh)
		return nullptr;

	CPed* ped = nullptr;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(seat, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x561);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 04BB: set_area_visible 0
void ScriptCommand::SetAreaVisible(int area)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(area, false);

	TheSCMWrapper.CallCommand(0x4BB);

	return;
}

// 0860: set_char_area_visible $PLAYER_ACTOR to 6
void ScriptCommand::SetPedAreaVisible(CPed* ped, int area)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(area, false);

	TheSCMWrapper.CallCommand(0x860);

	return;
}

// 01C2: mark_char_as_no_longer_needed 2@
void ScriptCommand::MarkPedAsNoLongerNeeded(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x1C2);

	return;
}

// 01C3: mark_car_as_no_longer_needed $IMPORT_CAR
void ScriptCommand::MarkCarAsNoLongerNeeded(CVehicle* veh)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x1C3);

	return;
}

// 0630: set_group_leader 192@ to 423@
void ScriptCommand::SetAsGroupLeader(int groupHandle, CPed* ped)
{
	if (!ped || (groupHandle < 0 || groupHandle >= 8))
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(groupHandle, false);
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x630);

	return;
}

// 0631: set_group_member $PLAYER_GROUP char $ACTOR_RYDER
void ScriptCommand::SetAsGroupMember(int groupHandle, CPed* ped)
{
	if (groupHandle == -1)
	{
		if (!ped)
			return;
	}
	else
	{
		if (!ped || (groupHandle < 0 || groupHandle >= 8))
			return;
	}

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	if (groupHandle == -1)
	{
		int PLAYER_GROUP = TheSCMWrapper.GetGlobalVariableOffsetByNumber(11);	// player group

		TheSCMWrapper.PushGlobalVariable(PLAYER_GROUP, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	}
	else
		TheSCMWrapper.PushInt(groupHandle, false);
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x631);

	return;
}

// 0632: remove_group $PLAYER_GROUP
void ScriptCommand::ReleaseGroup(int groupHandle)
{
	if (groupHandle < 0 || groupHandle >= 8)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(groupHandle, false);

	TheSCMWrapper.CallCommand(0x632);

	return;
}

// 0940: set_group_follow_status 260@ to 1
void ScriptCommand::SetGroupFollowStatus(int groupHandle, bool bStatus)
{
	if (groupHandle < 0 || groupHandle >= 8)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(groupHandle, false);
	TheSCMWrapper.PushInt(bStatus, false);

	TheSCMWrapper.CallCommand(0x940);

	return;
}

// 087F: set_char_never_leaves_group 263@ to 1
void ScriptCommand::SetPedNeverLeaveGroup(CPed* ped, bool bDontLeaveGroup)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(bDontLeaveGroup, false);

	TheSCMWrapper.CallCommand(0x87F);

	return;
}

// 0129: create_char_inside_car 35@ pedtype 23 model #SPECIAL02 store_to 41@
CPed* ScriptCommand::CreatePedInCarAsDriver(CVehicle* veh, ePedType type, int model)
{
	if (!veh)
		return nullptr;

	CPed* ped = nullptr;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(type, false);
	TheSCMWrapper.PushInt(model, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x129);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 01C8: create_char_as_passenger 35@ pedtype 23 model #SPECIAL01 seat 0 store_to 40@
CPed* ScriptCommand::CreatePedInCarAsPassenger(CVehicle* veh, ePedType type, int model, int seat)
{
	if (!veh)
		return nullptr;

	CPed* ped = nullptr;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(type, false);
	TheSCMWrapper.PushInt(model, false);
	TheSCMWrapper.PushInt(seat, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x1C8);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 06C1: create_searchlight_on_vehicle 40@ offset 0.0 1.0 -0.5 target 2228.36 -1171.48 25.82 target_radius 5.0 radius 0.4 store_to 58@
int ScriptCommand::CreateSearchlightOnVehicle(CVehicle* veh, CVector offset, CVector target, float dstRadius, float srcRadius)
{
	if (!veh)
		return NULL;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(offset.x, false);
	TheSCMWrapper.PushFloat(offset.y, false);
	TheSCMWrapper.PushFloat(offset.z, false);
	TheSCMWrapper.PushFloat(target.x, false);
	TheSCMWrapper.PushFloat(target.y, false);
	TheSCMWrapper.PushFloat(target.z, false);
	TheSCMWrapper.PushFloat(dstRadius, false);
	TheSCMWrapper.PushFloat(srcRadius, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x6C1);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}
// 06B2: delete_searchlight 58@
void ScriptCommand::DeleteSearchlight(int searchlightHandle)
{
	if (searchlightHandle <= NULL)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);

	TheSCMWrapper.CallCommand(0x6B2);

	return;
}
// 06B5: point_searchlight_at_coord 4@ to 0.0 0.0 0.0 speed 0.0
void ScriptCommand::PointSearchlightAtCoord(int searchlightHandle, CVector coord, float speed)
{
	if (searchlightHandle <= NULL)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushFloat(speed, false);

	TheSCMWrapper.CallCommand(0x6B5);

	return;
}
// 06B6: point_searchlight_at_char 58@ char $ACTOR_SWEET speed 0.2
void ScriptCommand::PointSearchlightAtPed(int searchlightHandle, CPed* ped, float speed)
{
	if (searchlightHandle <= NULL || !ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(speed, false);

	TheSCMWrapper.CallCommand(0x6B6);

	return;
}
// 06B4: move_searchlight_between_coords 58@ from 2228.36 -1171.48 25.82 to 2215.41 -1142.51 25.5 speed 0.5
void ScriptCommand::MoveSearchlightBetweenPoints(int searchlightHandle, CVector coord1, CVector coord2, float speed)
{
	if (searchlightHandle <= NULL)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);
	TheSCMWrapper.PushFloat(coord1.x, false);
	TheSCMWrapper.PushFloat(coord1.y, false);
	TheSCMWrapper.PushFloat(coord1.z, false);
	TheSCMWrapper.PushFloat(coord2.x, false);
	TheSCMWrapper.PushFloat(coord2.y, false);
	TheSCMWrapper.PushFloat(coord2.z, false);
	TheSCMWrapper.PushFloat(speed, false);

	TheSCMWrapper.CallCommand(0x6B4);

	return;
}
// 0941: set_searchlight_clip_if_colliding 58@ to 1
void ScriptCommand::SetSearchlightClipIfColliding(int searchlightHandle, bool bSet)
{
	if (searchlightHandle <= NULL)
		return;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);
	TheSCMWrapper.PushBoolean(bSet, false);

	TheSCMWrapper.CallCommand(0x941);

	return;
}

// 04BA: set_car_forward_speed 34@ to 0.0
void ScriptCommand::SetCarForwardSpeed(CVehicle* veh, float speed)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(speed, false);

	TheSCMWrapper.CallCommand(0x4BA);

	return;
}

// 039F: turn_car_to_face_coord 51@ coord 116@ 117@
void ScriptCommand::TurnCarToFaceCoord(CVehicle* veh, float x, float y)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(x, false);
	TheSCMWrapper.PushFloat(y, false);

	TheSCMWrapper.CallCommand(0x39F);

	return;
}

// 0119:   is_car_dead 0@
bool ScriptCommand::IsCarDead(CVehicle* veh)
{
	if (!veh)
		return true;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x119);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 0118:   is_char_dead 0@
bool ScriptCommand::IsPedDead(CPed* ped)
{
	if (!ped)
		return true;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x118);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 060B: set_char_decision_maker 1@ to 65543
void ScriptCommand::SetPedDecisionMaker(CPed* ped, int decision)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(decision, false);
	TheSCMWrapper.CallCommand(0x60B);

	return;
}
// 07DD: set_char_shoot_rate 0@ to 85
void ScriptCommand::SetPedShootRate(CPed* ped, int rate)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(rate, false);
	TheSCMWrapper.CallCommand(0x7DD);

	return;
}
// 077A: set_char_relationship 0@ relationship 4 to_ped_type 0
void ScriptCommand::SetPedRelationshipToPedtype(CPed* ped, char relationType, ePedType type)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(relationType, false);
	TheSCMWrapper.PushInt(type, false);
	TheSCMWrapper.CallCommand(0x77A);

	return;
}

// 00AF: set_car_mission 62@ to 5
void ScriptCommand::SetCarMission(CVehicle* veh, char mission)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(mission, false);

	TheSCMWrapper.CallCommand(0x0AF);

	return;
}

// 02C2: car_goto_coordinates_accurate 71@ coords 2644.462 -2016.282 12.5547
void ScriptCommand::SetCarGoToCoordAccurate(CVehicle* veh, CVector coord)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x2C2);

	return;
}

// 0477: set_car_temp_action 77@ to 3 time 6000
void ScriptCommand::SetCarTempAction(CVehicle* veh, char action, int time)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(action, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x477);

	return;
}

// 06C7: task_car_temp_action $PLAYER_ACTOR car $TEMPVAR_ACTOR_CAR action 6 time 2000000
void ScriptCommand::SetTaskCarTempAction(CPed* ped, CVehicle* pedVeh, char action, int time)
{
	if (!ped || !pedVeh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(pedVeh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(action, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x6C7);

	return;
}

// 0825: set_heli_blades_full_speed 40@
void ScriptCommand::SetHeliBladesFullSpeed(CVehicle* veh)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x825);

	return;
}

// 095E: control_car_door 47@ door 4 latch 1 angle -1.0
void ScriptCommand::ControlCarDoor(CVehicle* veh, int door, int latchValue, float angle)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(door, false);
	TheSCMWrapper.PushInt(latchValue, false);
	TheSCMWrapper.PushFloat(angle, false);

	TheSCMWrapper.CallCommand(0x95E);

	return;
}

// 009A: create_char 4 model #MALE01 at 0.0 0.0 0.0 store_to 2@
CPed* ScriptCommand::CreatePedAtPosition(ePedType pedType, int model, CVector coord)
{
	CPed* ped = nullptr;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedType, false);
	TheSCMWrapper.PushInt(model, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x09A);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 0376: create_random_char -1576.88 55.26 8.57 store_to 18@
CPed* ScriptCommand::CreateRandomPedAtCoord(CVector coord)
{
	CPed* ped = nullptr;

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x376);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	ped = CPools::ms_pPedPool->AtHandle(retVal.returnedValues[0].Int);

	return ped;
}

// 02CE: get_ground_z_for_3d_coord 2@ 3@ 4@ store_to 16@
float ScriptCommand::GetGroundZForCoord(CVector coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_FLOAT);

	TheSCMWrapper.CallCommand(0x2CE);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Float;
}

// 085A: create_emergency_services_car #FIRETRUK at 2340.637 -1152.722 25.9686
void ScriptCommand::CreateEmergencyServiceVehicleAtCoord(int model, CVector coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(model, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x85A);

	return;
}

// 09C7: set_player_model $PLAYER_CHAR to #FAM1
void ScriptCommand::SetPlayerModel(int model)
{
	CRunningScriptWrapper TheSCMWrapper;

	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	TheSCMWrapper.PushInt(model, false);

	TheSCMWrapper.CallCommand(0x9C7);

	return;
}

// 070D: build_player_model $PLAYER_CHAR
void ScriptCommand::BuildPlayerModel()
{
	CRunningScriptWrapper TheSCMWrapper;

	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);

	TheSCMWrapper.CallCommand(0x70D);

	return;
}

// 00E1:   is_button_pressed 0 button 19
bool ScriptCommand::IsButtonPressed(ePadButton button)
{
	CRunningScriptWrapper TheSCMWrapper;

	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	TheSCMWrapper.PushInt(button, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x0E1);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 00E1:   is_button_pressed 0 button 19
bool ScriptCommand::IsButtonPressed(int button)
{
	CRunningScriptWrapper TheSCMWrapper;

	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	TheSCMWrapper.PushInt(button, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x0E1);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 06BC: fire_single_bullet 2193.268 -1165.441 1031.124 target $TEMPVAR_X_COORD $TEMPVAR_Y_COORD $TEMPVAR_Z_COORD energy 1
void ScriptCommand::FireSingleBullet(CVector src, CVector dest, int energy)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(src.x, false);
	TheSCMWrapper.PushFloat(src.y, false);
	TheSCMWrapper.PushFloat(src.z, false);
	TheSCMWrapper.PushFloat(dest.x, false);
	TheSCMWrapper.PushFloat(dest.y, false);
	TheSCMWrapper.PushFloat(dest.z, false);
	TheSCMWrapper.PushInt(energy, false);

	TheSCMWrapper.CallCommand(0x6BC);

	return;
}

// 0541: fire_weapon_of_car 35@
void ScriptCommand::FireWeaponOfCar(CVehicle* veh)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x541);

	return;
}

// 07A1: set_next_desired_move_state 4
void ScriptCommand::SetNextMoveState(eMoveState state)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(state, false);

	TheSCMWrapper.CallCommand(0x7A1);

	return;
}

// 0781: get_weapontype_model $AMMU_SELECTED_WEAPON store_to $AMMU_SELECTED_WEAPON_MODEL
int ScriptCommand::GetModelFromWeaponType(eWeaponType weapon)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt((int)weapon, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x781);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}
int ScriptCommand::GetModelFromWeaponType(int weaponID)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(weaponID, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x781);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 03D3: get_closest_car_node_with_heading $TEMPVAR_FLOAT_1 $TEMPVAR_FLOAT_2 $TEMPVAR_FLOAT_3 store_to $TEMPVAR_FLOAT_1 $TEMPVAR_FLOAT_2 $TEMPVAR_FLOAT_3 heading_to $TEMPVAR_ANGLE
float ScriptCommand::GetHeadingForClosestCarNode(CVector coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_FLOAT);

	TheSCMWrapper.CallCommand(0x3D3);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Float;;
}

// 03A3:   is_char_male 0@
bool ScriptCommand::IsPedMale(CPed* ped)
{
	if (!ped)
		return false;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x3A3);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 0248:   has_model_loaded 15@
bool ScriptCommand::HasModelLoaded(int model)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(model, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x248);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 06EE:   is_group_member 263@ group 260@
bool ScriptCommand::IsGroupMember(CPed* ped, int groupHandle)
{
	if (groupHandle == -1)
	{
		if (!ped)
			return false;
	}
	else
	{
		if (!ped || (groupHandle < 0 || groupHandle >= 8))
			return false;
	}

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	if (groupHandle == -1)
	{
		int PLAYER_GROUP = TheSCMWrapper.GetGlobalVariableOffsetByNumber(11);	// player group

		TheSCMWrapper.PushGlobalVariable(PLAYER_GROUP, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	}
	else
		TheSCMWrapper.PushInt(groupHandle, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x6EE);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 00A1: set_char_coordinates $PLAYER_ACTOR to 345.5621 306.2212 998.4484
void ScriptCommand::SetPedCoordinates(CPed* ped, CVector coord)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x0A1);

	return;
}

// 0713: task_drive_by 52@ char -1 car -1 coord 952.92 -1102.99 22.85 radius 100.0 style 4 from_rhs 1 fire_rate 90
void ScriptCommand::SetTaskDriveBy(CPed* ped, CPed* targetPed, CVehicle* targetVeh, CVector coord, float radius, int style, bool bRHS, int fireRate)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	int targetPedHandle = CPools::ms_pPedPool->GetIndex(targetPed);
	int targetVehHandle = CPools::ms_pVehiclePool->GetIndex(targetVeh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetPedHandle, false);
	TheSCMWrapper.PushInt(targetVehHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushFloat(radius, false);
	TheSCMWrapper.PushInt(style, false);
	TheSCMWrapper.PushInt(bRHS, false);
	TheSCMWrapper.PushInt(fireRate, false);

	TheSCMWrapper.CallCommand(0x713);

	return;
}

// 05C9: task_look_about -1 time 2000
void ScriptCommand::SetTaskLookAbout(CPed* ped, int time)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x5C9);

	return;
}

// 05C8: task_scratch_head -1
void ScriptCommand::SetTaskScratchHead(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x5C8);

	return;
}

// 05D3: task_go_straight_to_coord $PLAYER_ACTOR coord 681.8004 -474.1063 15.5363 mode 4 time 3000
void ScriptCommand::SetTaskGoToCoordOnFoot(CPed* ped, CVector coord, eMoveState state, int time)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushInt(state, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x5D3);

	return;
}

// 07F6: get_group_size 260@ store_leaders_to 262@ members_to 261@
int ScriptCommand::GetNumberOfGroupMembers(int groupHandle)
{
	CRunningScriptWrapper TheSCMWrapper;
	if (groupHandle == -1)
	{
		int PLAYER_GROUP = TheSCMWrapper.GetGlobalVariableOffsetByNumber(11);	// player group

		TheSCMWrapper.PushGlobalVariable(PLAYER_GROUP, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	}
	else
		TheSCMWrapper.PushInt(groupHandle, false);

	TheSCMWrapper.PushReturnArguments(RUNNING_SCRIPT_VALUE_TYPE_INT, 2);

	TheSCMWrapper.CallCommand(0x7F6);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[1].Int;
}

// 0245: set_anim_group_for_char $ACTOR_SMOKE to "FATMAN"
void ScriptCommand::SetAnimGroupForPed(CPed* ped, char* animName)
{
	if (!ped || !animName)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushLongString(animName, false);

	TheSCMWrapper.CallCommand(0x245);

	return;
}

// 0751: task_flee_char_any_means 71@ char $PLAYER_ACTOR run_distance 100000.0 time 999999 change_course 1 unknown 3000 5000 radius 50.0
void ScriptCommand::SetTaskFleePedAnyMeans(CPed* ped, CPed* targetPed, float runDistanceRadius, int time, bool bChangeCourse, int timeUnk1, int timeUnk2, float radius)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(runDistanceRadius, false);
	TheSCMWrapper.PushInt(time, false);
	TheSCMWrapper.PushInt(bChangeCourse, false);
	TheSCMWrapper.PushInt(timeUnk1, false);
	TheSCMWrapper.PushInt(timeUnk2, false);
	TheSCMWrapper.PushFloat(radius, false);

	TheSCMWrapper.CallCommand(0x751);

	return;
}

// 05DC: task_smart_flee_point 94@ coord 2336.399 -18.3093 25.4766 radius 30.0 time 8000
void ScriptCommand::SetTaskSmartFleePoint(CPed* ped, CVector point, float radius, int time)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(point.x, false);
	TheSCMWrapper.PushFloat(point.y, false);
	TheSCMWrapper.PushFloat(point.z, false);
	TheSCMWrapper.PushFloat(radius, false);
	TheSCMWrapper.PushInt(time, false);


	TheSCMWrapper.CallCommand(0x5DC);

	return;
}

// 05DD: task_smart_flee_char $ACTOR_SMOKE char $PLAYER_ACTOR radius 100.0 time 10000
void ScriptCommand::SetTaskSmartFleePed(CPed* ped, CPed* targetPed, float radius, int time)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(radius, false);
	TheSCMWrapper.PushInt(time, false);


	TheSCMWrapper.CallCommand(0x5DD);

	return;
}

// 00C2:   is_point_on_screen 159@ 160@ 161@ radius 5.0
bool ScriptCommand::IsPointOnScreen(CVector point, float radius)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(point.x, false);
	TheSCMWrapper.PushFloat(point.y, false);
	TheSCMWrapper.PushFloat(point.z, false);
	TheSCMWrapper.PushFloat(radius, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x0C2);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 04E4: request_collision 2488.562 -1666.865
void ScriptCommand::RequestCollision(CVector2D coord)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);

	TheSCMWrapper.CallCommand(0x4E4);

	return;
}

// 07A3: task_goto_char_aiming $10516(12@,8i) char $PLAYER_ACTOR radius_from 5.0 to 10.0
void ScriptCommand::SetTaskGoToPedWhileAiming(CPed* ped, CPed* targetPed, float radiusMin, float radiusMax)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(radiusMin, false);
	TheSCMWrapper.PushFloat(radiusMax, false);


	TheSCMWrapper.CallCommand(0x7A3);

	return;
}

// 06B3:   does_searchlight_exist 58@
bool ScriptCommand::DoesSearchlightExist(int searchlightHandle)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(searchlightHandle, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x6B3);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);

	return retVal.returnedValues[0].Int;
}

// 05CF: task_leave_car_and_flee 102@ car 73@ to 2316.4 -1519.2 24.3
void ScriptCommand::SetTaskLeaveCarAndFleeToCoord(CPed* ped, CVehicle* veh, CVector coord)
{
	if (!ped || !veh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);


	TheSCMWrapper.CallCommand(0x5CF);

	return;
}

// 06EC: get_num_available_paintjobs $CARMOD_CAR store_to $10446
int ScriptCommand::GetNumberOfAvailablePaintjobs(CVehicle* veh)
{
	if (!veh)
		return NULL;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x6EC);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 06ED: give_vehicle_paintjob 34@ to 0
void ScriptCommand::GiveVehiclePaintjob(CVehicle* veh, unsigned int jobNum)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(jobNum, false);

	TheSCMWrapper.CallCommand(0x6ED);

	return;
}

// 073E: get_random_car_in_sphere_no_save -1577.942 52.6333 16.3281 radius 4.0 unused #INFO store_to $TEMPVAR_ACTOR_CAR
CVehicle* ScriptCommand::GetRandomCarInSphereNoSave(CVector coord, float radius)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushFloat(radius, false);
	TheSCMWrapper.PushInt(-1, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x73E);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return CPools::ms_pVehiclePool->AtHandle(retVal.returnedValues[0].Int);
}

// 0639: task_turn_char_to_face_char -1 char 86@
void ScriptCommand::SetTaskTurnToFacePed(CPed* ped, CPed* targetPed)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);

	TheSCMWrapper.CallCommand(0x639);

	return;
}

// 0106:   locate_char_in_car_char_3d $PLAYER_ACTOR char 71@ radius 15.0 15.0 15.0 sphere 0
bool ScriptCommand::IsPedInCarNearPed(CPed* ped, CPed* targetPed, float radiusX, float radiusY, float radiusZ)
{
	if (!ped || !targetPed)
		return false;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(radiusX, false);
	TheSCMWrapper.PushFloat(radiusX, false);
	TheSCMWrapper.PushFloat(radiusX, false);
	TheSCMWrapper.PushBoolean(false, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x106);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 06E4: task_char_arrest_char 55@(141@,9i) char $PLAYER_ACTOR
void ScriptCommand::SetTaskArrestPed(CPed* ped, CPed* targetPed)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);

	TheSCMWrapper.CallCommand(0x6E4);

	return;
}

// 0741:   has_char_been_arrested $PLAYER_ACTOR
bool ScriptCommand::HasPedBeenArrested(CPed* ped)
{
	if (!ped)
		return false;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x741);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 05C1: task_say -1 subject 230
void ScriptCommand::SetTaskSay(CPed* ped, int audioTable)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(audioTable, false);

	TheSCMWrapper.CallCommand(0x5C1);

	return;
}

// 05D9: task_goto_char 87@(216@,5i) char $PLAYER_ACTOR time 5000 radius 3.0
void ScriptCommand::SetTaskGoToPedOnFoot(CPed* ped, CPed* targetPed, int time, float radius)
{
	if (!ped || !targetPed)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetPed);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushInt(time, false);
	TheSCMWrapper.PushFloat(radius, false);

	TheSCMWrapper.CallCommand(0x5D9);

	return;
}

// 075C:   does_blip_exist 1@
bool ScriptCommand::DoesBlipExist(int blipIndex)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(blipIndex, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x75C);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 034F: remove_char_elegantly 2@
void ScriptCommand::RemovePedElegantly(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x34F);

	return;
}

// 0792: clear_char_tasks_immediately $PLAYER_ACTOR
void ScriptCommand::SetClearPedTasksImmediately(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x792);

	return;
}

// 07DE:   is_model_in_cdimage 43@
bool ScriptCommand::IsModelInCD(int model)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(model, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x7DE);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 09B2: get_random_car_model_in_memory 1 model_to 150@ class_to 151@
int ScriptCommand::GetRandomVehicleModelInMemory(bool bArg)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(bArg, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x9B2);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 0893: attach_trailer_to_cab 37@ car 34@
void ScriptCommand::AttachTrailerToCab(CVehicle* veh, CVehicle* trailer)
{
	if (!veh || !trailer)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	int trailerHandle = CPools::ms_pVehiclePool->GetIndex(trailer);


	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(trailerHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x893);

	return;
}

// 	0948: add_explosion_variable_shake $TEMPVAR_FLOAT_1 $TEMPVAR_FLOAT_2 $TEMPVAR_FLOAT_3 type 11 shake 5.0
void ScriptCommand::CreateExplosionWithCameraShake(CVector coord, int type, float camShake)
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushInt(type, false);
	TheSCMWrapper.PushFloat(camShake, false);

	TheSCMWrapper.CallCommand(0x948);

	return;
}

// 020C: add_explosion 72@ 73@ 74@ type 0
void ScriptCommand::CreateExplosion(CVector coord, int type)
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushInt(type, false);

	TheSCMWrapper.CallCommand(0x20C);

	return;
}

// 015F: set_fixed_camera_position 664.9277 -479.6112 16.1668 rotation 0.0 0.0 0.0
void ScriptCommand::SetFixedCameraPosition(CVector pos, float xAngle, float yAngle, float zAngle)
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushFloat(pos.x, false);
	TheSCMWrapper.PushFloat(pos.y, false);
	TheSCMWrapper.PushFloat(pos.z, false);
	TheSCMWrapper.PushFloat(xAngle, false);
	TheSCMWrapper.PushFloat(yAngle, false);
	TheSCMWrapper.PushFloat(zAngle, false);

	TheSCMWrapper.CallCommand(0x15F);

	return;
}

// 	0160: point_camera_at_point 665.8948 -479.5685 16.4175 switchstyle 2
void ScriptCommand::PointCameraAtPosition(CVector pos, int switchstyle)
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushFloat(pos.x, false);
	TheSCMWrapper.PushFloat(pos.y, false);
	TheSCMWrapper.PushFloat(pos.z, false);
	TheSCMWrapper.PushInt(switchstyle, false);

	TheSCMWrapper.CallCommand(0x160);

	return;
}

// 	01B4: set_player_control $PLAYER_CHAR to 1
void ScriptCommand::SetPlayerControl(bool enable)
{
	CRunningScriptWrapper TheSCMWrapper;

	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);
	TheSCMWrapper.PushBoolean(enable, false);

	TheSCMWrapper.CallCommand(0x1B4);

	return;
}

// 06BA: task_turn_char_to_face_coord $PLAYER_ACTOR coord 2313.414 -1150.093 25.7997
void ScriptCommand::SetTaskTurnToFaceCoord(CPed* ped, CVector coord)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);

	TheSCMWrapper.CallCommand(0x6BA);

	return;
}

// 03A1: draw_sphere 2468.8 -1278.2 29.1 radius 1.2
void ScriptCommand::DrawSphere(CVector coord, float radius)
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.PushFloat(coord.x, false);
	TheSCMWrapper.PushFloat(coord.y, false);
	TheSCMWrapper.PushFloat(coord.z, false);
	TheSCMWrapper.PushFloat(radius, false);

	TheSCMWrapper.CallCommand(0x3A1);

	return;
}

// 	015A: restore_camera
void ScriptCommand::RestoreCamera()
{
	CRunningScriptWrapper TheSCMWrapper;

	TheSCMWrapper.CallCommand(0x15A);

	return;
}

// 01F0: set_max_wanted_level 6
void ScriptCommand::SetMaxWantedLevel(int level)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(level, false);

	TheSCMWrapper.CallCommand(0x1F0);

	return;
}

// 0430: warp_char_into_car_as_passenger 18@ car $TEMPVAR_ACTOR_CAR seat 0
void ScriptCommand::WarpPedInCarAsPassenger(CPed* ped, CVehicle* veh, int seat)
{
	if (!ped || !veh)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);
	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushInt(seat, false);

	TheSCMWrapper.CallCommand(0x430);

	return;
}

// 060A: load_char_decision_maker 0 store_to 207@
int ScriptCommand::LoadPedDecisionMaker(int id)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(id, false);
	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x60A);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 06C9: remove_char_from_group $ACTOR_RYDER
void ScriptCommand::RemoveFromGroup(CPed* ped)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);

	TheSCMWrapper.CallCommand(0x6C9);

	return;
}

// 0745: plane_starts_in_air 35@(328@,10i)
void ScriptCommand::PlaneStartsInAir(CVehicle* veh)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);

	TheSCMWrapper.CallCommand(0x745);

	return;
}

// 	067A: attach_camera_to_vehicle_look_at_vehicle 186@ offset 15.0 15.0 10.0 vehicle 34@ tilt 15.0 switchstyle 2
void ScriptCommand::AttachCameraToVehicleLookAtVehicle(CVehicle* veh, CVector offset, CVehicle* targetveh, float tilt, int switchstyle)
{
	if (!veh || !targetveh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	int targetHandle = CPools::ms_pVehiclePool->GetIndex(targetveh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(offset.x, false);
	TheSCMWrapper.PushFloat(offset.y, false);
	TheSCMWrapper.PushFloat(offset.z, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(tilt, false);
	TheSCMWrapper.PushInt(switchstyle, false);

	TheSCMWrapper.CallCommand(0x67A);

	return;
}

// 	067B: attach_camera_to_vehicle_look_at_char $1238 offset -1.5 1.5 1.5 char $1237 tilt 6.0 switchstyle 2
void ScriptCommand::AttachCameraToVehicleLookAtPed(CVehicle* veh, CVector offset, CPed* targetped, float tilt, int switchstyle)
{
	if (!veh || !targetped)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);
	int targetHandle = CPools::ms_pPedPool->GetIndex(targetped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(offset.x, false);
	TheSCMWrapper.PushFloat(offset.y, false);
	TheSCMWrapper.PushFloat(offset.z, false);
	TheSCMWrapper.PushInt(targetHandle, false);
	TheSCMWrapper.PushFloat(tilt, false);
	TheSCMWrapper.PushInt(switchstyle, false);

	TheSCMWrapper.CallCommand(0x67B);

	return;
}

// 05B9: task_pause -1 time 1
void ScriptCommand::SetTaskPause(CPed* ped, int time)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0x5B9);

	return;
}

// 	04D0: set_heli_orientation 58@ to 270.0
void ScriptCommand::ForceHeliOrientation(CVehicle* veh, float angle)
{
	if (!veh)
		return;

	int vehHandle = CPools::ms_pVehiclePool->GetIndex(veh);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(vehHandle, false);
	TheSCMWrapper.PushFloat(angle, false);

	TheSCMWrapper.CallCommand(0x4D0);

	return;
}

// 05A4: get_angle_between_2d_vectors 9@ 10@ and 0.0 -1.0 store_to 26@
float ScriptCommand::GetAngleBetween2dVectors(float x1, float y1, float x2, float y2)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushFloat(x1, false);
	TheSCMWrapper.PushFloat(y1, false);
	TheSCMWrapper.PushFloat(x2, false);
	TheSCMWrapper.PushFloat(y2, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_FLOAT);

	TheSCMWrapper.CallCommand(0x5A4);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Float;
}

// 	0117:   is_player_dead $PLAYER_CHAR
bool ScriptCommand::IsPlayerDead()
{
	CRunningScriptWrapper TheSCMWrapper;
	int PLAYER_CHAR = TheSCMWrapper.GetGlobalVariableOffsetByNumber(2);

	TheSCMWrapper.PushGlobalVariable(PLAYER_CHAR, RUNNING_SCRIPT_VALUE_TYPE_INT, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x117);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 0A1A: task_play_anim_secondary 88@ anim "HIKER_POSE_L" ifp "MISC" framedelta 4.0 loop 0 lockX 0 lockY 0 lockF 1 time -1
void ScriptCommand::SetTaskPlayAnimSecondary(CPed* ped, char* animName, char* animFile, float framedelta, bool loop, bool lockX, bool lockY, bool lockF, int time)
{
	if (!ped)
		return;

	int pedHandle = CPools::ms_pPedPool->GetIndex(ped);

	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushInt(pedHandle, false);
	TheSCMWrapper.PushLongString(animName, false);
	TheSCMWrapper.PushShortString(animFile, false);
	TheSCMWrapper.PushFloat(framedelta, false);
	TheSCMWrapper.PushBoolean(loop, false);
	TheSCMWrapper.PushBoolean(lockX, false);
	TheSCMWrapper.PushBoolean(lockY, false);
	TheSCMWrapper.PushBoolean(lockF, false);
	TheSCMWrapper.PushInt(time, false);

	TheSCMWrapper.CallCommand(0xA1A);

	return;
}

// 04ED: request_animation "LOWRIDER"
void ScriptCommand::RequestionAnimationFile(char* animFile)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushShortString(animFile, false);

	TheSCMWrapper.CallCommand(0x4ED);

	return;
}

// 04EE:   has_animation_loaded "LOWRIDER"
bool ScriptCommand::HasAnimationFileLoaded(char* animFile)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushShortString(animFile, false);

	TheSCMWrapper.PushReturnArgument(RUNNING_SCRIPT_VALUE_TYPE_INT);

	TheSCMWrapper.CallCommand(0x4EE);

	tRunningScriptWrapper_SavedReturnedValuesArray retVal;
	TheSCMWrapper.SaveReturnedValues(retVal);
	return retVal.returnedValues[0].Int;
}

// 04EF: remove_animation "LOWRIDER"
void ScriptCommand::ReleaseAnimationFile(char* animFile)
{
	CRunningScriptWrapper TheSCMWrapper;
	TheSCMWrapper.PushShortString(animFile, false);


	TheSCMWrapper.CallCommand(0x4EF);

	return;
}