To solve this, we can use a greedy algorithm. The greedy approach involves making locally optimal choices at each step to eventually reach a globally optimal solution. In our case, we’ll prioritize items based on their value-to-weight ratio.

Here’s how we can proceed:

Calculate Value-to-Weight Ratio:
For each item, compute the value-to-weight ratio (value divided by weight).
Sort Items by Ratio:
Sort the items in descending order of their value-to-weight ratio.
Select Items:
Start with an empty backpack.
Add items to the backpack in the order of their sorted ratio until the weight limit is reached.


#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

bool compareRatio(const Item& a, const Item& b) {
    double ratioA = static_cast<double>(a.value) / a.weight;
    double ratioB = static_cast<double>(b.value) / b.weight;
    return ratioA > ratioB; // Sort in descending order
}

int main() {
    std::vector<Item> items = {
        {100, 2},   // Canned food
        {80, 3},    // Medical supplies
        {120, 5},   // Weapons
        {50, 1}     // Tools
    };

    std::sort(items.begin(), items.end(), compareRatio);

    int totalWeight = 0;
    int totalValue = 0;

    for (const Item& item : items) {
        if (totalWeight + item.weight <= 10) {
            totalWeight += item.weight;
            totalValue += item.value;
        }
    }

    std::cout << "Max value carried: " << totalValue << std::endl;

    return 0;
}

In this example, the algorithm would select the weapons (120 value, 5 weight) and the canned food (100 value, 2 weight), 
totaling 220 value within the weight limit. Adjust the item values and weights as needed for your specific scenario.

