#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
    int32_t num_cars, max_floor_cars, num_plays;
    std::cin >> num_cars >> max_floor_cars >> num_plays;

    std::queue<int32_t> sequence;
    for (int32_t i = 0; i < num_plays; i++) {
        int32_t car_id;
        std::cin >> car_id;
        sequence.push(car_id);
    }

    int32_t operations = 0;
    std::unordered_set<int32_t> cars_on_floor;

    while (!sequence.empty()) {
        int32_t current_car = sequence.front();
        sequence.pop();
        if (cars_on_floor.count(current_car) == 0) {
            operations++;
            if (cars_on_floor.size() == max_floor_cars) {
                cars_on_floor.erase(cars_on_floor.begin());
            }
            cars_on_floor.insert(current_car);
        }
    }
    std::cout << operations << std::endl;
    return 0;
}