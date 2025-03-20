#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <utility>
#include <string>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

class disPlay {
private:
	int speed;
	char headX; // 蛇头的横坐标
	char headY; // 蛇头的纵坐标
	char tailX; // 蛇尾的横坐标
	char tailY; // 蛇尾的纵坐标
	int length; // 蛇的长度
	std::string disp[30][30]; // 第一个是行，第二个是列
	std::vector<std::pair<char, char>> snakeNode = { {10, 19}, {10, 9} ,{25, 9} };

public:
	disPlay() : headX(10), headY(10), tailX(10), tailY(9), length(2), speed(1000) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				disp[i][j] = "　";
			}
		}
	}
	void display() const {
		for (int i = 0; i < 20; i++) {
			std::cout << std::endl; // 清空屏幕
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				std::cout << disp[i][j];
			}
			std::cout << std::endl;
		}
	}
	void setNodeToNode(std::pair<char, char> snakeNode1, std::pair<char, char> snakeNode2) {
		if (snakeNode1.first == snakeNode2.first) {
			int minY = min(snakeNode1.second, snakeNode2.second); // 两个节点的纵坐标的最小值
			int maxY = max(snakeNode1.second, snakeNode2.second); // 两个节点的纵坐标的最大值
			for (int i = minY; i <= maxY; i++) {
				disp[snakeNode1.first][i] = "＊";
			}
		}
		else if (snakeNode1.second == snakeNode2.second) {
			int minX = min(snakeNode1.first, snakeNode2.first); // 两个节点的横坐标的最小值
			int maxX = max(snakeNode1.first, snakeNode2.first); // 两个节点的横坐标的最大值
			for (int i = minX; i <= maxX; i++) {
				disp[i][snakeNode1.second] = "＊";
			}
		}
		else {
			std::cout << "Error: The two nodes are not in the same row or column." << std::endl;
		}
	}
	void setBody() {
		for (int i = 0; i < snakeNode.size() - 1; i++) {
			setNodeToNode(snakeNode[i], snakeNode[i + 1]);
		}
	}
};

int main() {
	disPlay* d = new disPlay;
	d->setBody();
	d->display();
	delete d;

	return 0;
}