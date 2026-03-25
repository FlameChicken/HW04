#include <vector>
#include <string>
#include <iostream>

// ==========================
// PotionRecipe
// ==========================
class PotionRecipe
{
public:
    PotionRecipe(const std::string& potionName,
        const std::string& coreIngredient)
        : potionName_(potionName), coreIngredient_(coreIngredient) {
    }

    const std::string& GetPotionName() const
    {
        return potionName_;
    }

    const std::string& GetCoreIngredient() const
    {
        return coreIngredient_;
    }

private:
    std::string potionName_;
    std::string coreIngredient_;
};

// ==========================
// AlchemyWorkshop
// ==========================
class AlchemyWorkshop
{
public:
    // 레시피 추가
    void AddRecipe(const std::string& potionName,
        const std::string& coreIngredient)
    {
        recipes_.push_back(PotionRecipe(potionName, coreIngredient));
    }

    // 전체 출력
    void DisplayAllRecipes() const
    {
        std::cout << "=== 모든 레시피 ===" << std::endl;

        for (const PotionRecipe& r : recipes_)
        {
            std::cout << r.GetPotionName()
                << " | 핵심 재료: "
                << r.GetCoreIngredient()
                << std::endl;
        }
    }

    // 이름으로 검색
    PotionRecipe SearchRecipeByName(const std::string& name) const
    {
        for (const PotionRecipe& r : recipes_)
        {
            if (r.GetPotionName() == name)
            {
                return r;
            }
        }

        // 찾지 못한 경우
        std::cout << "[경고] 해당 이름의 레시피 없음" << std::endl;
        return PotionRecipe("NONE", "NONE");
    }

    // 재료로 검색 (여러 개 가능)
    std::vector<PotionRecipe>
        SearchRecipeByIngredient(const std::string& ingredient) const
    {
        std::vector<PotionRecipe> result;

        for (const PotionRecipe& r : recipes_)
        {
            if (r.GetCoreIngredient() == ingredient)
            {
                result.push_back(r);
            }
        }

        if (result.empty())
        {
            std::cout << "[알림] 해당 재료를 사용하는 레시피 없음"
                << std::endl;
        }

        return result;
    }

private:
    std::vector<PotionRecipe> recipes_;
};

// ==========================
// main
// ==========================
int main()
{
    AlchemyWorkshop workshop;

    workshop.AddRecipe("Healing Potion", "Herb");
    workshop.AddRecipe("Mana Potion", "Magic Water");
    workshop.AddRecipe("Stamina Potion", "Herb");
    workshop.AddRecipe("Fire Resistance Potion", "Fire Flower");

    workshop.DisplayAllRecipes();

    // 이름 검색
    PotionRecipe recipe =
        workshop.SearchRecipeByName("Mana Potion");

    std::cout << "검색된 레시피: "
        << recipe.GetPotionName() << std::endl;

    // 재료 검색
    std::vector<PotionRecipe> herbRecipes =
        workshop.SearchRecipeByIngredient("Herb");

    std::cout << "Herb를 사용하는 레시피 수: "
        << herbRecipes.size() << std::endl;

    return 0;
}