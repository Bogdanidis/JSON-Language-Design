#include "Hogwarts.h"

BEGIN_GAME
CREATE SPELL{
NAME: "Ex" ,
ACTION : START
		 //��������� ��� �������� ���� (DEFENDER)
		 EQUIP DEFENDER _
	// ���� ��� 2 ������ ���������� �� ����� ���� �������� (DEFENDER)
	AFTER 2 ROUNDS DO
	EQUIP DEFENDER --- �
	END
	END
}
CREATE SPELL{
NAME: "leviosa" ,
ACTION : START
		 // ��� 5 ������ ����� 8 damage ���� �������� (DEFENDER)
		 FOR 5 ROUNDS DO
			DAMAGE DEFENDER 10
		 END
	
		 END
}
CREATE SPELL{
NAME: "leviosaaa" ,
ACTION : START
		 // ��� 5 ������ ����� 8 damage ���� �������� (DEFENDER)
		 AFTER 2 ROUNDS DO
			DAMAGE DEFENDER 10
		 END

		 END
}

CREATE SPELL{
NAME: "Expulso" ,
ACTION : START
		 // ����� 22 damage ���� �������� (DEFENDER)
		 DAMAGE DEFENDER 22
		 END
}
CREATE SPELL{
NAME: "Anapneo" ,
ACTION : START
		 // ����� heal ���� ����� ��� (ATTACKER)
		 IF GET_HP( ATTACKER ) <= 30 DO
			IF GET_HOUSE ( ATTACKER ) != "Ravenclaw" DO
				HEAL ATTACKER 20
		ELSE
			HEAL ATTACKER 30
		 END
		END
		 END
}

CREATE SPELL{
NAME: "nothing" ,
ACTION : START

		 END
}

CREATE WIZARD{
NAME: "Harry Potter" ,
HOUSE : "Ravenclaw" ,
HP : 99
}
CREATE WIZARD{
NAME: "Draco Malfoy" ,
HOUSE : "Ravenclaw" ,
HP : 90
}
MR "Harry Potter" LEARN[
	SPELL_NAME(Ex)
		SPELL_NAME(leviosa)
		SPELL_NAME(leviosaaa)
		SPELL_NAME(Expulso)
		SPELL_NAME(Anapneo)
		SPELL_NAME(nothing)
]
MR "Draco Malfoy" LEARN[
	SPELL_NAME(Ex)
		SPELL_NAME(Expulso)
		SPELL_NAME(nothing)
]
DUEL
END_GAME