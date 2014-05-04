/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIRELANDS_H_
#define FIRELANDS_H_

#include "Map.h"
#include "CreatureAI.h"

#define FirelandsScriptName "instance_firelands"

uint32 const EncounterCount = 7;

enum Datas
{
    DATA_BETH_TILAC         = 0,
    DATA_LORD_RHYOLITH      = 1,
    DATA_SHANNOX            = 2,
    DATA_ALYSRAZOR          = 3,
    DATA_BALEROC            = 4,
    DATA_MAJORDOMO_STAGHELM = 5,
    DATA_RAGNAROS           = 6,
};

enum GameObjectIds
{
	// Bethilac
	GO_DOOR_BETHILAC			= 208877,

	// Ragnaros
	GO_RAGNAROS_DOOR            = 209073,
    GO_RAGNAROS_PLATFORM        = 208835,
    GO_CACHE_OF_THE_FIRELORD    = 209261,
    GO_CACHE_OF_THE_FIRELORD_HC = 208967,
};

enum CreatureIds
{
	// Ragnaros
	BOSS_RAGNAROS                   = 52409,
    NPC_SULFURAS_SMASH_TRIGGER      = 53266,
    NPC_SULFURAS_SMASH_TARGET       = 53268,
    NPC_LAVA_WAVE                   = 53363,
 
    NPC_ENGULFING_FLAMES_TRIGGER    = 53485,
    NPC_SPLITTING_BLOW_TRIGGER      = 53393,
    NPC_MAGMA_POOL_TRIGGER          = 53729,
    NPC_PLATFORM_TRIGGER            = 53952,
    NPC_MAGMA_TRAP                  = 53086,
    NPC_SULFURAS_HAND_OF_RAGNAROS   = 53420,
    NPC_SON_OF_FLAME                = 53140,
    NPC_MOLTEN_ERUPTER              = 53617,
    NPC_MOLTEN_SPEWER               = 53545,

	// Alysrazor
    NPC_BLAZING_MONSTROSITY_LEFT    = 53786,
    NPC_BLAZING_MONSTROSITY_RIGHT   = 53791,
    NPC_EGG_PILE                    = 53795,
    NPC_HARBINGER_OF_FLAME          = 53793,
    NPC_MOLTEN_EGG_TRASH            = 53914,
    NPC_SMOULDERING_HATCHLING       = 53794,

	// Shannox
	NPC_RIPLIMB						= 53694,    // Shannox Dogs
	NPC_RAGEFACE					 = 53695,
	NPC_SHANNOX_SPEAR				 = 53752,    // Shannox Spear
	NPC_CRYSTAL_TRAP        = 53713,
	NPC_CRYSTAL_PRISON      = 53819,

	// Bethilac
	// Bethilac
	NPC_CINDERWEB_SPINNER   = 53642,
	NPC_CINDERWEB_DRONE     = 53635,
	NPC_CINDERWEB_SPIDERLING = 53631,
	NPC_ENGORGED_BROODLING  = 53745,
	NPC_SPIDERWEB_FILAMENT  = 53082, 
};

enum Actions
{
	//Shannox
	ACTION_SAY_RIPLIMB,		     //Shannox yell when Riplimb bites someone
};

class DelayedAttackStartEvent : public BasicEvent
{
    public:
        DelayedAttackStartEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
        {
            _owner->AI()->DoZoneInCombat(_owner, 200.0f);
            return true;
        }

    private:
        Creature* _owner;
};

template<class AI>
CreatureAI* GetFirelandsAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(FirelandsScriptName))
                return new AI(creature);
    return NULL;
}

#endif // FIRELANDS_H_
