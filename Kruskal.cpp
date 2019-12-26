#include <iostream>
#include <algorithm>
#include <vector>

#define VERTEX	7
#define EDGE	11

using namespace std;

int getParent(int*, int);
void unionParent(int*, int, int);
bool findParent(int*, int, int);

class Node {
public:
	int node1;
	int node2;
	int distance;

	Node(int node1, int node2, int distance) {
		this->node1 = node1;
		this->node2 = node2;
		this->distance = distance;
	}

	bool operator < (Node& node) {
		return this->distance < node.distance;
	}
};

int main() {
	vector<Node> v;
	v.push_back(Node(1, 7, 12));
	v.push_back(Node(1, 4, 28));
	v.push_back(Node(1, 2, 67));
	v.push_back(Node(1, 5, 17));
	v.push_back(Node(2, 4, 24));
	v.push_back(Node(2, 5, 62));
	v.push_back(Node(3, 5, 20));
	v.push_back(Node(3, 6, 37));
	v.push_back(Node(4, 7, 13));
	v.push_back(Node(5, 6, 45));
	v.push_back(Node(5, 7, 73));

	sort(v.begin(), v.end());

	int parent[VERTEX + 1];
	for (int i = 1; i <= VERTEX; i++)
		parent[i] = i;
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node1, v[i].node2)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node1, v[i].node2);
		}
	}

	printf("최소비용 : %d\n", sum);
}

int getParent(int* parent, int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = getParent(parent, parent[v]);
}

//UNION - FIND 함수
void unionParent(int* parent, int a, int b) {
	if (getParent(parent, a) > getParent(parent, b))
		parent[a] = b;
	else
		parent[b] = a;
}

bool findParent(int* parent, int a, int b) {
	if(getParent(parent, a) == getParent(parent,b))
		return true;
	return false;
}

