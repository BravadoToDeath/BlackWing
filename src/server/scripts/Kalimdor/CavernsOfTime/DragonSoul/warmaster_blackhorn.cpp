// #include

enum Spells {

};

enum Events {

};

enum Speeches {

};

enum Actions {

};

enum Phases {

};

class at_warmaster_blackhorn_intro : public AreaTriggerScript
{
public:
	at_warmaster_blackhorn_intro() : AreaTriggerScript("at_warmaster_blackhorn_intro") { }

	bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
	{
		if(InstanceScript* instance = player->GetInstanceScript())
			if (Creature* warmaster_blackhorn = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_warmaster_blackhorn)))
				warmaster_blackhorn->AI()->DoAction(ACTION_INTRO);
		return true;
	}
};

class boss_warmaster_blackhorn : public CreatureScript
{
	public:
		boss_warmaster_blackhorn() : CreatureScript("boss_warmaster_blackhorn") { }

		struct boss_warmaster_blackhornAI : public ScriptedAI
		{
			boss_warmaster_blackhornAI(Creature* creature) : BossAI(creature, DATA_warmaster_blackhorn)
			{
				_intro = false;
			}

			void Reset() OVERRIDE
			{

			}

			void EnterCombat(Unit* /*who*/) OVERRIDE
			{

			}

			void KilledUnit(Unit * /*victim*/) OVERRIDE
			{

			}

			void JustDied(Unit * /*victim*/) OVERRIDE
			{

			}

			void MoveInLineOfSight(Unit* who)
            {
                if (!_introDone && me->IsWithinDistInMap(who, 110.0f))
                {
                    _introDone = true;
                    Talk(SAY_INTRO);
                }
            }

			void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
			{

			}

			void JustSummoned(Creature* summon)
			{

			}

			void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
			{
			}

			void RemoveSummons()
			{
			}

			void UpdateAI(uint32 diff = events.Ewarmaster_blackhornecuteEvent()) OVERRIDE
			{
				events.Update(diff);

				if (me->HasUnitState(UNITE_STATE_CASTING))
					return;

				switch(eventId)
				{
				case EVENT_Y:
					DoCastVictim(me, SPELL_Y);
					events.ScheduleEvent(EVENT_Y, seconds in MS, 0, phasing);
					break;
				case EVENT_BERSERK:
					DoCast(me, SPELL_BERSERK);
					talk(SAY_BERSERK);
					break;
				default:
					break;
				}
				DoMeleeAttackIfReady();
			}
		};
};