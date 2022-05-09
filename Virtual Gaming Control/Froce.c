#include "Froce.h"
byte CONFIGURED_EFFECT_NUMBER[12] = { 0 };
void SetEffect(PSET_GET_EFFECT_STRUCTURE pset_get_effect, byte* buffer)
{
	pset_get_effect->SET_REPORT_REQUEST.report_id = buffer[0];
	pset_get_effect->SET_REPORT_REQUEST.effect_type = buffer[1];
	pset_get_effect->SET_REPORT_REQUEST.byte_count = buffer[2];
	switch (pset_get_effect->SET_REPORT_REQUEST.effect_type)
	{
	case 1:// Usage ET Constant Force 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 1; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[0] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.

		break;
	case 2:// Usage ET Ramp 1
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 2; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[1] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 3:// Usage ET Square 2
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 3; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[2] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 4:// Usage ET Sine 3
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 4; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated.

		CONFIGURED_EFFECT_NUMBER[3] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 5:// Usage ET Triangle 4
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 5; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[4] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 6:// Usage ET Sawtooth Up 5
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 6; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[5] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 7:// Usage ET Sawtooth Down 6
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 7; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this, because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[6] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 8:// Usage ET Spring 7
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 8; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this  because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated.

		CONFIGURED_EFFECT_NUMBER[7] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 9:// Usage ET Damper 8
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 9; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this , because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[8] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 10:// Usage ET Inertia 9
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 10; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this , because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[9] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 11:// Usage ET Friction 10
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 11; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this , because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[10] = 1; // I HAVE CONFIGURED CONSTANT FORCE EFFECT FOR THIS DEVICE
		// now, when the host issues a get_report blah blah, i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	case 12:// Usage ET Custom Force Data 11 ! NOT SUPPORTED BY THIS DEVICE !
		pset_get_effect->PID_BLOCK_LOAD_REPORT.report_id = 2; // 2= PID BLOCK LOAD REPORT
		pset_get_effect->PID_BLOCK_LOAD_REPORT.effect_block_index = 12; //0=i can't create effect, 1 = CONSTANT FORCE, index in the array = effect_block_index-1 : 0
		pset_get_effect->PID_BLOCK_LOAD_REPORT.block_load_status = 1; // ok, i can load this , because i have already memory for it, and because : reasons
		pset_get_effect->PID_BLOCK_LOAD_REPORT.ram_pool_available = 0xFFFF; // i have no ideea why i need this, however i have no more memory except for the effects already preallocated. 

		CONFIGURED_EFFECT_NUMBER[11] = 0; // 
		// now, when the host issues a get_report , i send the pset_get_effect->PID_BLOCK_LOAD_REPORT.
		break;
	}
}