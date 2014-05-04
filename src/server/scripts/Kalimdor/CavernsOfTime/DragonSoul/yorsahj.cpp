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

class at_yor_sahj_intro : public AreaTriggerScript
{
public:
	at_yor_sahj_intro() : AreaTriggerScript("at_yor_sahj_intro") { }

	bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
	{
		if(InstanceScript* instance = player->GetInstanceScript())
			if (Creature* yor_sahj = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_yor_sahj)))
				yor_sahj->AI()->DoAction(ACTION_INTRO);
		return true;
	}
};

class boss_yor_sahj : public CreatureScript
{
	public:
		boss_yor_sahj() : CreatureScript("boss_yor_sahj") { }

		struct boss_yor_sahjAI : public ScriptedAI
		{
			boss_yor_sahjAI(Creature* creature) : BossAI(creature, DATA_yor_sahj)
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

			void UpdateAI(uint32 diff = events.Eyor_sahjecuteEvent()) OVERRIDE
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