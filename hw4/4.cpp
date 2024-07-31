#include <iostream>
#include <vector>
#include <string>
#include "container_cout.h"

using std::cout, std::vector, std::endl, std::string;
using namespace std::string_literals;

class Time {
private:
    int mHours, mMinutes, mSeconds;
public:
    Time(int hours, int minutes, int seconds)
    {
    	mHours   = hours;
    	mMinutes = minutes;
    	mSeconds = seconds;
    }


    Time(std::string_view s) // строка в формате "hh:mm:ss"
    {
    	string h   = {s[0], s[1]};
    	string m   = {s[3], s[4]};
    	string sec = {s[6], s[7]};
    	mHours     = std::stoi(h);
    	mMinutes   = std::stoi(m);
    	mSeconds   = std::stoi(sec);
    }


    Time operator+(Time b) const
    {
    	int sec1 = mHours * 3600 + mMinutes * 60 + mSeconds;
    	int sec2 = b.hours() * 3600 + b.minutes() * 60 + b.seconds();
    	int sum  = sec1 + sec2;
    	return Time((sum / 3600) % 24, (sum % 3600) / 60, sum % 60);
    }

    int hours() const {return mHours;}
    int minutes() const {return mMinutes;}
    int seconds() const {return mSeconds;}

    friend std::ostream& operator<<(std::ostream& out, Time t);
};

std::ostream& operator<<(std::ostream& out, Time t)
{
	out << "(" << t.hours() << ":" << t.minutes() << ":" << t.seconds() << ")";
	return out;
}


Time stotime(std::string_view s) // строка в формате "hh:mm:ss"
    {
    	string h   = {s[0], s[1]};
    	string m   = {s[3], s[4]};
    	string sec = {s[6], s[7]};
    	int hours     = std::stoi(h);
    	int minutes   = std::stoi(m);
    	int seconds   = std::stoi(sec);
    	return Time(hours, minutes, seconds);
    }

vector<Time> getTimesFromString(std::string_view s)
{
	vector<Time> t {};
	string cur_t {};
	int n = s.size() / 9 + 1;
	for (int i = 0; i < n; i++)
	{
		cur_t = s.substr(i * 9, 8);
		t.push_back(stotime(cur_t));
	}
	return t;
}


Time sumTimes(const std::vector<Time>& v)
{
	int sz = v.size();
	int fullsec = 0;

	for (int i = 0; i < sz; i++)
		fullsec += v[i].hours() * 3600 + v[i].minutes() * 60 + v[i].seconds();

	int h = (fullsec / 3600) % 24;
	int m = (fullsec % 3600) /60;
	int s = fullsec % 60;

	return Time(h, m, s);
}

int main()
{
	Time t1 (12, 31, 58);
	Time t2 (13, 20, 47);
	Time t3 ("12:13:14");
	cout << t1 + t2 << endl;
	cout << t3 << endl;
	vector<Time> t = getTimesFromString("12:20:05 05:45:30 22:10:45");
	cout << t << endl;
	Time fulltime = sumTimes(t);
	cout << fulltime;
	return 0;
}