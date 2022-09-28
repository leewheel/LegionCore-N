#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"

class example_ItemGossip : public ItemScript
{
public:
    example_ItemGossip() : ItemScript("example_ItemGossip") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override // Any hook here
    {
        player->CLEAR_GOSSIP_MENU(); // Clears old options
        player->ADD_GOSSIP_ITEM(0, "Morph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(0, "Demorph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
        return false; // Cast the spell on use normally
    }

    void OnGossipSelect(Player* player, Item* /*item*/, uint32 /*sender*/, uint32 action) override
    {
        player->CLEAR_GOSSIP_MENU();

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->SetDisplayId(999);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->DeMorph();
            break;
        }
        player->CLOSE_GOSSIP_MENU();
    }
};

void AddSC_example_ItemGossip() // Add to scriptloader normally
{
    new example_ItemGossip();
}
