#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#pragma execution_character_set("UTF-8")

class example_ItemGossip : public ItemScript
{
public:
	example_ItemGossip() : ItemScript("example_ItemGossip") { }

	void TeleportTo(Player* player, uint32 mapId, float x, float y, float z, float orientation)
	{
		player->TeleportTo(mapId, x, y, z, orientation);
		player->CLOSE_GOSSIP_MENU();
	}

	bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) override // Any hook here
	{
		player->CLEAR_GOSSIP_MENU(); // Clears old options
		
		std::vector<uint8> alienceRace = { RACE_HUMAN,RACE_DWARF,RACE_NIGHTELF,RACE_GNOME,RACE_DRAENEI,RACE_PANDAREN_ALLIANCE };// ����Race
		player->ADD_GOSSIP_ITEM(0, "===== ���Ǵ��� =====", GOSSIP_SENDER_MAIN,
			0);
		if (std::count(alienceRace.begin(), alienceRace.end(), player->getRace()) != 0)
		{
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� �����|CFF009933", GOSSIP_SENDER_MAIN,
				10);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� ��¯��|CFF009933", GOSSIP_SENDER_MAIN,
				11);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� ������˹|CFF009933", GOSSIP_SENDER_MAIN,
				12);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� ������|CFF009933", GOSSIP_SENDER_MAIN,
				13);
		}
		else
		{
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� �¸�����|CFF009933", GOSSIP_SENDER_MAIN,
				20);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� ������|CFF009933", GOSSIP_SENDER_MAIN,
				21);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� �İ���|CFF009933", GOSSIP_SENDER_MAIN,
				22);
			player->ADD_GOSSIP_ITEM(0, "|CFF0000FF���� ���³�|CFF009933", GOSSIP_SENDER_MAIN,
				23);
		}
		player->ADD_GOSSIP_ITEM(0, "===== �������ٵ��³� =====", GOSSIP_SENDER_MAIN,
			0);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FFӢ���|CFF009933", GOSSIP_SENDER_MAIN,
			100);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF�ɻ�֮��|CFF009933", GOSSIP_SENDER_MAIN,
			101);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF������µĳ�Ѩ|CFF009933", GOSSIP_SENDER_MAIN,
			102);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF������֮��|CFF009933", GOSSIP_SENDER_MAIN,
			103);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF�����ߵؿ�|CFF009933", GOSSIP_SENDER_MAIN,
			104);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF�����ֵ�|CFF009933", GOSSIP_SENDER_MAIN,
			105);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FFħ������|CFF009933", GOSSIP_SENDER_MAIN,
			106);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FFȺ��ͥԺ|CFF009933", GOSSIP_SENDER_MAIN,
			107);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF������|CFF009933", GOSSIP_SENDER_MAIN,
			108);
		player->ADD_GOSSIP_ITEM(0, "===== ���������ŶӸ��� =====", GOSSIP_SENDER_MAIN,
			0);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF�������|CFF009933", GOSSIP_SENDER_MAIN,
			120);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF��������|CFF009933", GOSSIP_SENDER_MAIN,
			121);
		player->ADD_GOSSIP_ITEM(0, "|CFF0000FF��ҹҪ��|CFF009933", GOSSIP_SENDER_MAIN,
			122);
		player->ADD_GOSSIP_ITEM(0, "�˳�", GOSSIP_SENDER_MAIN, 500);
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
		return true; // Cast the spell on use normally
	}

	void OnGossipSelect(Player* player, Item* /*item*/, uint32 /*sender*/, uint32 action) override
	{
		player->CLEAR_GOSSIP_MENU();
		switch (action)
		{
		case 10:
			// �����
			this->TeleportTo(player, 0, -9065, 434, 94, 0);
			break;
		case 11:
			// ��¯��
			this->TeleportTo(player, 0, -4925.28f, -957.402f, 501.521f, 0);
			break;
		case 12:
			// ������˹
			this->TeleportTo(player, 1, 9961, 2055, 1329, 0);
			break;
		case 13:
			// ���R������
			this->TeleportTo(player, 530, -4071.7f, -12036.7f, -1.5f, 0);
			break;
		case 20:
			// �¸�����
			this->TeleportTo(player, 1, 1602.64f, -4393.98f, 9.53f, 0);
			break;
		case 21:
			// ������
			this->TeleportTo(player, 1, -1391, 140, 23, 0);
			break;
		case 22:
			// �İ���
			this->TeleportTo(player, 0, 1909, 235, 53, 0);
			break;
		case 23:
			// Ѫ��������
			this->TeleportTo(player, 530, 9336.9f, -7278.4f, 13.6f, 0);
			break;
		case 100:
			// Ӣ���
			this->TeleportTo(player, 1220, 2443.96f, 823.46f, 252.93f, 5.53f);
			break;
		case 101:
			// �ɻ�֮��
			this->TeleportTo(player, 1220, 3398.71f, 1993.36f, 11.35f, 6.17f);
			break;
		case 102:
			// ������µĳ�Ѩ
			this->TeleportTo(player, 1220, 3736.79f, 4186.34f, 891.99f, 3.20f);
			break;
		case 103:
			// ������֮��
			this->TeleportTo(player, 1220, 0.71f, 5774.22f, 3.59f, 1.65f);
			break;
		case 104:
			// �����ߵؿ�
			this->TeleportTo(player, 1220, -1820.20f, 6670.41f, 146.45f, 5.74f);
			break;
		case 105:
			// �����ֵ�
			this->TeleportTo(player, 1220, 3813.40f, 6347.88f, 185.32f, 0.71f);
			break;
		case 106:
			// ħ������
			this->TeleportTo(player, 1220, 1172.96f, 4370.65f, 8.36f, 2.64f);
			break;
		case 107:
			// Ⱥ��ͥԺ
			this->TeleportTo(player, 1220, 1021.95f, 3849.80f, 7.83f, 4.56f);
			break;
		case 108:
			// ��������-������
			this->TeleportTo(player, 0, -11130.60f, -2001.37f, 48.35f, 1.26f);
			break;
		case 120:
			// �������
			this->TeleportTo(player, 1220, 3585.70f, 6482.25f, 177.98f, 0.66f);
			break;
		case 121:
			// ��������
			this->TeleportTo(player, 1220, 2365.04f, 900.95f, 252.92f, 2.34f);
			break;
		case 122:
			// ��ҹҪ��
			this->TeleportTo(player, 1220, 1226.28f, 4211.08f, -66.94f, 5.76f);
			break;
		case 500:
			player->CLOSE_GOSSIP_MENU();
			break;
		default:
			player->CLOSE_GOSSIP_MENU();
			break;
		}
	}
};

void AddSC_example_ItemGossip() // Add to scriptloader normally
{
	new example_ItemGossip();
}
