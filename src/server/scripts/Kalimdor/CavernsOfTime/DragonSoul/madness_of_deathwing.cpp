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

class at_madness_of_deathwing_intro : public AreaTriggerScript
{
public:
	at_madness_of_deathwing_intro() : AreaTriggerScript("at_madness_of_deathwing_intro") { }

	bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
	{
		if(InstanceScript* instance = player->GetInstanceScript())
			if (Creature* madness_of_deathwing = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_madness_of_deathwing)))
				madness_of_deathwing->AI()->DoAction(ACTION_INTRO);
		return true;
	}
};

class boss_madness_of_deathwing : public CreatureScript
{
	public:
		boss_madness_of_deathwing() : CreatureScript("boss_madness_of_deathwing") { }

		struct boss_madness_of_deathwingAI : public ScriptedAI
		{
			boss_madness_of_deathwingAI(Creature* creature) : BossAI(creature, DATA_madness_of_deathwing)
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

			void UpdateAI(uint32 diff = events.Emadness_of_deathwingecuteEvent()) OVERRIDE
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