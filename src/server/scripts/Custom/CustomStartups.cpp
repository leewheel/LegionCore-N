#include "Config.h"
#include "Chat.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "GossipDef.h"

#define MENU_ID 666666 

namespace {
    class OnNewCharFirstLogin : public PlayerScript
    {
    public:
        OnNewCharFirstLogin() : PlayerScript("OnNewCharFirstLogin")
        {
        }

        // run at first login of a new character
        void OnLogin(Player* player, bool firstLogin) override
        {
            if (!firstLogin) return;
            if (player->getClass() == CLASS_DEMON_HUNTER) return; // ��ʱ����DH������
            // �´�����ɫ�ȼ�101��
            player->GiveLevel(101);
            player->SetUInt32Value(PLAYER_FIELD_XP, 0);
            // TODO:Ϊ�����´����Ľ�ɫ���װ��
            uint32 bag = 41600;
            uint8 classCode = player->getClass();
            std::map<std::string, uint32> classMap;
            // ͨ��װ�����
            classMap["neck"] = 133767;
            classMap["back"] = 133639;
            classMap["ring1"] = 133638;
            classMap["ring2"] = 133679;
            classMap["trinkett1"] = 133642;
            // ��ְͬҵװ�����
            switch (classCode)
            {
            case CLASS_WARRIOR:
            case CLASS_PALADIN:
            case CLASS_DEATH_KNIGHT:
                // ���
                classMap["head"] = 134182;
                classMap["shoulder"] = 133631;
                classMap["chest"] = 134179;
                classMap["wrist"] = 139283;
                classMap["hand"] = 133628;
                classMap["waist"] = 136773;
                classMap["leg"] = 133630;
                classMap["foot"] = 136772;
                classMap["trinkett2"] = 136975;
                classMap["weapon1"] = 124375; // ˫�ִ�
                break;
            case CLASS_HUNTER:
            case CLASS_SHAMAN:
                // ����
                classMap["head"] = 136777;
                classMap["shoulder"] = 134213;
                classMap["chest"] = 133622;
                classMap["wrist"] = 133626;
                classMap["hand"] = 134209;
                classMap["waist"] = 134207;
                classMap["leg"] = 134212;
                classMap["foot"] = 133623;
                classMap["trinkett2"] = 136975;
                if (classCode == CLASS_HUNTER)
                {
                    classMap["weapon1"] = 124361; // ����
                }
                else
                {
                    classMap["weapon2"] = 124368; // ȭ��
                    classMap["weapon3"] = 124368; // ȭ��*2
                }
                break;
            case CLASS_ROGUE:
            case CLASS_DRUID:
            case CLASS_MONK:
                // Ƥ��
                classMap["head"] = 139281;
                classMap["shoulder"] = 133620;
                classMap["chest"] = 133615;
                classMap["wrist"] = 133621;
                classMap["hand"] = 133617;
                classMap["waist"] = 136776;
                classMap["leg"] = 134194;
                classMap["foot"] = 134193;
                classMap["trinkett2"] = 136975;
                if (classCode == CLASS_ROGUE)
                {
                    classMap["weapon1"] = 124367; // ذ��
                    classMap["weapon2"] = 124367; // ذ��*2
                }
                else
                {
                    classMap["weapon4"] = 124378; // ��������
                }
                break;
            default:
                // ����
                classMap["head"] = 134216;
                classMap["shoulder"] = 136775;
                classMap["chest"] = 134219;
                classMap["wrist"] = 134222;
                classMap["hand"] = 133609;
                classMap["waist"] = 133613;
                classMap["leg"] = 133610;
                classMap["foot"] = 136774;
                classMap["trinkett2"] = 133641;
                classMap["weapon1"] = 124381; // ˫�ַ���
                break;
            }
            // ���װ��
            for (auto cl : classMap)
            {
                player->AddItem(cl.second, 1);
            }
            // ��Ӵ��ͱ�ʯ
            player->AddItem(6, 1);
            // ��ӱ���
            player->AddItem(bag, 2);
        }
    };
}

class OnWorldserverLoaded : public WorldScript
{
public:
    OnWorldserverLoaded() : WorldScript("OnWorldserverLoaded") {}

    // run always when worldserver has loaded
    void OnStartup() override
    {
        //TC_LOG_INFO(LOG_FILTER_WORLDSERVER, "LegionCore loaded...");
    }
};

void AddSC_CustomStartups() {
    new OnNewCharFirstLogin();
    new OnWorldserverLoaded();
}
