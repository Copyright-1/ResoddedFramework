#include "Achievements.h"
#include "PlayerInfo.h"
#include "../../LawnApp.h"
#include "../../Resources.h"
#include "../../Sexy.TodLib/TodStringFile.h"
#include "../Board.h"
#include "../Widget/GameSelector.h"

AchievementDefinition gAchievementDefs[NUM_ACHIEVEMENT_TYPES] = {
	{ "Home Lawn Security", "Complete Adventure Mode." },
	{ "Nobel Peas Prize", "Get the golden sunflower trophy." },
	{ "Better Off Dead", "Get to a streak of 10 in I, Zombie Endless" },
	{ "China Shop", "Get to a streak of 15 in Vasebreaker Endless" },
	{ "SPUDOW!", "Blow up a zombie using a Potato Mine." },
	{ "Explodonator", "Take out 10 full-sized zombies with a single Cherry Bomb." },
	{ "Morticulturalist", "Collect all 49 plants (including plants from Crazy Dave's shop)." },
	{ "Don't Pea in the Pool", "Complete a daytime pool level without using pea shooters of any kind." },
	{ "Roll Some Heads", "Bowl over 5 zombies with the same wall-nut." },
	{ "Grounded", "Defeat a normal roof level without using any catapult plants." },
	{ "Zombologist", "Discover the Yeti zombie." },
	{ "Penny Pincher", "Pick up 30 coins in a row on a single level without letting any disappear." },
	{ "Sunny Days", "Get 8000 sun during a single level." },
	{ "Popcorn Party", "Defeat 2 Gargantuars with Corn Cob missiles in a single level." },
	{ "Good Morning", "Complete a daytime level by planting only Mushrooms and Coffee Beans." },
	{ "No Fungus Among Us", "Complete a nighttime level without planting any Mushrooms." },
	{ "Beyond the Grave", "Beat all 20 mini games." },
	{ "Immortal", "Survive 20 waves of pure zombie ferocity." },
	{ "Towering Wisdom", "Grow the Tree of Wisdom to 100 feet." },
	{ "Mustache Mode", "Enable Mustache Mode" },
};

AchievementDefinition Achievements::GetAchievementDefinition(AchievementID theAchievement)
{
	return gAchievementDefs[theAchievement];
}

Achievements::Achievements(LawnApp *theApp)
{
	mApp = theApp;
}

Achievements ::~Achievements()
{

}

void Achievements::GiveAchievement(AchievementID theAchievement, bool aForceGive)
{
	if (mApp->mPlayerInfo == nullptr)
		return;
	if (!aForceGive && mApp->mPlayerInfo->mEarnedAchievements[theAchievement])
		return;

	mApp->mPlayerInfo->mEarnedAchievements[theAchievement] = true;

	if (mApp->mBoard == nullptr)
		return;

	mApp->PlaySample(Sexy::SOUND_ACHIEVEMENT);

	mApp->mBoard->DisplayAdvice(
		StrFormat("%s Achievement!, TodStringTranslate(Achievements::GetAchievementDefinition(theAchievement).mName).c_str()),
		MessageStyle::MESSAGE_STYLE_ACHIEVEMENT, AdviceType::ADVICE_NONE
	);
}

void Achievements::SyncAchievements()
{
	if (mApp->mPlayerInfo == nullptr)
		return;

	if (mApp->HasFinishedAdventure())
		GiveAchievement(AchievementID::ACHIEVEMENT_HOME_SECURITY, true);

	if (mApp->EarnedGoldTrophy())
		GiveAchievement(AchievementID::ACHIEVEMENT_NOBEL_PEAS_PRIZE, true);

	if (mApp->CanSpawnYetis())
		GiveAchievement(AchievementID::ACHIEVEMENT_ZOMBOLOGIST, true);

	if (mApp->mPlayerInfo->mChallengeRecords[GAMEMODE_TREE_OF_WISDOM - 1])
		GiveAchievement(AchievementID::ACHIEVEMENT_TOWERING_WISDOM, true);

	bool aHasAllPlants = true;
	for (int i = SeedType::SEED_PEASHOOTER; i < SeedType::NUM_SEEDS_IN_CHOOSER; i++)
	{
		if (!mApp->SeedTypeAvailable(SeedType(i)))
			aHasAllPlants = false;
	}

	if (aHasAllPlants)
		GiveAchievement(AchievementID::ACHIEVEMENT_MORTICULTURALIST, true);
}

bool Achievements::HasUnshownAchievements()
{
	if (mApp->mPlayerInfo == nullptr)
		return false;
	for (int i = 0; i < AchievementID::NUM_ACHIEVEMENT_TYPES; i++)
		if (!mApp->mPlayerInfo->mShownAchievements[i] && mApp->mPlayerInfo->mEarnedAchievements[i])
			return true;
	return false;
}
