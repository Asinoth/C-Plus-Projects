#include "Simple_window.h"
#define iteration 7
#define winsize 700


//the class Vec2
class Vec2
{
public:
	int x, y;
};

//points x,y
vector<Vec2> find_the_points(vector<Vec2> og, int i)
{
	vector<Vec2> allthepoints;
	Vec2 up, down, upleft, upright, leftdown, rightdown, right, left;
	for (int j = 0; j < pow(8, i); j++)
	{
		up.x = og[j].x;
		up.y = og[j].y + winsize / pow(3, i + 1);
		allthepoints.push_back(up);

		down.x = og[j].x;
		down.y = og[j].y - winsize / pow(3, i + 1);
		allthepoints.push_back(down);


		upleft.x = og[j].x - winsize / pow(3, i + 1);
		upleft.y = og[j].y + winsize / pow(3, i + 1);
		allthepoints.push_back(upleft);

		upright.x = og[j].x + winsize / pow(3, i + 1);
		upright.y = og[j].y + winsize / pow(3, i + 1);
		allthepoints.push_back(upright);

		leftdown.x = og[j].x - winsize / pow(3, i + 1);
		leftdown.y = og[j].y - winsize / pow(3, i + 1);
		allthepoints.push_back(leftdown);

		rightdown.x = og[j].x + winsize / pow(3, i + 1);
		rightdown.y = og[j].y - winsize / pow(3, i + 1);
		allthepoints.push_back(rightdown);

		right.x = og[j].x + winsize / pow(3, i + 1);
		right.y = og[j].y;
		allthepoints.push_back(right);

		left.x = og[j].x - winsize / pow(3, i + 1);
		left.y = og[j].y;
		allthepoints.push_back(left);
	}

	return allthepoints;
}


//main

int main()
{
	Point x(100, 100); //where to open window
	Simple_window win(x, winsize, winsize , "sierpinski's carpet"); //opens the window

	vector<Vec2> og;
	Vec2 temp;
	temp.x = winsize / 2; //middle dot
	temp.y = winsize / 2;

	og.push_back(temp);

	Point first(og.at(0).x, og.at(0).y);
	Mark firsttemp(first, '.');
	win.attach(firsttemp);

	for (int i = 0; i < iteration ; i++) // find and prints the dots
	{
		og = find_the_points(og, i);
		Mark * p2;
		for (int p = 0; p < og.size(); p++)
		{
			p2 = new Mark(Point(og[p].x, og[p].y),'.');
			win.attach(*p2);
		}
	}
	win.wait_for_button();

}
