#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <utility>
#include <string>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

constexpr auto row = 25;
constexpr auto col = 25;

class disPlay {
private:
	int speed;
	int length;				// 蛇的长度
	char headX;				// 蛇头的横坐标
	char headY;				// 蛇头的纵坐标
	char tailX;				// 蛇尾的横坐标
	char tailY;				// 蛇尾的纵坐标
	char direction;			// 蛇的方向

	std::string disp[row][col];
	std::vector<std::pair<char, char>> snakeNodeVector;

public:
	disPlay() : speed(1000), length(6), headX(10), headY(10), tailX(10), tailY(5), direction('R') {
		snakeNodeVector = { {10, 10}, {10, 5} };
		resetBody();
	}
	~disPlay() {
		delete[] disp;
	}

	void setHeadX(char x) {
		headX = x;
	}
	char getHeadX() const {
		return headX;
	}
	void setHeadY(char y) {
		headY = y;
	}
	char getHeadY() const {
		return headY;
	}
	int getSpeed() const {
		return speed;
	}
	void setDirection(char d) {
		direction = d;
	}
	char getDirection() const {
		return direction;
	}
	void insertNode(std::pair<char, char> newNode) {
		snakeNodeVector.insert(snakeNodeVector.begin(), newNode);
	}
	void setFirstNode(int X, int Y) {
		snakeNodeVector[0] = { X, Y };
	}

	void resetBody() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				disp[i][j] = "[]"; // □
			}
		}
	}
	void display() const {
		for (int i = 0; i < 20; i++) {
			std::cout << std::endl;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << disp[i][j];
			}
			std::cout << std::endl;
		}
	}
	int setNodeToNode(int lengthTemp, std::pair<char, char> snakeNode1, std::pair<char, char> snakeNode2) {
		int length_Node1_Node2 = 0;
		if (snakeNode1.first == snakeNode2.first) {
			int minY = MIN(snakeNode1.second, snakeNode2.second);
			int maxY = MAX(snakeNode1.second, snakeNode2.second);
			length_Node1_Node2 = maxY - minY + 1;

			if (this->length < lengthTemp + length_Node1_Node2) {
				for (int i = minY; i <= this->tailY; i++) {
					disp[snakeNode1.first][i] = "＊";
				}
			}
			else {
				for (int i = minY; i <= maxY; i++) {
					disp[snakeNode1.first][i] = "＊";
				}
			}
		}
		else if (snakeNode1.second == snakeNode2.second) {
			int minX = MIN(snakeNode1.first, snakeNode2.first);
			int maxX = MAX(snakeNode1.first, snakeNode2.first);
			length_Node1_Node2 = maxX - minX + 1;

			if (this->length < lengthTemp + length_Node1_Node2) {
				for (int i = minX; i <= this->tailX; i++) {
					disp[i][snakeNode1.second] = "＊";
				}
			}
			else {
				for (int i = minX; i <= maxX; i++) {
					disp[i][snakeNode1.second] = "＊";
				}
			}
		}
		else {
			std::cout << "Error: The two nodes are not in the same row or column." << std::endl;
		}
		return length_Node1_Node2;
	}
	void setBody() {
		int lengthTemp = 0;
		resetBody();
		if (snakeNodeVector.size() == 1) {
			std::pair<char, char> nodeTemp = { tailX, tailY };
			setNodeToNode(lengthTemp, snakeNodeVector[0], nodeTemp);
		}
		for (int i = 0; i < snakeNodeVector.size() - 1; i++) {
			lengthTemp += setNodeToNode(lengthTemp, snakeNodeVector[i], snakeNodeVector[static_cast<std::vector<std::pair<char, char>, std::allocator<std::pair<char, char>>>::size_type>(i) + 1]);
		}
	}
	void headMove() {
		if ('U' == direction) {
			headX--;
		}
		else if ('D' == direction) {
			headX++;
		}
		else if ('L' == direction) {
			headY--;
		}
		else if ('R' == direction) {
			headY++;
		}
	}
	void tailMove() {
		if (tailX == snakeNodeVector[snakeNodeVector.size() - 1].first && tailY == snakeNodeVector[snakeNodeVector.size() - 1].second) {
			snakeNodeVector.pop_back();
		}

		if (tailX == snakeNodeVector[snakeNodeVector.size() - 1].first) {
			// 蛇尾在同一行
			if (tailY < snakeNodeVector[snakeNodeVector.size() - 1].second) {
				tailY++;
			}
			else if (tailY > snakeNodeVector[snakeNodeVector.size() - 1].second) {
				tailY--;
			}
		}
		else if (tailY == snakeNodeVector[snakeNodeVector.size() - 1].second) {
			// 蛇尾在同一列
			if (tailX < snakeNodeVector[snakeNodeVector.size() - 1].first) {
				tailX++;
			}
			else if (tailX > snakeNodeVector[snakeNodeVector.size() - 1].first) {
				tailX--;
			}
		}
	}
};

int main() {
	disPlay* d = new disPlay;

	while (true) {
		if (d->getHeadX() <= 0 || d->getHeadX() >= row - 1 || d->getHeadY() <= 0 || d->getHeadY() >= col - 1) {
			break;
		}
		if (_kbhit()) {
			char ch = _getch();

			if (ch == 'w' || ch == 'W') {
				std::pair<char, char> newNode = { d->getHeadX(), d->getHeadY() - 1 };
				d->insertNode(newNode); // 插入新的首个转弯节点
				d->setDirection('U');
			}
			else if (ch == 's' || ch == 'S') {
				std::pair<char, char> newNode = { d->getHeadX(), d->getHeadY() + 1 };
				d->insertNode(newNode);
				d->setDirection('D');
			}
			else if (ch == 'a' || ch == 'A') {
				std::pair<char, char> newNode = { d->getHeadX() - 1, d->getHeadY() };
				d->insertNode(newNode);
				d->setDirection('L');
			}
			else if (ch == 'd' || ch == 'D') {
				std::pair<char, char> newNode = { d->getHeadX() + 1, d->getHeadY() };
				d->insertNode(newNode);
				d->setDirection('R');
			}
		}
		if (d->getHeadX() <= 0 || d->getHeadX() >= row - 1 || d->getHeadY() <= 0 || d->getHeadY() >= col - 1) {
			break;
		}
		d->headMove();
		d->tailMove();

		d->setFirstNode(d->getHeadX(), d->getHeadY());

		d->setBody();
		d->display();

		Sleep(d->getSpeed());
	}
	delete d;

	return 0;
}