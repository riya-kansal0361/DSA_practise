class FoodRatings {
public:
    unordered_map<string,int> food_rating;
    unordered_map<string,string> food_cuisine;
    unordered_map<string, set<pair<int,string>>> cuisine_rating_food;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i=0;i<n;i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            
            food_rating[food] = rating;
            food_cuisine[food] = cuisine;
            cuisine_rating_food[cuisine].insert({-rating,food});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rating = food_rating[food];
        food_rating[food] = newRating;
        string cuisine = food_cuisine[food];
        
        cuisine_rating_food[cuisine].erase({-old_rating,food});
        
        cuisine_rating_food[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */