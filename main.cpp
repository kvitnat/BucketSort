#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<float> array;
    float a;
    float max = 0;
    std::cin >> a;
    while(a != 0)
    {
        array.push_back(a);
        std::cin >> a;
        if (a > max)
            max = a;
    }
    int n = array.size();

    std::vector<float> buckets[n];

    for(int i = 0; i < n; ++i)
    {
        int index = array[i] * n / (max + 1);
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i < n; i++)
        std::sort(buckets[i].begin(), buckets[i].end());

    int collisions = 0;
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            std::cout << buckets[i][j] << ' ';
            if (buckets[i].size() > collisions)
                collisions = buckets[i].size();
        }
    }
    std::cout << '\n' << collisions << '\n';

    return 0;
}
