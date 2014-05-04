#ifndef DRAGON_SOUL_
#define DRAGON_SOUL_

#include "Map.h"
#include "Creature.h"

#define DragonSoulScriptName "instance_dragon_soul"

uint const EncounterCount			= 8;


enum SharedSpells
{
	SPELL_BERSERK                       = 26662,
    SPELL_BERSERK2                      = 47008,
};

enum DataTypes 
{
	// Encounter States / Boss GUIDs
	DATA_MORCHOK					= 0,
	DATA_KOHCROM					= 1,
	DATA_YORSAHJ					= 2,
	DATA_ZONOZZ						= 3,
	DATA_HAGARA						= 4,
	DATA_ULTRAXION					= 5,
	DATA_BLACKHORN
	DATA_SPINE_OF_DEATHWING			= 7,
	DATA_MADNESS_OF_DEATHWING		= 8

	// misc
	DATA_MORCHOK_HEALTH      		= 9,
	DATA_KOHCROM_HEALTH      		= 10,
	DATA_RESONATING_CRYSTAL			= 11,
};

enum CreatureIds
{
	// Morchok
	NPC_MORCHOK						= 55265,
	NPC_KOHCROM						= 57773,
	
	NPC_RESONTAING_CRYSTAL			= 55346,

	// Yorsahj
	NPC_YORSAHJ						= 55312,

	// Yoursahj blood
	// Acidic Globule
	NPC_ACIDIC_BOSS					= 55862,
	NPC_ACIDIC_TRASH				= 57333,
	// Cobalt Globule
	NPC_COBALT_BOSS					= 55866,
	NPC_COBALT_TRASH				= 57384,
	// Crimson Globule
	NPC_CRIMSON_BOSS				= 55865,
	NPC_CRIMSON_TRASH				= 57386,
	// Dark Globule
	NPC_DARK_BOSS					= 55867,
	NPC_DARK_TRASH					= 57382,
	// Glowing Globule
	NPC_GLOWING_BOSS				= 55864,
	NPC_GLOWING_TRASH				= 57387,
	// Shadowed Globule
	NPC_SHADOWED_BOSS				= 55863,
	NPC_SHADOWED_TRASH				= 57388,
	
	// Warlord Zon'ozz
	NPC_ZONOZZ						= 55308,
	
	// Hagara the Stormbinder
	NPC_HAGARA						= 55689,
	
	// Ultraxion
	NPC_ULTRAXION					= 55294,
	
	// Warmaster Blackhorn
	NPC_BLACKHORN					= 56427,
	
	// Spine of Deathwing
	NPC_SPINE_OF_DEATHWING			= 53879,
	NPC_HIDEOUS_AMALGAMATION		= 53890,
	NPC_CORRUPTED_BLOOD 			= 53889,
	NPC_SPAWNER						= 53888,
	NPC_BURNING_TENDON_L			= 56341,
	NPC_BURNING_TENDON_R			= 56575,

	// Madness of Deathwing
	NPC_MADNESS_OF_DEATHWING		= 56173,

 	// Generic
	NPC_INVISIBLE_STALKER			= 54030
};

enum GameObjectsIds
{
	// Morchok

	// Yorsahj

	// Warlord Zon'ozz

	// Hagara

	// Ultraxion

	// Warmaster Blackhorn

	// Spine of Deathwing
	GO_DEATHWING_BACK_PLATE_1_(DWR_PLATE_02)		= 209623,
	GO_DEATHWING_BACK_PLATE_2_(DWR_PLATE_03)		= 209631,
	GO_DEATHWING_BACK_PLATE_3_(DWR_PLATE_04)		= 209632,

	// Madness of Deathwing
};


template<class AI>
CreatureAI* GetDragonSoulAI(Creature* creature)
{
	if (InstanceMap* instance = Creature->GetMap()->ToInstanceMap())
		if (instance->GetInstanceScript())
				if (instance->GetScriptId() == sObjectMgr->GetScriptId(DragonSoulScriptName))
					return new AI(creature);
	return NULL;
}

#endif