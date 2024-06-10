#include <iostream>
#include <vector>
using namespace std;

vector<int> duaJumlah(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> hasil = duaJumlah(nums, target);

    if (!hasil.empty()) {
        cout << "Indeks: " << hasil[0] << ", " << hasil[1] << endl;
    } else {
        cout << " solusi ga ditemukan" << endl;
    }

    return 0;
}