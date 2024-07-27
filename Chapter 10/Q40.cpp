
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

struct PointWithDistance {
	int32_t x;
	int32_t y;
	double distance;

	PointWithDistance(int32_t x_in, int32_t y_in)
		:x(x_in), y(y_in) {
		distance = (x * x) + (y * y);
	}
	bool operator<(const PointWithDistance& other) const {
		return distance < other.distance;
	}
};

std::vector<std::vector<int32_t>> k_closest_to_origin (const std::vector<
std::vector<int32_t>>& points, int32_t k) {
	std::priority_queue<PointWithDistance, std::vector<PointWithDistance>> pq;
	for(const auto& point: points) {
		pq.emplace(point[0], point[1]);
		if(pq.size() > k) {
			pq.pop();
		}
	}
	std::vector<std::vector<int32_t>> solution;
	solution.reserve(k);

	while(!pq.empty()) {
		solution.push_back({pq.top().x, pq.top().y});
		pq.pop();
	}

	return solution;
}

void print_vec(const std::vector<std::vector<int32_t>> vec) {

    for(const auto& i : vec) { 
        std::cout << "{" << i[0] << ", " << i[1] << "}\n";    
    }

}

int main()
{
	std::vector<std::vector<int32_t>> points = {
		{101, 183},
		{-203, 280},
		{281, -370}
	};
	auto answer = k_closest_to_origin(points, 2);
	print_vec(answer); 
	return 0;
}