#pragma once 
#include "core/features/features.hpp"

// https://www.unknowncheats.me/wiki/Counter_Strike_Global_Offensive:Skin_Changer

enum {
    SKIN_QUALITY_NORMAL = 0,
    SKIN_QUALITY_GENUINE,
    SKIN_QUALITY_VINTAGE,
    SKIN_QUALITY_UNUSUAL,
    SKIN_QUALITY_COMMUNITY = 5,
    SKIN_QUALITY_DEVELOPER,
    SKIN_QUALITY_SELF_MADE,
    SKIN_QUALITY_CUSTOMIZED,
    SKIN_QUALITY_STRANGE,
    SKIN_QUALITY_COMPLETED,
    SKIN_QUALITY_TOURNAMENT = 12
};

struct skin_info {
    int item_definition_index = NULL;       // iItemDefinitionIndex
    int paint_kit = 0;						// nFallbackPaintKit
    int seed = 0;							// nFallbackSeed
    int stattrack = -1;						// nFallbackStatTrak	(-1 = disabled, positive value is kill number)
    int quality = 4;						// iEntityQuality       (https://www.unknowncheats.me/wiki/Counter_Strike_Global_Offensive:Skin_Changer#m_iEntityQuality)
    char* custom_name = nullptr;		    // szCustomName
    float wear = 0.001f;			        // flFallbackWear		(Lower = Newer)
};

namespace skins {
    inline bool apply_skin(DWORD weapon_handle);
    void change_skins(client_frame_stage_t stage);
    void update_knife_model(weapon_t* weapon);

    inline std::unordered_map<int, skin_info> custom_skins;
    inline std::unordered_map<int, const char*> custom_models;      // Stores custom model names
    inline void init_skin_config() {
        // CT Knife
        custom_skins[WEAPON_KNIFE].item_definition_index = WEAPON_KNIFE_M9_BAYONET;
        custom_models[WEAPON_KNIFE_M9_BAYONET] = "models/weapons/v_knife_m9_bay.mdl";
        custom_skins[WEAPON_KNIFE_M9_BAYONET].paint_kit = 38;
        custom_skins[WEAPON_KNIFE_M9_BAYONET].seed = 69;
        custom_skins[WEAPON_KNIFE_M9_BAYONET].quality = SKIN_QUALITY_UNUSUAL;

        // T Knife
        custom_skins[WEAPON_KNIFE_T].item_definition_index = WEAPON_KNIFE_BUTTERFLY;
        custom_models[WEAPON_KNIFE_BUTTERFLY] = "models/weapons/v_knife_butterfly.mdl";
        custom_skins[WEAPON_KNIFE_BUTTERFLY].paint_kit = 417;
        custom_skins[WEAPON_KNIFE_BUTTERFLY].quality = SKIN_QUALITY_UNUSUAL;

        custom_skins[WEAPON_GLOCK].paint_kit = 38;
        custom_skins[WEAPON_GLOCK].stattrack = 1337;

        custom_skins[WEAPON_USP_SILENCER].paint_kit = 653;
        
        custom_skins[WEAPON_DEAGLE].paint_kit = 962;

        custom_skins[WEAPON_AK47].paint_kit = 639;

        custom_skins[WEAPON_M4A1].paint_kit = 844;

        custom_skins[WEAPON_AWP].paint_kit = 344;
        custom_skins[WEAPON_AWP].quality = SKIN_QUALITY_DEVELOPER;
    }
}
