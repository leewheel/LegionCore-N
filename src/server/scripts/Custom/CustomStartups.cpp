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
            if (player->getClass() == CLASS_DEMON_HUNTER) return; // 暂时不对DH做处理
            // 新创建角色等级101级
            player->GiveLevel(101);
            player->SetUInt32Value(PLAYER_FIELD_XP, 0);
            // TODO:为所有新创建的角色添加装备
            uint32 bag = 41600;
            uint8 classCode = player->getClass();
            std::map<std::string, uint32> classMap;
            // 通用装备添加
            classMap["neck"] = 133767;
            classMap["back"] = 133639;
            classMap["ring1"] = 133638;
            classMap["ring2"] = 133679;
            classMap["trinkett1"] = 133642;
            // 不同职业装备添加
            switch (classCode)
            {
            case CLASS_WARRIOR:
            case CLASS_PALADIN:
            case CLASS_DEATH_KNIGHT:
                // 板甲
                classMap["head"] = 134182;
                classMap["shoulder"] = 133631;
                classMap["chest"] = 134179;
                classMap["wrist"] = 139283;
                classMap["hand"] = 133628;
                classMap["waist"] = 136773;
                classMap["leg"] = 133630;
                classMap["foot"] = 136772;
                classMap["trinkett2"] = 136975;
                classMap["weapon1"] = 124375; // 双手锤
                break;
            case CLASS_HUNTER:
            case CLASS_SHAMAN:
                // 锁甲
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
                    classMap["weapon1"] = 124361; // 弓箭
                }
                else
                {
                    classMap["weapon2"] = 124368; // 拳套
                    classMap["weapon3"] = 124368; // 拳套*2
                }
                break;
            case CLASS_ROGUE:
            case CLASS_DRUID:
            case CLASS_MONK:
                // 皮甲
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
                    classMap["weapon1"] = 124367; // 匕首
                    classMap["weapon2"] = 124367; // 匕首*2
                }
                else
                {
                    classMap["weapon4"] = 124378; // 长柄武器
                }
                break;
            default:
                // 布甲
                classMap["head"] = 134216;
                classMap["shoulder"] = 136775;
                classMap["chest"] = 134219;
                classMap["wrist"] = 134222;
                classMap["hand"] = 133609;
                classMap["waist"] = 133613;
                classMap["leg"] = 133610;
                classMap["foot"] = 136774;
                classMap["trinkett2"] = 133641;
                classMap["weapon1"] = 124381; // 双手法杖
                break;
            }
            // 添加装备
            for (auto cl : classMap)
            {
                player->AddItem(cl.second, 1);
            }
            // 添加传送宝石
            player->AddItem(6, 1);
            // 添加背包
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
